#include "conexion.h"
#include <QNetworkReply>
#include <QDebug>

Conexion::Conexion(){

	manaer = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(triggered(QNetworkReply *)),
		this,SLOT(slotRespuestaFinalizada(QNetworkReply *)));
		
	manager->get(QNetworkRequest(QUrl("https://dummy.restapiexample.com/api/v1/employees")));
}

void Conexion:slotRespuestaFinalizada(QNetworkReply * reply){

	QByteArray data = reply->readAll();
	
	text = QString(data);
	text+="final";
	
	qDebug() << "error" << reply->error();

}
