#ifndef _MODELOTABLAARTICULO_H_
#define _MODELOTABLAARTICULO_H_
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QTableView>
#include "model/articulo.h"
#include <QVariant>
class ModeloTablaArticulo : public QAbstractTableModel{
Q_OBJECT
public:
	ModeloTablaArticulo(QVector <Articulo*> *);
	QVector <Articulo*> *listaArticulo;
	int columnCount(const QModelIndex & = QModelIndex())const;
	int rowCount(const QModelIndex & = QModelIndex())const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role=Qt::DisplayRole)const;
	void tablaModificada();
	
};
#endif
