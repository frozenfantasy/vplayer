#ifndef MARK_BAR_H
#define MARK_BAR_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>

namespace Ui {
class mark_bar;
}

class mark_bar : public QWidget
{
    Q_OBJECT

public:
    explicit mark_bar(QWidget *parent = nullptr);
    ~mark_bar();
    QSlider *get_bar();
    void set_bar_value(int val);
    void set_bar_maximum(int val);
    void insert_marker(uint x);
    int get_bar_value();
    void set_width(int val);
protected:
    uint marker_count;
    uint marker_width;
    uint marker_strok;
    uint marker_l;
    uint max_frame;
    QColor mcolor;
    void update_marker_width();
private:
    Ui::mark_bar *ui;
    class marker_lb : public QPushButton
    {
    public:
        marker_lb(mark_bar *parent = nullptr,uint x = 0);
        void update_coor(bool f = 1);
        void check_marker();
        void add_marker(uint x);
        void insert_marker(uint x);
    private:
        mark_bar *p;
        uint id;
        uint lstamp;
        marker_lb *next;
        std::list<uint> bucket;
    };
    marker_lb *LBtail;
};

#endif // MARK_BAR_H
