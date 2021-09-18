#include "mark_bar.h"
#include "ui_mark_bar.h"
#include <QDebug>
#include <QImage>

mark_bar::mark_bar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mark_bar)
{
    ui->setupUi(this);
    ui->bar->setMinimumWidth(width());

    mcolor = Qt::red;

    marker_count =100;
    marker_strok = 1;
    update_marker_width();
    LBtail = new marker_lb(this,marker_count);
   // add_marker(0);
}

void mark_bar::update_marker_width()
{
    marker_width = ui->bar->width() / marker_count - marker_strok;
    marker_l = marker_width + marker_strok;
}

void mark_bar::insert_marker(uint x)
{
    LBtail->insert_marker(x);
}

QSlider *mark_bar::get_bar()
{
    return ui->bar;
}
void mark_bar::set_bar_value(int val)
{
    ui->bar->setValue(val);
}
void mark_bar::set_bar_maximum(int val)
{
    ui->bar->setMaximum(val);
    max_frame = val;
    if(max_frame % marker_count == 0)
        LBtail->check_marker();
}
int mark_bar::get_bar_value()
{
    return ui->bar->value();
}

mark_bar::~mark_bar()
{
    delete ui;
}

void mark_bar::set_width(int val)
{

    resize(val,30);
    ui->bar->resize(val,20);
    update_marker_width();
    LBtail->update_coor();
}

mark_bar::marker_lb::marker_lb(mark_bar *parent,uint x) :
    QPushButton(parent)
{
    id = x;
    p = parent;
    if(isVisible())
        update_coor();
    setFlat(1);
    QPalette pal = palette();
    pal.setColor(QPalette::Button,parent->mcolor);
    setPalette(pal);
    setAutoFillBackground(true);
    if(x)
        next = new marker_lb(parent,x-1);
    else
        next = NULL;
}

void mark_bar::marker_lb::add_marker(uint x)
{
    bucket.push_back(x);
}
void mark_bar::marker_lb::insert_marker(uint x)
{
    if(x < lstamp)
    {
        next->insert_marker(x);
    }
    else
    {
        if(bucket.back()<x)
            bucket.push_back(x);
        for(auto i = bucket.begin();i!=bucket.end();i++)
        {
            if(*i>=x)
            {
                if(*i!=x)
                    bucket.insert(i,x);
                return;
            }
        }
    }
}

void mark_bar::marker_lb::check_marker()    //
{
    if(bucket.empty())
    {
        setVisible(0);
    }
    else
    {
        if(!isVisible())
            setVisible(1);
        while(!bucket.empty() &&bucket.front()<lstamp)
        {
            next->add_marker(bucket.front());
            bucket.pop_front();
        }
    }
    if(next)
        next->check_marker();
    update_coor(0);
}
void mark_bar::marker_lb::update_coor(bool f)
{
    qDebug()<<"updating"<<id;
    lstamp = id * p->max_frame / p->marker_count;
    if(!isVisible())
        return;
    if(uint(width())!=id*p->marker_l || uint(x())!=p->marker_width)
        setGeometry(id*p->marker_l,18,p->marker_width,10);
    if(next && f)
        next->update_coor();
}
