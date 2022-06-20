#include "../include/ReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

ReservaGrupal::~ReservaGrupal(){}

ReservaGrupal::ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, Habitacion* hab, Huesped* hues, int cantGrupoHues,  map<string, Huesped *> grupHuespedes) : Reserva(codigo, checkIn, checkOut, fechaRealizada, estado, costo, hab, hues){
	this->cantGrupoHues = cantGrupoHues;
	this->grupHuespedes = grupHuespedes;
} 
//ReservaGrupal::setearValoresGrupal(float precio,int cantH){
	//precio = precio;
	//cantH = cantH;
//}

map<string, Huesped *> ReservaGrupal::getGrupHuespedes(){
	return this->grupHuespedes;
}

void ReservaGrupal::setGrupHuespedes(map<string, Huesped *>){
	this->grupHuespedes = grupHuespedes;
}

int ReservaGrupal::getCantH(){
	return this->cantGrupoHues;
}

DtReservaGrupal ReservaGrupal::getDtReservaGrupal(){
	DtReservaGrupal dtr = DtReservaGrupal(this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, this->huesped->getEmail(), this->cantGrupoHues, this->grupHuespedes);
 /*DtReservaGrupal dtr = DtReservaGrupal(1, this->checkIn, this->checkOut, this->fechaRealizada, ABIERTA, 20, this->huesped->getEmail(), 2, this->grupHuespedes);*/
    return dtr;
}

 void ReservaGrupal::setEstadiaEnReservaGrupal(Estadia *est){
   this->estadiasReserva.insert(est);
 };
