#ifndef DTRESERVA_HPP
#define DTRESERVA_HPP

#include "../include/DtFechaHora.hpp"
#include "../include/TipoEstado.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtReserva {
	protected : 
        int codigo;
        DtFechaHora checkIn, checkOut, fechaRealizada;
		TipoEstado estado;
		float costo;
	public :
		Reserva();
		~Reserva();
		
		int getCodigo () ;
		DtFechaHora getCheckIn () ;
		DtFechaHora getCheckOut () ;
		DtFechaHora getFechaRealizada () ;
		TipoEstado getEstado () ;
		float getCosto ();
};
#endif