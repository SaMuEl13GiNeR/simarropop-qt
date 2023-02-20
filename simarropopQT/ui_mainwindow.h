/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabSimarropop;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *btnActTablas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(825, 613);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabSimarropop = new QTabWidget(centralwidget);
        tabSimarropop->setObjectName(QString::fromUtf8("tabSimarropop"));
        tabSimarropop->setGeometry(QRect(60, 60, 681, 461));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabSimarropop->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabSimarropop->addTab(tab_2, QString());
        btnActTablas = new QPushButton(centralwidget);
        btnActTablas->setObjectName(QString::fromUtf8("btnActTablas"));
        btnActTablas->setGeometry(QRect(548, 20, 161, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabSimarropop->setTabText(tabSimarropop->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabSimarropop->setTabText(tabSimarropop->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        btnActTablas->setText(QCoreApplication::translate("MainWindow", "Actualizar tablas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
