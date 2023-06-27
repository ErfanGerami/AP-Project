/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QLabel *label;
    QLabel *name;
    QLabel *prev;
    QLabel *time;
    QLabel *winner;
    QLabel *score;
    QLabel *no_games2;
    QLabel *no_games1;
    QLabel *score_show;
    QLabel *time_show;
    QLabel *winner_show;
    QPushButton *create_server;
    QPushButton *join_server;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_6;
    QFrame *line_1;
    QFrame *line_9;
    QFrame *line_4;
    QFrame *line_7;
    QFrame *line_10;
    QLabel *prev_2;
    QFrame *line_11;
    QLabel *prev_3;
    QLabel *prev_4;
    QLabel *prev_5;
    QLabel *won;
    QLabel *coin;
    QLabel *lost;
    QLabel *coin_pic;
    QPushButton *change_info;
    QSplitter *splitter;
    QLabel *label_2;
    QLineEdit *server_name;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(923, 711);
        QFont font;
        font.setFamily(QString::fromUtf8("Baskerville Old Face"));
        MainMenu->setFont(font);
        MainMenu->setStyleSheet(QString::fromUtf8("#MainMenu{border-image:url(:/images/images/WhiteSkull.jpg); }"));
        label = new QLabel(MainMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 211, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Blackadder ITC"));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:white;font-size:60px"));
        name = new QLabel(MainMenu);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(240, 10, 301, 91));
        name->setFont(font1);
        name->setStyleSheet(QString::fromUtf8("color:red;font-size:60px;"));
        prev = new QLabel(MainMenu);
        prev->setObjectName(QString::fromUtf8("prev"));
        prev->setGeometry(QRect(10, 370, 221, 41));
        prev->setFont(font1);
        prev->setStyleSheet(QString::fromUtf8("color:white;font-size:40px"));
        time = new QLabel(MainMenu);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(30, 410, 211, 31));
        time->setFont(font1);
        time->setStyleSheet(QString::fromUtf8("color:white;font-size:30px"));
        winner = new QLabel(MainMenu);
        winner->setObjectName(QString::fromUtf8("winner"));
        winner->setGeometry(QRect(30, 440, 211, 31));
        winner->setFont(font1);
        winner->setStyleSheet(QString::fromUtf8("color:white;font-size:30px"));
        score = new QLabel(MainMenu);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(30, 470, 211, 31));
        score->setFont(font1);
        score->setStyleSheet(QString::fromUtf8("color:white;font-size:30px"));
        no_games2 = new QLabel(MainMenu);
        no_games2->setObjectName(QString::fromUtf8("no_games2"));
        no_games2->setGeometry(QRect(0, 220, 321, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bernard MT Condensed"));
        no_games2->setFont(font2);
        no_games2->setStyleSheet(QString::fromUtf8("color:rgb(255, 144, 46);font-size:40px;background-color:yellow;"));
        no_games1 = new QLabel(MainMenu);
        no_games1->setObjectName(QString::fromUtf8("no_games1"));
        no_games1->setEnabled(true);
        no_games1->setGeometry(QRect(0, 290, 321, 51));
        no_games1->setFont(font2);
        no_games1->setStyleSheet(QString::fromUtf8("color:rgb(255, 144, 46);font-size:40px;background-color:yellow;"));
        score_show = new QLabel(MainMenu);
        score_show->setObjectName(QString::fromUtf8("score_show"));
        score_show->setGeometry(QRect(140, 470, 211, 31));
        score_show->setFont(font1);
        score_show->setStyleSheet(QString::fromUtf8("color:red;font-size:30px"));
        time_show = new QLabel(MainMenu);
        time_show->setObjectName(QString::fromUtf8("time_show"));
        time_show->setGeometry(QRect(100, 410, 211, 31));
        time_show->setFont(font1);
        time_show->setStyleSheet(QString::fromUtf8("color:red;font-size:30px"));
        winner_show = new QLabel(MainMenu);
        winner_show->setObjectName(QString::fromUtf8("winner_show"));
        winner_show->setGeometry(QRect(120, 440, 211, 31));
        winner_show->setFont(font1);
        winner_show->setStyleSheet(QString::fromUtf8("color:red;font-size:30px"));
        create_server = new QPushButton(MainMenu);
        create_server->setObjectName(QString::fromUtf8("create_server"));
        create_server->setGeometry(QRect(10, 620, 221, 28));
        create_server->setStyleSheet(QString::fromUtf8("border-radius:0px;background-color:white;"));
        join_server = new QPushButton(MainMenu);
        join_server->setObjectName(QString::fromUtf8("join_server"));
        join_server->setGeometry(QRect(10, 670, 221, 31));
        join_server->setStyleSheet(QString::fromUtf8("border-radius:0px;background-color:white\n"
";"));
        line = new QFrame(MainMenu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 650, 261, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(MainMenu);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(240, 500, 21, 211));
        line_2->setLineWidth(10);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(MainMenu);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 500, 251, 20));
        line_3->setLineWidth(10);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(MainMenu);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(-30, 700, 281, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_1 = new QFrame(MainMenu);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setGeometry(QRect(0, 340, 241, 20));
        line_1->setLineWidth(10);
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(MainMenu);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(230, 340, 20, 161));
        line_9->setLineWidth(10);
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(MainMenu);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(-20, 400, 261, 20));
        line_4->setLineWidth(3);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(MainMenu);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(-20, 430, 261, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(MainMenu);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(-20, 460, 261, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        prev_2 = new QLabel(MainMenu);
        prev_2->setObjectName(QString::fromUtf8("prev_2"));
        prev_2->setGeometry(QRect(10, 530, 211, 41));
        prev_2->setFont(font1);
        prev_2->setStyleSheet(QString::fromUtf8("color:white;font-size:40px"));
        line_11 = new QFrame(MainMenu);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(-10, 560, 261, 20));
        line_11->setLineWidth(3);
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        prev_3 = new QLabel(MainMenu);
        prev_3->setObjectName(QString::fromUtf8("prev_3"));
        prev_3->setGeometry(QRect(670, 20, 101, 41));
        prev_3->setFont(font1);
        prev_3->setStyleSheet(QString::fromUtf8("color:white;font-size:40px"));
        prev_4 = new QLabel(MainMenu);
        prev_4->setObjectName(QString::fromUtf8("prev_4"));
        prev_4->setGeometry(QRect(640, 70, 211, 51));
        prev_4->setFont(font1);
        prev_4->setStyleSheet(QString::fromUtf8("color:white;font-size:40px"));
        prev_5 = new QLabel(MainMenu);
        prev_5->setObjectName(QString::fromUtf8("prev_5"));
        prev_5->setGeometry(QRect(630, 120, 231, 51));
        prev_5->setFont(font1);
        prev_5->setStyleSheet(QString::fromUtf8("color:white;font-size:40px"));
        won = new QLabel(MainMenu);
        won->setObjectName(QString::fromUtf8("won"));
        won->setGeometry(QRect(850, 125, 141, 41));
        won->setFont(font1);
        won->setStyleSheet(QString::fromUtf8("color:red;font-size:40px"));
        coin = new QLabel(MainMenu);
        coin->setObjectName(QString::fromUtf8("coin"));
        coin->setGeometry(QRect(780, 20, 151, 41));
        coin->setFont(font1);
        coin->setStyleSheet(QString::fromUtf8("color:yellow;font-size:40px"));
        lost = new QLabel(MainMenu);
        lost->setObjectName(QString::fromUtf8("lost"));
        lost->setGeometry(QRect(850, 75, 141, 41));
        lost->setFont(font1);
        lost->setStyleSheet(QString::fromUtf8("color:red;font-size:40px"));
        coin_pic = new QLabel(MainMenu);
        coin_pic->setObjectName(QString::fromUtf8("coin_pic"));
        coin_pic->setGeometry(QRect(770, 20, 51, 51));
        coin_pic->setFont(font1);
        coin_pic->setStyleSheet(QString::fromUtf8("border-image:url(:/images/images/coin.png);"));
        change_info = new QPushButton(MainMenu);
        change_info->setObjectName(QString::fromUtf8("change_info"));
        change_info->setGeometry(QRect(20, 90, 181, 20));
        QFont font3;
        change_info->setFont(font3);
        change_info->setStyleSheet(QString::fromUtf8("#change_info{border-radius:1px;background:transparent;color:red;font-size:13px;background:transparent;}\n"
"#change_info:hover{\n"
"border-radius:6px;color:black;font-size:13px;background-color:red;\n"
"color:black;\n"
"}"));
        change_info->setFlat(false);
        splitter = new QSplitter(MainMenu);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 580, 221, 24));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter->addWidget(label_2);
        server_name = new QLineEdit(splitter);
        server_name->setObjectName(QString::fromUtf8("server_name"));
        splitter->addWidget(server_name);

        retranslateUi(MainMenu);

        change_info->setDefault(false);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Dialog", nullptr));
        label->setText(QApplication::translate("MainMenu", "Welcome", nullptr));
        name->setText(QApplication::translate("MainMenu", "Name", nullptr));
        prev->setText(QApplication::translate("MainMenu", "Previous Game:", nullptr));
        time->setText(QApplication::translate("MainMenu", "time:", nullptr));
        winner->setText(QApplication::translate("MainMenu", "winner:", nullptr));
        score->setText(QApplication::translate("MainMenu", "your score:", nullptr));
        no_games2->setText(QApplication::translate("MainMenu", "You havnt played ", nullptr));
        no_games1->setText(QApplication::translate("MainMenu", "any games yet", nullptr));
        score_show->setText(QString());
        time_show->setText(QString());
        winner_show->setText(QString());
        create_server->setText(QApplication::translate("MainMenu", "create a new server", nullptr));
        join_server->setText(QApplication::translate("MainMenu", "join an existing server", nullptr));
        prev_2->setText(QApplication::translate("MainMenu", "New Game:", nullptr));
        prev_3->setText(QApplication::translate("MainMenu", "coins:", nullptr));
        prev_4->setText(QApplication::translate("MainMenu", "lost games:", nullptr));
        prev_5->setText(QApplication::translate("MainMenu", "won games:", nullptr));
        won->setText(QString());
        coin->setText(QString());
        lost->setText(QString());
        coin_pic->setText(QString());
        change_info->setText(QApplication::translate("MainMenu", "Change Your Information Here", nullptr));
        label_2->setText(QApplication::translate("MainMenu", "server name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
