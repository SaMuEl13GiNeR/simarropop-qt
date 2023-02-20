
#ifndef DUSUARIO_H
#define DUSUARIO_H
#include "ui_dusuario.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include "model/usuario.h"
#include "controller/usuariocontroller.h"
#include <QMessageBox>
#include <QCloseEvent>

class DUsuario : public QDialog, public Ui::DUsuario {
Q_OBJECT

public:
	DUsuario(Usuario *usuario,QWidget *parent = NULL);
	DUsuario(QWidget *parent = NULL);
	Usuario *usuario;
	UsuarioController *usuCtrl;
	void closeEvent(QCloseEvent *);

public slots:
	void slotGuardarDialogo();
	void slotCancelarDialogo();
	void slotInsertarDialogo();
	void slotBorrarDialogo();
	void slotEmitirAccept();


};

#endif 
