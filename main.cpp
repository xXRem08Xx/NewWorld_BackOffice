#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("rmaissa_NewWorld");
    db.setUserName("rmaissa");
    db.setPassword("elini01");
    bool ok = db.open();


    Connexion seConnecter;

    //si la boite de dialogue renvoie accept()
    if(seConnecter.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        return 20;
    }
}
