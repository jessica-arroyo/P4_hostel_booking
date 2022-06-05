#include ../include/Hostal.hpp


Hostal::Hostal(nombre string, direccion string, telefono int,0){
    this->nombre = nombre ;
    this->direccion = direccion ;
    this->telefono = telefono ;
    this->calificacionPromedio = 0 ; //se crea con calificacionPromedio igual a cero.
}

//Hostal::Hostal() ; es el destructor que no encontré para poner el símbolo del ñoqui.

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
