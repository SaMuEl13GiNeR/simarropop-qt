#ifndef _DVALORACION_H
#define _DVALORACION_H
#include "ui_dvaloracioneditar.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include "model/valoracion.h"
#include "controller/valoracioncontroller.h"

class DValoracionEditar : public QDialog, public Ui::DValoracionEditar {
Q_OBJECT

public:
	DValoracionEditar(Valoracion *,QWidget *parent = NULL);
	DValoracionEditar(QWidget *parent = NULL);
	Valoracion *valoracion;
	ValoracionController *valCtrl;
	void closeEvent(QCloseEvent *);
	
public slots:
	void slotGuardarDialogo();
	void slotCancelarDialogo();
	void slotInsertarDialogo();
	void slotBorrarDialogo();
	void slotEmitirAccept();

};

#endif 
