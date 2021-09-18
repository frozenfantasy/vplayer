/********************************************************************************
** Form generated from reading UI file 'multi_player.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTI_PLAYER_H
#define UI_MULTI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multi_player
{
public:
    QGridLayout *gridLayout;
    QGridLayout *Layout;

    void setupUi(QWidget *multi_player)
    {
        if (multi_player->objectName().isEmpty())
            multi_player->setObjectName(QStringLiteral("multi_player"));
        multi_player->resize(400, 300);
        gridLayout = new QGridLayout(multi_player);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Layout = new QGridLayout();
        Layout->setSpacing(0);
        Layout->setObjectName(QStringLiteral("Layout"));

        gridLayout->addLayout(Layout, 0, 0, 1, 1);


        retranslateUi(multi_player);

        QMetaObject::connectSlotsByName(multi_player);
    } // setupUi

    void retranslateUi(QWidget *multi_player)
    {
        multi_player->setWindowTitle(QApplication::translate("multi_player", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class multi_player: public Ui_multi_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTI_PLAYER_H
