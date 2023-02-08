#include "database.h"
#include <QVariant>

Database::Database(){}

bool Database::connect(){
	db = QSqlDatabase::addDatabase("QPSQL");
	db.setHostName("192.168.8.226");
	db.setDatabaseName("sge22");
	db.setUserName("odoo");
	db.setPassword("1234");
	
	if(!db.open()){
		return false;
	}
	return true;
}

void Database::close(){
	db.close();
}

bool Database::insert(const QString& name, const QString& correo, const QString& contrasenya){
	QSqlQuery query;
	query.prepare("INSERT INTO usuarios (nombre, correo, contrasenya) VALUES (:name, :correo, :contrasenya)");
	query.bindValue(":name", QVariant(name));
	query.bindValue(":correo", QVariant(correo));
	query.bindValue(":contrasenya", QVariant(contrasenya));
	return query.exec();
}

bool Database::update(const QString& name,const QString& correo, int id){
	//, const QString& apellidos, const QString& ubicacion
	QSqlQuery query;
	query.prepare("UPDATE usuario SET name = :name, correo = :correo WHERE id = :id");
	query.bindValue(":name", QVariant(name));
	query.bindValue(":correo", QVariant(correo));
	query.bindValue(":id", QVariant(id));
	return query.exec();
}

void Database::select(){
	QSqlQuery query;
	qDebug()<<"dentro del select";
	query.prepare("SELECT * FROM simarropop_articulo");
	query.exec();
	
	while(query.next())
	{
	qDebug() << "id: " << query.value(0).toString();
	
	}
}


