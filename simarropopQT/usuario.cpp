#include "usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(long idPasado, QString nombrePasado, QString apellidosPasado, 
				QString ubicacionPasado, QString contrasenyaPasado, QString correoPasado){
	id = idPasado;
	nombre = nombrePasado;
	apellidos = apellidosPasado;
	ubicacion = ubicacionPasado;
	contrasenya = contrasenyaPasado;
	correo = correoPasado;
}
