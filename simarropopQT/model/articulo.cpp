#include "articulo.h"

Articulo::Articulo()
{


}
Articulo::Articulo(int idPasado, QString tituloPasado, int likesPasado, QString descripcionPasado, float precioPasado, QString estadoPasado, int usuario_compradorPasado, int usuario_vendedorPasado,int categoriaPasado)
{
	id = idPasado;
	titulo = tituloPasado;
	likes = likesPasado;
	descripcion = descripcionPasado;
	precio = precioPasado;
	estado = estadoPasado;
	usuario_comprador = usuario_compradorPasado;
	usuario_vendedor = usuario_vendedorPasado;
	categoria = categoriaPasado;
}
Articulo::Articulo(QString tituloPasado, int likesPasado, QString descripcionPasado, float precioPasado, QString estadoPasado, int usuario_compradorPasado, int usuario_vendedorPasado,int categoriaPasado)
{
	titulo = tituloPasado;
	likes = likesPasado;
	descripcion = descripcionPasado;
	precio = precioPasado;
	estado = estadoPasado;
	usuario_comprador = usuario_compradorPasado;
	usuario_vendedor = usuario_vendedorPasado;
	categoria = categoriaPasado;
}

