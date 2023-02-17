#ifndef _VALORACIONCONTROLLER_H
#define _VALORACIONCONTROLLER_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonDocument>
#include <QVector>
#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include "valoracion.h"

class ValoracionController : public QObject{
Q_OBJECT

public:
	ValoracionController();
	void insertarValoracion();
	void selectAll();
	void editarValoraciones(Valoracion *);
	void getValoraciones(QVector <Valoracion*>*);
	QJsonDocument responseData;
	
public slots:
	void slotPeticion(QNetworkReply*);

signals:
	void peticionTerminada();
};

#endif 
