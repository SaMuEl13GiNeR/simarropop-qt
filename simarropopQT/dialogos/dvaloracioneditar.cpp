#include "dvaloracioneditar.h"

DValoracionEditar::DValoracionEditar(Valoracion *valoracionPasada,QWidget *parent): QDialog(parent){
		setupUi(this);
	valCtrl = new ValoracionController();
	valoracion = valoracionPasada;
	leEstrellas->insert(QString::number(valoracion->estrellas));
	leOpinion->insert(valoracion->opinion);
	leUsuario_emisor->insert(QString::number(valoracion->usuario_emisor));
	leUsuario_receptor->insert(QString::number(valoracion->usuario_receptor));
	connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotGuardarDialogo()));
	connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotBorrarDialogo()));
	connect(valCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));

}
DValoracionEditar::DValoracionEditar(QWidget *parent): QDialog(parent){
		setupUi(this);
		
	valCtrl = new ValoracionController();
	connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotInsertarDialogo()));
	connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotCancelarDialogo()));
	connect(valCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));
}

void DValoracionEditar::slotInsertarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Vas a insertar la valoracion en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		valoracion = new Valoracion(leEstrellas->displayText().toInt(),
		leOpinion->displayText(),
		leUsuario_emisor->displayText().toInt(),
		leUsuario_receptor->displayText().toInt());
		valCtrl->insertarValoracion(valoracion);
	}
}

void DValoracionEditar::slotGuardarDialogo(){
int respuesta = QMessageBox::warning(this,QString("Vas a modificar la valoracion en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		valoracion->estrellas=leEstrellas->displayText().toInt();
		valoracion->opinion=leOpinion->displayText();
		valoracion->usuario_emisor=(leUsuario_emisor->displayText().toInt());
		valoracion->usuario_receptor=(leUsuario_receptor->displayText().toInt());
		valCtrl->editarValoracion(valoracion);
	}
}

void DValoracionEditar::slotBorrarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Vas a borrar la valoracion de la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		valCtrl->eliminarValoracion(valoracion->id);
	}
}

void DValoracionEditar::slotCancelarDialogo(){
	this->reject();
}

void DValoracionEditar::slotEmitirAccept(){
	this->accept();
}

void DValoracionEditar::closeEvent(QCloseEvent *event){
       this->reject();
}

