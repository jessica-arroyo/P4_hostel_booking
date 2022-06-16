#include "../include/Huesped.hpp"
#include "../include/DtHuesped.hpp"
#include "../include/DtUsuario.hpp"
#include "../include/Usuario.hpp"

#include <string>
#include <iostream>
#include <map> 

Huesped::Huesped() {} 
Huesped::~Huesped() {}
Huesped::Huesped(string nombre, string email, string password, bool esFinger) : Usuario(nombre, email, password) {
    this->esFinger = esFinger ;
}

bool Huesped::getEsFinger() {
    return esFinger ;
}

void Huesped::setEsFinger(bool esFinger){
    this->esFinger = esFinger;
}

DtHuesped Huesped::getDtHuesped(){
    DtHuesped dth = DtHuesped(this->nombre, this->email, this->password, this->esFinger);
    return dth;
}

Estadia* Huesped::getEstadia(){
    return estadia ;
}

void Huesped::setEstadia(Estadia *estadia){
    this->estadia = estadia ;
}

map<string , Hostal *> Huesped::getHostalesHuesped(){
    return hostalesHuesped ;
} 

void Huesped::anadirHostalAlHuesped(Hostal *hostal){
    this->hostalesHuesped[hostal->getNombre()] = hostal;
}



//void Huesped::accesoHuesped(string){}

//void Huesped::obtenerEstadiasHuesped(){}

//void accederEstadia(DtEstadia){}
