#include ../include/Habitacion.hpp
//en el .hpp ya está incluído en el hostal.hpp (que no sé si hay que incluirlo).
//los constructores por defecto, los que no tienen parámetros hay que ponerlos. Es una pregunta jeje.

Habitacion::Habitacion(int codigo, int precio, int capacidad){
    this->codigo = codigo ;
    this->precio = precio ;
    this->capacidad = capacidad ;
}

//Habitacion::Habitacion() ; es el destructor que no encontré para poner el símbolo del ñoqui.

int Habitacion::getCodigo(){
   return codigo ;
}

int Habitacion::getPrecio(){
    return precio ;
}

int Habitacion::getCapacidad(){
    return capacidad ;
}

void Habitacion::setCodigo(int codigo){
    this->codigo = codigo ;
}

void Habitacion::setPrecio(int precio){
    this->precio = precio ;
}

void Habitacion::setCapacidad(int capacidad){
    this->capacidad = capacidad ;
}
