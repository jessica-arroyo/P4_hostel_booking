#include "../include/DtFechaHora.hpp"
#include <iostream>
using namespace std;
#include <stdexcept>

int DtFechaHora::getHora() {
    return hora;
}

int DtFechaHora::getDia() {
    return dia;
}

int DtFechaHora::getMes() {
    return mes;
}

int DtFechaHora::getAnio() {
    return anio;
}

DtFechaHora::DtFechaHora(){}

DtFechaHora::DtFechaHora(int hora, int dia, int mes, int anio) {
    if (hora <= 24 && dia >= 1 && dia <=31 && mes >= 1 && mes <=12 && anio >= 1900 ) { //no es hora<=24 ?
        this->hora = hora ;
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    else 
        throw invalid_argument("Fecha no válida") ;
}


DtFechaHora::~DtFechaHora(){};