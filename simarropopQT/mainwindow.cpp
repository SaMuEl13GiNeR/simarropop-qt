#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
		setupUi(this);
	crearActions();
	crearMenus();		
		
	modeloTablaArticulo=NULL;
	modeloTablaUsuario=NULL;
	modeloTablaValoracion=NULL;
	connect(btnActTabs,SIGNAL(clicked()),
			this,SLOT(slotActualizarTablas()));


	dValoracionEditar = NULL;
	dArticuloEditar = NULL;
	dUsuario = NULL;


	tabSimarropop->clear();
	tabValoracion = new QTableView();
	tabArticulo = new QTableView();
	tabUsuario = new QTableView();


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
	valCtrl->selectAll();
	usuCtrl->selectAll();
}

// conjunto tab valoracion
void MainWindow::crearTablaValoracion(){
	modeloTablaValoracion = new ModeloTablaValoracion(&listaValoracion);
	tabValoracion->setModel(modeloTablaValoracion);
	connect(tabValoracion,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoValoracion(const QModelIndex &)));
	tabSimarropop->addTab(tabValoracion,"Valoraciones");
}

void MainWindow::slotPeticionValoracionTerminada(){
	valCtrl->getValoraciones(&listaValoracion);
	if(modeloTablaValoracion==NULL){
		crearTablaValoracion();
	}else
	modeloTablaValoracion->tablaModificada();
}

void MainWindow::slotDialogoValoracion(const QModelIndex &index){
	int i =  index.row();
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
// fin valoracion 

// conjunto tab articulo
void MainWindow::crearTablaArticulo(){
	modeloTablaArticulo = new ModeloTablaArticulo(&listaArticulo);
	tabArticulo->setModel(modeloTablaArticulo);
	connect(tabArticulo,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoArticulo(const QModelIndex &)));
	tabSimarropop->addTab(tabArticulo,"Articulos");
}

void MainWindow::slotPeticionArticuloTerminada(){
	artCtrl->getArticulos(&listaArticulo);
	if(modeloTablaArticulo==NULL){
		crearTablaArticulo();
	}else
	modeloTablaArticulo->tablaModificada();
}

void MainWindow::slotDialogoArticulo(const QModelIndex &index){
	int i =  index.row();
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
		artCtrl->selectAll();
	}
	if(result==QDialog::Rejected){
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
// fin articulo

// conjunto tab usuario
void MainWindow::crearTablaUsuario(){
	modeloTablaUsuario = new ModeloTablaUsuario(&listaUsuario);
	tabUsuario->setModel(modeloTablaUsuario);
	connect(tabUsuario,SIGNAL(doubleClicked(const QModelIndex &)),
			this,SLOT(slotDialogoUsuario(const QModelIndex &)));
	tabSimarropop->addTab(tabUsuario,"Usuarios");
}

void MainWindow::slotPeticionUsuarioTerminada(){
	usuCtrl->getUsuarios(&listaUsuario);
	if(modeloTablaUsuario==NULL){
		crearTablaUsuario();
	}else
	modeloTablaUsuario->tablaModificada();
}

void MainWindow::slotDialogoUsuario(const QModelIndex &index){
	int i =  index.row();
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
		usuCtrl->selectAll();
	}
	if(result==QDialog::Rejected){
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
// fin usuario

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

void MainWindow::crearMenus(){
	QMenu * menuInsertar = menuBar()->addMenu("Insertar Datos");
	menuInsertar->addAction(accionInsertUsuario);
	menuInsertar->addAction(accionInsertArticulo);
	menuInsertar->addAction(accionInsertValoracion);
}

