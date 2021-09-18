#ifndef TEMP_MANAGER_H
#define TEMP_MANAGER_H

#include <string>
#include <QDir>


class temp_manager
{
public:
    temp_manager();
    ~temp_manager();
    temp_manager(std::string);
    void init(std::string);
    void destory();
    void setDir(QPointer<QDir> newDir);

    std::string temp_prefix;
protected:
    QDir *dir;
};

#endif // temp_manager_H
