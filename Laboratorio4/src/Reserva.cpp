#include "../include/Reserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

Reserva::Reserva() {
}

Reserva::Reserva(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, Habitacion* hab, Huesped* hues){
	this->codigo = codigo ;
	this->checkIn = checkIn ;
	this->checkOut = checkOut ;
	this->fechaRealizada = fechaRealizada ;
	this->estado = estado ;
	this->costo = costo ;
	this->habitacion = hab;
	this->huesped = hues;
	this->estadia = NULL ;

} 

Reserva::~Reserva() {
}

void Reserva::setCodigo (int codigo){
	this->codigo = codigo ;
}

void Reserva::setCheckIn (DtFechaHora checkIn){
	this->checkIn = checkIn ;
}

void Reserva::setCheckOut (DtFechaHora checkOut){
	this->checkOut = checkOut ;
}

void Reserva::setFechaRealizada (DtFechaHora fechaRealizada){
	this->fechaRealizada = fechaRealizada ;
}

void Reserva::setEstado (TipoEstado estado){
	this->estado = estado ;
}

void Reserva::setCosto (float costo){
	this->costo = costo ;
}

void Reserva::setEstadia (Estadia * est){
	this->estadia = est ;
}

void Reserva::setHabitacion(Habitacion *hab){
	this->habitacion = hab ;
}

void Reserva::setHuesped(Huesped* hues){
	this->huesped = hues ;
}

int Reserva::getCodigo (){
	return this->codigo;
}

DtFechaHora Reserva::getCheckIn (){
	return this->checkIn;
}

DtFechaHora Reserva::getCheckOut (){
	return this->checkOut;
}

DtFechaHora Reserva::getFechaRealizada (){
	return this->fechaRealizada;
}

TipoEstado Reserva::getEstado (){
	return this->estado;
}

float Reserva::getCosto (){
	return this->costo;
}

Estadia* Reserva::getEstadia (){
	return this->estadia;
}

Habitacion* Reserva::getHabitacion(){
	return this->habitacion;
}

Huesped* Reserva::getHuesped(){
	return this->huesped;
}

DtReserva Reserva::getDtReserva(){
	DtReserva dtr = DtReserva(this->codigo, this->checkIn, this->checkOut, this->fechaRealizada, this->estado, this->costo, this->huesped->getEmail());
    return dtr;
}

/*
std::string Reserva::getEmailHuesped (){}

float Reserva::getNumeroHabitacion (){}

Reserva::obtenerReserva(){}

DtFechaHora Reserva::getFecha(){}

Reserva::create(DtFechaHora checkin,DtFechaHora checkout,DtFechaHora fechaRealizacionReserva){}

Reserva::setearValores(DtFechaHora checkin,DtFechaHora checkout,DtFechaHora fechaRealizacionReserva){}

Reserva::add(Reserva res){}

Reserva::agregarHuesAReserva(Huesped hues){}

Reserva::entrarEst(){} //?

Reserva Reserva::find(Codigo reserva){}

//Reserva::setEstadoCerrado(){}

//Reserva::setEstado(Cerrado){}

//Reserva::linkeoest(Estadia est){}

Reserva::encontrarhab(){}

//int Reserva::getCodigo(){}

//Reserva::obtenerEstadiaAsociada(){}

//Reserva::obtenerHuespedAsociado(){}

//Reserva::obtenerCodigoHabitacion(){}

Reserva::remove(Reserva r){}*/

