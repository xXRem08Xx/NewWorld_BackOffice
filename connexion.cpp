#include "connexion.h"
#include "ui_connexion.h"
#include "QString"
#include "QDebug"
#include "QSqlQuery"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMessageBox>
#include <QCloseEvent>

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
    ui->labelConnexionError->setText("");
    ui->lineEditLogin->setText("rmaissa");
    ui->lineEditPassword->setText("elini01");
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButtonValider_clicked()
{
    qDebug()<<"on_pushButtonValider_clicked()";

    QString cmdConnexion = "SELECT numUtilisateur, login, motDePasse, actif, idRole FROM Utilisateur WHERE login = '"+ui->lineEditLogin->text()+"' AND motDePasse = PASSWORD('"+ui->lineEditPassword->text()+"');";
    QSqlQuery requeteConnexion(cmdConnexion);

    qDebug()<<cmdConnexion;
    //si la requete renvoie un resultat
    if(requeteConnexion.next())
    {
        //on enregistre les informations de connection
        login = ui->lineEditLogin->text();
        password = ui->lineEditPassword->text();
        idUtilisateur = requeteConnexion.value("numUtilisateur").toInt();

        //on accepte la QDialog
        accept();
    }
    else
    {
        ui->labelConnexionError->setText("Connexion impossible : Verifiez les informations souscrites");
    }

}

void Connexion::on_pushButtonAnnuler_clicked()
{
    qDebug()<<"on_pushButtonAnnuler_clicked()";
    ui->lineEditLogin->setText("");
    ui->lineEditPassword->setText("");
}

void Connexion::on_pushButtonQuitter_clicked()
{
    qDebug()<<"on_pushButtonQuitter_clicked()";
    close();
}

bool Connexion::quitConfirm()
{
    qDebug()<<"Connexion::quitConfirm()";
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment quitter cette fenêtre ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        return true;
    }
    else {
        return false;
    }
}

void Connexion::closeEvent(QCloseEvent *event)
{
    qDebug()<<"Connexion::closeEvent(QCloseEvent *event)";
    if(quitConfirm())
    {
        event->accept();
    }
    else {
        event->ignore();
    }
}

int Connexion::getIdProfil()
{
    qDebug()<<"Connexion::getProfil()";
    return idUtilisateur;
}
