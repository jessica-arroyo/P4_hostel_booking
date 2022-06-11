#include "../include/DtReservaIndividual.hpp"

		DtReservaIndividual::DtReservaIndividual(){}
		
		DtReservaIndividual::~DtReservaIndividual(){}
		
		DtReservaIndividual::DtReservaIndividual(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo){
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
		} 

#endif