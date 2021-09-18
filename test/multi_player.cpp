#include "multi_player.h"
#include "ui_multi_player.h"

#include <QRadioButton>
#include <QPushButton>
#include <QDebug>
multi_player::multi_player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multi_player)
{
    ui->setupUi(this);

    dm = new daemon(this);

    Lplayer = new QGridLayout();
    Lmarker = new QVBoxLayout();
    Lpanel = new QHBoxLayout();
    Lsize = new QVBoxLayout();

    Lplayer->setVerticalSpacing(0);
    Lplayer->setHorizontalSpacing(0);
    Lplayer->setSpacing(0);

    ui->Layout->addLayout(Lplayer,0,0,8,8);
    ui->Layout->addLayout(Lmarker,8,0,1,8);
    ui->Layout->addLayout(Lpanel,9,0,2,8);
    Boff = new QPushButton("停止");
    Bsave = new QPushButton("保存视频");
    Bload = new QPushButton("载入");
    Bstop_continue = new QPushButton("播放/暂停");
    LBframe_info = new QLabel("Frame_Info");
    Lpanel->addWidget(Boff);
    Lpanel->addWidget(Bstop_continue);
    Lpanel->addWidget(Bsave);
    Lpanel->addWidget(Bload);
    Lpanel->addLayout(Lsize);
    Lpanel->addWidget(LBframe_info);


    rgsz = new QButtonGroup();
    rgsz->setExclusive(1);
    for(uint i=1;i<=maximum_size;i++)
    {
        QRadioButton *t = new QRadioButton((std::to_string(i)+"X"+std::to_string(i)).c_str());
        rgsz->addButton(t);
        QObject::connect(t,&QRadioButton::clicked,this,[=](){
            on_rbsz_checked(i);
        });
        QObject::connect(Boff,&QPushButton::clicked,this,[=](){
            on_mp_off_clicked();
            });
        Lsize->addWidget(t);
    }

    QObject::connect(Bload,SIGNAL(clicked()),this,SLOT(on_mp_load_clicked()));
    QObject::connect(Bstop_continue,SIGNAL(clicked()),this,SLOT(on_mp_stop_continue_cicked()));
    QObject::connect(Bsave,SIGNAL(clicked()),this,SLOT(on_mp_save_clicked()));
    size = 0;
    cur_col = cur_row = 0;
    cur_marker = NULL;
    for(uint i=0;i<maximum_size;i++)
        for(uint j=0;j<maximum_size;j++)
            players[i][j] = NULL;
    init_players(1);
    select(0,0);
    players[0][0]->load_cam(0);

    dm->start();
}

multi_player::~multi_player()
{
    delete ui;
    stop_all();
    close_all();
    delete dm;
}

void multi_player::init_players(uint sz)
{
    if(cur_col > sz || cur_row > sz)
        select(0,0);
    while(size<sz)
    {
        size++;
        for(uint i=0;i<size-1;i++)
        {
            add_player(i,size-1);
            add_player(size-1,i);
        }
        add_player(size-1,size-1);
    }
    while(size>sz)
    {
        for(uint i=0;i<size-1;i++)
        {
            remove_player(i,size-1);
            remove_player(size-1,i);
        }
        remove_player(size-1,size-1);
        size--;
    }
    for(uint i=0;i<size;i++)
    {
        for(uint j=0;j<size;j++)
        {
            players[i][j]->req_resize(width()/size,(height()*8/11)/size);
        }
    }
}

void multi_player::close_all()
{
    for(uint i=0;i<maximum_size;i++)
    {
        for(uint j=0;j<maximum_size;j++)
        {
            if(players[i][j])
                players[i][j]->on_off_clicked();
        }
    }
}

void multi_player::stop_all()
{
    for(uint i=0;i<maximum_size;i++)
    {
        for(uint j=0;j<maximum_size;j++)
        {
            if(players[i][j])
                players[i][j]->set_stop(1);
        }
    }
}

void multi_player::select(int row,int col)
{
    if(cur_marker)
        cur_marker->setVisible(0);
    cur_marker = players[row][col]->get_mark_bar();
    cur_marker->set_width(width() - 80);
    cur_marker->set_bar_maximum(players[row][col]->get_frames());
    cur_marker->setVisible(1);
    cur_row = row;
    cur_col = col;
}

void multi_player::add_player(int row,int col)
{
    if(!players[row][col])
    {
        players[row][col] = new player(this,0,row,col);
        players[row][col]->player_socket=mul_socket;
        QObject::connect(players[row][col],static_cast<void(player::*)()>(&player::clicked),this,[=](){
            on_player_clicked(row,col);
        });

        Lplayer->addWidget(players[row][col],row,col,1,1);
        players[row][col]->get_mark_bar()->setVisible(0);
        Lmarker->addWidget(players[row][col]->get_mark_bar());
    }
    else
    {
        players[row][col]->setVisible(1);
    }
}
void multi_player::remove_player(int row, int col)
{
//    qDebug()<<row<<col;
    if(players[row][col])
    {
        players[row][col]->set_stop(1);
        players[row][col]->setVisible(0);
        //ui->LPlayer->removeWidget(players[row][col]);
        //->removeWidget();
        //delete players[row][col];
    }
}


void multi_player::on_rbsz_checked(uint i)
{
//    stop_all();
    init_players(i);
}
void multi_player::on_mp_off_clicked()
{
    close_all();
}

multi_player::daemon::daemon(multi_player *mp)
{
    this->mp = mp;
}

void multi_player::daemon::run()
{
    while(enable)
    {
        emit mp->flush();
   //     flushall();
        msleep(10);
    }
    enable = 1;
}

void multi_player::on_player_clicked(uint row,uint col)
{
    qDebug()<<"Switched"<<col<<row;
    select(row,col);
}

void multi_player::on_mp_load_clicked()
{
    players[cur_row][cur_col]->on_load_clicked();
}

void multi_player::on_mp_stop_continue_cicked()
{
    players[cur_row][cur_col]->on_stop_continue_clicked();
}

void multi_player::on_mp_save_clicked()
{
    players[cur_row][cur_col]->on_save_clicked();
}
