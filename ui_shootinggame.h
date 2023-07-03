/********************************************************************************
** Form generated from reading UI file 'shootinggame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOOTINGGAME_H
#define UI_SHOOTINGGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ShootingGame
{
public:
    QLabel *label;
    QLabel *coins;
    QLabel *target;
    QLabel *aim;

    void setupUi(QDialog *ShootingGame)
    {
        if (ShootingGame->objectName().isEmpty())
            ShootingGame->setObjectName(QString::fromUtf8("ShootingGame"));
        ShootingGame->resize(823, 621);
        ShootingGame->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(ShootingGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 20, 55, 16));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        coins = new QLabel(ShootingGame);
        coins->setObjectName(QString::fromUtf8("coins"));
        coins->setGeometry(QRect(500, 20, 55, 16));
        coins->setStyleSheet(QString::fromUtf8("color:white;"));
        target = new QLabel(ShootingGame);
        target->setObjectName(QString::fromUtf8("target"));
        target->setGeometry(QRect(50, 50, 81, 81));
        target->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/target.png);"));
        aim = new QLabel(ShootingGame);
        aim->setObjectName(QString::fromUtf8("aim"));
        aim->setGeometry(QRect(100, 240, 51, 51));
        aim->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/aim.png);\n"
""));

        retranslateUi(ShootingGame);

        QMetaObject::connectSlotsByName(ShootingGame);
    } // setupUi

    void retranslateUi(QDialog *ShootingGame)
    {
        ShootingGame->setWindowTitle(QApplication::translate("ShootingGame", "Dialog", nullptr));
        label->setText(QApplication::translate("ShootingGame", "points:", nullptr));
        coins->setText(QApplication::translate("ShootingGame", "0", nullptr));
        target->setText(QString());
        aim->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShootingGame: public Ui_ShootingGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOOTINGGAME_H
