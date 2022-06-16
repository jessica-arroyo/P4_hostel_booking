#ifndef FABRICA_H
#define FABRICA_H

#include "../include/IUsuario.hpp"
#include "../include/IHostal.hpp"
#include "../include/IReserva.hpp"
#include "../include/IFecha.hpp"
#include "ControladorHostal.hpp"
#include "ControladorReserva.hpp"
#include "ControladorUsuario.hpp"
#include <cstddef>

class ControladorUsuario;
class ControladorHostal;
class ControladorReserva;
class Fecha;

class Fabrica
{
	private:
		Fabrica();
		static Fabrica *_instancia;

	public:
		~Fabrica();
		IHostal *getIHostal();
		IFecha *getIFecha();
		IUsuario *getIUsuario();
		IReserva *getIReserva();
		static Fabrica* getInstancia();
};

#include "../include/ControladorUsuario.hpp"
#include "../include/ControladorHostal.hpp"
#include "../include/ControladorReserva.hpp"
#include "../include/Fecha.hpp"

#endif