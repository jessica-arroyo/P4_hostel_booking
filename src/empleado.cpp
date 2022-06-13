#include "../include/empleado.hpp"
#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"
#include "../include/usuario.hpp"
using namespace std;

Empleado::Empleado() {}
Empleado::~Empleado() {}
Empleado::Empleado(string nombre, string email, string password, TipoCargo cargo) : DtUsuario(nombre, email, password) {
    this->cargo = cargo;
}

/* TipoCargo Empleado::getCargo(){
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
}*/

TipoCargo Empleado::getCargo(){
    return this->cargo
}

void Empleado::setCargo(TipoCargo cargo){
    this->cargo = cargo;
}

bool estaAsignado(string nombreHostal)
{
    if (nombreHostal == hostal->getNombre())
        {
            return true;
        }
    }
    return false;

}

DtEmpleado Empleado::getDtEmpleado(){
    DtEmpleado dte = DtEmpleado(this->nombre, this->email, this->password, this->cargo);
    return dte;
}

void Empleado::asignarHostalAEmpleado(Hostal *nuevohostal){
    hostal = nuevohostal;
}


void Empleado::entrarHostal(){
}

