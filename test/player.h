#ifndef PLAYER_H
#define PLAYER_H

#include "mark_bar.h"
#include "temp_manager.h"
#include <QWidget>
#include <QThread>
#include <QLabel>

#include <opencv2/core/mat.hpp>

#include <opencv2/videoio.hpp>

#include <QButtonGroup>
#include <QHBoxLayout>
#include <QPushButton>
#include <clientwidget.h>
class multi_player;
class mainclass;

namespace Ui {
class player;
}

class player : public QWidget
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = nullptr,bool init_control_panel = 0,uint r = 0,uint c = 0);
    void display(QImage img);
    void display(int frame);
    void display_next();
    bool has_next();
    mark_bar *get_mark_bar();
    void add_frame(cv::Mat frame);
    void load_cam(uint c);
    void set_stop(bool f);
    std::string get_frame_path(int frame);
    QImage get_frame(int frame);
    uint get_frames();
    cv::Mat get_frame();
    void update_frame();
    void update_size();
    void req_resize(int w,int h);
    ~player();
    void req_load();
    QTcpSocket* player_socket;
signals:
    void clicked();
public slots:
    void on_off_clicked();
    void on_stop_continue_clicked();
    void on_save_clicked();
    void on_bar_sliderPressed();
    void on_bar_sliderReleased();
    void on_load_clicked();
protected:
//    virtual bool event(QEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent * ev);
    void load();
    void save(std::string path);
    uint req_w,req_h;       //
    uint d_width,d_height;  //
    uint row,col;   //inited
    bool has_panel; //inited
    uint frame_top; //inited
    uint cur_frame; //inited
    std::string load_path;
private:
    Ui::player *ui;
    class daemon : public QThread
    {
    public:
        daemon(player *pl);
    protected:
        bool enable;
        bool stopped;
        bool sliding;
        bool to_save;
        bool to_load;
        bool resizing;
        bool streaming;
        int req_w,req_h;
        player * p;
        void run();
    public:
        void disable();
        bool disabled();
        bool stop_continue();
        void set_stop(bool f);
        bool is_stopped();
        void set_sliding(bool f);
        void set_resizing(bool f);
        void load(std::string path);
        void prep_load();
        void prep_save();
        void check_flag();
    };
    daemon *dm;
    //multi_player* m_parent;
    QLabel *displayer;
    mark_bar *marker;
    temp_manager *vp_tmp;
    cv::VideoCapture *vc;

    QButtonGroup *rgsz;
    QGridLayout *Lplayer;
    QVBoxLayout *Lmarker;
    QHBoxLayout *Lpanel;
    QPushButton *Boff;
    QPushButton *Bsave;
    QPushButton *Bload;
    QPushButton *Bstop_continue;
    QLabel *LBframe_info;
};

#endif // PLAYER_H
