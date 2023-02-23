#include "dusuario.h"

DUsuario::DUsuario(Usuario *usuarioPasado,QWidget *parent): QDialog(parent){
		setupUi(this);
		usuCtrl = new UsuarioController();
		usuario = usuarioPasado;
		leName->insert(usuario->name);
		leApellidos->insert(usuario->apellidos);
		leLongitud->insert(QString::number(usuario->longitud));
		leLatitud->insert(QString::number(usuario->latitud));
		leCorreo->insert(usuario->correo);
		leContrasenya->insert(usuario->contrasenya);
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
	
	int respuesta = QMessageBox::warning(this,QString("Vas a insertar el usuario en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		usuario = new Usuario(leName->displayText(),
		leApellidos->displayText(),
		leLongitud->displayText().toFloat(),
		leLatitud->displayText().toFloat(),
		leCorreo->displayText(),
		leContrasenya->displayText());
		
		usuCtrl->insertarUsuario(usuario);
	}
}

void DUsuario::slotGuardarDialogo(){
	
	int respuesta = QMessageBox::warning(this,QString("Vas a modificar el usuario en la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		usuario->name=leName->displayText();
		usuario->apellidos=leApellidos->displayText();
		usuario->longitud=leLongitud->displayText().toFloat();
		usuario->latitud=leLatitud->displayText().toFloat();
		usuario->correo=leCorreo->displayText();
		usuario->contrasenya=leContrasenya->displayText();
		usuCtrl->editarUsuario(usuario);
	}
}

void DUsuario::slotBorrarDialogo(){
	int respuesta = QMessageBox::warning(this,QString("Vas a borrar el usuario de la bd"),
	QString("¿Seguro?"),
	QMessageBox::Yes | QMessageBox::No);
	if (respuesta == QMessageBox::No);
	if(respuesta == QMessageBox::Yes){
		usuCtrl->eliminarUsuario(usuario->id);
	}
}

void DUsuario::slotCancelarDialogo(){
	this->reject();
}

void DUsuario::closeEvent(QCloseEvent *event){
       this->reject();
}

void DUsuario::slotEmitirAccept(){
		this->accept();
}

