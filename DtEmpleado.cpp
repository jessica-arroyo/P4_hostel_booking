#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"


TipoCargo  DtEmpleado::getCargo() {
    return cargo;
}

DtEmpleado::DtEmpleadp(string nombre, string email, string password, TipoCargo cargo) : DtUsuario(nombre, email, password) {
    this->cargo = cargo;
}

DtEmpleado::~DtEmpleado(){}
DtEmpleado::~DtEmpleado(){}
