#include "../include/ReservaIndividual.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

ReservaIndividual::~ReservaIndividual(){}

ReservaIndividual::ReservaIndividual(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, Habitacion* hab, Huesped* hues) : Reserva(codigo, checkIn, checkOut, fechaRealizada, estado, costo, hab, hues){

} 

DtReservaIndividual ReservaIndividual::getDtReservaIndividual(){
//DtReservaIndividual dtr = DtReservaIndividual(this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, this->huesped->getEmail());
   /* DtReservaIndividual dtr = DtReservaIndividual(this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, "peii");*/
	return {this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, this->huesped->getEmail()};
}
//ReservaIndividual::setearValoresIndividual(float precio){
	//precio = precio;
//}

