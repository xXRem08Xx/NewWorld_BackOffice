#include "connexion.h"
#include "ui_connexion.h"
#include "QString"
#include "QDebug"
#include "QSqlQuery"
#include <QTableWidgetItem>
#include <QTableWidget>

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
    ui->labelConnexionError->setText("");
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButtonValider_clicked()
{
    qDebug()<<"on_pushButtonValider_clicked()";

    QString cmdConnexion = "SELECT login, motDePasse, actif, idRole FROM Utilisateur WHERE login = '"+ui->lineEditLogin->text()+"' AND motDePasse = PASSWORD('"+ui->lineEditPassword->text()+"');";
    QSqlQuery requeteConnexion(cmdConnexion);

    qDebug()<<cmdConnexion;
    //si la requete renvoie un resultat
    if(requeteConnexion.next())
    {
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
    close();
}
