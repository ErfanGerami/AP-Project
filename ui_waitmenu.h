/********************************************************************************
** Form generated from reading UI file 'waitmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITMENU_H
#define UI_WAITMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WaitMenu {
public:
	QListWidget *listWidget;
	QLabel *Players;
	QGraphicsView *graphicsView;
	QPushButton *pushButton;

	void setupUi(QMainWindow *WaitMenu) {
		if ( WaitMenu->objectName().isEmpty() )
			WaitMenu->setObjectName(QString::fromUtf8("WaitMenu"));
		WaitMenu->resize(646, 501);
		WaitMenu->setStyleSheet(QString::fromUtf8("#WaitMenu{border-image:url(:/images/images/WhiteSkull.jpg); }"));
		listWidget = new QListWidget(WaitMenu);
		listWidget->setObjectName(QString::fromUtf8("listWidget"));
		listWidget->setGeometry(QRect(10, 50, 381, 192));
		listWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,100);color:white;font-size:15px;\n"
			""));
		Players = new QLabel(WaitMenu);
		Players->setObjectName(QString::fromUtf8("Players"));
		Players->setEnabled(true);
		Players->setGeometry(QRect(10, 20, 91, 26));
		QFont font;
		font.setFamily(QString::fromUtf8("MV Boli"));
		Players->setFont(font);
		Players->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
			"\n"
			";font-size:25px;border-radius:10px;"));
		graphicsView = new QGraphicsView(WaitMenu);
		graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
		graphicsView->setGeometry(QRect(0, 0, 661, 501));
		graphicsView->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);"));
		pushButton = new QPushButton(WaitMenu);
		pushButton->setObjectName(QString::fromUtf8("pushButton"));
		pushButton->setGeometry(QRect(480, 150, 93, 28));
		graphicsView->raise();
		listWidget->raise();
		Players->raise();
		pushButton->raise();

		retranslateUi(WaitMenu);

		QMetaObject::connectSlotsByName(WaitMenu);
	} // setupUi

	void retranslateUi(QMainWindow *WaitMenu) {
		WaitMenu->setWindowTitle(QApplication::translate("WaitMenu", "Dialog", nullptr));
		Players->setText(QApplication::translate("WaitMenu", "Players:", nullptr));
		pushButton->setText(QApplication::translate("WaitMenu", "PushButton", nullptr));
	} // retranslateUi

};

namespace Ui {
	class WaitMenu: public Ui_WaitMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITMENU_H
