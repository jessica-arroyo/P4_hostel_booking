#include "../include/Reserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

Reserva::Reserva() {
}

Reserva::~Reserva() {
}

void Reserva::setCodigo (int codigo){
	codigo = codigo ;
}

void Reserva::setCheckIn (DtFechaHora checkIn){
	checkIn = checkIn ;
}

void Reserva::setCheckOut (DtFechaHora checkOut){
	checkOut = checkOut ;
}

void Reserva::setFechaRealizada (DtFechaHora fechaRealizada){
	fechaRealizada = fechaRealizada ;
}

void Reserva::setEstado (TipoEstado estado){
	estado = estado ;
}

void Reserva::setCosto (float costo){
	costo = costo ;
}

void Reserva::agregarEstadia (Estadia * est){}

void Reserva::agregarHabitacion(Habitacion *hab){}

void Reserva::agregarHuesped(Huesped* hues){}

int getCodigo (){
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

Estadia* Reserva::getEstadia (){}

Habitacion* Reserva::getHabitacion(){}

Huesped* Reserva::getHuesped(){}

std::string Reserva::getEmailHuesped (){}

float Reserva::getNumeroHabitacion (){}

DtReserva Reserva::getDtReserva(){}

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

Reserva::remove(Reserva r){}

#endif