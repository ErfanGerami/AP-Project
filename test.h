#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include "card.h"
#include <thread>
namespace Ui {
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
    void animate2();

    explicit test(QWidget *parent = nullptr);
    ~test();

    void animate();
    QPushButton* button;
private:
    Ui::test *ui;
};

#endif // TEST_H
