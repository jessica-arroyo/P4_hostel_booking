#ifndef HOSTAL_H
#define HOSTAL_H

#include "../include/DtHostal.hpp"

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
 
 
    DtHostal getDtHostal() ;
    /*
    void linkeohos(Habitacion *hab) ; puntero a la habitación no sería?
    void asignarEmpleadoAHostal(Empleado *emp) ;
    void accesoHostal() ;
    void agregarReservaAlHostal(Reserva *res) ;
    void entrarRes() ;
    void obtenerReservas() ; es un void? No debería devolver un conjunto o un map más bien de Reserva?
    void obtenerEstadiasdelHostal(string emailHuesped) ; verificar que esta efectivamente no devuelva nada (por lo de obtener pero no devuelve nada).
 
 */
}; 

#endif

