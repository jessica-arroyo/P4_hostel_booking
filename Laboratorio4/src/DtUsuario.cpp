#include "../include/DtUsuario.hpp"
#include <string>
#include <iostream>
using namespace std;
 
string DtUsuario::getNombre(){
    return nombre;
}

string DtUsuario::getEmail() {
    return email;
}

string DtUsuario::getPassword() {
    return password;
}

DtUsuario::DtUsuario() {}
DtUsuario::~DtUsuario() {}

DtUsuario::DtUsuario(string nombre, string email, string password){
    this->nombre = nombre ;
    this->email = email ;
    this->password = password ;
}
