
#include "darticuloeditar.h"
#include <QDebug>

DArticuloEditar::DArticuloEditar(Articulo *articuloPasado,QWidget *parent): QDialog(parent){
		setupUi(this);
		btnCancelar->setText("Borrar");
		artCtrl = new ArticuloController();
		articulo = articuloPasado;
		nameLineEdit->insert(articulo->name);
		categoriaLineEdit->insert(QString::number(articulo->categoria));
		precioLineEdit->insert(QString::number(articulo->precio));
		descripcionLineEdit->insert(articulo->descripcion);
		ubicacionLineEdit->insert(articulo->ubicacion);
		usuarioLineEdit->insert(QString::number(articulo->usuario));
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
		articulo = new Articulo(nameLineEdit->displayText(),
		categoriaLineEdit->displayText().toInt(),
		precioLineEdit->displayText().toFloat(),
		descripcionLineEdit->displayText(),
		ubicacionLineEdit->displayText(),
		usuarioLineEdit->displayText().toInt());
		
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
		articulo->name=nameLineEdit->displayText();
		articulo->categoria=(categoriaLineEdit->displayText().toInt());
		articulo->precio=(precioLineEdit->displayText().toFloat());
		articulo->descripcion=descripcionLineEdit->displayText();
		articulo->ubicacion=ubicacionLineEdit->displayText();
		articulo->usuario=(usuarioLineEdit->displayText().toInt());
		artCtrl->editarArticulo(articulo);
		

	}


}
void DArticuloEditar::slotCancelarDialogo(){
	qDebug()<<"se cancela el dialogo";
	this->reject();

}
void DArticuloEditar::closeEvent(QCloseEvent *event)
{
	qDebug()<<"se cierra el dialogo";
       this->reject();
  
    
}
void DArticuloEditar::slotEmitirAccept(){
	
		this->accept();
}

