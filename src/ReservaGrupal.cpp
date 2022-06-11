#include "../include/ReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

ReservaGrupal::~ReservaGrupal(){}

ReservaGrupal::ReservaGrupal(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, Habitacion* hab, Huesped* hues, Huesped * grupHuespedes){
	checkIn = checkIn ;
	checkOut = checkOut ;
	fechaRealizada = fechaRealizada ;
	estado = estado ;
	costo = costo ;
	cantH = catH;
} 
ReservaGrupal::setearValoresGrupal(float precio,int cantH){
	precio = precio;
	cantH = catH;
}

Huesped * ReservaGrupal::getGrupoHues(){
	
}

int ReservaGrupal::getCantH(){
	return this->cantH;
}

#endif