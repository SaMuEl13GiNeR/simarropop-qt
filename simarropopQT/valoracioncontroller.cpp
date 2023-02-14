#include "valoracioncontroller.h"
ValoracionController::ValoracionController(){}

void ValoracionController::insertarValoracion(){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", "970248153");
	
	QJsonObject params;
	params.insert("service","object");
	params.insert("service","execute");
	
	QJsonArray args;
	args.append("sge22");
	args.append("2");
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("create");
	
	QJsonObject fields;
	fields.insert("estrellas", "4");
	fields.insert("opinion", "la valoracion hecha desde qt");
	fields.insert("usuario_emisor", "42");
	fields.insert("usuario_receptor", "82");
	
	args.append(fields);
	params.insert("args", args);
	jsonObject.insert("params", params);
	
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
	
	if(reply->error() != QNetworkReply::NoError){
		qDebug() << "ERROR: " << reply->errorString();
	} else{
		qDebug() << reply->readAll();
	}
}

void ValoracionController::selectAll(){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", "970248153");
	
	QJsonObject params;
	params.insert("service","object");
	params.insert("service","execute");
	
	QJsonArray args;
	args.append("sge22");
	args.append("2");
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("search_read");
	
	QJsonArray emptyArray;
	args.append(emptyArray);
	
	QJsonArray fields;
	fields.append("id");
	fields.append("estrellas");
	fields.append("opinion");
	
	args.append(fields);
	params.insert("args", args);
	jsonObject.insert("params", params);
	
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
	
	connect(manager, SIGNAL(finished(QNetowrkReply *)),
			this,SLOT(slotPeticion(QNetowrkReply *)));
}

//void ValoracionController::editarValoraciones(Valoracion* valoracion){
	
//}

void ValoracionController::slotPeticion(QNetworkReply* reply){
	if(reply->error() != QNetworkReply::NoError){
		qDebug() << "ERROR: " << reply->errorString();
	} else{
		responseData = QJsonDocument::fromJson(reply->readAll());
		emit peticionTerminada();
		
	}
	reply->deleteLater();
}

void ValoracionController::getValoraciones(QVector<Valoracion*>*listaValoraciones){
	QJsonObject jsonResponse = responseData.object();
		if(jsonResponse.contains("result")){
			QJsonArray result = jsonResponse["result"].toArray();
			for(int i=0; i<result.size();i++){
				QJsonObject partner = result[i].toObject();
				QJsonArray resultUsuarioEmisor = partner["usuario_emisor"].toArray();
				QJsonArray resultUsuarioReceptor = partner["usuario_receptor"].toArray();
				Valoracion *valoracion = new Valoracion(partner["id"].toInt(),
				partner["estrellas"].toInt(),
				partner["opinion"].toString(),
				resultUsuarioEmisor.at(0).toInt(),
				resultUsuarioReceptor.at(0).toInt());
				listaValoraciones->append(valoracion);
			}
			qDebug() << listaValoraciones->size();
		}

}

