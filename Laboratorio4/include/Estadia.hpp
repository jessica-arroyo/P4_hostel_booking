#ifndef ESTADIA_HPP
#define ESTADIA_HPP

#include "DtEstadia.hpp"
#include "DtFechaHora.hpp"


#include <map>
//#include <set> si usamos.
#include <iterator>
#include <iostream>

class Habitacion ;
class Calificacion ;
class Huesped ;

using namespace std ;

class Estadia
{
private:
   DtFechaHora checkIn, checkOut;
   Calificacion* calificacion;
   Habitacion* habitacion;
   Huesped* huesped ;
public:
    Estadia();
    ~Estadia();
    Estadia(DtFechaHora checkIn, DtFechaHora checkOut, Habitacion *hab, Huesped *hues) ;
    void setCheckIn (DtFechaHora checkIn) ;
	void setCheckOut (DtFechaHora checkOut);
    void agregarCalificacion(Calificacion *cal) ;
    void agregarHabitacionAEstadia(Habitacion *hab) ;
	void setHuesped(Huesped *hues) ;

	DtFechaHora getCheckIn () ;
	DtFechaHora getCheckOut () ;
	Calificacion* getCalificacion ();
	Habitacion* getHabitacion();
	Huesped* getHuesped() ;
	DtEstadia getDtEstadia() ;

    //create(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab);  
    //setearValoresIniciales(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab);
    //add(Estadia esta); //va aca o controlador??
    //entrarCal();
    //linkeoHab();  //en el dcd dice linkeo habitacion
    //Estadia find(DtEstadia estadia);
    //aniadirCalificacionAEstadia(Calificacion *cal);
};

#include "Habitacion.hpp"
#include "Calificacion.hpp"
#include "Huesped.hpp"

#endif