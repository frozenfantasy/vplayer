#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <vector>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QDebug>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new multi_player(this);
    ui->L->addWidget(p);

}

bool MainWindow::event(QEvent *event)
{

    if(event->type() == QEvent::NonClientAreaMouseButtonRelease)
    {
        update_size();
        return true;
    }
    else if(event->type() == QEvent::Resize)
    {

        return true;
    }
    else
        return QWidget::event(event);
}

void MainWindow::update_size()
{
   // p->req_resize(width(),height());
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionconnect_triggered()
{
    tcpclient->show();
    _socket=NULL;
    //信号不太对
    connect(tcpclient->tcpSocket,SIGNAL(on_ButtonConnect_clicked()),this,SLOT(connect_tcp()));
    //set_my_socket(tcpclient->get_my_socket());
    qDebug()<<"connect!";
}

void MainWindow::connect_tcp(){
    set_my_socket(tcpclient->get_my_socket());
}

void MainWindow::set_my_socket(QTcpSocket *skt){
    qDebug()<<"how dare u!";
    _socket=skt;
    p->mul_socket=this->_socket;
    ifconnect=1;
}
/*multi_player get_player(){
    
}*/

