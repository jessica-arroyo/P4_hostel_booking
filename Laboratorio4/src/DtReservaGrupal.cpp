#include "../include/DtReservaGrupal.hpp"

		DtReservaGrupal::DtReservaGrupal(){}
		
		DtReservaGrupal::~DtReservaGrupal(){}
		
		DtReservaGrupal::DtReservaGrupal(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped, int cantGrupHuespedes, map<std::string, Huesped *> grupHuespedes) : DtReserva(codigo, checkIn, checkOut, fechaRealizada, estado, costo, emailHuesped){
			map<std::string, Huesped *>::iterator grupHues ;
			set<string> nombresHuespedes;
			for(grupHues=grupHuespedes.begin(); grupHues!=grupHuespedes.end(); grupHues++){
				nombresHuespedes.insert(grupHues->second->getNombre());
			}
			this->cantGrupHuespedes = cantGrupHuespedes;
			
		} 
		
        int DtReservaGrupal::getCantGrupHuespedes(){
			return this->cantGrupHuespedes;
		}
		
		set<string> DtReservaGrupal::getNombresHuespedes(){
			return this->nombresHuespedes ;
		}