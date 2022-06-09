#include ../include/DtHostal.hpp


DtHostal::DtHostal(string nom, string direc, int tel, string calProm){
    this->nombre = nom ;
    this->direccion = direc ;
    this->telefono = tel ;
    this->calificacionPromedio = calProm ;
}

DtHostal::~DtHostal() {} 


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
