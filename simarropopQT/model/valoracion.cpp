#include "valoracion.h"

Valoracion::Valoracion(){}
Valoracion::Valoracion(int idPasado, int estrellasPasado, QString opinionPasado, int usuario_emisorPasado, int usuario_receptorPasado){
	id = idPasado;
	estrellas = estrellasPasado;
	opinion = opinionPasado;
	usuario_emisor= usuario_emisorPasado;
	usuario_receptor = usuario_receptorPasado;
}

Valoracion::Valoracion(int estrellasPasado, QString opinionPasado, int usuario_emisorPasado, int usuario_receptorPasado){
	estrellas = estrellasPasado;
	opinion = opinionPasado;
	usuario_emisor= usuario_emisorPasado;
	usuario_receptor = usuario_receptorPasado;
}


