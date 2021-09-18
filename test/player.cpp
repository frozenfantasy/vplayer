#include "player.h"
#include "ui_player.h"
#include "misc.h"
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <QPushButton>
#include <QObject>
#include <string>
#include <QDebug>
#include <QFileDialog>
#include <multi_player.h>
#include <QHostAddress>
#include <QTcpSocket>
player::player(QWidget *parent,bool init_control_panel,uint r,uint c) :
    QWidget(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);

    Lplayer = new QGridLayout();
    ui->Layout->addLayout(Lplayer,0,0,8,8);

    if(init_control_panel)
    {
        Lmarker = new QVBoxLayout();
        Lpanel = new QHBoxLayout();

        ui->Layout->addLayout(Lmarker,8,0,1,8);
        ui->Layout->addLayout(Lpanel,9,0,2,8);
        Boff = new QPushButton("OFF");
        Bsave = new QPushButton("SAVE");
        Bload = new QPushButton("LOAD");
        Bstop_continue = new QPushButton("STOP_CONTINUE");
        Lpanel->addWidget(Boff);
        Lpanel->addWidget(Bstop_continue);
        Lpanel->addWidget(Bsave);
        Lpanel->addWidget(Bload);

    }
    has_panel = init_control_panel;

    row = r;
    col = c;
    dm = new daemon(this);
    displayer = new QLabel("click here for playing video");
    marker = new mark_bar();
    LBframe_info = new QLabel("Frame_Info");

    Lplayer->addWidget(displayer);

    displayer->setVisible(1);
    if(init_control_panel)
    {
        Lmarker->addWidget(marker);
        Lpanel->addWidget(LBframe_info);
        marker->setVisible(1);
        Bstop_continue->setText("STOP");

    }
    else
        marker->setVisible(0);
    update_size();

    cur_frame = frame_top = 0;


    vc = NULL;


    vp_tmp = new temp_manager("vp_temp/vp("+std::to_string(row)+","+std::to_string(col)+")");

    if(init_control_panel)
    {
        QObject::connect(Boff,SIGNAL(QButton::clicked()),this,SLOT(on_off_clicked()));
        QObject::connect(Bstop_continue,SIGNAL(QButton::clicked()),this,SLOT(on_stop_continue_clicked()));
        QObject::connect(Bsave,SIGNAL(QButton::clicked()),this,SLOT(on_save_clicked()));
        QObject::connect(Bload,SIGNAL(QButton::clicked()),this,SLOT(on_load_clicked()));
    }
    QObject::connect(marker->get_bar(),SIGNAL(sliderPressed()),this,SLOT(on_bar_sliderPressed()));
    QObject::connect(marker->get_bar(),SIGNAL(sliderReleased()),this,SLOT(on_bar_sliderReleased()));
    dm->start();
}

player::daemon::daemon(player * pl)
{
    p = pl;
    enable = true;
    stopped = 0;
    streaming = 1;
    to_save = 0;
    to_load = 0;

}

player::~player()
{
    delete ui;
    delete marker;
    delete vp_tmp;
    delete vc;

    delete dm;
    qDebug()<<"Player deleted";
}

mark_bar *player::get_mark_bar()
{
    return marker;
}

void player::display(QImage img)
{

    displayer->setPixmap(QPixmap::fromImage(img).scaled(d_width,d_height));
}
void player::display(int frame)
{
    display(get_frame(frame));

}
void player::display_next()
{
  //  qDebug()<<"next";
    cur_frame++;
    if(cur_frame<frame_top)
    {
        display(cur_frame);
        marker->set_bar_value(cur_frame);
    }
}
bool player::has_next()
{
    return frame_top && cur_frame<frame_top-1;
}
uint player::get_frames()
{
    return frame_top;
}
cv::Mat player::get_frame()
{
    cv::Mat frame;
    if(vc)
        vc->read(frame);
 //   qDebug()<<frame.empty();
    return frame;
}
QImage player::get_frame(int frame)
{
    if(ifconnect){
        //qDebug()<<player_socket->peerAddress().toString();
        //qDebug()<<QString("fuck u!");
    }
    return QImage(get_frame_path(frame).c_str());
}

std::string player::get_frame_path(int frame)
{
    return vp_tmp->temp_prefix+"/temp_frame"+std::to_string(frame)+".jpg";
}

void player::add_frame(cv::Mat frame)
{
    ++frame_top;
    cv::imwrite(get_frame_path(frame_top),frame);
    if(marker->isVisible())
        marker->set_bar_maximum(frame_top);
}

void player::update_frame()
{

    LBframe_info->setText((std::to_string(cur_frame+1)+"/"+std::to_string(frame_top)).c_str());
    //qDebug()<<(std::to_string(cur_frame+1)+"/"+std::to_string(frame_top)).c_str();
}

void player::save(std::string path)
{
    cv::VideoWriter vw;
    vw.open(path,vw.fourcc('M','J','P','G'),60,cv::Size(640,480));
    cv::Mat mat;
    for(unsigned int i = 1;i<=frame_top;i++)
    {
        vw<<cv::imread(get_frame_path(i));
    }
    vw.release();
}
void player::load()
{
    cur_frame = frame_top = 0;
    vc = new cv::VideoCapture(load_path);

    qDebug()<<load_path.c_str();
}
void player::load_cam(uint c)
{
    cur_frame = frame_top = 0;
    delete(vc);
    vc = new cv::VideoCapture(c);
}

void player::req_load()
{
    load_path = QFileDialog::getOpenFileName(this, "请选择视频文件路径...", "./").toStdString();
    dm->prep_load();
}

void player::update_size()
{
    qDebug()<<"Resizing";
    d_width = req_w;
    d_height = req_h;
    resize(req_w,req_h);
    displayer->resize(d_width,d_height);
    if(has_panel)
        marker->set_width(req_w - 80);
}

void player::req_resize(int w, int h)
{
    if(w>4000)
        w = 4000;
    if(h>3000)
        h = 3000;
    req_w = w;
    req_h = h;
    if(dm->is_stopped())
        update_size();
    else
        dm->set_resizing(1);
}

void player::mouseReleaseEvent(QMouseEvent * ev){
//   qDebug()<<row<<col;
   emit clicked();
}

void player::daemon::run()
{
    while(enable)
    {
        check_flag();
        while(!p->vc && enable)
        {
            msleep(100);
            check_flag();
        }
        if(sliding)
        {
            p->cur_frame = p->marker->get_bar_value();
            p->display(p->cur_frame);
        }
        else if(!stopped)
        {
            while(resizing && enable)
            {
                resizing = 0;
                msleep(100);
                if(!resizing)
                    p->update_size();
            }
            if(!p->has_next())
            {
                if(!streaming)
                {
               //     qDebug()<<"Not streaming,stopping";
                    set_stop(1);
                }
            }
            else
            {
                p->display_next();
            }
        }
        if(streaming)
        {
            cv::Mat mat = p->get_frame();
            if(!mat.empty())
                p->add_frame(mat);
        }
        msleep(17);
        p->update_frame();
    }
    enable = 1;
}

void player::daemon::check_flag()
{
    if(to_load)
    {
        p->load();
        to_load = 0;
    }
    if(to_save)
    {
        p->save("SAVE("+std::to_string(p->row)+","+std::to_string(p->col)+").avi");
        to_save = 0;
        qDebug()<<(std::string("Saved ")+"SAVE("+std::to_string(p->row)+","+std::to_string(p->col)+").avi").c_str();
    }
}

void player::daemon::disable()
{
    enable = false;
}
bool player::daemon::disabled()
{
    return enable;
}
void player::daemon::set_stop(bool flag)
{
  //  qDebug()<<p->row<<p->col<<"stop"<<flag;
    stopped = flag;
}

void player::daemon::set_sliding(bool flag)
{
    sliding = flag;
}

void player::daemon::set_resizing(bool f)
{
    resizing = f;
}

bool player::daemon::stop_continue()
{
    set_stop(!stopped);
    return stopped;
}
void player::daemon::prep_save()
{
    to_save = 1;
}
void player::daemon::prep_load()
{
    to_load = 1;
}

void player::set_stop(bool f)
{
    dm->set_stop(f);
}

bool player::daemon::is_stopped()
{
    return stopped;
}



void player::on_off_clicked()
{
    dm->disable();
}

void player::on_stop_continue_clicked()
{
   // qDebug()<<"stop_continue clicked";
    if(has_panel)
        Bstop_continue->setText(dm->stop_continue()?"CONTINUE":"STOP");
    else
        dm->stop_continue();
}

void player::on_save_clicked()
{
    dm->prep_save();
}

void player::on_load_clicked()
{
    req_load();
}

void player::on_bar_sliderPressed()
{
    dm->set_sliding(1);
}
void player::on_bar_sliderReleased()
{
    dm->set_sliding(0);
}

