/********************************************************************************
** Form generated from reading UI file 'serverselection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERSELECTION_H
#define UI_SERVERSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_ServerSelection
{
public:
    QListView *listView;

    void setupUi(QDialog *ServerSelection)
    {
        if (ServerSelection->objectName().isEmpty())
            ServerSelection->setObjectName(QString::fromUtf8("ServerSelection"));
        ServerSelection->resize(400, 300);
        listView = new QListView(ServerSelection);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 341, 261));

        retranslateUi(ServerSelection);

        QMetaObject::connectSlotsByName(ServerSelection);
    } // setupUi

    void retranslateUi(QDialog *ServerSelection)
    {
        ServerSelection->setWindowTitle(QApplication::translate("ServerSelection", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerSelection: public Ui_ServerSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERSELECTION_H
