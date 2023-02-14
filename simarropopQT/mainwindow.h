#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QMenuBar>
#include <QAction>
#include "dinformacion.h"
#include "valoracioncontroller.h"


class MainWindow : public QMainWindow{

Q_OBJECT

public:

	MainWindow(QWidget *parent = nullptr);
	QTimer * temporizador;
	
	QAction *accionInformacion;
	DInformacion *dInformacion;
	
	ValoracionController *valoracionController;	
	
	void crearActions();
	void crearMenus();
	

public slots:
	void slotInformacion();

};

#endif 
