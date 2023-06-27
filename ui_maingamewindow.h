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

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow
{
public:
    QGraphicsView *Graphics;

    void setupUi(QDialog *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QString::fromUtf8("MainGameWindow"));
        MainGameWindow->resize(1605, 1020);
        Graphics = new QGraphicsView(MainGameWindow);
        Graphics->setObjectName(QString::fromUtf8("Graphics"));
        Graphics->setGeometry(QRect(0, 0, 1611, 1021));
        Graphics->setStyleSheet(QString::fromUtf8("#Graphics{border-image:url(:/images/images/gameground.png); }"));
        Graphics->setInteractive(true);
        Graphics->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        retranslateUi(MainGameWindow);

        QMetaObject::connectSlotsByName(MainGameWindow);
    } // setupUi

    void retranslateUi(QDialog *MainGameWindow)
    {
        MainGameWindow->setWindowTitle(QApplication::translate("MainGameWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAMEWINDOW_H
