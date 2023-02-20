#include "modelotablaarticulo.h"

ModeloTablaArticulo::ModeloTablaArticulo(QVector <Articulo*> *listaArticuloPasada){
	listaArticulo=listaArticuloPasada;

}
int ModeloTablaArticulo::columnCount(const QModelIndex &)const{
	return 7;
}

int ModeloTablaArticulo::rowCount(const QModelIndex &)const{
	return listaArticulo->size();

}
QVariant ModeloTablaArticulo::data(const QModelIndex &index, int role)const{
	int row = index.row();
	int col = index.column();
	if(role ==Qt::BackgroundRole){
		
	}
	if(role !=Qt::DisplayRole) return QVariant();
	QString cadena("hola");
	switch(col){
		case 0:
			cadena=QString::number(listaArticulo->at(row)->id);
			
			break;
		case 1:
			cadena=listaArticulo->at(row)->name;
			
			break;
		case 2:
			cadena=QString::number(listaArticulo->at(row)->categoria);
			
			break;
		case 3:
			cadena=QString::number(listaArticulo->at(row)->precio);
			
			break;
		case 4:
			cadena=listaArticulo->at(row)->descripcion;
			
			break;
		case 5:
			cadena=listaArticulo->at(row)->ubicacion;
			
			break;
		case 6:
			cadena=QString::number(listaArticulo->at(row)->usuario);
			
			break;

	
	}
	
	return QVariant(cadena);
	
	

}
QVariant ModeloTablaArticulo::headerData(int section,Qt::Orientation orientation, int role)const{
	int i = 0;
	if(role !=Qt::DisplayRole)return QVariant();
		if(orientation == Qt::Horizontal){
			switch(section){
				case 0: return QString("ID ");
				case 1: return QString("Name ");
				case 2: return QString("Categoria ");
				case 3: return QString("Precio ");
				case 4: return QString("Descripcion ");
				case 5: return QString("Ubicacion ");
				case 6: return QString("Usuario ");
				
				
			}
		}
		QString cadena("Bola ");
		if(orientation==Qt::Vertical){
		return QVariant(QString::number(section));
		
		}
		return QVariant();
}

void ModeloTablaArticulo::tablaModificada(){
	qDebug()<<"se actualiza la tabla";
	emit layoutChanged();


}

