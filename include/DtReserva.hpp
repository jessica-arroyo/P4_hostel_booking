#ifndef DTRESERVA_HPP
#define DTRESERVA_HPP

#include "../include/DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std;

enum TipoEstado
{
  ABIERTA,
  CERRADA,
  CANCELADA
};

class DtReserva {
	protected : 
        int codigo;
        DtFechaHora checkIn, checkOut, fechaRealizada;
		TipoEstado estado;
		float costo;
		string emailHuesped ;
	public :
		DtReserva();
		DtReserva(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped);
		~DtReserva();
		
		int getCodigo () ;
		DtFechaHora getCheckIn () ;
		DtFechaHora getCheckOut () ;
		DtFechaHora getFechaRealizada () ;
		TipoEstado getEstado () ;
		float getCosto ();
		string getEmailHuesped() ;
		
};
#endif