#ifndef WAITMENU_H
#define WAITMENU_H

#include <QDialog>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QGraphicsProxyWidget>
namespace Ui {
class WaitMenu;
}

class WaitMenu : public QDialog
{
    Q_OBJECT

public:
    explicit WaitMenu(QWidget *parent = nullptr);
    ~WaitMenu();

private:
    Ui::WaitMenu *ui;
    QGraphicsScene* scene;
};

#endif // WAITMENU_H
