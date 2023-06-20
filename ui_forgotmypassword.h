/********************************************************************************
** Form generated from reading UI file 'forgotmypassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTMYPASSWORD_H
#define UI_FORGOTMYPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgotMyPassword
{
public:
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *user;
    QLineEdit *userL;
    QHBoxLayout *horizontalLayout;
    QLabel *phone;
    QLineEdit *phoneL;
    QPushButton *check;
    QPushButton *confirm;
    QLineEdit *passL;
    QLabel *pass;
    QLineEdit *confirm_passL;
    QLabel *confirm_pass;

    void setupUi(QDialog *ForgotMyPassword)
    {
        if (ForgotMyPassword->objectName().isEmpty())
            ForgotMyPassword->setObjectName(QString::fromUtf8("ForgotMyPassword"));
        ForgotMyPassword->resize(641, 489);
        ForgotMyPassword->setStyleSheet(QString::fromUtf8("#ForgotMyPassword {border-image: url(:/images/images/back.jpg) 0 0 0 0 \n"
";}"));
        layoutWidget_2 = new QWidget(ForgotMyPassword);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 4, 241, 61));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        user = new QLabel(layoutWidget_2);
        user->setObjectName(QString::fromUtf8("user"));
        user->setStyleSheet(QString::fromUtf8("#user{color:white;}"));

        horizontalLayout_2->addWidget(user);

        userL = new QLineEdit(layoutWidget_2);
        userL->setObjectName(QString::fromUtf8("userL"));
        QFont font;
        font.setItalic(true);
        userL->setFont(font);
        userL->setStyleSheet(QString::fromUtf8("#userL{border-image:url(:/images/images/gameground.png);padding-left:10px;}"));
        userL->setEchoMode(QLineEdit::Password);
        userL->setCursorPosition(0);

        horizontalLayout_2->addWidget(userL);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        phone = new QLabel(layoutWidget_2);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setAutoFillBackground(false);
        phone->setStyleSheet(QString::fromUtf8("color:white;"));

        horizontalLayout->addWidget(phone);

        phoneL = new QLineEdit(layoutWidget_2);
        phoneL->setObjectName(QString::fromUtf8("phoneL"));
        phoneL->setFont(font);
        phoneL->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/gameground.png);padding-left:10px;"));
        phoneL->setCursorPosition(0);

        horizontalLayout->addWidget(phoneL);


        verticalLayout->addLayout(horizontalLayout);

        check = new QPushButton(ForgotMyPassword);
        check->setObjectName(QString::fromUtf8("check"));
        check->setGeometry(QRect(10, 70, 241, 28));
        check->setStyleSheet(QString::fromUtf8("#check{background-color:green;}\n"
""));
        confirm = new QPushButton(ForgotMyPassword);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(10, 200, 241, 28));
        confirm->setStyleSheet(QString::fromUtf8("#confirm{background-color:green;opacity: 0.5;;}\n"
""));
        passL = new QLineEdit(ForgotMyPassword);
        passL->setObjectName(QString::fromUtf8("passL"));
        passL->setGeometry(QRect(120, 130, 131, 21));
        passL->setFont(font);
        passL->setStyleSheet(QString::fromUtf8("#passL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        passL->setCursorPosition(0);
        pass = new QLabel(ForgotMyPassword);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(15, 120, 101, 36));
        pass->setStyleSheet(QString::fromUtf8("#pass{color:white;}"));
        confirm_passL = new QLineEdit(ForgotMyPassword);
        confirm_passL->setObjectName(QString::fromUtf8("confirm_passL"));
        confirm_passL->setGeometry(QRect(120, 170, 131, 21));
        confirm_passL->setFont(font);
        confirm_passL->setStyleSheet(QString::fromUtf8("#confirm_passL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        confirm_passL->setCursorPosition(0);
        confirm_pass = new QLabel(ForgotMyPassword);
        confirm_pass->setObjectName(QString::fromUtf8("confirm_pass"));
        confirm_pass->setGeometry(QRect(15, 160, 111, 37));
        confirm_pass->setStyleSheet(QString::fromUtf8("#confirm_pass{color:white;}"));

        retranslateUi(ForgotMyPassword);

        QMetaObject::connectSlotsByName(ForgotMyPassword);
    } // setupUi

    void retranslateUi(QDialog *ForgotMyPassword)
    {
        ForgotMyPassword->setWindowTitle(QApplication::translate("ForgotMyPassword", "Dialog", nullptr));
        user->setText(QApplication::translate("ForgotMyPassword", "username", nullptr));
        phone->setText(QApplication::translate("ForgotMyPassword", "phone number", nullptr));
        check->setText(QApplication::translate("ForgotMyPassword", "check", nullptr));
        confirm->setText(QApplication::translate("ForgotMyPassword", "confirm", nullptr));
        pass->setText(QApplication::translate("ForgotMyPassword", "new password", nullptr));
        confirm_pass->setText(QApplication::translate("ForgotMyPassword", "confirm password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotMyPassword: public Ui_ForgotMyPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTMYPASSWORD_H
