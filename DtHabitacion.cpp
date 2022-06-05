#include ../include/DtHabitacion.hpp


DtHabitacion::DtHabitacion(int codigo, int precio, int capacidad){
    this->codigo = codigo ;
    this->precio = precio ;
    this->capacidad = capacidad ;
}

//DtHabitacion::DtHabitacion() {} el destructor. No encuentro el símbolo de ñoqui para ponerle.


int DtHabitacion::getCodigo(){
    return codigo ;
}

int DtHabitacion::getPrecio(){
    return precio ;
}

int DtHabitacion::getCapacidad(){
    return capacidad ;
}
