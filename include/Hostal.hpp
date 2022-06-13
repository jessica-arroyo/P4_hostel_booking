#ifndef HOSTAL_H
#define HOSTAL_H

#include "DtHostal.hpp"
#include "Reserva.hpp" //Hay que incluír también las subclases?
#include "Habitacion.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
//#include "DtEstadia.hpp" si devolvemos un map de DtEstadia en obtenerEstadiasHostal hay que poner este include,

#include <map>
#include <iterator>
#include <iostream>

using namespace std ;
class Hostal {
  private:
    string nombre ;
    string direccion ;
    int telefono ;
    float calificacionPromedio ;
    map<int , Habitacion *> habitaciones; 
    map<int , Reserva *> reservas;
    map<string , Empleado *> empleados;
    map<string , Huesped *> huespedes;
    
  
  public:
    Hostal(string nombre, string direccion, int telefono,0) ; //empieza con calificacionPromedio=0.
    ~Hostal() ;
    string getNombre() ;
    string getDireccion() ;
    int getTelefono() ;
    int getCalificacionPromedio() ;
    map<int , Habitacion *> getHabitaciones() ;
    map<int , Reserva *> getReservas() ;
    map<int , Empleado *> getEmpleados() ;
    map<int , Huesped *> getHuespedes() ;

    void setNombre(string nom) ;
    void setDireccion(string direc) ;
    void setTelefono(int tel) ;
    void setCalPromedio(int calProm) ;
    void setHabitacion(Habitacion *hab); //agregar habitación al Hostal.
    void agregarReservaAHostal(Reserva *res);
    void agregarHuespedAHostal(Huesped *hues) ;
    void asignarEmpleadoAHostal(Empleado *emp) ; //añade el empleado a la colección de Empleados del Hostal.
 
 
    DtHostal getDtHostal() ;

    void accesoHostal() ; //no sé de donde es ni que haría.
    void entrarRes() ; 
    void obtenerEstadiasdelHostal(string emailHuesped) ; Debería devolver un conjunto de DtEstadía.
    //void linkeohos(Habitacion *hab) ; //ya está en setHab.
 
}; 

#endif

