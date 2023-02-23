#include "modelotablausuario.h"

ModeloTablaUsuario::ModeloTablaUsuario(QVector <Usuario*> *listaUsuarioPasada){
	listaUsuario=listaUsuarioPasada;
}

int ModeloTablaUsuario::columnCount(const QModelIndex &)const{
	return 7;
}

int ModeloTablaUsuario::rowCount(const QModelIndex &)const{
	return listaUsuario->size();
}

QVariant ModeloTablaUsuario::data(const QModelIndex &index, int role)const{
	int row = index.row();
	int col = index.column();
	if(role ==Qt::BackgroundRole){}
	if(role !=Qt::DisplayRole) return QVariant();
	QString cadena("");
	switch(col){
		case 0:
			cadena=QString::number(listaUsuario->at(row)->id);
			break;
		case 1:
			cadena=listaUsuario->at(row)->name;
			break;
		case 2:
			cadena=listaUsuario->at(row)->apellidos;
			break;
		case 3:
			cadena=QString::number(listaUsuario->at(row)->longitud);
			break;
		case 4:
			cadena=QString::number(listaUsuario->at(row)->latitud);
			break;
		case 5:
			cadena=listaUsuario->at(row)->correo;
			break;
		case 6:
			cadena=listaUsuario->at(row)->contrasenya;
			break;
	}
	return QVariant(cadena);
}

QVariant ModeloTablaUsuario::headerData(int section,Qt::Orientation orientation, int role)const{
	if(role !=Qt::DisplayRole)return QVariant();
		if(orientation == Qt::Horizontal){
			switch(section){
				case 0: return QString("ID ");
				case 1: return QString("Name ");
				case 2: return QString("apellidos ");
				case 3: return QString("longitud ");
				case 4: return QString("latitud ");
				case 5: return QString("correo ");
				case 6: return QString("contrasenya ");
			}
		}
		if(orientation==Qt::Vertical){
			return QVariant(QString::number(section));
		}
	return QVariant();
}

void ModeloTablaUsuario::tablaModificada(){
	emit layoutChanged();
}

