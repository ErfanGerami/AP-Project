#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QDialog>

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

private:
    Ui::ChangeInfo *ui;
};

#endif // CHANGEINFO_H
