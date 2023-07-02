/********************************************************************************
** Form generated from reading UI file 'maingamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAMEWINDOW_H
#define UI_MAINGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow
{
public:
    QGraphicsView *Graphics;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGraphicsView *sticker_graphics;
    QComboBox *comboBox;
    QPushButton *pushButton_7;
    QLabel *label;
    QLabel *score;
    QFrame *line;
    QLabel *star_0;
    QLabel *star_2;
    QLabel *star_1;
    QLabel *star_3;
    QPushButton *pause;
    QLabel *arrow0;
    QLabel *arrow1;
    QLabel *arrow3;
    QLabel *arrow2;

    void setupUi(QDialog *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QString::fromUtf8("MainGameWindow"));
        MainGameWindow->resize(1733, 1020);
        Graphics = new QGraphicsView(MainGameWindow);
        Graphics->setObjectName(QString::fromUtf8("Graphics"));
        Graphics->setGeometry(QRect(-10, -20, 1611, 1031));
        Graphics->setStyleSheet(QString::fromUtf8("#Graphics{border-image:url(:/images/images/gameground.png); }"));
        Graphics->setInteractive(true);
        Graphics->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);
        pushButton = new QPushButton(MainGameWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1600, 210, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-image:url(:/images/images/cry.png);}\n"
"#pushButton:hover{background-color:rgba(70,70,70,200);}"));
        pushButton_2 = new QPushButton(MainGameWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1670, 210, 61, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{border-image:url(:/images/images/happy.png);}\n"
"#pushButton_2:hover{background-color:rgba(70,70,70,200);}"));
        pushButton_3 = new QPushButton(MainGameWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1600, 280, 61, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("#pushButton_3{border-image:url(:/images/images/wondered.png);}\n"
"#pushButton_3:hover{background-color:rgba(70,70,70,200);}"));
        pushButton_4 = new QPushButton(MainGameWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1670, 280, 61, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("#pushButton_4{border-image:url(:/images/images/VeryHappy.png);}\n"
"#pushButton_4:hover{background-color:rgba(70,70,70,200);}"));
        pushButton_5 = new QPushButton(MainGameWindow);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1600, 360, 61, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("#pushButton_5{border-image:url(:/images/images/laugh.png);}\n"
"#pushButton_5:hover{background-color:rgba(70,70,70,200);}"));
        pushButton_6 = new QPushButton(MainGameWindow);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1670, 360, 61, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("#pushButton_6{border-image:url(:/images/images/sleep.png);}\n"
"#pushButton_6:hover{background-color:rgba(70,70,70,200);}"));
        sticker_graphics = new QGraphicsView(MainGameWindow);
        sticker_graphics->setObjectName(QString::fromUtf8("sticker_graphics"));
        sticker_graphics->setGeometry(QRect(1600, 420, 141, 601));
        sticker_graphics->setStyleSheet(QString::fromUtf8("background-color:rgba(200,200,200,200);"));
        sticker_graphics->setInteractive(true);
        sticker_graphics->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);
        comboBox = new QComboBox(MainGameWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1270, 920, 111, 31));
        pushButton_7 = new QPushButton(MainGameWindow);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1390, 920, 181, 31));
        label = new QLabel(MainGameWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1600, 0, 81, 31));
        label->setStyleSheet(QString::fromUtf8("font-size:30px"));
        score = new QLabel(MainGameWindow);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(1600, 30, 81, 31));
        score->setStyleSheet(QString::fromUtf8("font-size:30px;color:red"));
        line = new QFrame(MainGameWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1600, 190, 131, 30));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        star_0 = new QLabel(MainGameWindow);
        star_0->setObjectName(QString::fromUtf8("star_0"));
        star_0->setGeometry(QRect(510, 910, 71, 71));
        star_0->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/star.png);"));
        star_2 = new QLabel(MainGameWindow);
        star_2->setObjectName(QString::fromUtf8("star_2"));
        star_2->setGeometry(QRect(20, 600, 71, 71));
        star_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/star.png);"));
        star_1 = new QLabel(MainGameWindow);
        star_1->setObjectName(QString::fromUtf8("star_1"));
        star_1->setGeometry(QRect(570, 0, 71, 71));
        star_1->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/star.png);"));
        star_3 = new QLabel(MainGameWindow);
        star_3->setObjectName(QString::fromUtf8("star_3"));
        star_3->setGeometry(QRect(1510, 310, 71, 71));
        star_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/star.png);"));
        pause = new QPushButton(MainGameWindow);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(1600, 120, 141, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("NSimSun"));
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        pause->setFont(font);
        pause->setStyleSheet(QString::fromUtf8("font-size:30px"));
        arrow0 = new QLabel(MainGameWindow);
        arrow0->setObjectName(QString::fromUtf8("arrow0"));
        arrow0->setGeometry(QRect(420, 910, 71, 71));
        arrow0->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/arrow.png);"));
        arrow1 = new QLabel(MainGameWindow);
        arrow1->setObjectName(QString::fromUtf8("arrow1"));
        arrow1->setGeometry(QRect(1510, 630, 71, 71));
        arrow1->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/arrow_up.png);"));
        arrow3 = new QLabel(MainGameWindow);
        arrow3->setObjectName(QString::fromUtf8("arrow3"));
        arrow3->setGeometry(QRect(20, 300, 71, 71));
        arrow3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/arrow_down.png);"));
        arrow2 = new QLabel(MainGameWindow);
        arrow2->setObjectName(QString::fromUtf8("arrow2"));
        arrow2->setGeometry(QRect(1030, 0, 71, 71));
        arrow2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/arrow_left.png);background-color:rgba(100,100,100,100);border-radius:50px;"));

        retranslateUi(MainGameWindow);

        QMetaObject::connectSlotsByName(MainGameWindow);
    } // setupUi

    void retranslateUi(QDialog *MainGameWindow)
    {
        MainGameWindow->setWindowTitle(QApplication::translate("MainGameWindow", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QApplication::translate("MainGameWindow", "Swap Cards with this player", nullptr));
        label->setText(QApplication::translate("MainGameWindow", "Score:", nullptr));
        score->setText(QApplication::translate("MainGameWindow", "0", nullptr));
        star_0->setText(QString());
        star_2->setText(QString());
        star_1->setText(QString());
        star_3->setText(QString());
        pause->setText(QApplication::translate("MainGameWindow", "pause", nullptr));
        arrow0->setText(QString());
        arrow1->setText(QString());
        arrow3->setText(QString());
        arrow2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAMEWINDOW_H
