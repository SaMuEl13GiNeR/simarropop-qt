#include <QDebug>
#include <QString>

class Articulo{

public:
	Articulo();
	Articulo(long, QString, int, QString, float, QString, bool);
	
	long id;
	QString titulo, descripcion, estado;
	int likes;
	float precio;
	bool vendido;
};
