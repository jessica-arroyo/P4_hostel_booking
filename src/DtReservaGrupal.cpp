#include "../include/DtReservaGrupal.hpp"

		DtReservaGrupal::DtReservaGrupal(){}
		
		DtReservaGrupal::~DtReservaGrupal(){}
		
		DtReservaGrupal::DtReservaGrupal(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, std::string estado, float costo, int cantGrupHuespedes){
			codigo = codigo ;
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
