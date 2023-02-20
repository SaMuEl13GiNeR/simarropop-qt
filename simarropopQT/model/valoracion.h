#ifndef _VALORACION_H_
#define _VALORACION_H_

#include <QString>

class Valoracion{

public:
	Valoracion();
	Valoracion(int, int, QString, int, int);
	Valoracion(int, QString, int, int);
	
	int id;
	int estrellas;
	QString opinion;
	int usuario_emisor;
	int usuario_receptor;
};

#endif
