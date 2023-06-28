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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow {
public:
	QGraphicsView *Graphics;
	QPushButton *pushButton;
	QPushButton *pushButton_2;
	QPushButton *pushButton_3;
	QPushButton *pushButton_4;
	QPushButton *pushButton_5;
	QPushButton *pushButton_6;
	QGraphicsView *sticker_graphics;

    void setupUi(QDialog *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QString::fromUtf8("MainGameWindow"));

        MainGameWindow->resize(1733, 1020);
        Graphics = new QGraphicsView(MainGameWindow);
        Graphics->setObjectName(QString::fromUtf8("Graphics"));
        Graphics->setGeometry(QRect(-10, -10, 1611, 1031));
        Graphics->setStyleSheet(QString::fromUtf8("#Graphics{border-image:url(:/images/images/gameground.png); }"));
        Graphics->setInteractive(true);
        Graphics->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);
        pushButton = new QPushButton(MainGameWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1600, 0, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/cry.png);"));
        pushButton_2 = new QPushButton(MainGameWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1670, 0, 61, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/happy.png);"));
        pushButton_3 = new QPushButton(MainGameWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1600, 70, 61, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/wondered.png);"));
        pushButton_4 = new QPushButton(MainGameWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1670, 70, 61, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/VeryHappy.png);"));
        pushButton_5 = new QPushButton(MainGameWindow);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1600, 150, 61, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/laugh.png);"));
        pushButton_6 = new QPushButton(MainGameWindow);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1670, 150, 61, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/sleep.png);"));
        sticker_graphics = new QGraphicsView(MainGameWindow);
        sticker_graphics->setObjectName(QString::fromUtf8("sticker_graphics"));
        sticker_graphics->setGeometry(QRect(1600, 230, 141, 791));
        sticker_graphics->setStyleSheet(QString::fromUtf8(""));
        sticker_graphics->setInteractive(true);
        sticker_graphics->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);


		retranslateUi(MainGameWindow);

		QMetaObject::connectSlotsByName(MainGameWindow);
	} // setupUi

	void retranslateUi(QDialog *MainGameWindow) {
		MainGameWindow->setWindowTitle(QApplication::translate("MainGameWindow", "Dialog", nullptr));
		pushButton->setText(QString());
		pushButton_2->setText(QString());
		pushButton_3->setText(QString());
		pushButton_4->setText(QString());
		pushButton_5->setText(QString());
		pushButton_6->setText(QString());
	} // retranslateUi

};

namespace Ui {
	class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAMEWINDOW_H
