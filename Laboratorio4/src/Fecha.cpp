#include "../include/DtFechaHora.hpp"
#include "../include/Fecha.hpp"

//inicializa la instancia a 0
Fecha* Fecha::_instancia = 0;

Fecha::Fecha() {}

DtFechaHora Fecha::getFechaHora()
{
	return this->horaActual;
}

void Fecha::setFechaHora(DtFechaHora horaActual)
{
	this->horaActual=horaActual;
}


Fecha* Fecha::getInstancia()
{
	if (_instancia == 0){
		_instancia = new Fecha;	
	}
	return _instancia;
}
