#ifndef _JSONBUILDER_H_
#define _JSONBUILDER_H_
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
class JsonBuilder{
public:
	JsonBuilder();
	QJsonObject jsonObject;
	QJsonObject params;
	QJsonArray args;
	static void insertJson(QString);
   	static void selectAllJson(QString);
	static void updateJson(QString);

};


#endif
