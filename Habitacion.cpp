#include ../include/Habitacion.hpp
//en el .hpp ya está incluído en el hostal.hpp (que no sé si hay que incluirlo).
//los constructores por defecto, los que no tienen parámetros hay que ponerlos. Es una pregunta jeje.

Habitacion::Habitacion(int numero, int precio, int capacidad){
    this->numero = numero ;
    this->precio = precio ;
    this->capacidad = capacidad ;
}

//Habitacion::Habitacion() ; es el destructor que no encontré para poner el símbolo del ñoqui.

int Habitacion::getNumero(){
   return numero ;
}

int Habitacion::getPrecio(){
    return precio ;
}

int Habitacion::getCapacidad(){
    return capacidad ;
}

void Habitacion::setNumero(int numero){
    this->numero = numero ;
}

void Habitacion::setPrecio(int precio){
    this->precio = precio ;
}

void Habitacion::setCapacidad(int capacidad){
    this->capacidad = capacidad ;
}
