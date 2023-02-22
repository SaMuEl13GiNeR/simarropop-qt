#include "darticuloeditar.h"
#include <QDebug>

DArticuloEditar::DArticuloEditar(Articulo *articuloPasado,QWidget *parent): QDialog(parent){
		setupUi(this);
		btnCancelar->setText("Borrar");
		artCtrl = new ArticuloController();
		articulo = articuloPasado;
		tituloLineEdit->insert(articulo->titulo);
		likesLineEdit->insert(QString::number(articulo->likes));
		descripcionLineEdit->insert(articulo->descripcion);
		precioLineEdit->insert(QString::number(articulo->precio));
		estadoLineEdit->insert(articulo->estado);
		usuario_compradorLineEdit->insert(QString::number(articulo->usuario_comprador));
		usuario_vendedorLineEdit->insert(QString::number(articulo->usuario_vendedor));
		categoriaLineEdit->insert(QString::number(articulo->categoria));
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
	
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		articulo = new Articulo(tituloLineEdit->displayText(),
		likesLineEdit->displayText().toInt(),
		descripcionLineEdit->displayText(),
		precioLineEdit->displayText().toFloat(),
		estadoLineEdit->displayText(),
		usuario_compradorLineEdit->displayText().toInt(),
		usuario_vendedorLineEdit->displayText().toInt(),
		categoriaLineEdit->displayText().toInt());
		
		artCtrl->insertarArticulo(articulo);
	}
}
void DArticuloEditar::slotBorrarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres borrar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		artCtrl->eliminarArticulo(articulo->id);
	}
}

void DArticuloEditar::slotGuardarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		articulo->titulo=tituloLineEdit->displayText();
		articulo->likes=(likesLineEdit->displayText().toInt());
		articulo->descripcion=descripcionLineEdit->displayText();
		articulo->precio=(precioLineEdit->displayText().toFloat());
		articulo->estado=estadoLineEdit->displayText();
		articulo->usuario_comprador=(usuario_compradorLineEdit->displayText().toInt());
		articulo->usuario_vendedor=(usuario_vendedorLineEdit->displayText().toInt());
		articulo->categoria=(categoriaLineEdit->displayText().toInt());
		artCtrl->editarArticulo(articulo);
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

