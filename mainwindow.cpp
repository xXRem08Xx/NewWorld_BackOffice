#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QDebug"
#include "QSqlQuery"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(int identifiantUtilisateur ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    idUtilisateur = identifiantUtilisateur;
    ui->setupUi(this);

    //on rempli la fenetre de profil
    getPlaceInfoUtilisateur(identifiantUtilisateur);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Cette fonction permet d'afficher une fenetre de dialogue demandant si l'utilisateur veux bien fermer la fenetre
 * @return Renvoie un booléen contenant la reponde de l'utilisateur
 */
bool MainWindow::quitConfirm()
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

/**
 * @brief Cette fonction permet d'executer la fonction quitConfirm quand on ferme la fenetre, et accepte la fermeture si quitConfirm renvoie true
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
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

void MainWindow::getPlaceInfoUtilisateur(int id)
{
    qDebug()<<"MainWindow::getPlaceInfoUtilisateur(int id)";

    QString cmdInfoUtilisateur = "SELECT `login`, `nom`, `prenom`, `adresse`, `ville`, `codePostal`, `telephone`, `mail`, "
                                 " `idRole` FROM `Utilisateur` WHERE `numUtilisateur` = "+QString::number(id);

    qDebug()<<"requeteInfoUtilisateur"<<cmdInfoUtilisateur;
    QSqlQuery requeteInfoUtilisateur(cmdInfoUtilisateur);
    requeteInfoUtilisateur.first();

    //on recupere les informations de l'utilisateur
    login = requeteInfoUtilisateur.value("login").toString();
    nom = requeteInfoUtilisateur.value("nom").toString();
    prenom = requeteInfoUtilisateur.value("prenom").toString();
    adresse = requeteInfoUtilisateur.value("adresse").toString();
    ville = requeteInfoUtilisateur.value("ville").toString();
    codePostal = requeteInfoUtilisateur.value("codePostal").toString();
    telephone = requeteInfoUtilisateur.value("telephone").toString();
    mail = requeteInfoUtilisateur.value("mail").toString();
    idRole = requeteInfoUtilisateur.value("idRole").toString();

    //on affiche les informations de l'utilisateur
    ui->lineEditProfil_Mail->setText(mail);
    ui->lineEditProfil_Login->setText(login);
    ui->lineEditProfil_Ville->setText(ville);
    ui->lineEditProfil_Adresse->setText(adresse);
    ui->lineEditProfil_Telephone->setText(telephone);
    ui->lineEditProfil_CodePostal->setText(codePostal);
    ui->labelProfil_NomARemplir->setText(nom);
    ui->labelProfil_PrenomARemplir->setText(prenom);
}

void MainWindow::on_pushButtonProfil_Enregistrer_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProfil_Enregistrer_clicked()";
    QString requeteUpdateUtilisateur = "UPDATE `Utilisateur` SET "
    "`login`='"+ui->lineEditProfil_Login->text()+"',"
    "`adresse`='"+ui->lineEditProfil_Adresse->text()+"',"
    "`ville`='"+ui->lineEditProfil_Ville->text()+"',"
    "`codePostal`='"+ui->lineEditProfil_CodePostal->text()+"',"
    "`telephone`='"+ui->lineEditProfil_Telephone->text()+"',"
    "`motDePasse`=PASSWORD('"+ui->lineEditProfil_password->text()+"'),"
    "`mail`='"+ui->lineEditProfil_Mail->text()+"'"
    " WHERE numUtilisateur = '"+QString::number(idUtilisateur)+"';";
    qDebug()<<"requeteUpdateUtilisateur : "<<requeteUpdateUtilisateur;

    QSqlQuery requeteUpdate(requeteUpdateUtilisateur);
}
