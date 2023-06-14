/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QPushButton *start;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *UseL;
    QLineEdit *user;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PassL;
    QLineEdit *pass;
    QPushButton *login;
    QLabel *label;
    QPushButton *forgot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        Login->setStyleSheet(QString::fromUtf8("#Login {border-image: url(:/images/images/back.jpg) 0 0 0 0 \n"
";}"));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(36, 230, 141, 20));
        QFont font;
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("#start{background:transparent;color:red;font-size:13px;}"));
        start->setFlat(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(36, 110, 213, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        UseL = new QLabel(layoutWidget);
        UseL->setObjectName(QString::fromUtf8("UseL"));
        UseL->setStyleSheet(QString::fromUtf8("#UseL{color:white;}"));

        horizontalLayout->addWidget(UseL);

        user = new QLineEdit(layoutWidget);
        user->setObjectName(QString::fromUtf8("user"));
        QFont font1;
        font1.setItalic(true);
        user->setFont(font1);
        user->setStyleSheet(QString::fromUtf8("#user{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        user->setCursorPosition(0);

        horizontalLayout->addWidget(user);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PassL = new QLabel(layoutWidget);
        PassL->setObjectName(QString::fromUtf8("PassL"));
        PassL->setStyleSheet(QString::fromUtf8("#PassL\n"
"{color:white;}"));

        horizontalLayout_2->addWidget(PassL);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setFont(font1);
        pass->setStyleSheet(QString::fromUtf8("#pass{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        pass->setEchoMode(QLineEdit::Password);
        pass->setCursorPosition(0);

        horizontalLayout_2->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout_2);

        login = new QPushButton(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("#login{background-color:green;}\n"
""));

        verticalLayout->addWidget(login);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/logo.png")));
        label->setScaledContents(true);
        forgot = new QPushButton(centralwidget);
        forgot->setObjectName(QString::fromUtf8("forgot"));
        forgot->setGeometry(QRect(30, 260, 141, 20));
        forgot->setFont(font);
        forgot->setLayoutDirection(Qt::LeftToRight);
        forgot->setStyleSheet(QString::fromUtf8("#forgot{background:transparent;color:red;font-size:13px;}"));
        Login->setCentralWidget(centralwidget);
        start->raise();
        layoutWidget->raise();
        forgot->raise();
        label->raise();
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        start->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        start->setText(QApplication::translate("Login", "Dont have an account?", nullptr));
        UseL->setText(QApplication::translate("Login", "UserName", nullptr));
        PassL->setText(QApplication::translate("Login", "Password", nullptr));
        login->setText(QApplication::translate("Login", "Login", nullptr));
        label->setText(QString());
        forgot->setText(QApplication::translate("Login", "forgot my password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
