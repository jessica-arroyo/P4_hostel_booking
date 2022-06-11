#ifndef DTRESERVAINDIVIDUAL_HPP
#define DTRESERVAINDIVIDUAL_HPP

#include "../include/DtReserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtReservaIndividual : public DtReserva {
	private : 
	public :
		DtReservaIndividual();
		~DtReservaIndividual();
		DtReservaIndividual(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo); 
};
#endif