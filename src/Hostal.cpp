#include "../include/Hostal.hpp"

using namespace std ;

Hostal::Hostal(string nombre, string direccion, int telefono,0){
    this->nombre = nombre ;
    this->direccion = direccion ;
    this->telefono = telefono ;
    this->calificacionPromedio = 0 ; //se crea con calificacionPromedio igual a cero.
}

Hostal::~Hostal(){}

string Hostal::getNombre(){
   return nombre ;
}

string Hostal::getDireccion(){
    return direccion ;
}

int Hostal::getTelefono(){
    return telefono ;
}

int Hostal::getCalificacionPromedio(){
    return calificacionPromedio ;
}

void Hostal::setNombre(string nom){
    this->nombre = nom ;
}

void Hostal::setDireccion(string direc){
    this->direccion = direc ;
}

void Hostal::setTelefono(int tel){
    this->telefono = tel ;
}

void Hostal::setCalPromedio(int calProm){
    this->calificacionPromedio = calProm ;
}

 DtHostal Hostal::getDtHostal(){
    DtHostal h = DtHostal(this->nombre, this->direccion, this->telefono, this->calificacionPromedio) ;
    return h ;
 } 

//map<int , Habitacion *> getHabitaciones() ;
    //map<int , Reserva *> getReservas() ;
    //map<int , Empleado *> getEmpleados() ;
    //map<int , Huesped *> getHuespedes() ;

 /*
 void Hostal::linkeohos(Habitacion hab){}
 void Hostal::asignarEmpleadoAHostal(Empleado emp){}
 void Hostal::accesoHostal(){}
 void Hostal::agregarReservaAlHostal(Reserva res){}
 void Hostal::entrarRes(){}
 //void Hostal::obtenerReservas(){} es un void? No debería devolver un conjunto o un map más bien de Reserva?
 //void Hostal::obtenerEstadiasdelHostal(std::string emailHuesped){} verificar que esta efectivamente no devuelva nada (por lo de obtener pero no devuelve nada).
 */
