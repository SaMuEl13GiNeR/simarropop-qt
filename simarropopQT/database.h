#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QString>

class Database{
public:
	Database();
	bool connect();
	void close();
	void select();
	void insertArticle();
private:
	QSqlDatabase db;
	



};



#endif
