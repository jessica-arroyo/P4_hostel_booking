#include "../include/DtReservaIndividual.hpp"

		DtReservaIndividual::DtReservaIndividual(){}
		
		DtReservaIndividual::~DtReservaIndividual(){}
		
		DtReservaIndividual::DtReservaIndividual(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped){
			codigo = codigo ;
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
			emailHuesped = emailHuesped ;
		} 
