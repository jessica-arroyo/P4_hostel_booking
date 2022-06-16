#ifndef RESERVAGRUPAL_HPP
#define RESERVAGRUPAL_HPP

#include "../include/Reserva.hpp"
#include "../include/DtReserva.hpp"
#include "../include/DtReservaGrupal.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class Huesped;

class ReservaGrupal : public Reserva {
	private : 
        int cantGrupoHues;
        map<std::string, Huesped *> grupHuespedes;
	public :
		~ReservaGrupal();
		ReservaGrupal(int codigo, DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, int cantGrupoHues, Habitacion* hab, Huesped* hues, map<std::string, Huesped *> grupHuespedes); 
		setearValoresGrupal(float precio,int cantH);
        map<std::string, Huesped *> getGrupHuespedes();
		map<std::string, Huesped *> setGrupHuespedes(map<std::string, Huesped *> grupHuespedes);
        int getCantH();
};
#endif