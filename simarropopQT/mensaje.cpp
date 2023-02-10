#include "mensaje.h"

Mensaje::Mensaje(){}

Mensaje::Mensaje(long idPasado, QString contenidoPasado, QString fechaPasado){
	id = idPasado;
	contenido = contenidoPasado;
	fecha = fechaPasado;
}
