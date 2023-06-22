#include "card.h"
const int Card::unknown = -1;
const int Card::treasure = 0;
const int Card::map = 1;
const int Card::parrot = 2;
const int Card::flag = 3;
const int Card::pirate = 4;
const int Card::queen = 5;
const int Card::king = 6;

Card::Card() {
	this->number = 0;
	this->type = Card::unknown;
	this->button = nullptr;
}
Card::Card(int type, int number, int x, int y, int rotation, QGraphicsScene *scene, QGraphicsView *view) {

	this->scene = scene;
	this->view = view;
	this->type = type;
	this->number = number;
	button = new QPushButton();
	button->resize(width, height);
	proxy = scene->addWidget(button);
	proxy->setPos(x, y);



	proxy->setRotation(rotation);

	QPixmap *picture;
	switch ( type ) {
		case Card::parrot:
			button->setStyleSheet("border-image:url(:/images/images/parot.png) strech 0 0 0;background:transparent;");
			break;
		case Card::map:
			button->setStyleSheet("border-image:url(:/images/images/map.png) strech 0 0 0;background:transparent;");
			break;
		case Card::treasure:
			button->setStyleSheet("border-image:url(:/images/images/treasure.png) strech 0 0 0;background:transparent;");
			break;
		case Card::queen:
			button->setStyleSheet("border-image:url(:/images/images/queen.png) strech 0 0 0;background:transparent;");
			break;
		case Card::flag:
			button->setStyleSheet("border-image:url(:/images/images/flag.png) strech 0 0 0;background:transparent;");
			break;
		case Card::king:
			button->setStyleSheet("border-image:url(:/images/images/skullking.png) strech 0 0 0;background:transparent;");
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
	rotation_animation->setEndValue(rand() % 100 + 100);
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
	QSound::play(":/sounds/sounds/card_push.wav");




}
int Card::GetNumber() { return number; }
int Card::GetType() { return type; }
QPushButton *Card::GetButton() { return button; }
void Card::show() {
	button->show();
}
void Card::hide() { button->hide(); }



