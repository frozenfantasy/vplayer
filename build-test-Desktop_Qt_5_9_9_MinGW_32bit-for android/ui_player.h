/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_player
{
public:
    QGridLayout *gridLayout;
    QGridLayout *Layout;

    void setupUi(QWidget *player)
    {
        if (player->objectName().isEmpty())
            player->setObjectName(QStringLiteral("player"));
        player->resize(400, 300);
        gridLayout = new QGridLayout(player);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Layout = new QGridLayout();
        Layout->setObjectName(QStringLiteral("Layout"));

        gridLayout->addLayout(Layout, 0, 0, 1, 1);


        retranslateUi(player);

        QMetaObject::connectSlotsByName(player);
    } // setupUi

    void retranslateUi(QWidget *player)
    {
        player->setWindowTitle(QApplication::translate("player", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class player: public Ui_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
