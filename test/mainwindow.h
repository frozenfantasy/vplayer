#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "multi_player.h"
#include "clientwidget.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <multi_player.h>
QT_BEGIN_NAMESPACE
static int ifconnect=0;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display(QImage img);
    void update_size();
    ClientWidget *tcpclient=new ClientWidget();
    multi_player get_player();
    multi_player *p;
    void set_my_socket(QTcpSocket *skt);
    QTcpSocket* _socket;

protected:
    virtual bool event(QEvent *event);
private slots:
    void on_actionconnect_triggered();
    //void receiveData(QString data);
    void connect_tcp();
private:
    //multi_player *p;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
