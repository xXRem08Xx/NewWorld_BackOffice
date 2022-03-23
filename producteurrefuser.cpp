#include "producteurrefuser.h"
#include "ui_producteurrefuser.h"
#include <QMessageBox>

ProducteurRefuser::ProducteurRefuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProducteurRefuser)
{
    ui->setupUi(this);
}

ProducteurRefuser::~ProducteurRefuser()
{
    delete ui;
}

QString ProducteurRefuser::getText()
{
    return raisonRefus;
}

void ProducteurRefuser::on_buttonBox_accepted()
{
    raisonRefus = ui->lineEdit_refus->text();
    close();
}


void ProducteurRefuser::on_buttonBox_rejected()
{
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment quitter cette fenêtre ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        close();
    }
}

