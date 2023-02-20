/********************************************************************************
** Form generated from reading UI file 'dlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLOGIN_H
#define UI_DLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DLogin
{
public:
    QPushButton *btnLogin;
    QPushButton *btnSalir;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;

    void setupUi(QDialog *DLogin)
    {
        if (DLogin->objectName().isEmpty())
            DLogin->setObjectName(QString::fromUtf8("DLogin"));
        DLogin->resize(474, 386);
        btnLogin = new QPushButton(DLogin);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(110, 240, 111, 31));
        btnSalir = new QPushButton(DLogin);
        btnSalir->setObjectName(QString::fromUtf8("btnSalir"));
        btnSalir->setGeometry(QRect(250, 240, 111, 31));
        label = new QLabel(DLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 40, 101, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineEdit = new QLineEdit(DLogin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 80, 113, 25));
        lineEdit_2 = new QLineEdit(DLogin);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 160, 113, 25));
        label_2 = new QLabel(DLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 120, 81, 16));
        label_2->setFont(font);

        retranslateUi(DLogin);

        QMetaObject::connectSlotsByName(DLogin);
    } // setupUi

    void retranslateUi(QDialog *DLogin)
    {
        DLogin->setWindowTitle(QCoreApplication::translate("DLogin", "Dialog", nullptr));
        btnLogin->setText(QCoreApplication::translate("DLogin", "Iniciar Sesi\303\263n", nullptr));
        btnSalir->setText(QCoreApplication::translate("DLogin", "Salir", nullptr));
        label->setText(QCoreApplication::translate("DLogin", "Nombre", nullptr));
        label_2->setText(QCoreApplication::translate("DLogin", "Contrase\303\261a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DLogin: public Ui_DLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLOGIN_H
