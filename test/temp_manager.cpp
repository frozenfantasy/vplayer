#include "temp_manager.h"

#include <QDir>
#include <QPointer>
#include <QDebug>
temp_manager::temp_manager()
{

}

temp_manager::temp_manager(std::string s)
{
    init(s);
}

temp_manager::~temp_manager()
{
    destory();
}

void temp_manager::init(std::string s)
{
    dir = new QDir(s.c_str());
    if(1 && dir->exists())
        dir->removeRecursively();
    while(dir->exists())
    {
        s += "_";
        delete(dir);
        dir =  new QDir(s.c_str());
    };
    QDir().mkpath(s.c_str());
    temp_prefix = s;
}

void temp_manager::destory()
{
    if(dir)
        dir->removeRecursively();
}




