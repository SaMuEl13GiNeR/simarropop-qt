#ifndef _VALORACIONCONTROLLER_H_
#define _VALORACIONCONTROLLER_H_
#include <QString>
#include "model/valoracion.h"
#include <QtNetwork>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>

class ValoracionController : public QObject{
Q_OBJECT

public:
	ValoracionController();
	void selectAll();
	void editarValoracion(Valoracion *);
	void insertarValoracion(Valoracion *);
	void getValoraciones(QVector<Valoracion*> *);
	void eliminarValoracion(int);
	QJsonDocument responseData;
	
public slots:
	void slotPeticion(QNetworkReply*);
	
signals:
    	void peticionTerminada();
};

#endif
