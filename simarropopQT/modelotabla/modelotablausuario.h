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
	//void actualizaDatos();
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role=Qt::DisplayRole)const;
	void tablaModificada();
	//bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole);
	//Qt::ItemFlags flags(const QModelIndex &index)const;
	
};

#endif
