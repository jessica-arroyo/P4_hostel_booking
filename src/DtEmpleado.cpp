#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"


TipoCargo  DtEmpleado::getCargo() {
    return cargo;
}

DtEmpleado::DtEmpleado(string nombre, string email, string password, TipoCargo cargo, string nombreHostal) : DtUsuario(nombre, email, password) {
    this->cargo = cargo;
    this->nombreHostal = nombreHostal;
}

DtEmpleado::~DtEmpleado(){}

