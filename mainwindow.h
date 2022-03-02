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

    ~MainWindow();

private slots:
    void on_pushButtonProfil_Enregistrer_clicked();

    void on_pushButtonProfil_Annuler_clicked();

private:
    Ui::MainWindow *ui;
    int idUtilisateur;

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

};

#endif // MAINWINDOW_H
