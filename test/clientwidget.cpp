#include "clientwidget.h"
#include <QHostAddress>
#include <QBuffer>
#include <player.h>
#include <string>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = NULL;
//    tcpServer = NULL;

    //分配空间，指定父对象
    tcpSocket = new QTcpSocket(this);


    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEditRead->setText("成功和服务器建立连接");
            }
            );
    //接收数据
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
                //获取对方发送的内容
                QByteArray arry = tcpSocket->readAll();
                //显示在编辑区
                ui->textEditRead->append(arry);
                //arry = tcpSocket->readAll();
                QByteArray qarry = QByteArray::fromBase64(arry);
                //QString SavePath=;
                QString SavePath="D:/qtproject/VP_player/VP_player/tas.jpg";
                QBuffer buffer(&qarry);
                buffer.open(QIODevice::WriteOnly);
                QPixmap imageresult;
                imageresult.loadFromData(qarry);
                if(SavePath != "")
                {
                    qDebug() <<"save" ;
                    imageresult.save(SavePath);
                }
            }
            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_ButtonConnect_clicked()
{
    //获取服务器IP和端口
    QString ip = ui->lineIP->text();
    //QString ip ="47.100.184.19";
    qint16 port = ui->linePort->text().toInt();

    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void ClientWidget::on_ButtonSend_clicked()
{
    //获取编辑框内容
    QString str = ui->textEditWrite->toPlainText();
    QString imgPath="D:/qtproject/base64test/2.jpg";

    QImage image(imgPath);
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, "jpg");
    QByteArray hexed = ba.toBase64();
    buf.close();
    //QString p_b=hexed;

    //QPixmap image2;
    //image2.loadFromData(QByteArray::fromBase64(p_b.toLocal8Bit()));
    //发送数据
    //tcpSocket->write(str.toUtf8().data());
    int sz=hexed.size();
    QString siz=QString::number(sz,10);
    tcpSocket->write("size:"+siz.toUtf8()+"\n");

    tcpSocket->flush();
    //for(int i=1;i<=100000000;++i);
    tcpSocket->write(hexed);
    //ui->textEditRead->append(hexed);
}

void ClientWidget::on_ButtonClose_clicked()
{
    //tcpSocket->write("size:323316");
    //主动和对方断开连接
    tcpSocket->close();
    tcpSocket->disconnectFromHost();
}

void ClientWidget::sendImage(QImage image){
    //QImage image(imgPath);
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, "jpg");
    QByteArray hexed = ba.toBase64();
    buf.close();
    //QString p_b=hexed;

    //QPixmap image2;
    //image2.loadFromData(QByteArray::fromBase64(p_b.toLocal8Bit()));
    //发送数据
    //tcpSocket->write(str.toUtf8().data());
    int sz=hexed.size();
    QString siz=QString::number(sz,10);
    tcpSocket->write("size:"+siz.toUtf8()+"\n");

    tcpSocket->flush();
    //for(int i=1;i<=100000000;++i);
    tcpSocket->write(hexed);
}

QTcpSocket* ClientWidget::get_my_socket(){
    return tcpSocket;
}
