
#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
		setupUi(this);
	crearActions();
	crearMenus();		
		
	modeloTablaArticulo=NULL;
	modeloTablaUsuario=NULL;
	modeloTablaValoracion=NULL;
	connect(btnActTablas,SIGNAL(clicked()),
			this,SLOT(slotActualizarTablas()));
//instanciamos los dialogos a null
	dValoracionEditar = NULL;
	dArticuloEditar = NULL;
	dUsuario = NULL;
//instanciamos tablas
	tabSimarropop->clear();
	tablaValoracion = new QTableView();
	tablaArticulo = new QTableView();
	tablaUsuario = new QTableView();

//instanciamos controllers	
	valCtrl = new ValoracionController();
	valCtrl->selectAll();
	connect(valCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotPeticionValoracionTerminada()));
			
	artCtrl = new ArticuloController();	
	artCtrl->selectAll();
	connect(artCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotPeticionArticuloTerminada()));
	
	usuCtrl = new UsuarioController();	
	usuCtrl->selectAll();
	connect(usuCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotPeticionUsuarioTerminada()));
}

void MainWindow::slotActualizarTablas(){
	artCtrl->selectAll();


}
//MANIPULACION DE TABLA VALORACION
void MainWindow::crearTablaValoracion(){
	modeloTablaValoracion = new ModeloTablaValoracion(&listaValoracion);
	tablaValoracion->setModel(modeloTablaValoracion);
	connect(tablaValoracion,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoValoracion(const QModelIndex &)));
	tabSimarropop->addTab(tablaValoracion,"Valoraciones");
	


}
void MainWindow::slotPeticionValoracionTerminada(){
	valCtrl->getValoraciones(&listaValoracion);
	if(modeloTablaValoracion==NULL){
		qDebug()<<"entro en slotPeticionValoracionTerminada primero, tamaño lista valoracion:"<<listaValoracion.size();
		crearTablaValoracion();
	}else
		qDebug()<<"entro en slotPeticionValoracionTerminada, tamaño lista valoracion:"<<listaValoracion.size();

	modeloTablaValoracion->tablaModificada();

}
void MainWindow::slotDialogoValoracion(const QModelIndex &index){
	int i =  index.row();
	qDebug()<<listaValoracion.at(i)->estrellas;
	if(dValoracionEditar==NULL){
		dValoracionEditar = new DValoracionEditar(listaValoracion.at(i));
		}
		dValoracionEditar->show();
		connect(dValoracionEditar,SIGNAL(finished(int)),
		this,SLOT(slotDialogoValoracionFinalizado(int)));


}
void MainWindow::slotDialogoValoracionFinalizado(int result) {
	if(result==QDialog::Accepted){
		dValoracionEditar=NULL;
		delete dValoracionEditar;
		valCtrl->selectAll();
	
	}
	if(result==QDialog::Rejected){
		dValoracionEditar=NULL;
		delete dValoracionEditar;

	}



}
void MainWindow::slotDialogoValoracionInsertar(){
	if(dValoracionEditar==NULL){
		dValoracionEditar = new DValoracionEditar();
		}
	dValoracionEditar->show();
	
	connect(dValoracionEditar,SIGNAL(finished(int)),
		this,SLOT(slotDialogoValoracionFinalizado(int)));

}
//MANIPULACION TABLA ARTICULO
void MainWindow::crearTablaArticulo(){

	modeloTablaArticulo = new ModeloTablaArticulo(&listaArticulo);
	tablaArticulo->setModel(modeloTablaArticulo);
	connect(tablaArticulo,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoArticulo(const QModelIndex &)));
	tabSimarropop->addTab(tablaArticulo,"Articulos");
	


}
void MainWindow::slotPeticionArticuloTerminada(){
	artCtrl->getArticulos(&listaArticulo);
	if(modeloTablaArticulo==NULL){
		qDebug()<<"entro en slotPeticionArticuloTerminada primero, tamaño lista articulo:"<<listaArticulo.size();
		crearTablaArticulo();
	}else
		qDebug()<<"entro en slotPeticionArticuloTerminada, tamaño lista articulo:"<<listaArticulo.size();

	modeloTablaArticulo->tablaModificada();
		
}
void MainWindow::slotDialogoArticulo(const QModelIndex &index){
	int i =  index.row();
	qDebug()<<listaArticulo.at(i)->titulo;
	if (dArticuloEditar==NULL)
		dArticuloEditar = new DArticuloEditar(listaArticulo.at(i));
	
	dArticuloEditar->show();
	connect(dArticuloEditar,SIGNAL(finished(int)),
		this,SLOT(slotDialogoArticuloFinalizado(int)));


}
void MainWindow::slotDialogoArticuloFinalizado(int result) {
	if(result==QDialog::Accepted){
		dArticuloEditar=NULL;
		delete dArticuloEditar;
		qDebug()<<"se acepta el dialogo";
		artCtrl->selectAll();
	
	}
	if(result==QDialog::Rejected){
		qDebug()<<"se reject el dialogo";
		dArticuloEditar=NULL;
		delete dArticuloEditar;

	}

	
}
void MainWindow::slotDialogoArticuloInsertar(){
if(dArticuloEditar==NULL){
		dArticuloEditar = new DArticuloEditar();
		}
		dArticuloEditar->show();
	
	connect(dArticuloEditar,SIGNAL(finished(int)),
		this,SLOT(slotDialogoArticuloFinalizado(int)));

}

//MANIPULACION DE TABLA USUARIO
void MainWindow::crearTablaUsuario(){
	modeloTablaUsuario = new ModeloTablaUsuario(&listaUsuario);
	tablaUsuario->setModel(modeloTablaUsuario);
	connect(tablaUsuario,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoUsuario(const QModelIndex &)));
	tabSimarropop->addTab(tablaUsuario,"Usuarios");
	


}

void MainWindow::slotPeticionUsuarioTerminada(){
	usuCtrl->getUsuarios(&listaUsuario);
	if(modeloTablaUsuario==NULL){
		qDebug()<<"entro en slotPeticionUsuarioTerminada primero, tamaño lista usuario:"<<listaUsuario.size();
		crearTablaUsuario();
	}else
		qDebug()<<"entro en slotPeticionUsuarioTerminada, tamaño lista usuario:"<<listaUsuario.size();

	modeloTablaUsuario->tablaModificada();
		

}

void MainWindow::slotDialogoUsuario(const QModelIndex &index){
	int i =  index.row();
	qDebug()<<listaUsuario.at(i)->name;
	if(dUsuario==NULL){
		dUsuario = new DUsuario(listaUsuario.at(i));
		}
		dUsuario->show();
	
	connect(dUsuario,SIGNAL(finished(int)),
		this,SLOT(slotDialogoUsuarioFinalizado(int)));


}

void MainWindow::slotDialogoUsuarioFinalizado(int result){
	if(result==QDialog::Accepted){
		dUsuario=NULL;
		delete dUsuario;
		qDebug()<<"se acepta el dialogo";
		usuCtrl->selectAll();
	
	}
	if(result==QDialog::Rejected){
		qDebug()<<"se reject el dialogo";
		dUsuario=NULL;
		delete dUsuario;

	}
}

void MainWindow::slotDialogoUsuarioInsertar(){
if(dUsuario==NULL){
		dUsuario = new DUsuario();
		}
		dUsuario->show();
	
	connect(dUsuario,SIGNAL(finished(int)),
		this,SLOT(slotDialogoUsuarioFinalizado(int)));

}



//CREACION DE ACTIONS
void MainWindow::crearActions(){
	accionInsertUsuario = new QAction("Insertar Usuario");
	connect(accionInsertUsuario,SIGNAL(triggered()),
		this,SLOT(slotDialogoUsuarioInsertar()));
	accionInsertArticulo = new QAction("Insertar Articulo");
	connect(accionInsertArticulo,SIGNAL(triggered()),
		this,SLOT(slotDialogoArticuloInsertar()));
		
	accionInsertValoracion = new QAction("Insertar Valoracion");
	connect(accionInsertValoracion,SIGNAL(triggered()),
		this,SLOT(slotDialogoValoracionInsertar()));
}
//CREACION DE MENUS
void MainWindow::crearMenus(){
	QMenu * menuInsertar = menuBar()->addMenu("Insertar Datos");
	menuInsertar->addAction(accionInsertUsuario);
	menuInsertar->addAction(accionInsertArticulo);
	menuInsertar->addAction(accionInsertValoracion);

}



