#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
#include "DtHabitacion.hpp" 
#include "DtCalificacion.hpp"
#include "DtEmpleado.hpp"
#include "DtHuesped.hpp"
#include "Habitacion.hpp" 
#include "Calificacion.hpp"
#include "Reserva.hpp"
#include "DtReserva.hpp"
#include "ReservaGrupal.hpp"
#include "ReservaIndividual.hpp"
#include "DtReservaGrupal.hpp"
#include "DtReservaIndividual.hpp"

#include <map>
#include <set>
#include <iostream>

using namespace std ;

class IHostal {
  public:
    IHostal();
    virtual ~IHostal()=0 ;
    
    virtual void altaHostal(string nombre, string direccion, string telefono, int calificacionProm)=0 ;
    virtual map<string , DtHostal> listarHostales()=0 ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
    //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
    virtual DtHostal infoHostal(string nombreHostal)=0 ;
    virtual void agregarHabitacion(int numero,int precio,int capacidad,string nombreH)=0 ;
    virtual bool existeHostal(string nombre)=0 ; 
    virtual bool existeHabitacion(int numero, string nombreHostal)=0 ; 
    virtual map<string, Hostal*> getSetHostales() = 0 ;
	virtual map<int , DtHabitacion> listarHabitaciones(string nombreHostal) = 0 ;
    virtual map<int , DtReservaGrupal> listarReservasGrupal(string nombreHostal) = 0 ; 
	virtual map<int , DtReservaIndividual> listarReservasIndividual(string nombreHostal) = 0; 
	virtual map<int, DtCalificacion> listarCalificaciones(string nombreHostal) = 0; 
    
    //virtual map<string , DtHostal> top3hostales()=0 ;
    //virtual map<int , DtHabitacion> listarHabitaciones()=0 ;
    virtual Hostal* encontrarHostal(string nombreHostal)=0 ; 
    virtual map<int , DtHabitacion> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal)=0 ;
    //set<DtCalificacion> listarCalificaciones(string nomhos)=0 ; 
        
         
        
};

#endif
