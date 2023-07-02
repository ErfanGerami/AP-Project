#include "dinogame.h"
#include "ui_dinogame.h"

DinoGame::DinoGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DinoGame)
{
    connect(this,SIGNAL(show_parent()),parent,SLOT(show_me()));
    ui->setupUi(this);
    barriers[0]=ui->bar1;
    barriers[1]=ui->bar2;
    barriers[2]=ui->bar3;

    connect(this,SIGNAL(update_coins()),this,SLOT(DoUpdateCoins()));
    connect(this,SIGNAL(collided_signal()),this,SLOT(Collide()));



    for(int i=0;i<3;i++){
        int max=-10000;//-inf
        for(int j=0;j<3;j++){
            if(barriers[j]->x()>max){
                max=barriers[j]->x();
            }


        }
        QPropertyAnimation* anim=new QPropertyAnimation(barriers[i],"geometry");
        int distance=rand()%3000+max+1000;
        int base=rand()%3000+max+1000;
        distance=base+200;
        anim->setStartValue(QRect(distance
                                  ,barriers[i]->y(),barriers[i]->width(),barriers[i]->height()));
        anim->setDuration(time*distance*1.0/time_in_distance
                          );
        anim->setEndValue(QRect(-200,barriers[i]->y(),barriers[i]->width(),barriers[i]->height()));
        anim->start();
        connect(anim,&QPropertyAnimation::finished,[this,anim,distance](){

                anim->setDuration(time*distance*1.0/time_in_distance);
                anim->start();});
    }

    clouds[0]=ui->cloud1;
    clouds[1]=ui->cloud2;
    clouds[2]=ui->cloud3;


    for(int i=0;i<3;i++){
        QPropertyAnimation* anim=new QPropertyAnimation(clouds[i],"geometry");
        int y=rand()%200;
        anim->setStartValue(QRect(900,y,clouds[i]->width(),clouds[i]->height()));
        anim->setDuration(rand()%6000+4000);
        anim->setEndValue(QRect(-200,y,clouds[i]->width(),clouds[i]->height()));
        anim->start();


        connect(anim,&QPropertyAnimation::finished,[this,anim](){

            anim->setDuration(rand()%6000);
            anim->start();

        });
    }
    connect(this,SIGNAL(dino_animation()),this,SLOT(DinoDoAnimation()));
    dino_animation_thread=new std::thread([this](){
        bool collided_temp=false;
        while(!collided_temp){

            _sleep(500);
            emit dino_animation();
            mute.lock();
             collided_temp=collided;
            mute.unlock();

        }
    });


    collision_thread=new std::thread([this](){
        bool collided_temp=false;
        while(!collided){
            CheckCollision();
            mute.lock();
            collided_temp=collided;
            mute.unlock();
        }});


    std::thread* counter_thread=new std::thread([this](){

        int collided_save=false;

        while(!collided_save){
            _sleep(3000);

            coins_achieved++;
            emit update_coins();
            mute.lock();
            collided_save=collided;
            mute.unlock();

        }
    });
}





void DinoGame::CloudsAnimation(int index){
    QPropertyAnimation* anim=new QPropertyAnimation(clouds[index],"geometry");
    int y=rand()%200;
    anim->setStartValue(QRect(5000,y,clouds[index]->width(),clouds[index]->height()));
    anim->setDuration(rand()%6000);
    anim->setStartValue(QRect(-100,y,clouds[index]->width(),clouds[index]->height()));
    anim->start();
    connect(anim,SIGNAL(finished()),this,SLOT(CloudsAnimation(index)));


}
DinoGame::~DinoGame()
{
    dino_animation_thread->join();
    counter_thread->join();
    collision_thread->join();
    delete ui;

}

void DinoGame::DoUpdateCoins(){
    ui->coins->setText(QString::number(coins_achieved));
}
void DinoGame::DinoDoAnimation(){
    if(dino_stat==1){

        ui->dino->setStyleSheet("border-image:url(:/images/images/dino2.png);");
        dino_stat=2;
    }else if(dino_stat==2){

        ui->dino->setStyleSheet("border-image:url(:/images/images/dino.png);");
        dino_stat=1;
    }



}


void DinoGame::on_pushButton_clicked()
{
    if(is_jumped)return;
    int first_y=ui->dino->y();



    int min_y=first_y-200
            ;
    QPropertyAnimation* anim=new QPropertyAnimation(ui->dino,"geometry");
    anim->setStartValue(QRect(ui->dino->x(),first_y,ui->dino->width(),ui->dino->height()));
    anim->setDuration(300);
    anim->setEndValue(QRect(ui->dino->x(),min_y,ui->dino->width(),ui->dino->height()));
    anim->start();

    QPropertyAnimation* reverse_anim=new QPropertyAnimation(ui->dino,"geometry");
    reverse_anim->setStartValue(QRect(ui->dino->x(),min_y,ui->dino->width(),ui->dino->height()));
    reverse_anim->setDuration(300);
    reverse_anim->setEndValue(QRect(ui->dino->x(),first_y,ui->dino->width(),ui->dino->height()));

    is_jumped=true;

    connect(anim,&QPropertyAnimation::finished,[reverse_anim](){reverse_anim->start();});
    connect(reverse_anim,&QPropertyAnimation::finished,[this](){this->is_jumped=false;});



}

void DinoGame::CheckCollision(){
    if(!collided){

        int x_right=ui->dino->x()+ui->dino->width()-50;
        int x_left=ui->dino->x();
        int y_down=ui->dino->y()+ui->dino->height()-50;
        for(int i=0;i<3;i++){
            int bar_x_right=barriers[i]->x()+barriers[i]->width()-100
                    ;
            int bar_x_left=barriers[i]->x();
            if((x_right<bar_x_right&&bar_x_left<x_right)||(x_right>bar_x_right&&bar_x_right>x_left)&&y_down>barriers[i]->y()
                    ){
                //collided=true;
                emit collided_signal();
                mute.lock();
                collided=true;
                mute.unlock();
                break;



            }


        }
    }
}
void DinoGame::Collide(){
    for(int i=0;i<3;i++){
        barriers[i]->hide();
        clouds[i]->hide();
    }
    QMessageBox::critical(this,"LOST","youve earned "+QString::number(coins_achieved)+" coins");
    MainPlayer->SettCoins(MainPlayer->GettCoins()+coins_achieved);
    FileHandeling::ChangePlayerEntirely(MainPlayer->GetUserName().c_str(),MainPlayer);
    emit show_parent();
    this->close();



}
