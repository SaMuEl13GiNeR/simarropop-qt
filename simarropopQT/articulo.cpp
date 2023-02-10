#include "articulo.h"

Articulo::Articulo(){}

Articulo::Articulo(long idPasado, QString tituloPasado, int likesPasado, QString descripcionPasado,
					 float precioPasado, QString estadoPasado, bool vendidoPasado){
	id = idPasado;
	titulo = tituloPasado;
	likes = likesPasado;
	descripcion = descripcionPasado;
	precio = precioPasado;
	estado = estadoPasado;
	vendido = vendidoPasado;
}
