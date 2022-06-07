#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "DtHabitacion.hpp"
//tengo que poner include "Habitacion.hpp"?
#include <map>

class IHostal {
  public:
    altaHostal(DtHostal hostal) ;
    listarHostales() : Set(DtHostal) ;
    listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal) : Set(DtHabitacion) ;
    ingresarDatos(string nombreHostal, DtHabitacion habitacion) ;
    agregarHabitacion() ;
    cancelarHabitacion() ;
    top3hostales() :  Set(DtHostal) ;
    infoHostal(string nombreHostal) : DtHostal ;
    listarHabitaciones(): Set(DtHabitacion) ;
    Hostal encontrarHostal(string nombreHostal) ; //acá creo que tiene que devolver el DtHostal.
    devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout): Set(DtHabitacion) ;
};
