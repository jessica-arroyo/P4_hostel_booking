#ifndef ESTADIA_HPP
#define ESTADIA_HPP

#include <map>
//#include <set> si usamos.
#include <iterator>
#include <iostream>

#include "../include/DtFechaHora.hpp"
#include "../include/Habitacion.hpp"
#include "../include/Calificacion.hpp"
#include "../include/DtEstadia.hpp"

class Estadia
{
private:
   DtFechaHora checkIn, checkout;
   std::string promo;
   Calificacion* calificacion;
   Habitacion* habitacion;
public:
    Estadia();
    virtual ~Estadia() = 0;
    void setCheckIn (DtFechaHora checkIn) ;
	void setCheckOut (DtFechaHora checkOut);
    void setPromo (std::string promo) ;
    void agregarCalificacion(Calificacion *cal) ;
    void agregarHabitacion(Habitacion *hab) ;

    std::string getPromo () ;
	DtFechaHora getCheckIn () ;
	DtFechaHora getCheckOut () ;
	Estadia* getCalificacion ();
	Habitacion* getHabitacion();

    create(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab);  
    setearValoresIniciales(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab);
    add(Estadia esta); //va aca o controlador??
    entrarCal();
    linkeoHab();  //en el dcd dice linkeo habitacion
    Estadia find(DtEstadia estadia);
    aniadirCalificacionAEstadia(Calificacion cal);
}
#endif