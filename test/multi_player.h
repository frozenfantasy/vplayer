#ifndef MULTI_PLAYER_H
#define MULTI_PLAYER_H

#include "player.h"
#include <qtcpsocket.h>
#include <QButtonGroup>
#include <QGridLayout>
#include <QRadioButton>
#include <QWidget>
#include <QPushButton>
#include <mainwindow.h>
#include <player.h>
class MainWindow;

namespace Ui {
class multi_player;
}
class multi_player : public QWidget
{
    Q_OBJECT

public:
    explicit multi_player(QWidget *parent = nullptr);
    ~multi_player();
    QTcpSocket* mul_socket;
signals:
    void flush();
public slots:
    void on_rbsz_checked(uint i);
    void on_mp_off_clicked();
    void on_mp_save_clicked();
    void on_mp_load_clicked();
    void on_mp_stop_continue_cicked();
    void on_player_clicked(uint row,uint col);
protected:
    uint size;
    uint cur_col,cur_row;
    mark_bar *cur_marker;
    void init_players(uint sz);
    void add_player(int row,int col);
    void remove_player(int row,int col);
    void mod_player_size(int w,int h);
    void select(int row,int col);
    void stop_all();
    void close_all();
private:
    class daemon : public QThread
    {
    public:
        daemon(multi_player *mp);
        void disable();
        bool disabled();
    protected:
        bool enable;
        multi_player * mp;
        void run();


    };
    MainWindow *m_parent;
    daemon *dm;
    Ui::multi_player *ui;
    QButtonGroup *rgsz;
    QGridLayout *Lplayer;
    QVBoxLayout *Lmarker;
    QVBoxLayout *Lsize;
    QHBoxLayout *Lpanel;
    QPushButton *Boff;
    QPushButton *Bsave;
    QPushButton *Bload;
    QPushButton *Bstop_continue;
    QLabel *LBframe_info;
    QTcpSocket *_socket;
    const uint maximum_size = 4;
    player *players[4][4];
};

#endif // MULTI_PLAYER_H
