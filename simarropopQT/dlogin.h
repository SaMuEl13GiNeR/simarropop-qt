
#ifndef DLOGIN_H
#define DLOGIN_H
#include "ui_dlogin.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include "mainwindow.h"
class DLogin : public QDialog, public Ui::DLogin {
Q_OBJECT

public:
	DLogin(QWidget *parent = NULL);

public slots:
	void slotAceptar();

};

#endif 
