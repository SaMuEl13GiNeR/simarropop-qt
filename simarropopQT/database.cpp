#include "database.h"
#include <QDebug>
#include <QStringList>

Database::Database(){


}


bool Database::connect(){

	qDebug() << "drivers instalados" << QSqlDatabase::drivers();
	db = QSqlDatabase::addDatabase("QPSQL");
	db.setHostName("192.168.8.99");
	db.setDatabaseName("jessica2dam");
	db.setUserName("odoo");
	db.setPassword("1234");
	if(db.open()){
	
	qDebug()<<"Base de datos abierta";
	return true;
	}
	return false;



}
void Database::close(){
db.close();

}
void Database::select(){
QSqlQuery query;
query.prepare("SELECT * FROM simarropop_categoria");

if(query.exec()){
	qDebug()<<"works!!";
}

while(query.next()){
		qDebug()<<"id: " << query.value(0).toString() << "name: "<<query.value(1).toString();
		
	}
qDebug()<<"dentro";

}

void Database::insertArticle(){
	QSqlQuery query = QSqlQuery(db);
	query.prepare("INSERT INTO simarropop_categoria (name,descripcion_categoria) VALUES 			(:valor1,:valor2)");
	query.bindValue(0, "prueba");
	query.bindValue(1, "prueba");
	if(query.exec()){
		qDebug()<<"works!!";
	}


}
