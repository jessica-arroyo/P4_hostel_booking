#ifndef DTRESERVAGRUPAL_HPP
#define DTRESERVAGRUPAL_HPP

#include "DtReserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std;

class DtReservaGrupal : public DtReserva {
	private : 
        int cantGrupHuespedes;
		set<string> nombresHuespedes ;
	public :
		DtReservaGrupal();
		~DtReservaGrupal();
		DtReservaGrupal(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped, int cantGrupHuespedes, map<std::string, Huesped *> grupHuespedes); 
        int getCantGrupHuespedes();
		set<string> getNombresHuespedes() ;
};
#endif