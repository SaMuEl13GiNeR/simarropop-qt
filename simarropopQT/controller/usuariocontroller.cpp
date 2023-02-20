#include "usuariocontroller.h"
UsuarioController::UsuarioController( )
{

}
void UsuarioController::insertarUsuario(Usuario *usuario){
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
        args.append("res.partner");
        args.append("create");
        
        QJsonObject fields;
     
        fields.insert("name",usuario->name);
        fields.insert("apellidos",usuario->apellidos);
        fields.insert("ubicacion",usuario->ubicacion);
        fields.insert("correo",usuario->correo);
        fields.insert("contrasenya",usuario->contrasenya);
        
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
void UsuarioController::editarUsuario(Usuario *usuario){
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
        args.append("res.partner");
        args.append("write");
        
        QJsonObject fields;
     
     	QJsonArray idArray;
        idArray.append(usuario->id);
        fields.insert("name",usuario->name);
        fields.insert("apellidos",usuario->apellidos);
        fields.insert("ubicacion",usuario->ubicacion);
        fields.insert("correo",usuario->correo);
        fields.insert("contrasenya",usuario->contrasenya);
        
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
void UsuarioController::eliminarUsuario(int id){
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
        args.append("res.partner");
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


void UsuarioController::selectAll(){
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
        args.append("res.partner");
        args.append("search_read");
        QJsonArray emptyArray;
        args.append(emptyArray);
        QJsonArray fields;
        fields.append("id");
        fields.append("name");
        fields.append("apellidos");
        fields.append("ubicacion");
        fields.append("correo");
        fields.append("contrasenya");
        
        
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
	qDebug()<<" No Se ha realizado la peticion";
	
      
	



}
void UsuarioController::slotPeticion(QNetworkReply* reply){
qDebug()<<"Se ha realizado la peticion";
 if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error: " << reply->errorString();
        } else {
        	
            responseData =QJsonDocument::fromJson(reply->readAll());
            emit peticionTerminada();
            
               
        }
        reply->deleteLater();

}

void UsuarioController::getUsuarios(QVector<Usuario*> *listaUsuario){
	for(int i = 0; i<listaUsuario->size();i++){
			delete listaUsuario->at(i);
		
		}
	listaUsuario->clear();
 	QJsonObject jsonResponse = responseData.object();
            
            if(jsonResponse.contains("result")){
            	QJsonArray result = jsonResponse["result"].toArray();
            	for(int i = 0; i < result.size(); i++){
            		QJsonObject partner = result[i].toObject();
            		Usuario *usuario = new Usuario(partner["id"].toInt(),
            		partner["name"].toString(),
            		partner["apellidos"].toString(),
            		partner["ubicacion"].toString(),
            		partner["correo"].toString(),
            		partner["contrasenya"].toString());
            		listaUsuario->append(usuario);
            	}
            	qDebug()<<listaUsuario->size();
            	
            
            }


}


