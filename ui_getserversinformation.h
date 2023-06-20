/********************************************************************************
** Form generated from reading UI file 'getserversinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSERVERSINFORMATION_H
#define UI_GETSERVERSINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetServersInformation
{
public:
    QPushButton *reload;
    QListWidget *listWidget;
    QCheckBox *checkBox;
    QPushButton *connect;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *IP_l;
    QLineEdit *IP;
    QLabel *port_l;
    QLineEdit *port;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *IP_l_2;
    QLineEdit *mai_servers_ip;
    QLabel *port_l_2;
    QLineEdit *mai_servers_port;

    void setupUi(QDialog *GetServersInformation)
    {
        if (GetServersInformation->objectName().isEmpty())
            GetServersInformation->setObjectName(QString::fromUtf8("GetServersInformation"));
        GetServersInformation->resize(411, 480);
        GetServersInformation->setStyleSheet(QString::fromUtf8("#GetServersInformation{border-image:url(:/images/images/WhiteSkull.jpg); }"));
        reload = new QPushButton(GetServersInformation);
        reload->setObjectName(QString::fromUtf8("reload"));
        reload->setGeometry(QRect(10, 10, 261, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        reload->setFont(font);
        reload->setStyleSheet(QString::fromUtf8("#reload{font-size:20px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 4px;}\n"
"#reload:hover{background-color:rgba(255,255,255,225);color:black;}"));
        listWidget = new QListWidget(GetServersInformation);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 90, 381, 192));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Black"));
        font1.setBold(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,100);color:white;font-size:15px;\n"
""));
        checkBox = new QCheckBox(GetServersInformation);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 310, 151, 20));
        checkBox->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:red\n"
";font-size:15px;border-radius:10px;"));
        connect = new QPushButton(GetServersInformation);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(0, 340, 411, 61));
        connect->setFont(font);
        connect->setStyleSheet(QString::fromUtf8("#connect{font-size:30px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 4px;}\n"
"#connect:hover{background-color:rgba(255,255,255,225);color:black;}"));
        layoutWidget = new QWidget(GetServersInformation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setEnabled(false);
        layoutWidget->setGeometry(QRect(30, 350, 358, 50));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        IP_l = new QLabel(layoutWidget);
        IP_l->setObjectName(QString::fromUtf8("IP_l"));
        IP_l->setEnabled(false);
        IP_l->setFont(font);
        IP_l->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
"\n"
";font-size:15px;border-radius:5px;"));

        horizontalLayout->addWidget(IP_l);

        IP = new QLineEdit(layoutWidget);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setEnabled(false);
        IP->setStyleSheet(QString::fromUtf8("#IP{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:1px;border-style:solid;border-width:3px;}\n"
"#IP:hover{background-color:black;}\n"
"\n"
""));

        horizontalLayout->addWidget(IP);

        port_l = new QLabel(layoutWidget);
        port_l->setObjectName(QString::fromUtf8("port_l"));
        port_l->setEnabled(false);
        port_l->setFont(font);
        port_l->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
"\n"
";font-size:15px;border-radius:10px;"));

        horizontalLayout->addWidget(port_l);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setEnabled(false);
        port->setStyleSheet(QString::fromUtf8("#port{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:1px;border-style:solid;border-width:3px;}\n"
"#port:hover{background-color:black;}\n"
"\n"
""));

        horizontalLayout->addWidget(port);

        layoutWidget1 = new QWidget(GetServersInformation);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 301, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        IP_l_2 = new QLabel(layoutWidget1);
        IP_l_2->setObjectName(QString::fromUtf8("IP_l_2"));
        IP_l_2->setEnabled(true);
        IP_l_2->setFont(font);
        IP_l_2->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
"\n"
";font-size:13px;border-radius:10px;"));

        horizontalLayout_2->addWidget(IP_l_2);

        mai_servers_ip = new QLineEdit(layoutWidget1);
        mai_servers_ip->setObjectName(QString::fromUtf8("mai_servers_ip"));
        mai_servers_ip->setEnabled(true);
        mai_servers_ip->setStyleSheet(QString::fromUtf8("#mai_servers_ip{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:1px;border-style:solid;border-width:1px;}\n"
"#mai_servers_ip:hover{background-color:black;}\n"
"\n"
""));

        horizontalLayout_2->addWidget(mai_servers_ip);

        port_l_2 = new QLabel(layoutWidget1);
        port_l_2->setObjectName(QString::fromUtf8("port_l_2"));
        port_l_2->setEnabled(true);
        port_l_2->setFont(font);
        port_l_2->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
"\n"
";font-size:13px;border-radius:10px;"));

        horizontalLayout_2->addWidget(port_l_2);

        mai_servers_port = new QLineEdit(layoutWidget1);
        mai_servers_port->setObjectName(QString::fromUtf8("mai_servers_port"));
        mai_servers_port->setEnabled(true);
        mai_servers_port->setStyleSheet(QString::fromUtf8("#mai_servers_port{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:1px;border-style:solid;border-width:1px;}\n"
"#mai_servers_port:hover{background-color:black;}\n"
"\n"
""));

        horizontalLayout_2->addWidget(mai_servers_port);


        retranslateUi(GetServersInformation);

        QMetaObject::connectSlotsByName(GetServersInformation);
    } // setupUi

    void retranslateUi(QDialog *GetServersInformation)
    {
        GetServersInformation->setWindowTitle(QApplication::translate("GetServersInformation", "Dialog", nullptr));
        reload->setText(QApplication::translate("GetServersInformation", "Load", nullptr));
        checkBox->setText(QApplication::translate("GetServersInformation", "Custum Server", nullptr));
        connect->setText(QApplication::translate("GetServersInformation", "Connect", nullptr));
        IP_l->setText(QApplication::translate("GetServersInformation", "IP", nullptr));
        port_l->setText(QApplication::translate("GetServersInformation", "PORT", nullptr));
        port->setText(QString());
        IP_l_2->setText(QApplication::translate("GetServersInformation", "IP", nullptr));
        mai_servers_ip->setText(QApplication::translate("GetServersInformation", "127.0.0.1", nullptr));
        port_l_2->setText(QApplication::translate("GetServersInformation", "PORT", nullptr));
        mai_servers_port->setText(QApplication::translate("GetServersInformation", "1025", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetServersInformation: public Ui_GetServersInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSERVERSINFORMATION_H
