#include ../include/DtHabitacion.hpp


DtHabitacion::DtHabitacion(int codigo, int precio, int capacidad){
    this->codigo = codigo ;
    this->precio = precio ;
    this->capacidad = capacidad ;
}

//DtHostal::DtHostal() {} el destructor. No encuentro el símbolo de ñoqui para ponerle.


string DtHostal::getNombre(){
    return nombre ;
}

string DtHostal::getDireccion(){
    return direccion ;
}

int DtHostal::getTelefono(){
    return telefono ;
}

int DtHostal::getCalPromedio(){
    return calificacionPromedio ;
}
