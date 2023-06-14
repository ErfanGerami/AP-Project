/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QPushButton *start;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QLineEdit *userL;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Pass;
    QLineEdit *passL;
    QHBoxLayout *horizontalLayout_4;
    QLabel *confirm;
    QLineEdit *ConfirmL;
    QHBoxLayout *horizontalLayout_5;
    QLabel *phone;
    QLineEdit *phoneL;
    QHBoxLayout *horizontalLayout_6;
    QLabel *adr;
    QLineEdit *adrL;
    QHBoxLayout *horizontalLayout_7;
    QLabel *email;
    QLineEdit *emailL;
    QTextEdit *textEdit;
    QCheckBox *agree;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(1006, 563);
        SignUp->setStyleSheet(QString::fromUtf8("#SignUp {border-image: url(:/images/images/back.jpg) 0 0 0 0 \n"
";}"));
        start = new QPushButton(SignUp);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(10, 440, 261, 111));
        QFont font;
        font.setPointSize(15);
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("#start{border-image:url(:/images/images/ship.jpg);border-radius:10px;text-align:left;}"));
        widget = new QWidget(SignUp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 260, 414));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user = new QLabel(widget);
        user->setObjectName(QString::fromUtf8("user"));
        user->setStyleSheet(QString::fromUtf8("#user{color:white;}"));

        horizontalLayout->addWidget(user);

        userL = new QLineEdit(widget);
        userL->setObjectName(QString::fromUtf8("userL"));
        QFont font1;
        font1.setItalic(true);
        userL->setFont(font1);
        userL->setStyleSheet(QString::fromUtf8("#userL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        userL->setCursorPosition(0);

        horizontalLayout->addWidget(userL);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Pass = new QLabel(widget);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setStyleSheet(QString::fromUtf8("#Pass\n"
"{color:white;}"));

        horizontalLayout_2->addWidget(Pass);

        passL = new QLineEdit(widget);
        passL->setObjectName(QString::fromUtf8("passL"));
        passL->setFont(font1);
        passL->setStyleSheet(QString::fromUtf8("#passL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        passL->setEchoMode(QLineEdit::Password);
        passL->setCursorPosition(0);

        horizontalLayout_2->addWidget(passL);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        confirm = new QLabel(widget);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setStyleSheet(QString::fromUtf8("#confirm\n"
"{color:white;}"));

        horizontalLayout_4->addWidget(confirm);

        ConfirmL = new QLineEdit(widget);
        ConfirmL->setObjectName(QString::fromUtf8("ConfirmL"));
        ConfirmL->setFont(font1);
        ConfirmL->setStyleSheet(QString::fromUtf8("#ConfirmL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        ConfirmL->setEchoMode(QLineEdit::Password);
        ConfirmL->setCursorPosition(0);

        horizontalLayout_4->addWidget(ConfirmL);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        phone = new QLabel(widget);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setStyleSheet(QString::fromUtf8("#phone\n"
"{color:white;}"));

        horizontalLayout_5->addWidget(phone);

        phoneL = new QLineEdit(widget);
        phoneL->setObjectName(QString::fromUtf8("phoneL"));
        phoneL->setFont(font1);
        phoneL->setStyleSheet(QString::fromUtf8("#phoneL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        phoneL->setEchoMode(QLineEdit::Normal);
        phoneL->setCursorPosition(0);

        horizontalLayout_5->addWidget(phoneL);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        adr = new QLabel(widget);
        adr->setObjectName(QString::fromUtf8("adr"));
        adr->setStyleSheet(QString::fromUtf8("#adr\n"
"{color:white;}"));

        horizontalLayout_6->addWidget(adr);

        adrL = new QLineEdit(widget);
        adrL->setObjectName(QString::fromUtf8("adrL"));
        adrL->setFont(font1);
        adrL->setStyleSheet(QString::fromUtf8("#adrL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        adrL->setEchoMode(QLineEdit::Normal);
        adrL->setCursorPosition(0);

        horizontalLayout_6->addWidget(adrL);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        email = new QLabel(widget);
        email->setObjectName(QString::fromUtf8("email"));
        email->setStyleSheet(QString::fromUtf8("#email\n"
"{color:white;}"));

        horizontalLayout_7->addWidget(email);

        emailL = new QLineEdit(widget);
        emailL->setObjectName(QString::fromUtf8("emailL"));
        emailL->setFont(font1);
        emailL->setStyleSheet(QString::fromUtf8("#emailL{border-image:\n"
"url(:/images/images/gameground.png);\n"
"padding-left:10px;\n"
"\n"
"}"));
        emailL->setEchoMode(QLineEdit::Normal);
        emailL->setCursorPosition(0);

        horizontalLayout_7->addWidget(emailL);


        verticalLayout->addLayout(horizontalLayout_7);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        agree = new QCheckBox(widget);
        agree->setObjectName(QString::fromUtf8("agree"));
        agree->setStyleSheet(QString::fromUtf8("#agree{color:red;font-size:20px;}"));

        verticalLayout->addWidget(agree);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Dialog", nullptr));
        start->setText(QApplication::translate("SignUp", "SignUp", nullptr));
        user->setText(QApplication::translate("SignUp", "UserName", nullptr));
        Pass->setText(QApplication::translate("SignUp", "Password", nullptr));
        confirm->setText(QApplication::translate("SignUp", "Confirm Password", nullptr));
        phone->setText(QApplication::translate("SignUp", "Phone Number", nullptr));
        adr->setText(QApplication::translate("SignUp", "Address", nullptr));
        email->setText(QApplication::translate("SignUp", "email", nullptr));
        textEdit->setHtml(QApplication::translate("SignUp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">SkullKing  </span><span style=\" font-size:8pt;\">by Erfan Geramizadeh and Shafagh Sepehr</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">version 1.0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;\"><br /></p>\n"
"<p style=\" ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">by Signing Up you agree to this terms:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">the player should have the most fun he/she can.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">if the user is a professor in IUT you should give the following individuals </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">a 20 for in course(Shafagh Sepehr,Erfan Geramizadeh)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-s"
                        "ize:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Google Sans','arial','sans-serif'; font-size:8pt; color:#202124; background-color:#ffffff;\">\302\251</span><span style=\" font-size:8pt; font-weight:600;\">all rights reserved</span></p></body></html>", nullptr));
        agree->setText(QApplication::translate("SignUp", "I agree with the terms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
