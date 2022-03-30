#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int identifiantUtilisateur, QWidget *parent = nullptr);

    bool quitConfirm();
    void closeEvent(QCloseEvent *event);
    void getPlaceInfoUtilisateur(int id);
    void createLigne(QTableWidget *tableau);
    void createColonne(QString nomColonne, QTableWidget *tableau);
    void createTableColonne(QString nomDeLaTable, QTableWidget *tableau);
    void verifProducteur();
    void listerProducteur();
    void listerInvalidation();
    void listerInactif();

    ~MainWindow();

private slots:
    void on_pushButtonProfil_Enregistrer_Info_clicked();

    void on_pushButtonProfil_Annuler_Info_clicked();

    void on_pushButtonProfil_Enregistrer_Mdp_clicked();

    void on_pushButtonProfil_Annuler_Mdp_clicked();

    void on_pushButtonProducteur_EnAttente_Valider_clicked();

    void on_tableWidgetProducteur_producteurAttenteValidation_itemSelectionChanged();

    void on_pushButtonProducteur_listeProducteur_Actif_clicked();

    void on_tableWidgetProducteur_listeProducteur_itemSelectionChanged();

    void on_pushButtonProducteur_listeProducteur_Inactif_clicked();

    void on_pushButtonProducteur_EnAttente_Refuser_clicked();

    void on_pushButton_listeProducteur_actualiser_clicked();

    void on_pushButtonProducteur_listeInvalidation_Actif_clicked();

    void on_pushButton_listeInvalidation_actualiser_clicked();

    void on_pushButtonInvalidation_changeRaison_clicked();

    void on_tableWidgetProducteur_listeInvalidation_itemSelectionChanged();

    void on_pushButtonProducteur_listeProducteurInactif_activation_clicked();

    void on_pushButton_listeProducteurInactif_actualiser_clicked();

    void on_tableWidgetProducteur_listeProducteurInactif_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    int idUtilisateur;
    int numLigneProdValidSelectionne = -1;
    int numLigneProdUnvalidSelectionne = -1;

    QString login;
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    QString codePostal;
    QString telephone;
    QString mail;
    QString idRole;
    bool boolLabelProfil_Avertissement = false;

    //si on a pas selectionné de ligne c'est false
    bool listProducteurRowSelected = false;
    bool producteurEnAttente = false;
    bool listProducteurInvalideRowSelected = false;
    bool listProducteurInactifRowSelected = false;

};

#endif // MAINWINDOW_H
