#ifndef _DATABASE_H
#define _DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class Database{

public:
	Database();
	bool connect();
	void close();
	bool insert(const QString& name, const QString& correo, const QString& contrasenya);
	bool update(const QString& name,const QString& correo, int id);
	void select();
	bool remove(int id);
	QSqlQuery selectAll();
	
private:
	QSqlDatabase db;

};

#endif 
