#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QFontDatabase>
#include "player.h"
#include "changeinfo.h"
extern Player MainPLayer;
namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_change_info_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
