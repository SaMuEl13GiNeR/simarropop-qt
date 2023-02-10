#include <QDebug>
#include <QString>

class Valoracion{

public:
	Valoracion();
	Valoracion(long, int, QString);
	
	long id;
	int estrellas;
	QString opinion;
};
