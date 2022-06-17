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

using namespace std ;

class Estadia
{
private:
   DtFechaHora checkIn, checkOut;
   string promo;
   Calificacion* calificacion;
   Habitacion* habitacion;
public:
    Estadia();
    ~Estadia();
    Estadia(DtFechaHora checkIn, DtFechaHora checkOut, string promo, Calificacion *cal, Habitacion *hab) ;
    void setCheckIn (DtFechaHora checkIn) ;
	void setCheckOut (DtFechaHora checkOut);
    void setPromo (string promo) ;
    void agregarCalificacion(Calificacion *cal) ;
    void agregarHabitacionAEstadia(Habitacion *hab) ;

    string getPromo () ;
	DtFechaHora getCheckIn () ;
	DtFechaHora getCheckOut () ;
	Calificacion* getCalificacion ();
	Habitacion* getHabitacion();

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

#endif