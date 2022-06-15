#include "../include/DtReservaIndividual.hpp"

		DtReservaIndividual::DtReservaIndividual(){}
		
		DtReservaIndividual::~DtReservaIndividual(){}
		
		DtReservaIndividual::DtReservaIndividual(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, std::string estado, float costo){
			codigo = codigo ;
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
		} 
