#include ../include/DtHabitacion.hpp


DtHabitacion::DtHabitacion(int numero, int precio, int capacidad){
    this->numero = numero ;
    this->precio = precio ;
    this->capacidad = capacidad ;
}

//DtHabitacion::DtHabitacion() {} el destructor. No encuentro el símbolo de ñoqui para ponerle.


int DtHabitacion::getNumero(){
    return numero ;
}

int DtHabitacion::getPrecio(){
    return precio ;
}

int DtHabitacion::getCapacidad(){
    return capacidad ;
}
