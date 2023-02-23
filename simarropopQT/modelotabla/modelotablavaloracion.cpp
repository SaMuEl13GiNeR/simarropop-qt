#include "modelotablavaloracion.h"

ModeloTablaValoracion::ModeloTablaValoracion(QVector <Valoracion*> *listaValoracionPasada){
	listaValoracion=listaValoracionPasada;
}

int ModeloTablaValoracion::columnCount(const QModelIndex &)const{
	return 5;
}

int ModeloTablaValoracion::rowCount(const QModelIndex &)const{
	return listaValoracion->size();
}

QVariant ModeloTablaValoracion::data(const QModelIndex &index, int role)const{
	int row = index.row();
	int col = index.column();
	if(role ==Qt::BackgroundRole){}
	if(role !=Qt::DisplayRole) return QVariant();
	QString cadena("");
	switch(col){
		case 0:
			cadena=QString::number(listaValoracion->at(row)->id);
			break;
		case 1:
			cadena=QString::number(listaValoracion->at(row)->estrellas);
			break;
		case 2:
			cadena=listaValoracion->at(row)->opinion;
			break;
		case 3:
			cadena=QString::number(listaValoracion->at(row)->usuario_emisor);
			break;
		case 4:
			cadena=QString::number(listaValoracion->at(row)->usuario_receptor);
			break;
	}
	return QVariant(cadena);
}
QVariant ModeloTablaValoracion::headerData(int section,Qt::Orientation orientation, int role)const{
	if(role !=Qt::DisplayRole)return QVariant();
		if(orientation == Qt::Horizontal){
			switch(section){
				case 0: return QString("ID ");
				case 1: return QString("Estrellas ");
				case 2: return QString("Opinion ");
				case 3: return QString("Usuario emisor ");
				case 4: return QString("Usuario receptor ");
			}
		}
		if(orientation==Qt::Vertical){
			return QVariant(QString::number(section));
		}
	return QVariant();
}

void ModeloTablaValoracion::tablaModificada(){
	emit layoutChanged();
}

