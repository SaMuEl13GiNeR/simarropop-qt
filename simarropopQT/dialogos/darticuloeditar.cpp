#include "darticuloeditar.h"

DArticuloEditar::DArticuloEditar(Articulo *articuloPasado,QWidget *parent): QDialog(parent){
		setupUi(this);
		artCtrl = new ArticuloController();
		articulo = articuloPasado;
		leTitulo->insert(articulo->titulo);
		leLikes->insert(QString::number(articulo->likes));
		leDescripcion->insert(articulo->descripcion);
		lePrecio->insert(QString::number(articulo->precio));
		leEstado->insert(articulo->estado);
		leUsuario_comprador->insert(QString::number(articulo->usuario_comprador));
		leUsuario_vendedor->insert(QString::number(articulo->usuario_vendedor));
		leCategoria->insert(QString::number(articulo->categoria));
		connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotGuardarDialogo()));
		connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotBorrarDialogo()));
		connect(artCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));
}

DArticuloEditar::DArticuloEditar(QWidget *parent): QDialog(parent){
		setupUi(this);
		
		artCtrl = new ArticuloController();
		connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotInsertarDialogo()));
		connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotCancelarDialogo()));
		connect(artCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));
	
}
void DArticuloEditar::slotInsertarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Vas a insertar el articulo en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		articulo = new Articulo(leTitulo->displayText(),
		leLikes->displayText().toInt(),
		leDescripcion->displayText(),
		lePrecio->displayText().toFloat(),
		leEstado->displayText(),
		leUsuario_comprador->displayText().toInt(),
		leUsuario_vendedor->displayText().toInt(),
		leCategoria->displayText().toInt());
		
		artCtrl->insertarArticulo(articulo);
	}
}

void DArticuloEditar::slotGuardarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Vas a modificar el usuario en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		articulo->titulo=leTitulo->displayText();
		articulo->likes=(leLikes->displayText().toInt());
		articulo->descripcion=leDescripcion->displayText();
		articulo->precio=(lePrecio->displayText().toFloat());
		articulo->estado=leEstado->displayText();
		articulo->usuario_comprador=(leUsuario_comprador->displayText().toInt());
		articulo->usuario_vendedor=(leUsuario_vendedor->displayText().toInt());
		articulo->categoria=(leCategoria->displayText().toInt());
		artCtrl->editarArticulo(articulo);
	}
}

void DArticuloEditar::slotBorrarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Vas a borrar el usuario de la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		artCtrl->eliminarArticulo(articulo->id);
	}
}

void DArticuloEditar::slotCancelarDialogo(){
	this->reject();
}

void DArticuloEditar::closeEvent(QCloseEvent *event){
       this->reject();
}

void DArticuloEditar::slotEmitirAccept(){
		this->accept();
}

