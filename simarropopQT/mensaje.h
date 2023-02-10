#include <QDebug>
#include <QString>

class Mensaje{

public:
	Mensaje();
	Mensaje(long, QString, QString);
	
	long id;
	QString contenido, fecha;
};
