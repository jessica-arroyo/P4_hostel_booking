#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"


string  DtEmpleado::getCargo() {
    return cargo;
}

DtEmpleado::DtEmpleado(string nombre, string email, string password, string cargo, string nombreHostal) : DtUsuario(nombre, email, password) {
    this->cargo = cargo;
    this->nombreHostal = nombreHostal;
}

DtEmpleado::~DtEmpleado(){}

