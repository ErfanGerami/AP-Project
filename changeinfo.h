#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QDialog>
#include   "player.h"
#include "filehandeling.h"
#include "errors.h"
#include <QMessageBox>

extern Player* MainPlayer;
extern QString SavedPassword;

namespace Ui {
class ChangeInfo;
}

class ChangeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeInfo(QWidget *parent = nullptr);
    ~ChangeInfo();

private slots:

    void on_user_check_toggled(bool checked);

    void on_pass_check_toggled(bool checked);

    void on_email_check_toggled(bool checked);


    void on_phone_check_toggled(bool checked);

    void on_submit_clicked();

    void on_adr_check_toggled(bool checked);

private:
    Ui::ChangeInfo *ui;
};

#endif // CHANGEINFO_H
