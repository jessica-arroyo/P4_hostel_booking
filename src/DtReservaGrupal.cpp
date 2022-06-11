#include "../include/DtReservaGrupal.hpp"

		ReservaGrupal::DtReservaGrupal(){}
		
		ReservaGrupal::~DtReservaGrupal(){}
		
		ReservaGrupal::DtReservaGrupal(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, int cantGrupoHues){
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
			cantGrupoHues = cantGrupoHues;
		} 
		
        int ReservaGrupal::getCantH(){
			return this->cantH;
		}

#endif