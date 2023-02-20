#include "usuario.h"

Usuario::Usuario()
{


}
Usuario::Usuario(int idPasado,QString namePasado,QString apellidosPasado,QString ubicacionPasado,QString correoPasado,QString passwordPasado)
{
	id = idPasado;
	name = namePasado;
	apellidos = apellidosPasado;
	ubicacion = ubicacionPasado;
	correo = correoPasado;
	contrasenya = passwordPasado;
}
Usuario::Usuario(QString namePasado,QString apellidosPasado,QString ubicacionPasado,QString correoPasado,QString passwordPasado)
{
	name = namePasado;
	apellidos = apellidosPasado;
	ubicacion = ubicacionPasado;
	correo = correoPasado;
	contrasenya = passwordPasado;
}


