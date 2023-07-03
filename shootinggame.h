#ifndef SHOOTINGGAME_H
#define SHOOTINGGAME_H

#include <QDialog>
#include <QVector>
#include <thread>
#include <QLabel>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDateTime>
#include <QString>
#include "player.h"
#include "filehandeling.h"


namespace Ui {
class ShootingGame;
}
extern Player* MainPlayer;
class ShootingGame : public QDialog
{
    Q_OBJECT

public:
    explicit ShootingGame(QWidget *parent = nullptr);
    ~ShootingGame();

private:
    QDateTime time;
    QString message;
    bool lost=false;

    std::thread* move_thread;
    std::pair<int,int> target_pos;

    Ui::ShootingGame *ui;
    int change_pos_time=1000;
    QVector<std::pair<QLabel*,std::pair<int,int>>> spots;
    bool GetTheCollistion(int x,int y);
private slots:
    void Move();
    void EndGame();
signals:
    void move();

    void end_game();
    void show_parent();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

};

#endif // SHOOTINGGAME_H
