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
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->cargo = cargo;
    this->hostal = NULL ;
    
}


TipoCargo Empleado::getCargo(){
    return this->cargo;
}

Hostal *  Empleado::getHostal(){
    return this->hostal;
}

void Empleado::setCargo(TipoCargo cargo){
    this->cargo = cargo;
}

bool Empleado::estaAsignado(string nombreHostal)
{
	bool asig ;
    if (this->hostal==NULL){
           asig = false ;
    }
	else if (nombreHostal == hostal->getNombre()) {
		asig = true ;
	}
  else {
		asig = false ;
	}
    
    return asig;

}

DtEmpleado Empleado::getDtEmpleado(){
	string nombrehos ;
	if(this->hostal != NULL){
		nombrehos = this->hostal->getNombre() ;
	}
	else {
		nombrehos = "vacio" ; 
	}
	
	DtEmpleado dte = DtEmpleado(this->getNombre(), this->getEmail(), this->getPassword(), this->cargo, nombrehos);
	
	
    return dte;
}

void Empleado::setHostal(Hostal *nuevohostal){
    this->hostal = nuevohostal;
}


//void Empleado::entrarHostal(){
//}

