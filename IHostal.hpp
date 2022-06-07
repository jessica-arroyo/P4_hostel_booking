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
    IHostal(){}
    virtual ~IHostal(){}=0 ;
    virtual altaHostal(DtHostal hostal)=0 ;
    virtual std::map<string , DtHostal *> hos listarHostales()=0 ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
    //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
    virtual map<int , DtHabitacion *> habs listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal)=0 ;
    virtual ingresarDatos(string nombreHostal, DtHabitacion habitacion)=0 ;
    virtual agregarHabitacion()=0 ;
    virtual cancelarHabitacion()=0 ;
    virtual std::map<string , DtHostal *> hos top3hostales()=0 ;
    virtual DtHostal infoHostal(string nombreHostal)=0 ;
    virtual map<int , DtHabitacion *> habs listarHabitaciones()=0 ;
    virtual Hostal encontrarHostal(string nombreHostal)=0 ; //acá creo que tiene que devolver el DtHostal.
    virtual map<int , DtHabitacion *> habs devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout)=0 ;
};
