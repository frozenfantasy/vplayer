#ifndef MTHREAD_H
#define MTHREAD_H

#include <QThread>
#include "mainwindow.h"


class mthread : public QThread
{
public:
    mthread();
    mthread(MainWindow *mw);
protected:
    MainWindow *w;
    void run();
};

#endif // MTHREAD_H
