#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);
    ~MainGameWindow();

private:
    Ui::MainGameWindow *ui;
};

#endif // MAINGAMEWINDOW_H
