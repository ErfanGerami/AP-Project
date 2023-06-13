#include "test.h"
#include "ui_test.h"
#include <QPushButton>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>

test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);


    QGraphicsScene* scene=new QGraphicsScene;


        QGraphicsView* view=new QGraphicsView(scene);
        view->resize(500,500);

view->setParent(this);
        Card* card=new Card(Card::parrot,1,10,10,0,scene,view);
        card->show();
        card->PushCard();
        view->show();



}
void test::animate2(){

}
void test::animate(){



}









test::~test()
{
    delete ui;
}
