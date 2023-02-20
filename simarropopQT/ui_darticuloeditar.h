/********************************************************************************
** Form generated from reading UI file 'darticuloeditar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DARTICULOEDITAR_H
#define UI_DARTICULOEDITAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DArticuloEditar
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *nameLineEdit;
    QLineEdit *categoriaLineEdit;
    QLineEdit *precioLineEdit;
    QLineEdit *descripcionLineEdit;
    QLineEdit *usuarioLineEdit;
    QLineEdit *ubicacionLineEdit;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *DArticuloEditar)
    {
        if (DArticuloEditar->objectName().isEmpty())
            DArticuloEditar->setObjectName(QString::fromUtf8("DArticuloEditar"));
        DArticuloEditar->resize(682, 444);
        label = new QLabel(DArticuloEditar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 67, 17));
        label_2 = new QLabel(DArticuloEditar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 80, 67, 17));
        label_3 = new QLabel(DArticuloEditar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 130, 67, 17));
        label_4 = new QLabel(DArticuloEditar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 180, 81, 17));
        label_5 = new QLabel(DArticuloEditar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 230, 67, 17));
        label_6 = new QLabel(DArticuloEditar);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 280, 67, 17));
        nameLineEdit = new QLineEdit(DArticuloEditar);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(280, 20, 191, 31));
        categoriaLineEdit = new QLineEdit(DArticuloEditar);
        categoriaLineEdit->setObjectName(QString::fromUtf8("categoriaLineEdit"));
        categoriaLineEdit->setGeometry(QRect(280, 70, 191, 31));
        precioLineEdit = new QLineEdit(DArticuloEditar);
        precioLineEdit->setObjectName(QString::fromUtf8("precioLineEdit"));
        precioLineEdit->setGeometry(QRect(280, 120, 191, 31));
        descripcionLineEdit = new QLineEdit(DArticuloEditar);
        descripcionLineEdit->setObjectName(QString::fromUtf8("descripcionLineEdit"));
        descripcionLineEdit->setGeometry(QRect(280, 170, 191, 31));
        usuarioLineEdit = new QLineEdit(DArticuloEditar);
        usuarioLineEdit->setObjectName(QString::fromUtf8("usuarioLineEdit"));
        usuarioLineEdit->setGeometry(QRect(280, 270, 191, 31));
        ubicacionLineEdit = new QLineEdit(DArticuloEditar);
        ubicacionLineEdit->setObjectName(QString::fromUtf8("ubicacionLineEdit"));
        ubicacionLineEdit->setGeometry(QRect(280, 220, 191, 31));
        btnGuardar = new QPushButton(DArticuloEditar);
        btnGuardar->setObjectName(QString::fromUtf8("btnGuardar"));
        btnGuardar->setGeometry(QRect(370, 380, 89, 25));
        btnCancelar = new QPushButton(DArticuloEditar);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setGeometry(QRect(510, 380, 89, 25));

        retranslateUi(DArticuloEditar);

        QMetaObject::connectSlotsByName(DArticuloEditar);
    } // setupUi

    void retranslateUi(QDialog *DArticuloEditar)
    {
        DArticuloEditar->setWindowTitle(QCoreApplication::translate("DArticuloEditar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DArticuloEditar", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("DArticuloEditar", "Categoria", nullptr));
        label_3->setText(QCoreApplication::translate("DArticuloEditar", "Precio", nullptr));
        label_4->setText(QCoreApplication::translate("DArticuloEditar", "Descripcion", nullptr));
        label_5->setText(QCoreApplication::translate("DArticuloEditar", "Ubicacion", nullptr));
        label_6->setText(QCoreApplication::translate("DArticuloEditar", "Usuario", nullptr));
        btnGuardar->setText(QCoreApplication::translate("DArticuloEditar", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("DArticuloEditar", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DArticuloEditar: public Ui_DArticuloEditar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DARTICULOEDITAR_H
