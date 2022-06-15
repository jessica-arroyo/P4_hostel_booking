#include "../include/ReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

ReservaGrupal::~ReservaGrupal(){}

ReservaGrupal::ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo,int cantH , Habitacion* hab, Huesped* hues, Huesped * grupHuespedes){
	codigo = codigo ;
	checkIn = checkIn ;
	checkOut = checkOut ;
	fechaRealizada = fechaRealizada ;
	estado = estado ;
	costo = costo ;
	cantH = cantH;
} 
ReservaGrupal::setearValoresGrupal(float precio,int cantH){
	precio = precio;
	cantH = cantH;
}

map<std::string, Huesped *> ReservaGrupal::getGrupoHues(){
	return this->grupHuespedes;
}

map<std::string, Huesped *> ReservaGrupal::setGrupHuespedes(map<std::string, Huesped *>){
	grupHuespedes = grupHuespedes;
}

int ReservaGrupal::getCantH(){
	return this->cantH;
}

#endif