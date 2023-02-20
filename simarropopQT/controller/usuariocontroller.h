#ifndef _USUARIOCONTROLLER_H_
#define _USUARIOCONTROLLER_H_
#include <QString>
#include "model/usuario.h"
#include <QtNetwork>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>

class UsuarioController : public QObject{
Q_OBJECT

public:
	UsuarioController();
	void selectAll();
	void insertarUsuario(Usuario *);
	void getUsuarios(QVector<Usuario*> *);
	void editarUsuario(Usuario *);
	void eliminarUsuario(int);
	QJsonDocument responseData;
	
public slots:

	void slotPeticion(QNetworkReply*);
signals:
    	void peticionTerminada();
	
	

};

#endif
