#include "../include/DtReservaGrupal.hpp"

		DtReservaGrupal::DtReservaGrupal(){}
		
		DtReservaGrupal::~DtReservaGrupal(){}
		
		DtReservaGrupal::DtReservaGrupal(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, int cantGrupHuespedes){
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
			cantGrupHuespedes = cantGrupHuespedes;
		} 
		
        int DtReservaGrupal::getCantGrupHuespedes(){
			return this->cantGrupHuespedes;
		}

#endif