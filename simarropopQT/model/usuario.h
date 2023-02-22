#ifndef _USUARIO_H_
#define _USUARIO_H_

#include <QString>
#include <QDate>

class Usuario{

public:
	Usuario();
	Usuario(int ,QString ,QString, float, float, QString, QString);
	Usuario(QString ,QString, float, float, QString, QString);
	int id;
	QString name;
	QString apellidos;
	float longitud;
	float latitud;
	QString correo;
	QString contrasenya;

	
	
private:
	


};

#endif
