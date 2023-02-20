#ifndef _USUARIO_H_
#define _USUARIO_H_

#include <QString>
#include <QDate>

class Usuario{

public:
	Usuario();
	Usuario(int ,QString ,QString,QString,QString,QString);
	Usuario(QString ,QString,QString,QString,QString);
	int id;
	QString name;
	QString apellidos;
	QString ubicacion;
	QString correo;
	QString contrasenya;

	
	
private:
	


};

#endif
