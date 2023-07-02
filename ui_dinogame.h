/********************************************************************************
** Form generated from reading UI file 'dinogame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINOGAME_H
#define UI_DINOGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DinoGame
{
public:
    QLabel *label;
    QLabel *coins;
    QLabel *dino;
    QLabel *bar1;
    QLabel *cloud3;
    QLabel *bar3;
    QFrame *line;
    QPushButton *pushButton;
    QLabel *cloud2;
    QLabel *bar2;
    QLabel *cloud1;

    void setupUi(QDialog *DinoGame)
    {
        if (DinoGame->objectName().isEmpty())
            DinoGame->setObjectName(QString::fromUtf8("DinoGame"));
        DinoGame->resize(879, 467);
        label = new QLabel(DinoGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 30, 101, 16));
        coins = new QLabel(DinoGame);
        coins->setObjectName(QString::fromUtf8("coins"));
        coins->setGeometry(QRect(670, 30, 101, 16));
        dino = new QLabel(DinoGame);
        dino->setObjectName(QString::fromUtf8("dino"));
        dino->setGeometry(QRect(140, 360, 91, 91));
        dino->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/dino.png\");\n"
""));
        bar1 = new QLabel(DinoGame);
        bar1->setObjectName(QString::fromUtf8("bar1"));
        bar1->setGeometry(QRect(710, 380, 71, 71));
        bar1->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/barrier.png\");\n"
""));
        cloud3 = new QLabel(DinoGame);
        cloud3->setObjectName(QString::fromUtf8("cloud3"));
        cloud3->setGeometry(QRect(140, 190, 141, 51));
        cloud3->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/cloud.png\");\n"
""));
        bar3 = new QLabel(DinoGame);
        bar3->setObjectName(QString::fromUtf8("bar3"));
        bar3->setGeometry(QRect(730, 380, 71, 71));
        bar3->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/barrier.png\");\n"
""));
        line = new QFrame(DinoGame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 450, 881, 20));
        line->setStyleSheet(QString::fromUtf8("background-color:black"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(DinoGame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 30, 201, 51));
        cloud2 = new QLabel(DinoGame);
        cloud2->setObjectName(QString::fromUtf8("cloud2"));
        cloud2->setGeometry(QRect(530, 120, 141, 51));
        cloud2->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/cloud.png\");\n"
""));
        bar2 = new QLabel(DinoGame);
        bar2->setObjectName(QString::fromUtf8("bar2"));
        bar2->setGeometry(QRect(730, 380, 71, 71));
        bar2->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/barrier.png\");\n"
""));
        cloud1 = new QLabel(DinoGame);
        cloud1->setObjectName(QString::fromUtf8("cloud1"));
        cloud1->setGeometry(QRect(290, 40, 141, 51));
        cloud1->setStyleSheet(QString::fromUtf8("border-image:url(\":/images/images/cloud.png\");\n"
""));

        retranslateUi(DinoGame);

        QMetaObject::connectSlotsByName(DinoGame);
    } // setupUi

    void retranslateUi(QDialog *DinoGame)
    {
        DinoGame->setWindowTitle(QApplication::translate("DinoGame", "Dialog", nullptr));
        label->setText(QApplication::translate("DinoGame", "coins achieved:", nullptr));
        coins->setText(QApplication::translate("DinoGame", "0", nullptr));
        dino->setText(QString());
        bar1->setText(QString());
        cloud3->setText(QString());
        bar3->setText(QString());
        pushButton->setText(QApplication::translate("DinoGame", "jump", nullptr));
        cloud2->setText(QString());
        bar2->setText(QString());
        cloud1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DinoGame: public Ui_DinoGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINOGAME_H
