#include "mainwindow.h"
#include <QDebug>
#define NUMBOLAS 5

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
	
	setWindowTitle("Simarropop");
	
	resize(800,600);
	
	dInformacion = NULL;
	valoracionController = new ValoracionController();
	
	crearActions();
	crearMenus();
	qDebug() << "antes del select";
	valoracionController->selectAll();
	qDebug() << "despues del select";
	valoracionController->insertarValoracion();
}

void MainWindow::crearActions(){
	accionInformacion = new QAction("informacion juego");
	connect(accionInformacion, SIGNAL(triggered()),
		this,SLOT(slotInformacion()));
}
	
void MainWindow::crearMenus(){
	//QMenuBar * menuBar = menuBar();
	QMenu * menuArchivo = menuBar() -> addMenu("Archivo");
	menuArchivo->addAction(accionInformacion);
}

void MainWindow::slotInformacion(){
	if(dInformacion == NULL)
		dInformacion = new DInformacion();
	dInformacion->show();
}






