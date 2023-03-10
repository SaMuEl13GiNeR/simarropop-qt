#ifndef _MODELOTABLAVALORACION_H_
#define _MODELOTABLAVALORACION_H_
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QTableView>
#include "model/valoracion.h"
#include <QVariant>
class ModeloTablaValoracion : public QAbstractTableModel{
Q_OBJECT
public:
	ModeloTablaValoracion(QVector <Valoracion*> *);
	QVector <Valoracion*> *listaValoracion;
	int columnCount(const QModelIndex & = QModelIndex())const;
	int rowCount(const QModelIndex & = QModelIndex())const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role=Qt::DisplayRole)const;
	void tablaModificada();
	
};
#endif
