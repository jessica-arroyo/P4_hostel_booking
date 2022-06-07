#include "../include/huesped.hpp"
#include "../include/DtHuesped.hpp"
#include "../include/DtUsuario.hpp"
#include "../include/usuario.hpp"

Huesped::Huesped() {}
Huesped::~Huesped() {}
Huesped::Huesped(string nombre, string email, string password, bool esFinger) : DtUsuario(nombre, email, password) {
    this->esFinger = esFinger ;
}

bool Huesped::getEsFinger() {
    return esFinger ;
}

void Huesped::setEsFinger(bool esFinger){
    this->esFinger = esFinger;
}
