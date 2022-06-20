#include "../include/DtHostal.hpp"


DtHostal::DtHostal(string nom, string direc, string tel, float calificacionPromedio){
    this->nombre = nom ;
    this->direccion = direc ;
    this->telefono = tel ;
    this->calificacionPromedio = calificacionPromedio ;
}

DtHostal::~DtHostal() {} 

DtHostal::DtHostal() {} 

string DtHostal::getNombre(){
    return nombre ;
}

string DtHostal::getDireccion(){
    return direccion ;
}

string DtHostal::getTelefono(){
    return telefono ;
}

float DtHostal::getCalificacionPromedio(){
    return calificacionPromedio ;
}
