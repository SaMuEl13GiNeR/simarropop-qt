#ifndef _MODELOTABLAUSUARIO_H_
#define _MODELOTABLAUSUARIO_H_
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QTableView>
#include "model/usuario.h"
#include <QVariant>
class ModeloTablaUsuario : public QAbstractTableModel{
Q_OBJECT
public:
	ModeloTablaUsuario(QVector <Usuario*> *);
	QVector <Usuario*> *listaUsuario;
	int columnCount(const QModelIndex & = QModelIndex())const;
	int rowCount(const QModelIndex & = QModelIndex())const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role=Qt::DisplayRole)const;
	void tablaModificada();
	
};
#endif
