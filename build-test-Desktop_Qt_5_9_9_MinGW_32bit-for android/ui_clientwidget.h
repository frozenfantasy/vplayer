/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *ButtonConnect;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QLineEdit *lineIP;
    QLineEdit *linePort;
    QPushButton *ButtonSend;
    QPushButton *ButtonClose;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(494, 480);
        label = new QLabel(ClientWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 17, 91, 21));
        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 101, 18));
        ButtonConnect = new QPushButton(ClientWidget);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));
        ButtonConnect->setGeometry(QRect(350, 10, 112, 34));
        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setGeometry(QRect(60, 120, 311, 121));
        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));
        textEditWrite->setGeometry(QRect(60, 260, 311, 131));
        lineIP = new QLineEdit(ClientWidget);
        lineIP->setObjectName(QStringLiteral("lineIP"));
        lineIP->setGeometry(QRect(120, 20, 201, 25));
        linePort = new QLineEdit(ClientWidget);
        linePort->setObjectName(QStringLiteral("linePort"));
        linePort->setGeometry(QRect(120, 60, 201, 25));
        ButtonSend = new QPushButton(ClientWidget);
        ButtonSend->setObjectName(QStringLiteral("ButtonSend"));
        ButtonSend->setGeometry(QRect(160, 430, 112, 34));
        ButtonClose = new QPushButton(ClientWidget);
        ButtonClose->setObjectName(QStringLiteral("ButtonClose"));
        ButtonClose->setGeometry(QRect(350, 60, 112, 34));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250ip", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", Q_NULLPTR));
        ButtonConnect->setText(QApplication::translate("ClientWidget", "connect", Q_NULLPTR));
        ButtonSend->setText(QApplication::translate("ClientWidget", "send", Q_NULLPTR));
        ButtonClose->setText(QApplication::translate("ClientWidget", "disconnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
