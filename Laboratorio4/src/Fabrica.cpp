#include "../include/Fabrica.hpp"

Fabrica* Fabrica::_instancia = NULL;

Fabrica::Fabrica(){}
Fabrica::~Fabrica(){}

IUsuario *Fabrica::getIUsuario()
{
	return ControladorUsuario::getInstancia();
}

IHostal *Fabrica::getIHostal()
{
	return ControladorHostal::getInstancia();
}

IFecha* Fabrica::getIFecha()
{
	return Fecha::getInstancia();
}
IReserva *Fabrica::getIReserva()
{
	return ControladorReserva::getInstancia();
}

Fabrica *Fabrica::getInstancia()
{
	if (_instancia == NULL)
		_instancia = new Fabrica();
	return _instancia;
}