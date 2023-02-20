
#ifndef DARTICULOEDITAR_H
#define DARTICULOEDITAR_H
#include "ui_darticuloeditar.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include "model/articulo.h"
#include "controller/articulocontroller.h"
#include <QMessageBox>
#include <QCloseEvent>


class DArticuloEditar : public QDialog, public Ui::DArticuloEditar {
Q_OBJECT

public:
	DArticuloEditar(Articulo *,QWidget *parent = NULL);
	DArticuloEditar(QWidget *parent = NULL);
	Articulo *articulo;
	ArticuloController *artCtrl;
	void closeEvent(QCloseEvent *);

public slots:
	void slotGuardarDialogo();
	void slotCancelarDialogo();
	void slotInsertarDialogo();
	void slotBorrarDialogo();
	void slotEmitirAccept();

};

#endif 
