QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11
QT       += core gui network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientwidget.cpp \
    login.cpp \
    mark_bar.cpp \
    main.cpp \
    mainwindow.cpp \
    misc.cpp \
    mthread.cpp \
    player.cpp \
    temp_manager.cpp \
    multi_player.cpp

HEADERS += \
    clientwidget.h \
    login.h \
    mark_bar.h \
    mainwindow.h \
    misc.h \
    mthread.h \
    player.h \
    temp_manager.h \
    multi_player.h

FORMS += \
    clientwidget.ui \
    login.ui \
    multi_player.ui \
    mark_bar.ui \
    mainwindow.ui \
    player.ui

TRANSLATIONS += \
    test_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations


INCLUDEPATH += D:\softdata\chromedownload\opencv\sources\build\install\include #*（这个是opencv解压以后存放的路径+所选的文件）*
CONFIG(debug, debug|release): {
LIBS += D:\softdata\chromedownload\opencv\sources\build\lib\libopencv_*.a
LIBS += -LD:\softdata\chromedownload\opencv\sources\build\install\x64\mingw\bin

} else:CONFIG(release, debug|release): {

LIBS += D:\softdata\chromedownload\opencv\sources\build\lib\libopencv_*.a
LIBS += -LD:\softdata\chromedownload\opencv\sources\build\install\x64\mingw\bin
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


