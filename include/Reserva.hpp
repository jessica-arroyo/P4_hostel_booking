#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "../include/DtFechaHora.hpp"
#include "../include/TipoEstado.hpp"
#include "../include/DtReserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class Habitacion;
class Estadia;
class Huesped;

class Reserva {
	protected : 
        int codigo;
        DtFechaHora checkIn, checkOut, fechaRealizada;
		TipoEstado estado;
		float costo;
        Estadia * estadia;
		Habitacion * habitacion;
		Huesped * huesped;
	public :
		Reserva();
		virtual ~Reserva() = 0;
		void setCodigo (int codigo) ;
		void setCheckIn (DtFechaHora checkIn) ;
		void setCheckOut (DtFechaHora checkOut);	
		void setFechaRealizada (DtFechaHora fechaRealizada) ;
		void setEstado (TipoEstado estado);
		void setCosto (float costo);
		void setEstadia(Estadia * est) ;
		void setHabitacion(Habitacion *hab);
		void setHuesped(Huesped* hues);
		
		int getCodigo () ;
		DtFechaHora getCheckIn () ;
		DtFechaHora getCheckOut () ;
		DtFechaHora getFechaRealizada () ;
		TipoEstado getEstado () ;
		float getCosto ();
		Estadia* getEstadia ();
		Habitacion* getHabitacion() ;
		Huesped* getHuesped() ;
		std::string getEmailHuesped ();
		float getNumeroHabitacion ();

		DtReserva getDtReserva();
		obtenerReserva();
		DtFechaHora getFecha(); 
		create(DtFechaHora checkin,DtFechaHora checkout,DtFechaHora fechaRealizacionReserva);
		setearValores(DtFechaHora checkin,DtFechaHora checkout,DtFechaHora fechaRealizacionReserva);
		add(Reserva res);
		agregarHuesAReserva(Huesped hues);
		entrarEst(); //?
		Reserva find(Codigo reserva);
		//setEstadoCerrado();
		//setEstado(Cerrado);
		//linkeoest(Estadia est);
		encontrarhab();
		//int getCodigo();
		//obtenerEstadiaAsociada();
		//obtenerHuespedAsociado();
		//obtenerCodigoHabitacion();
		remove(Reserva r);
		
};
#include "../include/Habitacion.hpp"
#include "../include/Estadia.hpp"
#include "../include/Huesped.hpp"
#endif