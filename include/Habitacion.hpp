

#ifndef HABITACION_H
#define HABITACION_H

#include "DtHabitacion.hpp"

class Hostal ;

class Habitacion {
  private:
    int numero ;
    int precio ;
    int capacidad ;
    Hostal *hostal ;
  public:
    Habitacion(int numero,int precio, int capacidad) ;
    ~Habitacion() ; 
    int getNumero() ;
    int getPrecio() ;
    int getCapacidad() ;
    Hostal* getHostal() ;
    void setNumero(int numero) ;
    void setPrecio(int precio) ;
    void setCapacidad(int capacidad) ;
    void setHostal(Hostal* hostal);
    
  
    
    DtHabitacion getDtHabitacion() ;
    //bool estadisponibleHabitacion(DtFechaHora checkin, DtFechaHora checkout) ; ////creo que vamos a hacer la función desde Reserva.
    //int getPrecio(Habitacion hab) ; // No tiene sentido la función.
    //encontrarHabitacion(int codigoHabitacion, string nombreHostal); //Va en el ControladorHostal.
    //Habitacion buscarHab() ; //Sin el nombre del hostal va al objeto Hostal.
    //find(int codigoHabitacion) ; Sin el nombre del hostal debería ir al objeto Hostal.
    //accederHab(int codigoHabitacion) ; // ni idea
    //int encontrarPrecio(Habitacion hab) ; // wtf
    //agregarHabitacion(Habitacion hab) ; //ya está en ControladorHostal.
    

    //linkeohab(Hostal hostal) ; está arriba.
    
}; 

#include "Hostal.hpp"

#endif


