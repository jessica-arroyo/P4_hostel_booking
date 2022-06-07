#include "../include/usuario.hpp"
#include "../include/DtUsuario.hpp"
#include <string>
#include <iostream>
using namespace std;
 
string Usuario::getNombre() {
    return nombre ;
}

string Usuario::getEmail() {
    return email ;
}

string Usuario::getPassword() {
    return password ;
}

Usuario::Usuario() {}
Usuario::~Usuario() {}

Usuario::Usuario(string nombre, string email, string password){
    this->nombre = nombre ;
    this->email = email ;
    this->password = password ;
}

void Usuario::setPassword(string password){
    this->password = password;
}

void Huesped::setNombre(string nombre){
    this->nombre = nombre;
}

void Huesped::setEmail(string email){
    this->email = email;
}
