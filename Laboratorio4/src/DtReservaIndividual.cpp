#include "../include/DtReservaIndividual.hpp"

		DtReservaIndividual::DtReservaIndividual(){}
		
		DtReservaIndividual::~DtReservaIndividual(){}
		
		DtReservaIndividual::DtReservaIndividual(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped) : DtReserva(codigo, checkIn, checkOut, fechaRealizada, estado, costo, emailHuesped){
		} 
