#include "card.h"
#include <QSound>
typedef int CardType;

const CardType Card::unknown = -1;
const CardType Card::treasure = 0;
const CardType Card::map = 1;
const CardType Card::parrot = 2;
const CardType Card::flag = 3;
const CardType Card::pirate = 4;
const CardType Card::queen = 5;
const CardType Card::king = 6;

int Card::angle_between_cards = 10;
int Card::space_between_cards = 50;
int Card::id = 0;

Card::Card() {
	this->number = 0;
	this->type = Card::unknown;
	this->button = nullptr;
	this->parent = nullptr;
	this->scene = nullptr;
}
Card::Card(CardType type, int number = -1) {
	this->number = number;
	this->type = type;
	this->scene = nullptr;


}
Card::Card(QObject *parent, CardType type, QGraphicsScene *scene, QGraphicsView *view, int number, int x, int y, int rotation) {
	this->scene = scene;
	this->view = view;
	this->parent = parent;
	this->type = type;
	this->number = number;
	button = new QPushButton();
	button->resize(width, height);
	proxy = scene->addWidget(button);
	proxy->setFlag(QGraphicsItem::ItemIgnoresTransformations);
	proxy->setPos(qreal(x), qreal(y));

	button->hide();

	proxy->setRotation(rotation);

	SetUpButton();
	connect(button, SIGNAL(clicked()), parent, SLOT(PushCard()));

}
void Card::operator=(const Card &other) {

	this->parent = other.parent;
	this->type = other.type;
	this->number = other.number;
	if ( other.scene != nullptr ) {
		this->view = other.view;
		this->button = other.button;
		this->scene = other.scene;


		button = new QPushButton();
		button->resize(width, height);
		proxy = new QGraphicsProxyWidget();
		proxy = scene->addWidget(button);
		proxy->setFlag(QGraphicsItem::ItemIgnoresTransformations);
		proxy->setPos(qreal(other.proxy->x()), qreal(other.proxy->y()));

		button->hide();

		proxy->setRotation(other.proxy->rotation());
		SetUpButton();

		connect(button, SIGNAL(clicked()), parent, SLOT(PushCard()));
	}

}

Card::Card(const Card &other) {
	(*this) = other;
}

void Card::SetUpButton() {

	//adjusting each cards picture to itself.
	id++;
	button->setObjectName("card_button" + QString::number(id));
	QString hover = !disabled ? "#card_button" + QString::number(id) + ":hover{border-image:url(:/images/images/unknown.png);}" : "";
	switch ( type ) {
		case Card::parrot:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/parrot" + QString::number(number) + ".png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}



		case Card::map:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/map" + QString::number(number) + ".png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}


		case Card::treasure:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/treasure" + QString::number(number) + ".png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}



		case Card::flag:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/flag" + QString::number(number) + ".png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}


		case Card::queen:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/queen.png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}

		case Card::king:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/scullking.png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}

		case Card::pirate:
		{
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/pirate.png) strech 0 0 0;background:transparent;}" + hover);
			break;
		}

		case Card::unknown:
		{
			//to be fixed;
			button->setStyleSheet("#card_button" + QString::number(id) + "{border-image:url(:/images/images/unknown.png) strech 0 0 0;background:transparent;}");
			break;
		}

	}

	QString style = button->styleSheet();
}


void Card::PushCard() {
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	QPropertyAnimation *rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(0);
	rotation_animation->setEndValue(rand() % 360);
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
QPropertyAnimation *Card::PushTo(std::pair<int, int> pos) {
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	QPropertyAnimation *rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(proxy->rotation());
	rotation_animation->setEndValue(rand() % 360);
	rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation *tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(proxy->x(), proxy->y(), width, height));
	tranform_animation->setEndValue(QRect(pos.first, pos.second, width, height));
	tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	//group->start();
	return tranform_animation;

}
QPropertyAnimation *Card::PushTo(std::pair<int, int> pos, int rotation) {
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	QPropertyAnimation *rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(proxy->rotation());
	rotation_animation->setEndValue(rotation);
	rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation *tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(proxy->x(), proxy->y(), width, height));
	tranform_animation->setEndValue(QRect(pos.first, pos.second, width, height));
	tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	group->start();

	return tranform_animation;
}
QPropertyAnimation *Card::PushTo(std::pair<int, int> pos, std::pair<int, int> size, int rotation) {
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	QPropertyAnimation *rotation_animation = new QPropertyAnimation(proxy, "rotation");
	rotation_animation->setStartValue(proxy->rotation());
	rotation_animation->setEndValue(rotation);
	rotation_animation->setDuration(200);
	rotation_animation->start();
	QPropertyAnimation *tranform_animation = new QPropertyAnimation(proxy, "geometry");
	tranform_animation->setStartValue(QRect(proxy->x(), proxy->y(), width, height));
	tranform_animation->setEndValue(QRect(pos.first, pos.second, size.first, size.second));
	tranform_animation->setDuration(200);
	tranform_animation->start();
	group->addAnimation(tranform_animation);
	group->addAnimation(rotation_animation);
	group->start();
	width = size.first;
	height = size.second;
	return tranform_animation;

}


int Card::GetNumber() const { return number; }
QGraphicsProxyWidget *Card::GetProxy() { return proxy; }
int Card::GetType()const { return type; }
void Card::SetNumber(int number) { this->number = number; }
void Card::SetType(CardType type) { this->type = type; }
QPushButton *Card::GetButton() { return button; }
void Card::show() {
	button->show();
}
void Card::hide() { button->hide(); }
void Card::ChangeCard(Card::CardType type, int number) {
	this->number = number;
	this->type = type;
	SetUpButton();

}
void Card::SetDisabled(bool disabled) {

	this->disabled = disabled; SetUpButton();
	if ( disabled )disconnect(button, SIGNAL(clicked()), parent, SLOT(PushCard()));
	else connect(button, SIGNAL(clicked()), parent, SLOT(PushCard()));
}

