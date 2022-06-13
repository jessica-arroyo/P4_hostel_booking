#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "DtHabitacion.hpp"
// poner include "Habitacion.hpp"?
#include <map>
#include <iostream>

class IHostal {
  public:
    IHostal(){}
    virtual ~IHostal(){}=0 ;
    virtual void altaHostal(DtHostal hostal)=0 ;
    virtual void std::map<string , DtHostal *> listarHostales()=0 ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
    //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
    virtual DtHostal infoHostal(string nombreHostal)=0 ;
    /*virtual map<int , DtHabitacion *> listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal)=0 ;
    virtual void ingresarDatos(string nombreHostal, DtHabitacion habitacion)=0 ;
    virtual void agregarHabitacion()=0 ;
    virtual void cancelarHabitacion()=0 ;
    virtual std::map<string , DtHostal *> top3hostales()=0 ;
    
    virtual map<int , DtHabitacion *> listarHabitaciones()=0 ;
    virtual DtHostal encontrarHostal(string nombreHostal)=0 ; //acá puse que se devuelva el DtHostal. Porque no se pueden devolver objetos.
    virtual map<int , DtHabitacion *> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout)=0 ;
    */
};

#endif
