#include "../include/ReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

ReservaGrupal::~ReservaGrupal(){}

ReservaGrupal::ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo,int cantH , Habitacion* hab, Huesped* hues, map<std::string, Huesped *> grupHuespedes){
	codigo = codigo ;
	checkIn = checkIn ;
	checkOut = checkOut ;
	fechaRealizada = fechaRealizada ;
	estado = estado ;
	costo = costo ;
	cantH = cantH;
	hab = hab;
	hues = hues;
	grupHuespedes = grupHuespedes;
} 
ReservaGrupal::setearValoresGrupal(float precio,int cantH){
	precio = precio;
	cantH = cantH;
}

map<std::string, Huesped *> ReservaGrupal::getGrupHuespedes(){
	return this->grupHuespedes;
}

map<std::string, Huesped *> ReservaGrupal::setGrupHuespedes(map<std::string, Huesped *>){
	grupHuespedes = grupHuespedes;
}

int ReservaGrupal::getCantH(){
	return this->cantGrupoHues;
}
