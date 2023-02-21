#ifndef _ARTICULO_H_
#define _ARTICULO_H_

#include <QString>

class Articulo{

public:
	Articulo();
	Articulo(int, QString, int, QString, float, QString, int, int ,int );
	Articulo(QString, int, QString, float, QString, int, int ,int );
	
	int id;
	QString titulo;
	int likes;
	QString descripcion;
	float precio;
	QString estado;
	int usuario_comprador;
	int usuario_vendedor;
	int categoria;

	
	
private:
	


};

#endif
