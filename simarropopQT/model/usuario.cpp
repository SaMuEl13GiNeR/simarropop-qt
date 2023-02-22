#include "usuario.h"

Usuario::Usuario()
{


}
Usuario::Usuario(int idPasado,QString namePasado,QString apellidosPasado, float longitudPasado, float latitudPasado, QString correoPasado,QString passwordPasado)
{
	id = idPasado;
	name = namePasado;
	apellidos = apellidosPasado;
	longitud = longitudPasado;
	latitud = latitudPasado;
	correo = correoPasado;
	contrasenya = passwordPasado;
}
Usuario::Usuario(QString namePasado, QString apellidosPasado, float longitudPasado, float latitudPasado, QString correoPasado, QString passwordPasado)
{
	name = namePasado;
	apellidos = apellidosPasado;
	longitud = longitudPasado;
	latitud = latitudPasado;
	correo = correoPasado;
	contrasenya = passwordPasado;
}


