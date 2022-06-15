#ifndef DTRESERVA_HPP
#define DTRESERVA_HPP

#include "../include/DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtReserva {
	protected : 
        int codigo;
        DtFechaHora checkIn, checkOut, fechaRealizada;
		std::string estado;
		float costo;
	public :
		DtReserva();
		DtReserva(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, std::string estado, float costo);
		~DtReserva();
		
		int getCodigo () ;
		DtFechaHora getCheckIn () ;
		DtFechaHora getCheckOut () ;
		DtFechaHora getFechaRealizada () ;
		std::string getEstado () ;
		float getCosto ();
};
#endif