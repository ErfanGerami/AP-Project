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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_GetServersInformation
{
public:
    QPushButton *reload;
    QListWidget *listWidget;
    QPushButton *connect;
    QSplitter *splitter;
    QLabel *port_l_3;
    QLineEdit *server_number;

    void setupUi(QDialog *GetServersInformation)
    {
        if (GetServersInformation->objectName().isEmpty())
            GetServersInformation->setObjectName(QString::fromUtf8("GetServersInformation"));
        GetServersInformation->resize(551, 368);
        GetServersInformation->setStyleSheet(QString::fromUtf8("#GetServersInformation{border-image:url(:/images/images/WhiteSkull.jpg); }"));
        reload = new QPushButton(GetServersInformation);
        reload->setObjectName(QString::fromUtf8("reload"));
        reload->setGeometry(QRect(10, 10, 521, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        reload->setFont(font);
        reload->setStyleSheet(QString::fromUtf8("#reload{font-size:20px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 4px;}\n"
"#reload:hover{background-color:rgba(255,255,255,225);color:black;}"));
        listWidget = new QListWidget(GetServersInformation);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 521, 192));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Black"));
        font1.setBold(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,100);color:white;font-size:15px;\n"
""));
        connect = new QPushButton(GetServersInformation);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(0, 300, 531, 61));
        connect->setFont(font);
        connect->setStyleSheet(QString::fromUtf8("#connect{font-size:30px; border-color:white;border-radius:35px;;background-color:rgba(0,0,0,225);color:white;border-style: solid;\n"
"  border-width: 4px;}\n"
"#connect:hover{background-color:rgba(255,255,255,225);color:black;}"));
        splitter = new QSplitter(GetServersInformation);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 260, 501, 24));
        splitter->setOrientation(Qt::Horizontal);
        port_l_3 = new QLabel(splitter);
        port_l_3->setObjectName(QString::fromUtf8("port_l_3"));
        port_l_3->setEnabled(true);
        port_l_3->setFont(font);
        port_l_3->setStyleSheet(QString::fromUtf8("border-style:solid; background-color: rgba(0, 0, 0,200); color:white\n"
"\n"
";font-size:13px;border-radius:10px;"));
        splitter->addWidget(port_l_3);
        server_number = new QLineEdit(splitter);
        server_number->setObjectName(QString::fromUtf8("server_number"));
        server_number->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(server_number->sizePolicy().hasHeightForWidth());
        server_number->setSizePolicy(sizePolicy);
        server_number->setStyleSheet(QString::fromUtf8("#mai_servers_ip{border-color:white;background-color:rgba(0,0,0,150);color:white;font-size:15px;border-radius:1px;border-style:solid;border-width:1px;}\n"
"#mai_servers_ip:hover{background-color:black;}\n"
"\n"
""));
        splitter->addWidget(server_number);

        retranslateUi(GetServersInformation);

        QMetaObject::connectSlotsByName(GetServersInformation);
    } // setupUi

    void retranslateUi(QDialog *GetServersInformation)
    {
        GetServersInformation->setWindowTitle(QApplication::translate("GetServersInformation", "Dialog", nullptr));
        reload->setText(QApplication::translate("GetServersInformation", "Load", nullptr));
        connect->setText(QApplication::translate("GetServersInformation", "Connect", nullptr));
        port_l_3->setText(QApplication::translate("GetServersInformation", "server number", nullptr));
        server_number->setText(QApplication::translate("GetServersInformation", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetServersInformation: public Ui_GetServersInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSERVERSINFORMATION_H
