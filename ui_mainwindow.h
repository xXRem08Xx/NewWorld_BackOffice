/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidgetGlobal;
    QWidget *tabProfil;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_Profil;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_18;
    QVBoxLayout *verticalLayout_Info;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelLogin;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditProfil_Login;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelNom;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelProfil_NomARemplir;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPrenom;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelProfil_PrenomARemplir;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelAdresse;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEditProfil_Adresse;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelVille;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEditProfil_Ville;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelCodePostal;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEditProfil_CodePostal;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelTelephone;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEditProfil_Telephone;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelMail;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEditProfil_Mail;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButtonProfil_Enregistrer_Info;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonProfil_Annuler_Info;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_Mdp;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *labelProfil_Avertissement;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelProfil_password;
    QLineEdit *lineEditProfil_password;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelProfil_password_2;
    QLineEdit *lineEditProfil_passwordConfirm;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButtonProfil_Enregistrer_Mdp;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButtonProfil_Annuler_Mdp;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer_9;
    QWidget *tabVerification;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidgetVerification;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableWidgetProducteur_producteurAttenteValidation;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_23;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QCheckBox *checkBoxConsultRegistre;
    QCheckBox *checkBoxContactTel;
    QCheckBox *checkBoxVisiteExploitation;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_20;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButtonProducteur_EnAttente_Valider;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButtonProducteur_EnAttente_Refuser;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_13;
    QWidget *tab_3;
    QWidget *tab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(894, 853);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Images/backOffice_logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tabWidgetGlobal = new QTabWidget(centralWidget);
        tabWidgetGlobal->setObjectName(QStringLiteral("tabWidgetGlobal"));
        QFont font;
        font.setPointSize(13);
        font.setItalic(true);
        tabWidgetGlobal->setFont(font);
        tabWidgetGlobal->setIconSize(QSize(25, 25));
        tabProfil = new QWidget();
        tabProfil->setObjectName(QStringLiteral("tabProfil"));
        horizontalLayout_13 = new QHBoxLayout(tabProfil);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_Profil = new QVBoxLayout();
        verticalLayout_Profil->setSpacing(6);
        verticalLayout_Profil->setObjectName(QStringLiteral("verticalLayout_Profil"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);

        verticalLayout_Info = new QVBoxLayout();
        verticalLayout_Info->setSpacing(6);
        verticalLayout_Info->setObjectName(QStringLiteral("verticalLayout_Info"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelLogin = new QLabel(tabProfil);
        labelLogin->setObjectName(QStringLiteral("labelLogin"));

        horizontalLayout_2->addWidget(labelLogin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEditProfil_Login = new QLineEdit(tabProfil);
        lineEditProfil_Login->setObjectName(QStringLiteral("lineEditProfil_Login"));

        horizontalLayout_2->addWidget(lineEditProfil_Login);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelNom = new QLabel(tabProfil);
        labelNom->setObjectName(QStringLiteral("labelNom"));

        horizontalLayout_3->addWidget(labelNom);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        labelProfil_NomARemplir = new QLabel(tabProfil);
        labelProfil_NomARemplir->setObjectName(QStringLiteral("labelProfil_NomARemplir"));

        horizontalLayout_3->addWidget(labelProfil_NomARemplir);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelPrenom = new QLabel(tabProfil);
        labelPrenom->setObjectName(QStringLiteral("labelPrenom"));

        horizontalLayout_4->addWidget(labelPrenom);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        labelProfil_PrenomARemplir = new QLabel(tabProfil);
        labelProfil_PrenomARemplir->setObjectName(QStringLiteral("labelProfil_PrenomARemplir"));

        horizontalLayout_4->addWidget(labelProfil_PrenomARemplir);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelAdresse = new QLabel(tabProfil);
        labelAdresse->setObjectName(QStringLiteral("labelAdresse"));

        horizontalLayout_5->addWidget(labelAdresse);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lineEditProfil_Adresse = new QLineEdit(tabProfil);
        lineEditProfil_Adresse->setObjectName(QStringLiteral("lineEditProfil_Adresse"));

        horizontalLayout_5->addWidget(lineEditProfil_Adresse);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelVille = new QLabel(tabProfil);
        labelVille->setObjectName(QStringLiteral("labelVille"));

        horizontalLayout_6->addWidget(labelVille);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEditProfil_Ville = new QLineEdit(tabProfil);
        lineEditProfil_Ville->setObjectName(QStringLiteral("lineEditProfil_Ville"));

        horizontalLayout_6->addWidget(lineEditProfil_Ville);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelCodePostal = new QLabel(tabProfil);
        labelCodePostal->setObjectName(QStringLiteral("labelCodePostal"));

        horizontalLayout_7->addWidget(labelCodePostal);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        lineEditProfil_CodePostal = new QLineEdit(tabProfil);
        lineEditProfil_CodePostal->setObjectName(QStringLiteral("lineEditProfil_CodePostal"));

        horizontalLayout_7->addWidget(lineEditProfil_CodePostal);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelTelephone = new QLabel(tabProfil);
        labelTelephone->setObjectName(QStringLiteral("labelTelephone"));

        horizontalLayout_8->addWidget(labelTelephone);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        lineEditProfil_Telephone = new QLineEdit(tabProfil);
        lineEditProfil_Telephone->setObjectName(QStringLiteral("lineEditProfil_Telephone"));

        horizontalLayout_8->addWidget(lineEditProfil_Telephone);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelMail = new QLabel(tabProfil);
        labelMail->setObjectName(QStringLiteral("labelMail"));

        horizontalLayout_9->addWidget(labelMail);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        lineEditProfil_Mail = new QLineEdit(tabProfil);
        lineEditProfil_Mail->setObjectName(QStringLiteral("lineEditProfil_Mail"));

        horizontalLayout_9->addWidget(lineEditProfil_Mail);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_Info->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Info->addItem(verticalSpacer_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        pushButtonProfil_Enregistrer_Info = new QPushButton(tabProfil);
        pushButtonProfil_Enregistrer_Info->setObjectName(QStringLiteral("pushButtonProfil_Enregistrer_Info"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Images/sauvegarder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonProfil_Enregistrer_Info->setIcon(icon1);

        horizontalLayout_10->addWidget(pushButtonProfil_Enregistrer_Info);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        pushButtonProfil_Annuler_Info = new QPushButton(tabProfil);
        pushButtonProfil_Annuler_Info->setObjectName(QStringLiteral("pushButtonProfil_Annuler_Info"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/Images/annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonProfil_Annuler_Info->setIcon(icon2);

        horizontalLayout_10->addWidget(pushButtonProfil_Annuler_Info);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_Info->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Info->addItem(verticalSpacer);


        horizontalLayout_12->addLayout(verticalLayout_Info);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_17);

        verticalLayout_Mdp = new QVBoxLayout();
        verticalLayout_Mdp->setSpacing(6);
        verticalLayout_Mdp->setObjectName(QStringLiteral("verticalLayout_Mdp"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        labelProfil_Avertissement = new QLabel(tabProfil);
        labelProfil_Avertissement->setObjectName(QStringLiteral("labelProfil_Avertissement"));
        labelProfil_Avertissement->setStyleSheet(QStringLiteral(""));

        verticalLayout_5->addWidget(labelProfil_Avertissement);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelProfil_password = new QLabel(tabProfil);
        labelProfil_password->setObjectName(QStringLiteral("labelProfil_password"));

        verticalLayout_2->addWidget(labelProfil_password);

        lineEditProfil_password = new QLineEdit(tabProfil);
        lineEditProfil_password->setObjectName(QStringLiteral("lineEditProfil_password"));

        verticalLayout_2->addWidget(lineEditProfil_password);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelProfil_password_2 = new QLabel(tabProfil);
        labelProfil_password_2->setObjectName(QStringLiteral("labelProfil_password_2"));

        verticalLayout_3->addWidget(labelProfil_password_2);

        lineEditProfil_passwordConfirm = new QLineEdit(tabProfil);
        lineEditProfil_passwordConfirm->setObjectName(QStringLiteral("lineEditProfil_passwordConfirm"));

        verticalLayout_3->addWidget(lineEditProfil_passwordConfirm);


        verticalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_Mdp->addLayout(verticalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Mdp->addItem(verticalSpacer_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        pushButtonProfil_Enregistrer_Mdp = new QPushButton(tabProfil);
        pushButtonProfil_Enregistrer_Mdp->setObjectName(QStringLiteral("pushButtonProfil_Enregistrer_Mdp"));
        pushButtonProfil_Enregistrer_Mdp->setIcon(icon1);

        horizontalLayout_11->addWidget(pushButtonProfil_Enregistrer_Mdp);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);

        pushButtonProfil_Annuler_Mdp = new QPushButton(tabProfil);
        pushButtonProfil_Annuler_Mdp->setObjectName(QStringLiteral("pushButtonProfil_Annuler_Mdp"));
        pushButtonProfil_Annuler_Mdp->setIcon(icon2);

        horizontalLayout_11->addWidget(pushButtonProfil_Annuler_Mdp);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_Mdp->addLayout(horizontalLayout_11);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Mdp->addItem(verticalSpacer_7);


        horizontalLayout_12->addLayout(verticalLayout_Mdp);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_19);


        verticalLayout_7->addLayout(horizontalLayout_12);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_9);


        verticalLayout_Profil->addLayout(verticalLayout_7);


        horizontalLayout_13->addLayout(verticalLayout_Profil);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/Images/Profil.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetGlobal->addTab(tabProfil, icon3, QString());
        tabVerification = new QWidget();
        tabVerification->setObjectName(QStringLiteral("tabVerification"));
        verticalLayout_4 = new QVBoxLayout(tabVerification);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidgetVerification = new QTabWidget(tabVerification);
        tabWidgetVerification->setObjectName(QStringLiteral("tabWidgetVerification"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_10 = new QVBoxLayout(tab_2);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tableWidgetProducteur_producteurAttenteValidation = new QTableWidget(tab_2);
        tableWidgetProducteur_producteurAttenteValidation->setObjectName(QStringLiteral("tableWidgetProducteur_producteurAttenteValidation"));
        tableWidgetProducteur_producteurAttenteValidation->setMinimumSize(QSize(0, 350));
        tableWidgetProducteur_producteurAttenteValidation->setAutoScroll(true);
        tableWidgetProducteur_producteurAttenteValidation->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetProducteur_producteurAttenteValidation->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetProducteur_producteurAttenteValidation->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_10->addWidget(tableWidgetProducteur_producteurAttenteValidation);

        verticalSpacer_12 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_23);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_9->addWidget(label);

        checkBoxConsultRegistre = new QCheckBox(tab_2);
        checkBoxConsultRegistre->setObjectName(QStringLiteral("checkBoxConsultRegistre"));

        verticalLayout_9->addWidget(checkBoxConsultRegistre);

        checkBoxContactTel = new QCheckBox(tab_2);
        checkBoxContactTel->setObjectName(QStringLiteral("checkBoxContactTel"));

        verticalLayout_9->addWidget(checkBoxContactTel);

        checkBoxVisiteExploitation = new QCheckBox(tab_2);
        checkBoxVisiteExploitation->setObjectName(QStringLiteral("checkBoxVisiteExploitation"));

        verticalLayout_9->addWidget(checkBoxVisiteExploitation);


        horizontalLayout_15->addLayout(verticalLayout_9);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_24);


        verticalLayout_10->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_20);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);

        pushButtonProducteur_EnAttente_Valider = new QPushButton(tab_2);
        pushButtonProducteur_EnAttente_Valider->setObjectName(QStringLiteral("pushButtonProducteur_EnAttente_Valider"));

        horizontalLayout->addWidget(pushButtonProducteur_EnAttente_Valider);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        pushButtonProducteur_EnAttente_Refuser = new QPushButton(tab_2);
        pushButtonProducteur_EnAttente_Refuser->setObjectName(QStringLiteral("pushButtonProducteur_EnAttente_Refuser"));

        horizontalLayout->addWidget(pushButtonProducteur_EnAttente_Refuser);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_22);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_11);


        horizontalLayout_14->addLayout(verticalLayout_8);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_21);


        verticalLayout_10->addLayout(horizontalLayout_14);

        verticalSpacer_13 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_13);

        tabWidgetVerification->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidgetVerification->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidgetVerification);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/Images/verification.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidgetGlobal->addTab(tabVerification, icon4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidgetGlobal->addTab(tab, QString());

        verticalLayout_6->addWidget(tabWidgetGlobal);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 894, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidgetGlobal->setCurrentIndex(1);
        tabWidgetVerification->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BackOffice", nullptr));
        labelLogin->setText(QApplication::translate("MainWindow", "Login : ", nullptr));
        labelNom->setText(QApplication::translate("MainWindow", "Nom : ", nullptr));
        labelProfil_NomARemplir->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPrenom->setText(QApplication::translate("MainWindow", "Prenom : ", nullptr));
        labelProfil_PrenomARemplir->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelAdresse->setText(QApplication::translate("MainWindow", "Adresse : ", nullptr));
        labelVille->setText(QApplication::translate("MainWindow", "Ville : ", nullptr));
        labelCodePostal->setText(QApplication::translate("MainWindow", "Code Postal : ", nullptr));
        labelTelephone->setText(QApplication::translate("MainWindow", "Telephone : ", nullptr));
        labelMail->setText(QApplication::translate("MainWindow", "Mail : ", nullptr));
        pushButtonProfil_Enregistrer_Info->setText(QApplication::translate("MainWindow", "Enregistrer", nullptr));
        pushButtonProfil_Annuler_Info->setText(QApplication::translate("MainWindow", " Annuler", nullptr));
        labelProfil_Avertissement->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelProfil_password->setText(QApplication::translate("MainWindow", "Nouveau Mot de Passe : ", nullptr));
        labelProfil_password_2->setText(QApplication::translate("MainWindow", "Confirmer Mot de Passe : ", nullptr));
        pushButtonProfil_Enregistrer_Mdp->setText(QApplication::translate("MainWindow", "Enregistrer", nullptr));
        pushButtonProfil_Annuler_Mdp->setText(QApplication::translate("MainWindow", " Annuler", nullptr));
        tabWidgetGlobal->setTabText(tabWidgetGlobal->indexOf(tabProfil), QApplication::translate("MainWindow", "Profil", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Element(s) de verification effectu\303\251(s) : </p><p><br/></p></body></html>", nullptr));
        checkBoxConsultRegistre->setText(QApplication::translate("MainWindow", "Consultation Registre", nullptr));
        checkBoxContactTel->setText(QApplication::translate("MainWindow", "Contact Telephonique", nullptr));
        checkBoxVisiteExploitation->setText(QApplication::translate("MainWindow", "Visite de l'exploitation", nullptr));
        pushButtonProducteur_EnAttente_Valider->setText(QApplication::translate("MainWindow", "Valider", nullptr));
        pushButtonProducteur_EnAttente_Refuser->setText(QApplication::translate("MainWindow", "Refuser", nullptr));
        tabWidgetVerification->setTabText(tabWidgetVerification->indexOf(tab_2), QApplication::translate("MainWindow", "En Attente", nullptr));
        tabWidgetVerification->setTabText(tabWidgetVerification->indexOf(tab_3), QApplication::translate("MainWindow", "Liste Producteur", nullptr));
        tabWidgetGlobal->setTabText(tabWidgetGlobal->indexOf(tabVerification), QApplication::translate("MainWindow", "Producteur", nullptr));
        tabWidgetGlobal->setTabText(tabWidgetGlobal->indexOf(tab), QApplication::translate("MainWindow", "Administration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
