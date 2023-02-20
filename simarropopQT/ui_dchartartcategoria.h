/********************************************************************************
** Form generated from reading UI file 'dchartartcategoria.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCHARTARTCATEGORIA_H
#define UI_DCHARTARTCATEGORIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DChartArtCategoria
{
public:
    QFrame *frameArticuloCategoria;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *DChartArtCategoria)
    {
        if (DChartArtCategoria->objectName().isEmpty())
            DChartArtCategoria->setObjectName(QString::fromUtf8("DChartArtCategoria"));
        DChartArtCategoria->resize(925, 573);
        frameArticuloCategoria = new QFrame(DChartArtCategoria);
        frameArticuloCategoria->setObjectName(QString::fromUtf8("frameArticuloCategoria"));
        frameArticuloCategoria->setGeometry(QRect(60, 60, 811, 471));
        frameArticuloCategoria->setFrameShape(QFrame::StyledPanel);
        frameArticuloCategoria->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frameArticuloCategoria);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 811, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DChartArtCategoria);

        QMetaObject::connectSlotsByName(DChartArtCategoria);
    } // setupUi

    void retranslateUi(QDialog *DChartArtCategoria)
    {
        DChartArtCategoria->setWindowTitle(QCoreApplication::translate("DChartArtCategoria", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChartArtCategoria: public Ui_DChartArtCategoria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCHARTARTCATEGORIA_H
