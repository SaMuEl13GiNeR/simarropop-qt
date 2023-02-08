
#ifndef DINFORMACION_H
#define DINFORMACION_H
#include "ui_dinformacion.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DInformacion : public QDialog, public Ui::DInformacion {
Q_OBJECT

public:
	DInformacion(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
