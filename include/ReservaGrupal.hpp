#ifndef RESERVAGRUPAL_HPP
#define RESERVAGRUPAL_HPP

#include "../include/Reserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class Huesped;

class ReservaGrupal : public Reserva {
	private : 
        int cantGrupoHues;
        std::map<std::string, Huesped *> grupHuespedes;
	public :
		~ReservaGrupal();
		ReservaGrupal(DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, int cantGrupoHues, Habitacion* hab, Huesped* hues, Huesped * grupHuespedes); 
		setearValoresGrupal(float precio,int cantH);
        Huesped * getGrupoHues();
        int getCantH();
};
#endif