#include <QDebug>
#include <QString>

class Usuario{

public:
	Usuario();
	Usuario(long, QString, QString, QString, QString, QString);
	
	long id;
	QString nombre, apellidos, ubicacion, contrasenya, correo;
};
