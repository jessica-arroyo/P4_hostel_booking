#include "../include/DtReservaGrupal.hpp"

		DtReservaGrupal::DtReservaGrupal(){}
		
		DtReservaGrupal::~DtReservaGrupal(){}
		
		DtReservaGrupal::DtReservaGrupal(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, int cantGrupHuespedes, set<string> nombresHuespedes){
			codigo = codigo ; 
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
			nombresHuespedes = nombresHuespedes ;
			cantGrupHuespedes = cantGrupHuespedes;
			
		} 
		
        int DtReservaGrupal::getCantGrupHuespedes(){
			return this->cantGrupHuespedes;
		}
		
		set<string> DtReservaGrupal::getNombresHuespedes(){
			return this->nombresHuespedes ;
		}