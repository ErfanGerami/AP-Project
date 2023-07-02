#ifndef DINOGAME_H
#define DINOGAME_H

#include <QDialog>
#include <QMessageBox>
#include <QMutex>
#include <thread>
#include <QPropertyAnimation>
#include "filehandeling.h"

#include "player.h"
namespace Ui {
class DinoGame;
}
extern Player* MainPlayer;
class DinoGame : public QDialog
{
    Q_OBJECT

public:
    explicit DinoGame(QWidget *parent = nullptr);
    ~DinoGame();

private:
    Ui::DinoGame *ui;
    bool is_jumped=false;
    QMutex mute;
    bool collided=false;
    int coins_achieved=0;
    int time=6000;
    int time_in_distance=3000;
    QLabel* clouds[3];
    QLabel* barriers[3];
    std::thread* dino_animation_thread;
    std::thread* collision_thread;
    std::thread* counter_thread;
    int dino_stat=1;
    void CheckCollision();

signals:
    void dino_animation();
    void cloud_animation(int index);
    void update_coins();
    void collided_signal();
    void show_parent();

private slots:
    void CloudsAnimation(int index);
    void DinoDoAnimation();
    void DoUpdateCoins();
    void Collide();


    void on_pushButton_clicked();
};

#endif // DINOGAME_H
