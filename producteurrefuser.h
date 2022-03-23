#ifndef PRODUCTEURREFUSER_H
#define PRODUCTEURREFUSER_H

#include <QDialog>

namespace Ui {
class ProducteurRefuser;
}

class ProducteurRefuser : public QDialog
{
    Q_OBJECT

public:
    explicit ProducteurRefuser(QWidget *parent = nullptr);
    ~ProducteurRefuser();
    QString getText();
    QString raisonRefus;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ProducteurRefuser *ui;
};

#endif // PRODUCTEURREFUSER_H
