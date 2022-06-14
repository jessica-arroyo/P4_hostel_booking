#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "DtHabitacion.hpp"
// poner include "Habitacion.hpp"?
#include <map>
#include <iostream>

using namespace std ;

class IHostal {
  public:
    IHostal(){}
    virtual ~IHostal(){}=0 ;
    virtual void altaHostal(string nombre, string direccion, int telefono, int calificacionProm)=0 ;
    virtual void std::map<string , DtHostal> listarHostales()=0 ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
    //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
    virtual DtHostal infoHostal(string nombreHostal)=0 ;
    virtual void agregarHabitacion(numero,precio,capacidad,nombreH)=0 ;
    virtual bool existeHostal(string nombre)=0 ; 
    virtual bool existeHabitacion(int numero, string nombreHostal)=0 ; 
    
    
    //virtual std::map<string , DtHostal> top3hostales()=0 ;
    //virtual map<int , DtHabitacion> listarHabitaciones()=0 ;
    //virtual Hostal* encontrarHostal(string nombreHostal)=0 ; 
    //virtual map<int , DtHabitacion> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal)=0 ;
    //map<int , DtCalificacion> listarCalificaciones(string nomhos)=0 ; 
        
         
        
};

#endif
