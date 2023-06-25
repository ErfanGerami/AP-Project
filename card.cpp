#include "card.h"
typedef int CardType;

const CardType Card::unknown = -1;
const CardType Card::treasure = 0;
const CardType Card::map = 1;
const CardType Card::parrot = 2;
const CardType Card::flag = 3;
const CardType Card::pirate = 4;
const CardType Card::queen = 5;
const CardType Card::king = 6;


Card::Card() {
	this->number = 0;
	this->type = Card::unknown;
	this->button = nullptr;
}
Card::Card(CardType type,QGraphicsScene *scene, QGraphicsView *view, int number,int x, int y, int rotation){
	this->scene = scene;
	this->view = view;
	this->type = type;
	this->number = number;
	button = new QPushButton();
	button->resize(width, height);
	proxy = scene->addWidget(button);
	proxy->setPos(qreal(x),qreal(y));

	button->hide();

	proxy->setRotation(rotation);

    SetUpButton();

}
void Card::operator=( const Card&  other) {
	this->scene = other.scene;
	this->view = other.view;
	this->type = other.type;
	this->number = other.number;
	button = new QPushButton();
	button->resize(width, height);
	proxy = scene->addWidget(button);
	proxy->setPos(qreal(other.proxy->x()), qreal(other.proxy->y()));

	button->hide();

	proxy->setRotation(other.proxy->rotation());
    SetUpButton();




}
Card::Card(const Card& other) {
	this->scene = other.scene;
	this->view = other.view;
	this->type = other.type;
	this->number = other.number;

	button = new QPushButton();
	button->resize(width, height);
	proxy = scene->addWidget(button);
	proxy->setPos(qreal(other.proxy->x()), qreal(other.proxy->y()));


	button->hide();
	proxy->setRotation(other.proxy->rotation());

    SetUpButton();



}
void Card::SetUpButton(){
    //adjusting each cards picture to itself.
    switch (type) {
    case Card::parrot:
        button->setStyleSheet("border-image:url(:/images/images/parrot"+QString::number(number)+".png) strech 0 0 0;background:transparent;");
        break;
    case Card::map:
        button->setStyleSheet("border-image:url(:/images/images/map"+QString::number(number)+".png) strech 0 0 0;background:transparent;");
        break;
    case Card::treasure:
        button->setStyleSheet("border-image:url(:/images/images/treasure"+QString::number(number)+".png) strech 0 0 0;background:transparent;");
        break;
    case Card::flag:
        button->setStyleSheet("border-image:url(:/images/images/flag"+QString::number(number)+".png) strech 0 0 0;background:transparent;");
        break;
    case Card::queen:
        button->setStyleSheet("border-image:url(:/images/images/queen.png) strech 0 0 0;background:transparent;");
        break;

    case Card::king:
        button->setStyleSheet("border-image:url(:/images/images/scullking.png) strech 0 0 0;background:transparent;");
        break;


    case Card::pirate:
        button->setStyleSheet("border-image:url(:/images/images/pirate.png) strech 0 0 0;background:transparent;");
        break;



    }

}
void Card::PushCard() {
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	QPropertyAnimation *rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(0);
	rotation_animation->setEndValue(rand() % 360 );
    rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation *tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(button->x(), button->y(), width, height));
	tranform_animation->setEndValue(QRect(dest_x, dest_y, width, height));
    tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	group->start();
	//QSound::play(":/sounds/sounds/card_push.wav");

}
void Card::PushTo(std::pair<int, int> pos) {
	QParallelAnimationGroup* group = new QParallelAnimationGroup;
	QPropertyAnimation* rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(0);
	rotation_animation->setEndValue(rand() % 360);
    rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation* tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(button->x(), button->y(), width, height));
	tranform_animation->setEndValue(QRect(pos.first, pos.second, width, height));
    tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	group->start();

}
void Card::PushTo(std::pair<int, int> pos,int rotation) {
	QParallelAnimationGroup* group = new QParallelAnimationGroup;
	QPropertyAnimation* rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(0);
	rotation_animation->setEndValue(rotation);
    rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation* tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(button->x(), button->y(), width, height));
	tranform_animation->setEndValue(QRect(pos.first, pos.second, width, height));
    tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	group->start();

}


int Card::GetNumber() { return number; }
int Card::GetType() { return type; }
void Card::SetNumber(int number) { this->number = number; }
void Card::SetType(CardType type) { this->type = type; }
QPushButton *Card::GetButton() { return button; }
void Card::show() {
	button->show();
}
void Card::hide() { button->hide(); }


