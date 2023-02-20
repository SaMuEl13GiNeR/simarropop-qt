#include "articulocontroller.h"
ArticuloController::ArticuloController( )
{

}
void ArticuloController::insertarArticulo(Articulo *articulo){
qDebug()<<"se realiza el insert";
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
        args.append("simarropop.articulo");
        args.append("create");
        
        QJsonObject fields;
     
        fields.insert("name",articulo->name);
        fields.insert("categoria",articulo->categoria);
        fields.insert("precio",articulo->precio);
        fields.insert("descripcion",articulo->descripcion);
        fields.insert("ubicacion",articulo->ubicacion);
        fields.insert("usuario",articulo->usuario);
        
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
        } else {
        
        qDebug() << reply->readAll();
        }





}
void ArticuloController::editarArticulo(Articulo *articulo){
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
        args.append("simarropop.articulo");
        args.append("write");
        
        QJsonObject fields;
     
     	QJsonArray idArray;
        idArray.append(articulo->id);
        fields.insert("name",articulo->name);
        fields.insert("usuario",articulo->usuario);
        fields.insert("categoria",articulo->categoria);
        fields.insert("precio",articulo->precio);
        fields.insert("descripcion",articulo->descripcion);
        fields.insert("ubicacion",articulo->ubicacion);
        fields.insert("usuario",articulo->usuario);
        
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
        } else {
        
        qDebug() << reply->readAll();
        }





}
void ArticuloController::eliminarArticulo(int id){
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
        args.append("simarropop.articulo");
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
        } else {
        
        qDebug() << reply->readAll();
        }



}


void ArticuloController::selectAll(){
qDebug()<<"Llego a selectall";
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
        args.append("simarropop.articulo");
        args.append("search_read");
        QJsonArray emptyArray;
        args.append(emptyArray);
        QJsonArray fields;
        fields.append("id");
        fields.append("name");
        fields.append("categoria");
        fields.append("precio");
        fields.append("descripcion");
        fields.append("ubicacion");
        fields.append("usuario");
        
        
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
void ArticuloController::slotPeticion(QNetworkReply* reply){
 if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error: " << reply->errorString();
        } else  if (reply->isFinished()){
        	
            responseData =QJsonDocument::fromJson(reply->readAll());
            emit peticionTerminada();
            
               
        }
        reply->deleteLater();

}

void ArticuloController::getArticulos(QVector<Articulo*> *listaArticulo){
		for(int i = 0; i<listaArticulo->size();i++){
			delete listaArticulo->at(i);
		
		}
		listaArticulo->clear();
		qDebug()<<"tamaño despues del clear:"<<listaArticulo->size();
 		QJsonObject jsonResponse = responseData.object();
            
            if(jsonResponse.contains("result")){
            	QJsonArray result = jsonResponse["result"].toArray();
            	qDebug()<<"result size:"<<result.size();
            	for(int i = 0; i < result.size(); i++){
            		QJsonObject partner = result[i].toObject();
            		QJsonArray resultCategory = partner["categoria"].toArray();
            		QJsonArray resultUsuario = partner["usuario"].toArray();
            		Articulo *articulo = new Articulo(partner["id"].toInt(),
            		partner["name"].toString(),
            		resultCategory.at(0).toInt(),
            		partner["precio"].toDouble(),
            		partner["descripcion"].toString(),
            		partner["ubicacion"].toString(),
            		resultUsuario.at(0).toInt());
            		listaArticulo->append(articulo);
            	}
            	qDebug()<<"tamaño despues de la peticion"<<listaArticulo->size();
            	
            
            }


}


