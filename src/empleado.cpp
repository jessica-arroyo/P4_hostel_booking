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
    DtEmpleado dte = DtEmpleado(this->nombre, this->email, this->password, this->cargo, this->nombreHostal);
    return dte;
}

void Empleado::asignarHostalAEmpleado(Hostal *nuevohostal){
    hostal = nuevohostal;
}


void Empleado::entrarHostal(){
}

