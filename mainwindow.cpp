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
    ui->labelProfil_Avertissement->setText("");

    //on rempli la fenetre de profil
    getPlaceInfoUtilisateur(identifiantUtilisateur);
    verifProducteur();
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
/**
 * @brief Cette fonction sert a recuperer les informations personnelles de l'utilisateur et de les afficher dans la fenetre Profil
 * @param id : Int Contient l'id de l'utilisateur en cour
 */
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

/**
 * @brief Cette fonction permet d'enregistrer les informations ecrites dans les champs de saisi dans la base de données, enregistrant ainsi les
 * modifications effectuées si il y en a eu
 */
void MainWindow::on_pushButtonProfil_Enregistrer_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProfil_Enregistrer_clicked()";

    //si la confirmation du mot de passe est la meme que celle renseigné au dessus
    if (ui->lineEditProfil_password->text() == ui->lineEditProfil_passwordConfirm->text())
    {
        ui->labelProfil_Avertissement->setText("Votre mot de passe a été modifié");

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
    else {
        ui->labelProfil_Avertissement->setText("Votre mot de passe n'est pas identique a la confirmation !");
        boolLabelProfil_Avertissement = true;
    }
}

/**
 * @brief Cette fonction sert a remettre les valeurs de base inscrite dans la base de données pour effacer les modifications de texte que
 * l'utilisateur aurai pu faire
 */
void MainWindow::on_pushButtonProfil_Annuler_clicked()
{
     qDebug()<<"MainWindow::on_pushButtonProfil_Annuler_clicked()";

     ui->lineEditProfil_Login->setText(login);
     ui->lineEditProfil_Ville->setText(ville);
     ui->lineEditProfil_Mail->setText(mail);
     ui->lineEditProfil_Adresse->setText(adresse);
     ui->lineEditProfil_password->setText("");
     ui->lineEditProfil_Telephone->setText(telephone);
     ui->lineEditProfil_CodePostal->setText(codePostal);
     ui->lineEditProfil_passwordConfirm->setText("");
}


/**
 * @brief insertion d'une nouvelle ligne dans le TableWidget
 */
void MainWindow::createLigne(QTableWidget *tableau)
{
    qDebug()<<"MainWindow::createLigne";
    tableau->insertRow(tableau->rowCount());
}

/**
 * @brief Insertion d'une colonne dans le TableWidget et modifie son nom
 * @param nomColonne : Contient le nom de la colonne a mettre dans la colonne qui va etre créé
 */
void MainWindow::createColonne(QString nomColonne, QTableWidget *tableau)
{
    qDebug()<<"MainWindow::createColonne";
    //insert une nouvelle colonne
    tableau->insertColumn(tableau->columnCount());
    //modifie le nom de la colonne
    tableau->setHorizontalHeaderItem(tableau->columnCount()-1, new QTableWidgetItem (nomColonne));
}

/**
 * @brief Cette fonction permet de creer toutes les colonnes du QTableWidget passé en parametre, une pour chaque champs de la table que l'on souhaite afficher
 * @param nomDeLaTable : QString Contient le nom de la table que l'on souhaite afficher
 * @param tableau : QTableWidget Contient le QTableWidget où l'on souhaite creer les colonnes
 */
void MainWindow::createTableColonne(QString nomDeLaTable, QTableWidget *tableau)
{
    qDebug()<<"MainWindow::createTableColonne(QString nomDeLaTable)";
    QString requeteColonne = "DESC "+nomDeLaTable;
    qDebug()<<"requeteColonne = "<<requeteColonne;
    QSqlQuery query(requeteColonne);

    while (query.next())
    {
        createColonne(query.value(0).toString(), tableau);
    }
}

void MainWindow::verifProducteur()
{
    qDebug()<<"MainWindow::verifProducteur()";

    //Creer les colonnes de la table Producteur dans le tableWidget
    createTableColonne("Producteur", ui->tableWidgetVerification);
    createLigne(ui->tableWidgetVerification);

    QString requeteVerification = "SELECT `identifiantProducteur`, `nom`, `prenom`, `mail`, `telephone`, `adresse`, `horaire`, "
                                  "`dateEnregistrement`, `actif`, `identifiantTypeAbonnement` FROM `Producteur` "
                                  "WHERE `identifiantTypeAbonnement` = 2";
    QSqlQuery resultatRequete(requeteVerification);
    while (resultatRequete.next())
    {
        createLigne(ui->tableWidgetVerification);
        int numLigne = ui->tableWidgetVerification->rowCount()-1;

        ui->tableWidgetVerification->setItem(numLigne,)
    }
}
