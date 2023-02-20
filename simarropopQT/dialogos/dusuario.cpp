#include "dusuario.h"
#include <QDebug>

DUsuario::DUsuario(Usuario *usuarioPasado,QWidget *parent): QDialog(parent){
		setupUi(this);
		btnCancelar->setText("Borrar");
		usuCtrl = new UsuarioController();
		usuario = usuarioPasado;
		nameLineEdit->insert(usuario->name);
		apellidosLineEdit->insert(usuario->apellidos);
		ubicacionLineEdit->insert(usuario->ubicacion);
		correoLineEdit->insert(usuario->correo);
		contrasenyaLineEdit->insert(usuario->contrasenya);
		connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotGuardarDialogo()));
		connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotBorrarDialogo()));
		connect(usuCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));
	
}

DUsuario::DUsuario(QWidget *parent): QDialog(parent){
		setupUi(this);
		usuCtrl = new UsuarioController();
		connect(btnGuardar,SIGNAL(clicked()),
			this,SLOT(slotInsertarDialogo()));
		connect(btnCancelar,SIGNAL(clicked()),
			this,SLOT(slotCancelarDialogo()));
			connect(usuCtrl,SIGNAL(peticionTerminada()),
			this,SLOT(slotEmitirAccept()));
	
}

void DUsuario::slotInsertarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		usuario = new Usuario(nameLineEdit->displayText(),
		apellidosLineEdit->displayText(),
		ubicacionLineEdit->displayText(),
		correoLineEdit->displayText(),
		contrasenyaLineEdit->displayText());
		
		usuCtrl->insertarUsuario(usuario);
	}
}

void DUsuario::slotGuardarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres guardar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
		usuario->name=nameLineEdit->displayText();
		usuario->apellidos=apellidosLineEdit->displayText();
		usuario->ubicacion=ubicacionLineEdit->displayText();
		usuario->correo=correoLineEdit->displayText();
		usuario->contrasenya=contrasenyaLineEdit->displayText();
		usuCtrl->editarUsuario(usuario);
	}
}

void DUsuario::slotBorrarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Esta seguro que quieres borrar?"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No) qDebug()<<"no se acepto el dialogo";
	if(respuesta == QMessageBox::Yes){
	
		usuCtrl->eliminarUsuario(usuario->id);
	}
}

void DUsuario::slotCancelarDialogo(){
	this->reject();
}

void DUsuario::closeEvent(QCloseEvent *event)
{
       this->reject();
}

void DUsuario::slotEmitirAccept(){
		this->accept();
}



