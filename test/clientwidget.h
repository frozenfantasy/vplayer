#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>//通信套接字
#include <ui_clientwidget.h>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

    void sendImage(QImage image);

    QTcpSocket* get_my_socket();

    QTcpSocket *tcpSocket;

public slots:
    void on_ButtonConnect_clicked();

    void on_ButtonSend_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::ClientWidget *ui;


};

#endif // CLIENTWIDGET_H
