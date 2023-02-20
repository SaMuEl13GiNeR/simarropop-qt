#include "articulo.h"

Articulo::Articulo()
{


}
Articulo::Articulo(int idPasado,QString namePasado,int categoriaPasado,float precioPasado,QString descripcionPasado,QString ubicacionPasado,int usuarioPasado)
{
	id = idPasado;
	name = namePasado;
	categoria = categoriaPasado;
	precio = precioPasado;
	descripcion = descripcionPasado;
	ubicacion = ubicacionPasado;
	usuario = usuarioPasado;
}
Articulo::Articulo(QString namePasado,int categoriaPasado,float precioPasado,QString descripcionPasado,QString ubicacionPasado,int usuarioPasado)
{
	name = namePasado;
	categoria = categoriaPasado;
	precio = precioPasado;
	descripcion = descripcionPasado;
	ubicacion = ubicacionPasado;
	usuario = usuarioPasado;
}

