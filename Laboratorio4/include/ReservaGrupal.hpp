#ifndef RESERVAGRUPAL_HPP
#define RESERVAGRUPAL_HPP

#include "../include/Reserva.hpp"
#include "../include/DtReserva.hpp"
#include "../include/DtReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

class Huesped;

class ReservaGrupal : public Reserva {
	private : 
        int cantGrupoHues;
        set<Estadia *>estadiasReserva;
        map<string, Huesped *> grupHuespedes;
	public :
		~ReservaGrupal();
		ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, Habitacion* hab, Huesped* hues, int cantGrupoHues, map<string, Huesped *> grupHuespedes); 
		//setearValoresGrupal(float precio,int cantH);
        map<string, Huesped *> getGrupHuespedes();
		void setGrupHuespedes(map<string, Huesped *> grupHuespedes);
        int getCantH();
		DtReservaGrupal getDtReservaGrupal();
   void setEstadiaEnReservaGrupal(Estadia *est);
};
#endif