/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Connexion
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelLogin;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditLogin;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelPassword;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditPassword;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;
    QLabel *labelConnexionError;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButtonValider;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButtonAnnuler;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonQuitter;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *Connexion)
    {
        if (Connexion->objectName().isEmpty())
            Connexion->setObjectName(QStringLiteral("Connexion"));
        Connexion->resize(628, 531);
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(13);
        font.setItalic(true);
        Connexion->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Images/backOffice_logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Connexion->setWindowIcon(icon);
        horizontalLayout_7 = new QHBoxLayout(Connexion);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label = new QLabel(Connexion);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Century Schoolbook L"));
        font1.setPointSize(32);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelLogin = new QLabel(Connexion);
        labelLogin->setObjectName(QStringLiteral("labelLogin"));

        horizontalLayout->addWidget(labelLogin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        lineEditLogin = new QLineEdit(Connexion);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));

        verticalLayout->addWidget(lineEditLogin);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        labelPassword = new QLabel(Connexion);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        horizontalLayout_2->addWidget(labelPassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEditPassword = new QLineEdit(Connexion);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));

        verticalLayout_2->addWidget(lineEditPassword);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        labelConnexionError = new QLabel(Connexion);
        labelConnexionError->setObjectName(QStringLiteral("labelConnexionError"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        labelConnexionError->setFont(font2);
        labelConnexionError->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(labelConnexionError);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        pushButtonValider = new QPushButton(Connexion);
        pushButtonValider->setObjectName(QStringLiteral("pushButtonValider"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Images/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonValider->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonValider);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        pushButtonAnnuler = new QPushButton(Connexion);
        pushButtonAnnuler->setObjectName(QStringLiteral("pushButtonAnnuler"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/Images/annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAnnuler->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonAnnuler);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButtonQuitter = new QPushButton(Connexion);
        pushButtonQuitter->setObjectName(QStringLiteral("pushButtonQuitter"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/Images/quitter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonQuitter->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButtonQuitter);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);


        horizontalLayout_7->addLayout(verticalLayout_4);


        retranslateUi(Connexion);

        QMetaObject::connectSlotsByName(Connexion);
    } // setupUi

    void retranslateUi(QDialog *Connexion)
    {
        Connexion->setWindowTitle(QApplication::translate("Connexion", "Dialog", nullptr));
        label->setText(QApplication::translate("Connexion", "Connexion", nullptr));
        labelLogin->setText(QApplication::translate("Connexion", "Login", nullptr));
        labelPassword->setText(QApplication::translate("Connexion", "Mot de passe", nullptr));
        labelConnexionError->setText(QApplication::translate("Connexion", "TextLabel", nullptr));
        pushButtonValider->setText(QApplication::translate("Connexion", "Valider", nullptr));
        pushButtonAnnuler->setText(QApplication::translate("Connexion", " Annuler", nullptr));
        pushButtonQuitter->setText(QApplication::translate("Connexion", " Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connexion: public Ui_Connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
