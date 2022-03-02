#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);

    bool quitConfirm();
    void closeEvent(QCloseEvent *event);
    int getIdProfil();

    ~Connexion();

private slots:
    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

    void on_pushButtonQuitter_clicked();

private:
    Ui::Connexion *ui;
    QString login;
    QString password;
    int idUtilisateur;
};

#endif // CONNEXION_H
