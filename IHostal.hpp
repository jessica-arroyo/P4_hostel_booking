#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "DtHabitacion.hpp"
//tengo que poner include "Habitacion.hpp"?
#include <map>
#include <iostream>

class IHostal {
  public:
    IHostal::IHostal(){}
    virtual IHostal::IHostal(){}=0 ;
    altaHostal(DtHostal hostal) ;
    std::map<string , DtHostal *> hos listarHostales() : Set(DtHostal) ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
    //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
    map<int , DtHabitacion *> habs listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal) ;
    ingresarDatos(string nombreHostal, DtHabitacion habitacion) ;
    agregarHabitacion() ;
    cancelarHabitacion() ;
    std::map<string , DtHostal *> hos top3hostales() ;
    DtHostal infoHostal(string nombreHostal) ;
    map<int , DtHabitacion *> habs listarHabitaciones() ;
    Hostal encontrarHostal(string nombreHostal) ; //acá creo que tiene que devolver el DtHostal.
    map<int , DtHabitacion *> habs devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout) ;
};
