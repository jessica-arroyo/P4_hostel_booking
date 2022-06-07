#include "../include/empleado.hpp"
#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"
#include "../include/usuario.hpp"

Empleado::Empleado() {}
Empleado::~Empleado() {}
Empleado::Empleado(string nombre, string email, string password, TipoCargo cargo) : DtUsuario(nombre, email, password) {
    this->cargo = cargo;
}

TipoCargo Empleado::getCargo(){
    if (this->cargo == 0)
    {
        cout << "Administracion";
    }
    else if (this->cargo == 1){
        cout << "Limpieza";
    }
    else if (this->cargo == 2){
        cout << "Recepcion";
    }
    else if (this->cargo == 3){
        cout << "Infraestructura";
    }
    return cargo;
}

void Empleado::setCargo(TipoCargo cargo){
    this->cargo = cargo;
}
