#include "dvaloracioneditar.h"
#include <QDebug>

DValoracionEditar::DValoracionEditar(Valoracion *valoracionPasada,QWidget *parent): QDialog(parent){
		setupUi(this);
	btnCancelar->setText("Borrar");
	valCtrl = new ValoracionController();
	valoracion = valoracionPasada;
	estrellasLineEdit->insert(QString::number(valoracion->estrellas));
	opinionLineEdit->insert(valoracion->opinion);
	usuario_emisorLineEdit->insert(QString::number(valoracion->usuario_emisor));
	usuario_receptorLineEdit->insert(QString::number(valoracion->usuario_receptor));
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
	int respuesta = QMessageBox::warning(this,QString("Está seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"No se aceptó el dialogo";
	if(respuesta == QMessageBox::Yes){
		valoracion = new Valoracion(estrellasLineEdit->displayText().toInt(),
		opinionLineEdit->displayText(),
		usuario_emisorLineEdit->displayText().toInt(),
		usuario_receptorLineEdit->displayText().toInt());
		valCtrl->insertarValoracion(valoracion);
	}
}

void DValoracionEditar::slotGuardarDialogo(){
int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		valoracion->estrellas=estrellasLineEdit->displayText().toInt();
		valoracion->opinion=opinionLineEdit->displayText();
		valoracion->usuario_emisor=(usuario_emisorLineEdit->displayText().toInt());
		valoracion->usuario_receptor=(usuario_receptorLineEdit->displayText().toInt());
		valCtrl->editarValoracion(valoracion);
	}
}

void DValoracionEditar::slotBorrarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres borrar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
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

