#include "../include/ReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

ReservaGrupal::~ReservaGrupal(){}

ReservaGrupal::ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo,int cantH , Habitacion* hab, Huesped* hues, map<std::string, Huesped *> grupHuespedes) : Reserva(codigo, checkIn, checkOut, fechaRealizada, estado, costo, hab, hues){
	cantH = cantH;
	grupHuespedes = grupHuespedes;
} 
//ReservaGrupal::setearValoresGrupal(float precio,int cantH){
	//precio = precio;
	//cantH = cantH;
//}

map<std::string, Huesped *> ReservaGrupal::getGrupHuespedes(){
	return this->grupHuespedes;
}

void ReservaGrupal::setGrupHuespedes(map<std::string, Huesped *>){
	grupHuespedes = grupHuespedes;
}

int ReservaGrupal::getCantH(){
	return this->cantGrupoHues;
}

DtReservaGrupal ReservaGrupal::getDtReservaGrupal(){
	DtReservaGrupal dtr = DtReservaGrupal(this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, this->huesped->getEmail(), this->cantGrupoHues, this->grupHuespedes);
    return dtr;
}
