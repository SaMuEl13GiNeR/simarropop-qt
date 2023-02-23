#include "valoracioncontroller.h"
ValoracionController::ValoracionController(){}

void ValoracionController::insertarValoracion(Valoracion *valoracion){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", 970248153);
	QJsonObject params;
	params.insert("service", "object");
	params.insert("method", "execute");
	QJsonArray args;
	args.append("sge22");
	args.append(2);
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("create");
        
	QJsonObject fields;
     
	fields.insert("estrellas",valoracion->estrellas);
	fields.insert("opinion",valoracion->opinion);
	fields.insert("usuario_emisor",valoracion->usuario_emisor);
	fields.insert("usuario_receptor",valoracion->usuario_receptor);
        
	args.append(fields);
	params.insert("args", args);
	jsonObject.insert("params", params);
        
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	connect(manager,SIGNAL(finished(QNetworkReply *)),
		this,SLOT(slotPeticion(QNetworkReply *)));
		
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
	if (reply->error() != QNetworkReply::NoError) {
		qDebug() << "Error: " << reply->errorString();
	}
}

void ValoracionController::editarValoracion(Valoracion *valoracion){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", 970248153);
	QJsonObject params;
	params.insert("service", "object");
	params.insert("method", "execute");
	QJsonArray args;
	args.append("sge22");
	args.append(2);
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("write");
        
	QJsonObject fields;
	QJsonArray idArray;
	idArray.append(valoracion->id);
	fields.insert("estrellas",valoracion->estrellas);
	fields.insert("opinion",valoracion->opinion);
	fields.insert("usuario_emisor",valoracion->usuario_emisor);
	fields.insert("usuario_receptor",valoracion->usuario_receptor);
  
	args.append(idArray);
	args.append(fields);
	params.insert("args", args);
	jsonObject.insert("params", params);
        
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	connect(manager,SIGNAL(finished(QNetworkReply *)),
		this,SLOT(slotPeticion(QNetworkReply *)));
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
	if (reply->error() != QNetworkReply::NoError) {
		qDebug() << "Error: " << reply->errorString();
	}
}

void ValoracionController::eliminarValoracion(int id){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", 970248153);
	QJsonObject params;
	params.insert("service", "object");
	params.insert("method", "execute");
	QJsonArray args;
	args.append("sge22");
	args.append(2);
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("unlink");
	QJsonArray idArray;
	idArray.append(id);
	args.append(idArray);
	params.insert("args", args);
	jsonObject.insert("params", params);
        
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	connect(manager,SIGNAL(finished(QNetworkReply *)),
		this,SLOT(slotPeticion(QNetworkReply *)));
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
	if (reply->error() != QNetworkReply::NoError) {
		qDebug() << "Error: " << reply->errorString();
	}
}

void ValoracionController::selectAll(){
	QJsonObject jsonObject;
	jsonObject.insert("jsonrpc", "2.0");
	jsonObject.insert("method", "call");
	jsonObject.insert("id", 970248153);
	QJsonObject params;
	params.insert("service", "object");
	params.insert("method", "execute");
	QJsonArray args;
	args.append("sge22");
	args.append(2);
	args.append("1234");
	args.append("simarropop.valoracion");
	args.append("search_read");
	QJsonArray emptyArray;
	args.append(emptyArray);
	QJsonArray fields;
	fields.append("id");
	fields.append("estrellas");
	fields.append("opinion");
	fields.append("usuario_emisor");
	fields.append("usuario_receptor");
	
	args.append(fields);
	params.insert("args", args);
	jsonObject.insert("params", params);
	
	QByteArray postData = QJsonDocument(jsonObject).toJson();
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	connect(manager,SIGNAL(finished(QNetworkReply *)),
		this,SLOT(slotPeticion(QNetworkReply *)));
	QNetworkRequest request;
	request.setUrl(QUrl("http://192.168.8.226:8069/jsonrpc"));
	request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));
	QNetworkReply *reply = manager->post(request, postData);
}

void ValoracionController::slotPeticion(QNetworkReply* reply){
 if (reply->error() != QNetworkReply::NoError) {
	qDebug() << "Error: " << reply->errorString();
	} else {
		responseData =QJsonDocument::fromJson(reply->readAll());
		emit peticionTerminada();
	}
	reply->deleteLater();
}

void ValoracionController::getValoraciones(QVector<Valoracion*> *listaValoracion){
	for(int i = 0; i<listaValoracion->size();i++){
		delete listaValoracion->at(i);	
	}
	listaValoracion->clear();
	QJsonObject jsonResponse = responseData.object();
	if(jsonResponse.contains("result")){
		QJsonArray result = jsonResponse["result"].toArray();
		for(int i = 0; i < result.size(); i++){
			QJsonObject partner = result[i].toObject();
			QJsonArray resultUsuarioEmisor = partner["usuario_emisor"].toArray();
			QJsonArray resultUsuarioReceptor = partner["usuario_receptor"].toArray();
			Valoracion *valoracion = new Valoracion(partner["id"].toDouble(),
			partner["estrellas"].toInt(),
			partner["opinion"].toString(),
			resultUsuarioEmisor.at(0).toInt(),
			resultUsuarioReceptor.at(0).toInt());
			listaValoracion->append(valoracion);
		}
	}
}


