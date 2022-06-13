

// Puse las operaciones que estaban en el DCD, pero capaz que hay más.
//A las operaciones que no aparecía como que devolvieran algo, les puse void.
//Vamos a usar -> o . (dinámico o estático)?

#ifndef HABITACION_H
#define HABITACION_H

#include "Hostal.hpp"

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
    void setNumero(int numero) ;
    void setPrecio(int precio) ;
    void setCapacidad(int capacidad) ;
    void setHostal(Hostal* hostal);
    
    //create(DtHabitacion habitacion); //el constructor sería este, el de arriba, o ambos?
    add(Habitacion hab) ;
    linkeohab(Hostal hostal) ;
    DtHabitacion getDtHabitacion() ;
    bool estadisponibleHabitacion(DtFechaHora checkin, DtFechaHora checkout) ;
    int getPrecio(Habitacion hab) ; // es el mismo de arriba?
    //encontrarHabitacion(int codigoHabitacion, string nombreHostal); //verificar que esta efectivamente no devuelva nada (por lo de encontrar pero no devuelve nada).
    Habitacion buscarHab() ;
    //find(int codigoHabitacion) ; //en tanto que find, no debería devolver algo? Una Habitacion en este caso.
    accederHab(int codigoHabitacion) ;
    int encontrarPrecio(Habitacion hab) ;
    agregarHabitacion(Habitacion hab) ;
    //int getCodigoHab() ; // es el mismo de arriba?
    
}; 

#endif


