/********************************************************************************
** Form generated from reading UI file 'dvaloracioneditar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVALORACIONEDITAR_H
#define UI_DVALORACIONEDITAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DValoracionEditar
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *estrellasLineEdit;
    QLineEdit *opinionLineEdit;
    QLineEdit *usuario_emisorLineEdit;
    QLineEdit *usuario_receptorLineEdit;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *DValoracionEditar)
    {
        if (DValoracionEditar->objectName().isEmpty())
            DValoracionEditar->setObjectName(QString::fromUtf8("DValoracionEditar"));
        DValoracionEditar->resize(638, 387);
        label = new QLabel(DValoracionEditar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 50, 67, 17));
        label_2 = new QLabel(DValoracionEditar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 100, 67, 17));
        label_3 = new QLabel(DValoracionEditar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 150, 81, 17));
        label_4 = new QLabel(DValoracionEditar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 200, 67, 17));
        estrellasLineEdit = new QLineEdit(DValoracionEditar);
        estrellasLineEdit->setObjectName(QString::fromUtf8("estrellasLineEdit"));
        estrellasLineEdit->setGeometry(QRect(230, 40, 191, 31));
        opinionLineEdit = new QLineEdit(DValoracionEditar);
        opinionLineEdit->setObjectName(QString::fromUtf8("opinionLineEdit"));
        opinionLineEdit->setGeometry(QRect(230, 90, 191, 31));
        usuario_emisorLineEdit = new QLineEdit(DValoracionEditar);
        usuario_emisorLineEdit->setObjectName(QString::fromUtf8("usuario_emisorLineEdit"));
        usuario_emisorLineEdit->setGeometry(QRect(230, 140, 191, 31));
        usuario_receptorLineEdit = new QLineEdit(DValoracionEditar);
        usuario_receptorLineEdit->setObjectName(QString::fromUtf8("usuario_receptorLineEdit"));
        usuario_receptorLineEdit->setGeometry(QRect(230, 190, 191, 31));
        btnGuardar = new QPushButton(DValoracionEditar);
        btnGuardar->setObjectName(QString::fromUtf8("btnGuardar"));
        btnGuardar->setGeometry(QRect(330, 300, 89, 25));
        btnCancelar = new QPushButton(DValoracionEditar);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setGeometry(QRect(460, 300, 89, 25));

        retranslateUi(DValoracionEditar);

        QMetaObject::connectSlotsByName(DValoracionEditar);
    } // setupUi

    void retranslateUi(QDialog *DValoracionEditar)
    {
        DValoracionEditar->setWindowTitle(QCoreApplication::translate("DValoracionEditar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DValoracionEditar", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("DValoracionEditar", "Opinion", nullptr));
        label_3->setText(QCoreApplication::translate("DValoracionEditar", "Puntuacion", nullptr));
        label_4->setText(QCoreApplication::translate("DValoracionEditar", "Usuario", nullptr));
        btnGuardar->setText(QCoreApplication::translate("DValoracionEditar", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("DValoracionEditar", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DValoracionEditar: public Ui_DValoracionEditar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVALORACIONEDITAR_H
