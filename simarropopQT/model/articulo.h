#ifndef _ARTICULO_H_
#define _ARTICULO_H_

#include <QString>

class Articulo{

public:
	Articulo();
	Articulo(int ,QString ,int,float,QString,QString,int);
	Articulo(QString ,int,float,QString,QString,int);
	int id;
	QString name;
	int categoria;
	float precio;
	QString descripcion;
	QString ubicacion;
	int usuario;

	
	
private:
	


};

#endif
