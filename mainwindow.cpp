#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "producteurrefuser.h"
#include "QString"
#include "QDebug"
#include "QSqlQuery"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMessageBox>
#include <QCloseEvent>
#include <QHeaderView>
#include <QFileDialog>
#include <QImage>
#include <QChar>


MainWindow::MainWindow(int identifiantUtilisateur ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    idUtilisateur = identifiantUtilisateur;

    ui->setupUi(this);
    ui->labelProfil_Avertissement->setText("");



    //on execute les fonctions de remplissage des fenetres
    getPlaceInfoUtilisateur(identifiantUtilisateur);
    //liste des producteur en attente de verification
    verifProducteur();
    //liste des producteurs sauf ceux en attente
    listerProducteur();
    listerInactif();
    listerInvalidation();

    //on affiche la liste des produit
    afficheRayon();
    afficheCategorie();
    comboBoxCategorie();


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
void MainWindow::on_pushButtonProfil_Enregistrer_Info_clicked()
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

/**
 * @brief Cette fonction sert a remettre les valeurs de base inscrite dans la base de données pour effacer les modifications de texte que
 * l'utilisateur aurai pu faire
 */
void MainWindow::on_pushButtonProfil_Annuler_Info_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProfil_Annuler_clicked()";

    ui->lineEditProfil_Login->setText(login);
    ui->lineEditProfil_Ville->setText(ville);
    ui->lineEditProfil_Mail->setText(mail);
    ui->lineEditProfil_Adresse->setText(adresse);
    ui->lineEditProfil_Telephone->setText(telephone);
    ui->lineEditProfil_CodePostal->setText(codePostal);
}


/**
 * @brief insertion d'une nouvelle ligne dans le TableWidget
 */
void MainWindow::createLigne(QTableWidget *tableau)
{
    //qDebug()<<"MainWindow::createLigne";

    tableau->insertRow(tableau->rowCount());
}

/**
 * @brief Insertion d'une colonne dans le TableWidget et modifie son nom
 * @param nomColonne : Contient le nom de la colonne a mettre dans la colonne qui va etre créé
 */
void MainWindow::createColonne(QString nomColonne, QTableWidget *tableau)
{
    //qDebug()<<"MainWindow::createColonne";

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

    ui->tableWidgetProducteur_producteurAttenteValidation->setColumnCount(0);
    //Creer les colonnes de la table Producteur dans le tableWidget
    createTableColonne("Producteur", ui->tableWidgetProducteur_producteurAttenteValidation);

    QString requeteProducteur = "SELECT * FROM `Producteur` "
                                "WHERE `identifiantTypeAbonnement` = 2";
    qDebug()<<"requeteProducteur"<<requeteProducteur;

    QSqlQuery resultatRequete(requeteProducteur);


    //tant qu'on a une ligne de resultat a traiter
    while (resultatRequete.next())
    {
        //on créé une ligne dans le tableWidget
        createLigne(ui->tableWidgetProducteur_producteurAttenteValidation);

        int numLigne = ui->tableWidgetProducteur_producteurAttenteValidation->rowCount()-1;

        QString requeteColonne = "DESC Producteur";
        qDebug()<<"requeteColonne = "<<requeteColonne;
        QSqlQuery query(requeteColonne);

        //on definie un num de colonne qui sera reset a chaque passage de la boucle
        int numColonne = 0;
        while (query.next())
        {
            ui->tableWidgetProducteur_producteurAttenteValidation->setItem(numLigne,numColonne, new QTableWidgetItem(resultatRequete.value(query.value(0).toString() ).toString() ) );
            //on augmente la colonne
            numColonne++;
        }
    }

    //on modifie l'affichage des colonnes pour une meilleur visibilité
    ui->tableWidgetProducteur_producteurAttenteValidation->resizeColumnsToContents();
    ui->tableWidgetProducteur_producteurAttenteValidation->resizeRowsToContents();

}

void MainWindow::listerProducteur()
{
    qDebug()<<"MainWindow::listerProducteur";

    ui->tableWidgetProducteur_listeProducteur->setColumnCount(0);

    int nombreDeLigne = ui->tableWidgetProducteur_listeProducteur->rowCount();

    //on supprime toutes les colonnes si il y en a
    for(int compteur = 0; compteur < nombreDeLigne; compteur++)
    {
        ui->tableWidgetProducteur_listeProducteur->removeRow(0);
    }

    //Creer les colonnes de la table Producteur dans le tableWidget
    createTableColonne("Producteur", ui->tableWidgetProducteur_listeProducteur);

    QString requeteProducteur = "SELECT * FROM `Producteur` "
                                "WHERE `identifiantTypeAbonnement` = 1 && `actif` = 1";
    qDebug()<<"requeteProducteur"<<requeteProducteur;

    QSqlQuery resultatRequete(requeteProducteur);


    //tant qu'on a une ligne de resultat a traiter
    while (resultatRequete.next())
    {
        //on créé une ligne dans le tableWidget
        createLigne(ui->tableWidgetProducteur_listeProducteur);

        int numLigne = ui->tableWidgetProducteur_listeProducteur->rowCount()-1;

        QString requeteColonne = "DESC Producteur";
        qDebug()<<"requeteColonne = "<<requeteColonne;
        QSqlQuery query(requeteColonne);

        //on definie un num de colonne qui sera reset a chaque passage de la boucle
        int numColonne = 0;
        while (query.next())
        {
            ui->tableWidgetProducteur_listeProducteur->setItem(numLigne,numColonne, new QTableWidgetItem(resultatRequete.value(query.value(0).toString() ).toString() ) );
            //on augmente la colonne
            numColonne++;
        }

    }
    //on modifie l'affichage des colonnes pour une meilleur visibilité
    ui->tableWidgetProducteur_listeProducteur->resizeColumnsToContents();
    ui->tableWidgetProducteur_listeProducteur->resizeRowsToContents();
}

void MainWindow::listerInvalidation()
{
    qDebug()<<"MainWindow::listerInvalidation";

    ui->tableWidgetProducteur_listeInvalidation->setColumnCount(0);

    int nombreDeLigne = ui->tableWidgetProducteur_listeInvalidation->rowCount();

    //on supprime toutes les colonnes si il y en a
    for(int compteur = 0; compteur < nombreDeLigne; compteur++)
    {
        ui->tableWidgetProducteur_listeInvalidation->removeRow(0);
    }

    //Creer les colonnes de la table Producteur dans le tableWidget
    createTableColonne("Producteur", ui->tableWidgetProducteur_listeInvalidation);

    QString requeteProducteur = "SELECT * FROM `Producteur` "
                                "WHERE `identifiantTypeAbonnement` = 3";
    qDebug()<<"requeteProducteur"<<requeteProducteur;

    QSqlQuery resultatRequete(requeteProducteur);


    //tant qu'on a une ligne de resultat a traiter
    while (resultatRequete.next())
    {
        //on créé une ligne dans le tableWidget
        createLigne(ui->tableWidgetProducteur_listeInvalidation);

        int numLigne = ui->tableWidgetProducteur_listeInvalidation->rowCount()-1;

        QString requeteColonne = "DESC Producteur";
        qDebug()<<"requeteColonne = "<<requeteColonne;
        QSqlQuery query(requeteColonne);

        //on definie un num de colonne qui sera reset a chaque passage de la boucle
        int numColonne = 0;
        while (query.next())
        {
            ui->tableWidgetProducteur_listeInvalidation->setItem(numLigne,numColonne, new QTableWidgetItem(resultatRequete.value(query.value(0).toString() ).toString() ) );
            //on augmente la colonne
            numColonne++;
        }

    }
    //on modifie l'affichage des colonnes pour une meilleur visibilité
    ui->tableWidgetProducteur_listeInvalidation->resizeColumnsToContents();
    ui->tableWidgetProducteur_listeInvalidation->resizeRowsToContents();
}

void MainWindow::listerInactif()
{
    qDebug()<<"MainWindow::listerInactif";

    ui->tableWidgetProducteur_listeProducteurInactif->setColumnCount(0);

    int nombreDeLigne = ui->tableWidgetProducteur_listeProducteurInactif->rowCount();

    //on supprime toutes les colonnes si il y en a
    for(int compteur = 0; compteur < nombreDeLigne; compteur++)
    {
        ui->tableWidgetProducteur_listeProducteurInactif->removeRow(0);
    }

    //Creer les colonnes de la table Producteur dans le tableWidget
    createTableColonne("Producteur", ui->tableWidgetProducteur_listeProducteurInactif);

    QString requeteProducteur = "SELECT * FROM `Producteur` "
                                "WHERE `identifiantTypeAbonnement` = 1 && `actif` = 0";
    qDebug()<<"requeteProducteur"<<requeteProducteur;

    QSqlQuery resultatRequete(requeteProducteur);


    //tant qu'on a une ligne de resultat a traiter
    while (resultatRequete.next())
    {
        //on créé une ligne dans le tableWidget
        createLigne(ui->tableWidgetProducteur_listeProducteurInactif);

        int numLigne = ui->tableWidgetProducteur_listeProducteurInactif->rowCount()-1;

        QString requeteColonne = "DESC Producteur";
        qDebug()<<"requeteColonne = "<<requeteColonne;
        QSqlQuery query(requeteColonne);

        //on definie un num de colonne qui sera reset a chaque passage de la boucle
        int numColonne = 0;
        while (query.next())
        {
            ui->tableWidgetProducteur_listeProducteurInactif->setItem(numLigne,numColonne, new QTableWidgetItem(resultatRequete.value(query.value(0).toString() ).toString() ) );
            //on augmente la colonne
            numColonne++;
        }

    }
    //on modifie l'affichage des colonnes pour une meilleur visibilité
    ui->tableWidgetProducteur_listeProducteurInactif->resizeColumnsToContents();
    ui->tableWidgetProducteur_listeProducteurInactif->resizeRowsToContents();
}



/**
 * @brief Cette fonction sert a enregistrer le mot de passe qui a été changé
 */
void MainWindow::on_pushButtonProfil_Enregistrer_Mdp_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProfil_Enregistrer_Mdp_clicked";

    //si la confirmation du mot de passe est la meme que celle renseigné au dessus
    if (ui->lineEditProfil_password->text() == ui->lineEditProfil_passwordConfirm->text())
    {
        ui->labelProfil_Avertissement->setText("Votre mot de passe a été modifié");

        QString commandePassword = "UPDATE `Utilisateur` SET `motDePasse` = PASSWORD('" + ui->lineEditProfil_password->text()+"') WHERE numUtilisateur = "+QString::number(idUtilisateur)+";";
        qDebug()<<"commandePassword = "<<commandePassword;

        QSqlQuery resultatCommandePassword(commandePassword);
    }
    else {
        ui->labelProfil_Avertissement->setText("Votre mot de passe n'est pas identique a la confirmation !");
        boolLabelProfil_Avertissement = true;
    }
}

/**
 * @brief Cette fonction sert a remettre les champs de saisi des mot de passe a vide
 */
void MainWindow::on_pushButtonProfil_Annuler_Mdp_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProfil_Annuler_Mdp_clicked";

    ui->lineEditProfil_password->setText("");
    ui->lineEditProfil_passwordConfirm->setText("");
}


void MainWindow::on_pushButtonProducteur_EnAttente_Valider_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProducteur_EnAttente_Valider_clicked";

    QString requeteValidationProducteur = "UPDATE `Producteur` SET identifiantTypeAbonnement = 1, ";

    //si au moins 1 checkBox est cochée
    if(ui->checkBoxConsultRegistre->isChecked() || ui->checkBoxContactTel->isChecked() || ui->checkBoxVisiteExploitation->isChecked() || ui->checkBoxAnnuaire->isChecked())
    {
        //si le numero de la ligne est different que sa valeur de depart --> signifie qu'une ligne a été selectionné
        if(numLigneProdValidSelectionne != -1)
        {
            //suivant les checkBox qui sont coché on insere dans la requete les champs a changer
            if(ui->checkBoxConsultRegistre->isChecked())
            {
                requeteValidationProducteur += "consultationRegistre = 1, ";
            }
            if(ui->checkBoxContactTel->isChecked())
            {
                requeteValidationProducteur += "contactTelephonique = 1, ";
            }
            if(ui->checkBoxVisiteExploitation->isChecked())
            {
                requeteValidationProducteur += "VisiteExploitation = 1, ";
            }
            if(ui->checkBoxAnnuaire->isChecked())
            {
                requeteValidationProducteur += "consultationAnnuaire = 1, ";
            }

            //supprime les 2 derniers caracteres pour enlever ", "
            requeteValidationProducteur = requeteValidationProducteur.remove(requeteValidationProducteur.size()-2, 2);

            //on termine la requete
            requeteValidationProducteur += " WHERE `identifiantProducteur` = " + ui->tableWidgetProducteur_producteurAttenteValidation->item(numLigneProdValidSelectionne,0)->text() + ";";

            qDebug()<<"requeteValidationProducteur = "<<requeteValidationProducteur;
            QSqlQuery resultatRequeteValidation(requeteValidationProducteur);

            //on supprime la ligne du tableWidget
            ui->tableWidgetProducteur_producteurAttenteValidation->removeRow(numLigneProdValidSelectionne);

            //on decoche toutes les checkBox
            ui->checkBoxConsultRegistre->setChecked(false);
            ui->checkBoxContactTel->setChecked(false);
            ui->checkBoxVisiteExploitation->setChecked(false);
            ui->checkBoxAnnuaire->setChecked(false);

            listerInactif();
            listerInvalidation();
            listerProducteur();
        }
        else {
            ui->statusBar->showMessage("Veuillez selectionner une ligne dans le tableau.",10000);
        }
    }

    else {
        ui->statusBar->showMessage("Merci de cocher au moins une checkBox avant de valider",10000);
    }
}


void MainWindow::on_tableWidgetProducteur_producteurAttenteValidation_itemSelectionChanged()
{
    qDebug()<<"MainWindow::on_tableWidgetProducteur_producteurAttenteValidation_itemSelectionChanged";

    numLigneProdValidSelectionne = ui->tableWidgetProducteur_producteurAttenteValidation->currentRow();
    producteurEnAttente = true;
}


void MainWindow::on_pushButtonProducteur_listeProducteur_Actif_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProducteur_listeProducteur_Actif_clicked";

    //on verifie si une ligne est selectionné
    if(listProducteurRowSelected)
    {
        int numLigne = ui->tableWidgetProducteur_listeProducteur->currentRow();
        int numProducteur = ui->tableWidgetProducteur_listeProducteur->item(numLigne,0)->text().toInt();

        qDebug()<<"numProducteur"<<numProducteur;

        QString requeteActif = "UPDATE `Producteur` SET `actif` = '1' WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
        QSqlQuery requeteProdActif(requeteActif);
    }
}


void MainWindow::on_tableWidgetProducteur_listeProducteur_itemSelectionChanged()
{
    qDebug()<<"on_tableWidgetProducteur_listeProducteur_itemSelectionChanged";

    listProducteurRowSelected = true;
}


void MainWindow::on_pushButtonProducteur_listeProducteur_Inactif_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProducteur_listeProducteur_Actif_clicked";

    //on verifie si une ligne est selectionné
    if(listProducteurRowSelected)
    {
        int numLigne = ui->tableWidgetProducteur_listeProducteur->currentRow();
        int numProducteur = ui->tableWidgetProducteur_listeProducteur->item(numLigne,0)->text().toInt();

        qDebug()<<"numProducteur"<<numProducteur;

        QString requeteActif = "UPDATE `Producteur` SET `actif` = '0' WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
        QSqlQuery requeteProdActif(requeteActif);

        ui->tableWidgetProducteur_listeProducteur->removeRow(numLigne);
        listerInactif();
    }
}


void MainWindow::on_pushButtonProducteur_EnAttente_Refuser_clicked()
{
    qDebug()<<"on_pushButtonProducteur_EnAttente_Refuser_clicked";

    //on verifie si une ligne est selectionné
    if(producteurEnAttente)
    {
        qDebug()<<"raisonARecup entré dans le if";

        int numLigne = ui->tableWidgetProducteur_producteurAttenteValidation->currentRow();
        int numProducteur = ui->tableWidgetProducteur_producteurAttenteValidation->item(numLigne,0)->text().toInt();

        //on execute la fenetre de refus
        ProducteurRefuser raisonARecup;

        if(raisonARecup.exec() == QDialog::Accepted)
        {
            QString raisonRefus = raisonARecup.getText();
            QString requeteRefus = "UPDATE Producteur SET raisonInvalidation = '"+raisonRefus+"', identifiantTypeAbonnement = 3"
                                                                                              " WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
            qDebug()<<"requeteRefus"<<requeteRefus;

            QSqlQuery requeteProdActif(requeteRefus);
        }
        ui->tableWidgetProducteur_producteurAttenteValidation->removeRow(ui->tableWidgetProducteur_producteurAttenteValidation->currentRow());
    }

}


void MainWindow::on_pushButton_listeProducteur_actualiser_clicked()
{
    qDebug()<<"on_pushButton_listeProducteur_actualiser_clicked";
    listerProducteur();
}


void MainWindow::on_pushButtonProducteur_listeInvalidation_Actif_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProducteur_listeInvalidation_Actif_clicked";

    //on verifie si une ligne est selectionné
    if(listProducteurInvalideRowSelected)
    {
        int numLigne = ui->tableWidgetProducteur_listeInvalidation->currentRow();
        int numProducteur = ui->tableWidgetProducteur_listeInvalidation->item(numLigne,0)->text().toInt();


        QString requeteActif = "UPDATE `Producteur` SET `actif` = '1' WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
        QSqlQuery requeteProdActif(requeteActif);

        qDebug()<<"requeteActif"<<requeteActif;
    }
}


void MainWindow::on_pushButton_listeInvalidation_actualiser_clicked()
{
    qDebug()<<"on_pushButton_listeInvalidation_actualiser_clicked";
    listerInvalidation();

}


void MainWindow::on_pushButtonInvalidation_changeRaison_clicked()
{
    qDebug()<<"on_pushButtonInvalidation_changeRaison_clicked";

    //on verifie si une ligne est selectionné
    if(listProducteurInvalideRowSelected)
    {
        qDebug()<<"raisonARecup entré dans le if";

        int numLigne = ui->tableWidgetProducteur_listeInvalidation->currentRow();
        int numProducteur = ui->tableWidgetProducteur_listeInvalidation->item(numLigne,0)->text().toInt();

        //on execute la fenetre de refus
        ProducteurRefuser raisonARecup;

        if(raisonARecup.exec() == QDialog::Accepted)
        {
            QString raisonRefus = raisonARecup.getText();
            QString requeteRefus = "UPDATE Producteur SET raisonInvalidation = '"+raisonRefus+"', identifiantTypeAbonnement = 3"
                                                                                              " WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
            qDebug()<<"requeteRefus"<<requeteRefus;

            QSqlQuery requeteProdActif(requeteRefus);

            ui->tableWidgetProducteur_listeInvalidation->item(numLigne, 14)->setText(raisonRefus);
            listerInvalidation();
        }
    }
}


void MainWindow::on_tableWidgetProducteur_listeInvalidation_itemSelectionChanged()
{
    qDebug()<<"on_tableWidgetProducteur_listeInvalidation_itemSelectionChanged";

    numLigneProdUnvalidSelectionne = ui->tableWidgetProducteur_listeInvalidation->currentRow();
    listProducteurInvalideRowSelected = true;
}


void MainWindow::on_pushButtonProducteur_listeProducteurInactif_activation_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonProducteur_listeProducteurInactif_activation_clicked";

    //on verifie si une ligne est selectionné
    if(listProducteurInactifRowSelected)
    {
        int numLigne = ui->tableWidgetProducteur_listeProducteurInactif->currentRow();
        int numProducteur = ui->tableWidgetProducteur_listeProducteurInactif->item(numLigne,0)->text().toInt();


        QString requeteActif = "UPDATE `Producteur` SET `actif` = '1' WHERE identifiantProducteur = "+QString::number(numProducteur)+";";
        QSqlQuery requeteProdActif(requeteActif);

        listerProducteur();
        qDebug()<<"requeteActif"<<requeteActif;

        ui->tableWidgetProducteur_listeProducteurInactif->removeRow(numLigne);
    }
}


void MainWindow::on_pushButton_listeProducteurInactif_actualiser_clicked()
{
    qDebug()<<"on_pushButton_listeProducteurInactif_actualiser_clicked";
    listerInactif();
}


void MainWindow::on_tableWidgetProducteur_listeProducteurInactif_itemSelectionChanged()
{
    qDebug()<<"on_tableWidgetProducteur_listeProducteurInactif_itemSelectionChanged";
    listProducteurInactifRowSelected = true;
}


/*** gestion Produit/categorie/rayon/varieté ***/

void MainWindow::afficheRayon()
{
    qDebug()<<"afficheRayon";

    ui->tableWidget_Rayon->setRowCount(0);
    ui->tableWidget_Rayon->setColumnCount(0);

    //on creer les titres des colonnes
    ui->tableWidget_Rayon->insertColumn(0);
    ui->tableWidget_Rayon->setHorizontalHeaderItem(0,new QTableWidgetItem("identifiant"));
    ui->tableWidget_Rayon->insertColumn(1);
    ui->tableWidget_Rayon->setHorizontalHeaderItem(1,new QTableWidgetItem("Image"));
    ui->tableWidget_Rayon->insertColumn(2);
    ui->tableWidget_Rayon->setHorizontalHeaderItem(2,new QTableWidgetItem("Nom"));
    QString txtRequeteAfficheRayon = "SELECT `identifiantRayon`, `libelle`, `lienImage` FROM `Rayon`;";
    QSqlQuery ExecutionRequeteAfficheRayon(txtRequeteAfficheRayon);

    //tant qu'on a une ligne de requete
    while(ExecutionRequeteAfficheRayon.next())
    {
        //on insere une ligne
        int ligne=ui->tableWidget_Rayon->rowCount();
        ui->tableWidget_Rayon->insertRow(ligne);

        QLabel *labelimage= new QLabel();
        labelimage->setPixmap(QPixmap(ExecutionRequeteAfficheRayon.value("lienImage").toString()).scaled(100,100));
        labelimage->setScaledContents(true);

        //on insere les valeur dans le tableau
        ui->tableWidget_Rayon->setItem(ligne,0, new QTableWidgetItem(ExecutionRequeteAfficheRayon.value("identifiantRayon").toString()));
        ui->tableWidget_Rayon->setItem(ligne,2, new QTableWidgetItem(ExecutionRequeteAfficheRayon.value("libelle").toString()));
        ui->tableWidget_Rayon->setCellWidget(ligne,1,labelimage);
    }
    ui->tableWidget_Rayon->resizeColumnsToContents();
    ui->tableWidget_Rayon->resizeRowsToContents();
    ui->tableWidget_Rayon->update();

    ui->label_image->setText("");
    ui->tableWidget_Rayon->resizeColumnsToContents();
    ui->tableWidget_Rayon->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::afficheCategorie()
{
    qDebug()<<"afficheCategorie";

    ui->tableWidget_Categorie->setRowCount(0);
    ui->tableWidget_Categorie->setColumnCount(0);

    //on creer les titres des colonnes
    ui->tableWidget_Categorie->insertColumn(0);
    ui->tableWidget_Categorie->setHorizontalHeaderItem(0,new QTableWidgetItem("identifiant"));
    ui->tableWidget_Categorie->insertColumn(1);
    ui->tableWidget_Categorie->setHorizontalHeaderItem(1,new QTableWidgetItem("Nom Categorie"));
    ui->tableWidget_Categorie->insertColumn(2);
    ui->tableWidget_Categorie->setHorizontalHeaderItem(2,new QTableWidgetItem("Nom Rayon"));

    QString txtRequeteAfficheCategorie = "SELECT `identifiantCategorie`, Categorie.`libelle` as libelle, Rayon.libelle as nomRayon FROM `Categorie`,`Rayon` WHERE Categorie.`identifiantRayon` = Rayon.identifiantRayon;";
    QSqlQuery ExecutionRequeteAfficheCategorie(txtRequeteAfficheCategorie);

    //tant qu'on a une ligne de requete
    while(ExecutionRequeteAfficheCategorie.next())
    {
        //on insere une ligne
        int ligne=ui->tableWidget_Categorie->rowCount();
        ui->tableWidget_Categorie->insertRow(ligne);

        //on insere les valeur dans le tableau
        ui->tableWidget_Categorie->setItem(ligne,0, new QTableWidgetItem(ExecutionRequeteAfficheCategorie.value("identifiantCategorie").toString()));
        ui->tableWidget_Categorie->setItem(ligne,1, new QTableWidgetItem(ExecutionRequeteAfficheCategorie.value("libelle").toString()));
        ui->tableWidget_Categorie->setItem(ligne,2, new QTableWidgetItem(ExecutionRequeteAfficheCategorie.value("nomRayon").toString()));

    }
    ui->tableWidget_Categorie->resizeColumnsToContents();
    ui->tableWidget_Categorie->resizeRowsToContents();
    ui->tableWidget_Categorie->update();

    ui->label_image->setText("");
    ui->tableWidget_Categorie->resizeColumnsToContents();
    ui->tableWidget_Categorie->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::comboBoxCategorie()
{
    qDebug()<<"comboBoxCategorie";

    QString requeteAfficheNumeroRayon="SELECT `libelle` FROM `Rayon`;";
    QSqlQuery afficheRayon(requeteAfficheNumeroRayon);

    ui->comboBox_selectionRayonCategorie->clear();
    while(afficheRayon.next())
    {
        QString libelle = afficheRayon.value("libelle").toString();
        ui->comboBox_selectionRayonCategorie->addItem(libelle);

    }
}

void MainWindow::on_pushButton_findRayon_clicked()
{
    qDebug()<<"on_pushButton_findRayon_clicked";
    ui->lineEdit_URLImageRayon->setText(QFileDialog::getOpenFileName(this,tr("Open PNG"),"/home/rmaissa/Images"));
    ui->label_image->setPixmap(QPixmap(ui->lineEdit_URLImageRayon->text()).scaled(150,150));

}


void MainWindow::on_pushButton_AjoutRayon_clicked()
{
    qDebug()<<"on_pushButton_AjoutRayon_clicked";
    QString nom,URLImage;
    nom = ui->lineEdit_NomRayon->text();
    URLImage = ui->lineEdit_URLImageRayon->text();

    QString txtRequeteSelectNumeroRayon = "select ifnull((select max(identifiantRayon)+1 from Rayon),1);";
    QSqlQuery requeteSelectNumeroRayon(txtRequeteSelectNumeroRayon);

    requeteSelectNumeroRayon.next();
    QString idRayon = requeteSelectNumeroRayon.value(0).toString();

    QString txtRequeteInsertionRayon = "INSERT INTO `Rayon`(`identifiantRayon`, `libelle`, `lienImage`) VALUES ("+idRayon+",'"+nom+"','"+URLImage+"');";
    qDebug()<<"txtRequeteInsertionRayon"<<txtRequeteInsertionRayon;

    if(!(nom.isEmpty() || URLImage.isEmpty())) {
        QSqlQuery requeteInsertionRayon(txtRequeteInsertionRayon);
    }
    //on met a jour
    afficheRayon();
    comboBoxCategorie();

}


void MainWindow::on_pushButton_ModifierRayon_clicked()
{
    qDebug()<<"on_pushButton_ModifierRayon_clicked";
    QString nom,urlImage;
    nom =  ui->lineEdit_NomRayon->text();
    urlImage = ui->lineEdit_URLImageRayon->text();

    QString requeteUpdateRayon = "UPDATE `Rayon` SET `libelle`='"+nom+"',`lienImage`='"+urlImage+"' WHERE `identifiantRayon` = "+ui->tableWidget_Rayon->selectedItems()[0]->text()+";";
    qDebug()<<requeteUpdateRayon;
    QSqlQuery executionUpdateRayon(requeteUpdateRayon);
    executionUpdateRayon.next();
    afficheRayon();
}


void MainWindow::on_tableWidget_Rayon_itemSelectionChanged()
{
    qDebug()<<"on_tableWidget_Rayon_itemSelectionChanged";

    if(!ui->tableWidget_Rayon->selectedItems().empty())
    {

        //on remplie les line edits
        ui->lineEdit_NomRayon->setText(ui->tableWidget_Rayon->selectedItems()[1]->text());
        //on va recuperer l'url de l'image
        QString requeteSelectURLImage="select lienImage from Rayon where identifiantRayon ="+ui->tableWidget_Rayon->selectedItems()[0]->text();
        QSqlQuery ExecutionRequeteSelectURLImage(requeteSelectURLImage);
        qDebug()<<"ExecutionRequeteSelectURLImage"<<requeteSelectURLImage;

        ExecutionRequeteSelectURLImage.next();

        //on insere le lien de l'image et l'affichage de l'image
        ui->lineEdit_URLImageRayon->setText(ExecutionRequeteSelectURLImage.value("lienImage").toString());
        ui->label_image->setPixmap(QPixmap(ExecutionRequeteSelectURLImage.value("lienImage").toString()).scaled(100,100));
    }
}


void MainWindow::on_pushButton_SupprimerRayon_clicked()
{
    qDebug()<<"on_pushButton_SupprimerRayon_clicked";

    //on recupere les valeurs
    QString nom,urlImage;
    nom =  ui->lineEdit_NomRayon->text();
    urlImage = ui->lineEdit_URLImageRayon->text();

    QString requeteSuppRayon = "DELETE FROM `Rayon` WHERE `identifiantRayon` = "+ui->tableWidget_Rayon->selectedItems()[0]->text();
    qDebug()<<requeteSuppRayon;
    QSqlQuery executionSuppRayon(requeteSuppRayon);
    executionSuppRayon.next();
    afficheRayon();
}


void MainWindow::on_pushButton_AjoutCategorie_clicked()
{
    qDebug()<<"on_pushButton_AjoutCategorie_clicked";

    QString nomCategorie, nomRayon;
    nomCategorie = ui->lineEdit_NomCategorie->text();
    nomRayon = ui->comboBox_selectionRayonCategorie->currentText();
    qDebug()<<"nomRayon"<<nomRayon;

    QString txtidRayon = "SELECT `identifiantRayon` FROM `Rayon` WHERE `libelle` = '"+nomRayon+"';";
    QSqlQuery requeteIdRayon(txtidRayon);
    requeteIdRayon.next();

    QString idRayon = requeteIdRayon.value(0).toString();

    QString txtRequeteInsertionCategorie = "INSERT INTO `Categorie`(`libelle`, `identifiantRayon`) VALUES ('"+nomCategorie+"','"+idRayon+"');";
    qDebug()<<"txtRequeteInsertionRayon"<<txtRequeteInsertionCategorie;

    if(!nomCategorie.isEmpty()) {
        QSqlQuery requeteInsertionCategorie(txtRequeteInsertionCategorie);
    }
    //on met a jour
    afficheCategorie();

}


void MainWindow::on_tableWidget_Categorie_itemSelectionChanged()
{
    qDebug()<<"on_tableWidget_Categorie_itemSelectionChanged";
    if(!ui->tableWidget_Categorie->selectedItems().empty())
    {
        //on remplie le line edit
        ui->lineEdit_NomCategorie->setText(ui->tableWidget_Categorie->selectedItems()[1]->text());
        ui->comboBox_selectionRayonCategorie->setCurrentText(ui->tableWidget_Categorie->selectedItems()[2]->text());
    }
}


void MainWindow::on_pushButton_ModifierCategorie_clicked()
{
    qDebug()<<"on_pushButton_ModifierCategorie_clicked";
    QString nomCategorie, nomRayon, idRayon;
    nomCategorie =  ui->lineEdit_NomCategorie->text();
    nomRayon =  ui->comboBox_selectionRayonCategorie->currentText();

    //on recupere l'id correspondant au libelle choisi dans la comboBox
    QString txtidRayon = "SELECT `identifiantRayon` FROM `Rayon` WHERE `libelle` = '"+nomRayon+"';";
    QSqlQuery requeteIdRayon(txtidRayon);
    requeteIdRayon.next();
    idRayon = requeteIdRayon.value(0).toString();


    QString requeteUpdateCategorie = "UPDATE `Categorie` SET `libelle`='"+nomCategorie+"', `identifiantRayon`='"+idRayon+"' WHERE `identifiantCategorie` = "+ui->tableWidget_Categorie->selectedItems()[0]->text();
    qDebug()<<requeteUpdateCategorie;
    QSqlQuery executionUpdateCategorie(requeteUpdateCategorie);
    executionUpdateCategorie.next();

    //on actualise
    afficheCategorie();
}


void MainWindow::on_pushButton_SupprimerCategorie_clicked()
{
    qDebug()<<"on_pushButton_SupprimerCategorie_clicked";

    QString nomCategorie, nomRayon, idRayon;
    nomCategorie =  ui->lineEdit_NomCategorie->text();
    nomRayon =  ui->comboBox_selectionRayonCategorie->currentText();

    //on recupere l'id correspondant au libelle choisi dans la comboBox
    QString txtidRayon = "SELECT `identifiantRayon` FROM `Rayon` WHERE `libelle` = '"+nomRayon+"';";
    QSqlQuery requeteIdRayon(txtidRayon);
    requeteIdRayon.next();
    idRayon = requeteIdRayon.value(0).toString();

    QString requeteSuppCategorie = "DELETE FROM `Categorie` WHERE `identifiantCategorie` = "+ui->tableWidget_Categorie->selectedItems()[0]->text();
    qDebug()<<requeteSuppCategorie;
    QSqlQuery executionSuppCategorie(requeteSuppCategorie);

    //on actualise
    afficheCategorie();
}

