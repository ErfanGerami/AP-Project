/********************************************************************************
** Form generated from reading UI file 'changeinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFO_H
#define UI_CHANGEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfo
{
public:
    QCheckBox *user_check;
    QCheckBox *pass_check;
    QCheckBox *email_check;
    QCheckBox *phone_check;
    QLabel *userL;
    QLabel *passL;
    QLabel *emailL;
    QLabel *phoneL;
    QLineEdit *user;
    QLineEdit *pass;
    QLineEdit *confirm;
    QLineEdit *email;
    QLineEdit *phone;
    QPushButton *submit;
    QLineEdit *adr;
    QCheckBox *adr_check;
    QLabel *adrL;
    QPushButton *pushButton;

    void setupUi(QDialog *ChangeInfo)
    {
        if (ChangeInfo->objectName().isEmpty())
            ChangeInfo->setObjectName(QString::fromUtf8("ChangeInfo"));
        ChangeInfo->resize(749, 427);
        ChangeInfo->setStyleSheet(QString::fromUtf8("#ChangeInfo{border-image:url(:/images/images/WhiteSkull.jpg); }"));
        user_check = new QCheckBox(ChangeInfo);
        user_check->setObjectName(QString::fromUtf8("user_check"));
        user_check->setGeometry(QRect(10, 30, 191, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ravie"));
        font.setItalic(false);
        user_check->setFont(font);
        user_check->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(72, 3, 3,100); color:white\n"
";font-size:17px;"));
        pass_check = new QCheckBox(ChangeInfo);
        pass_check->setObjectName(QString::fromUtf8("pass_check"));
        pass_check->setGeometry(QRect(10, 80, 191, 61));
        pass_check->setFont(font);
        pass_check->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(72, 3, 3,100); color:white\n"
";font-size:17px;"));
        email_check = new QCheckBox(ChangeInfo);
        email_check->setObjectName(QString::fromUtf8("email_check"));
        email_check->setGeometry(QRect(10, 140, 191, 61));
        email_check->setFont(font);
        email_check->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(72, 3, 3,100); color:white\n"
";font-size:17px;"));
        phone_check = new QCheckBox(ChangeInfo);
        phone_check->setObjectName(QString::fromUtf8("phone_check"));
        phone_check->setGeometry(QRect(10, 200, 191, 51));
        phone_check->setFont(font);
        phone_check->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(72, 3, 3,100); color:white\n"
";font-size:17px;"));
        userL = new QLabel(ChangeInfo);
        userL->setObjectName(QString::fromUtf8("userL"));
        userL->setEnabled(true);
        userL->setGeometry(QRect(210, 35, 111, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        userL->setFont(font1);
        userL->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        passL = new QLabel(ChangeInfo);
        passL->setObjectName(QString::fromUtf8("passL"));
        passL->setGeometry(QRect(210, 80, 211, 61));
        passL->setFont(font1);
        passL->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        emailL = new QLabel(ChangeInfo);
        emailL->setObjectName(QString::fromUtf8("emailL"));
        emailL->setGeometry(QRect(210, 140, 91, 61));
        emailL->setFont(font1);
        emailL->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        phoneL = new QLabel(ChangeInfo);
        phoneL->setObjectName(QString::fromUtf8("phoneL"));
        phoneL->setGeometry(QRect(210, 195, 151, 61));
        phoneL->setFont(font1);
        phoneL->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        user = new QLineEdit(ChangeInfo);
        user->setObjectName(QString::fromUtf8("user"));
        user->setEnabled(true);
        user->setGeometry(QRect(340, 50, 141, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell Condensed"));
        user->setFont(font2);
        user->setStyleSheet(QString::fromUtf8("#user{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#user:hover{background-color:black;}\n"
"\n"
""));
        pass = new QLineEdit(ChangeInfo);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(440, 100, 141, 31));
        pass->setFont(font2);
        pass->setStyleSheet(QString::fromUtf8("#pass{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#pass:hover{background-color:black;}\n"
"\n"
""));
        pass->setEchoMode(QLineEdit::Password);
        confirm = new QLineEdit(ChangeInfo);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(590, 100, 141, 31));
        confirm->setFont(font2);
        confirm->setStyleSheet(QString::fromUtf8("#confirm{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#confirm:hover{background-color:black;}"));
        confirm->setEchoMode(QLineEdit::Password);
        email = new QLineEdit(ChangeInfo);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(320, 150, 141, 31));
        email->setFont(font2);
        email->setStyleSheet(QString::fromUtf8("#email{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#email:hover{background-color:black;}\n"
"\n"
""));
        phone = new QLineEdit(ChangeInfo);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(380, 210, 141, 31));
        phone->setFont(font2);
        phone->setStyleSheet(QString::fromUtf8("#phone{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#phone:hover{background-color:black;}\n"
"\n"
""));
        submit = new QPushButton(ChangeInfo);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(10, 350, 731, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Mistral"));
        submit->setFont(font3);
        submit->setStyleSheet(QString::fromUtf8("#submit{font-size:40px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 10px;}\n"
"#submit:hover{background-color:rgba(255,255,255,225);color:black;}"));
        adr = new QLineEdit(ChangeInfo);
        adr->setObjectName(QString::fromUtf8("adr"));
        adr->setGeometry(QRect(380, 260, 141, 31));
        adr->setFont(font2);
        adr->setStyleSheet(QString::fromUtf8("#adr{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:10px;border-style:solid;border-width:3px;}\n"
"#adr:hover{background-color:black;}\n"
"\n"
""));
        adr_check = new QCheckBox(ChangeInfo);
        adr_check->setObjectName(QString::fromUtf8("adr_check"));
        adr_check->setGeometry(QRect(10, 250, 191, 51));
        adr_check->setFont(font);
        adr_check->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(72, 3, 3,100); color:white\n"
";font-size:17px;"));
        adrL = new QLabel(ChangeInfo);
        adrL->setObjectName(QString::fromUtf8("adrL"));
        adrL->setGeometry(QRect(210, 245, 151, 61));
        adrL->setFont(font1);
        adrL->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        pushButton = new QPushButton(ChangeInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 10, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{font-size:10px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 1px;}\n"
"#pushButton:hover{background-color:rgba(255,255,255,225);color:black;}"));

        retranslateUi(ChangeInfo);
        QObject::connect(user_check, SIGNAL(toggled(bool)), userL, SLOT(setVisible(bool)));
        QObject::connect(pass_check, SIGNAL(toggled(bool)), passL, SLOT(setVisible(bool)));
        QObject::connect(pass_check, SIGNAL(toggled(bool)), pass, SLOT(setVisible(bool)));
        QObject::connect(pass_check, SIGNAL(toggled(bool)), confirm, SLOT(setVisible(bool)));
        QObject::connect(email_check, SIGNAL(toggled(bool)), emailL, SLOT(setVisible(bool)));
        QObject::connect(email_check, SIGNAL(toggled(bool)), email, SLOT(setVisible(bool)));
        QObject::connect(phone_check, SIGNAL(toggled(bool)), phoneL, SLOT(setVisible(bool)));
        QObject::connect(phone_check, SIGNAL(toggled(bool)), phone, SLOT(setVisible(bool)));
        QObject::connect(user_check, SIGNAL(toggled(bool)), user, SLOT(setVisible(bool)));
        QObject::connect(adr_check, SIGNAL(toggled(bool)), adrL, SLOT(setVisible(bool)));
        QObject::connect(adr_check, SIGNAL(toggled(bool)), adr, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(ChangeInfo);
    } // setupUi

    void retranslateUi(QDialog *ChangeInfo)
    {
        ChangeInfo->setWindowTitle(QApplication::translate("ChangeInfo", "Dialog", nullptr));
        user_check->setText(QApplication::translate("ChangeInfo", "UserName", nullptr));
        pass_check->setText(QApplication::translate("ChangeInfo", "Password", nullptr));
        email_check->setText(QApplication::translate("ChangeInfo", "Email Address", nullptr));
        phone_check->setText(QApplication::translate("ChangeInfo", "Phone Number", nullptr));
        userL->setText(QApplication::translate("ChangeInfo", "new user name:", nullptr));
        passL->setText(QApplication::translate("ChangeInfo", "new password and confirm:", nullptr));
        emailL->setText(QApplication::translate("ChangeInfo", "new Email:", nullptr));
        phoneL->setText(QApplication::translate("ChangeInfo", "new Phone Bumber:", nullptr));
        submit->setText(QApplication::translate("ChangeInfo", "Submit", nullptr));
        adr_check->setText(QApplication::translate("ChangeInfo", "Address", nullptr));
        adrL->setText(QApplication::translate("ChangeInfo", "new Address:", nullptr));
        pushButton->setText(QApplication::translate("ChangeInfo", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfo: public Ui_ChangeInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFO_H
