#include "../include/Empleado.hpp"
#include "../include/DtEmpleado.hpp"
#include "../include/DtUsuario.hpp"
#include "../include/Usuario.hpp"
using namespace std;

//ya que Calificación no es más el Sujeto Observado, tiene que seguir viendo a Calificacion?

Empleado::Empleado() {}
Empleado::~Empleado() {}
Empleado::Empleado(string nombre, string email, string password, TipoCargo cargo) : Usuario(nombre, email, password) {
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
    
    return false;

}

DtEmpleado Empleado::getDtEmpleado(){
    DtEmpleado dte = DtEmpleado(this->nombre, this->email, this->password, this->cargo, this->hostal->getNombre());
    return dte;
}

void Empleado::asignarHostalAEmpleado(Hostal *nuevohostal){
    this->hostal = nuevohostal;
}


//void Empleado::entrarHostal(){
//}

