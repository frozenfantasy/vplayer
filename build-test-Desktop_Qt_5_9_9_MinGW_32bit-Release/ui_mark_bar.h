/********************************************************************************
** Form generated from reading UI file 'mark_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARK_BAR_H
#define UI_MARK_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mark_bar
{
public:
    QSlider *bar;

    void setupUi(QWidget *mark_bar)
    {
        if (mark_bar->objectName().isEmpty())
            mark_bar->setObjectName(QStringLiteral("mark_bar"));
        mark_bar->resize(257, 40);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mark_bar->sizePolicy().hasHeightForWidth());
        mark_bar->setSizePolicy(sizePolicy);
        mark_bar->setMinimumSize(QSize(0, 40));
        bar = new QSlider(mark_bar);
        bar->setObjectName(QStringLiteral("bar"));
        bar->setGeometry(QRect(9, 13, 71, 16));
        bar->setOrientation(Qt::Horizontal);

        retranslateUi(mark_bar);

        QMetaObject::connectSlotsByName(mark_bar);
    } // setupUi

    void retranslateUi(QWidget *mark_bar)
    {
        mark_bar->setWindowTitle(QApplication::translate("mark_bar", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mark_bar: public Ui_mark_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARK_BAR_H
