#include "../include/DtHuesped.hpp"
#include "../include/DtUsuario.hpp"


bool DtHuesped::getEsFinger() {
    return esFinger;
}

DtHuesped::DtHuesped(string nombre, string email, string password, bool esFinger) : DtUsuario(nombre, email, password) {
    this->esFinger = esFinger;
}

DtHuesped::~DtHuesped(){}
DtHuesped::DtHuesped(){} // va esto?
