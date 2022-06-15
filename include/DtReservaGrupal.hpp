#ifndef DTRESERVAGRUPAL_HPP
#define DTRESERVAGRUPAL_HPP

#include "DtReserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtReservaGrupal : public DtReserva {
	private : 
        int cantGrupHuespedes;
	public :
		DtReservaGrupal();
		~DtReservaGrupal();
		DtReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, std::string estado, float costo, int cantGrupHuespedes); 
        int getCantGrupHuespedes();
};
#endif