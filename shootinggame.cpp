#include "shootinggame.h"
#include "ui_shootinggame.h"

ShootingGame::ShootingGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShootingGame)
{
    ui->setupUi(this);
    connect(this,SIGNAL(show_parent()),parent,SLOT(show_me()));
    qApp->installEventFilter(this);
    connect(this,SIGNAL(move()),this,SLOT(Move()));
    connect(this,SIGNAL(end_game()),this,SLOT(EndGame()));
    move_thread=new std::thread([this](){while(true){_sleep(change_pos_time);emit move();}});
    time=QDateTime::currentDateTime();

}


ShootingGame::~ShootingGame()
{
    move_thread->join();
    delete ui;
}

bool ShootingGame::eventFilter(QObject *obj, QEvent *event) {

    if(time.msecsTo(QDateTime::currentDateTime())>300&&event->type()==QEvent::MouseButtonPress){
        if(GetTheCollistion(ui->aim->x()+ui->aim->width()/2,ui->aim->y()+ui->aim->height()/2)){
            time=QDateTime::currentDateTime();
            ui->coins->setText(QString::number(ui->coins->text().toInt()+1));
            spots.push_back({new QLabel(this),{ui->aim->x()+ui->aim->width()/2-ui->target->x()
                                               ,ui->aim->y()+ui->aim->height()/2-ui->target->y()}});
            int index=spots.size()-1;
            spots[index].first->show();
            spots[index].first->resize(10,10);
            spots[index].first->setStyleSheet("background-color:red;");

            spots[index].first->move(ui->aim->x()+ui->aim->width()/2,ui->aim->y()+ui->aim->height()/2);
            if(index>=4)
                spots[index-4].first->hide();




        }else if(!lost){
             message="youve lost";
             emit end_game();


        }

    }else if (event->type()!= QEvent::MouseMove)
        return false;


    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    QPoint mousePos = mouseEvent->pos();  // Retrieve the mouse position

    // Print the mouse coordinates
    int x=mouseEvent->pos().x();
    int y=mouseEvent->pos().y();
    if(y!=0||x!=0)
        ui->aim->move(x,y);

    return false;
}
bool ShootingGame::GetTheCollistion(int x,int y){

    float dis_pow_two=(x-(ui->target->x()+ui->target->width()/2))*(x-(ui->target->x()+ui->target->width()/2))
            +(y-(ui->target->y()+ui->target->height()/2))*(y-(ui->target->y()+ui->target->height()/2));
    if(dis_pow_two<ui->target->width()*ui->target->width()/4 )
        return true;
    return false;

}
void ShootingGame::Move(){
    if(!lost){
        int x=rand()%700;
        int y=rand()%500;
        change_pos_time-=10;
        if(change_pos_time<=300){
            message="youve won";
            emit end_game();
        }


        target_pos.first=x;
        target_pos.second=y;
        ui->target->move(x,y);




        for(int i=0;i<spots.size();i++){
            spots[i].first->move(x+spots[i].second.first,y+spots[i].second.second);
        }
    }
}


void ShootingGame::EndGame(){
    lost=true;


    QMessageBox::critical(this,"End",message+".earned "+QString::number(ui->coins->text().toInt()/4)+" coins");

    MainPlayer->SettCoins(MainPlayer->GettCoins()+ui->coins->text().toInt()/4);
    MainPlayer->SetEarnedCoins(true);
    FileHandeling::ChangePlayerEntirely(MainPlayer->GetUserName().c_str(),MainPlayer);

    emit show_parent();

    this->close();
}
