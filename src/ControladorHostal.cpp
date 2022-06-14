#include "../include/ControladorHostal.hpp"

#include "Habitacion.hpp" //Ya se incluye porque Hostal incluye a Habitacion?

//usan una biblioteca <cstddef>.
//tengo que poner lo de include la biblioteca <iostream>?

#include <map>
#include <set>
using namespace std ;

ControladorHostal::ControladorHostal(){}

ControladorHostal::~ControladorHostal(){
    map<string , Hostal*>::iterator iH = SetHostales.begin();
	while (iH!=SetHostales.end())
	{
		delete iH->second;
		iH++;
	}
}

ControladorHostal *ControladorHostal::_instancia = NULL ;

ControladorHostal *ControladorHostal::getInstancia(){
    if(_instancia==NULL){
      _instancia = new ControladorHostal() ;
    }
    return _instancia ;
}

void ControladorHostal::altaHostal(string nombre, string direccion, int telefono, int calificacionProm){
    
    Hostal hos = new Hostal(nombre, direccion, telefono, calificacionProm) ;
    this->SetHostales.insert(make_pair(hostalCreado->getNombre(), hostalCreado));
    
}

bool ControladorHostal::existeHostal(string nombre){
    
    return (SetHostales.find(nombre) != SetHostales.end()) ; // ver el end funca
}

bool existeHabitacion(int numero, string nombreHostal){
	 Hostal* hostal = setHostales.find(nombreHostal);
     return (hostal->getHabitaciones().find(numero) != hostal->getHabitaciones().end());
}

std::map<string, DtHostal> ControladorHostal::listarHostales(){
    
	map<string, DtHostal> hostales;
	DtAsignatura h;
	map<string, Hostal*>::iterator i; 
	for(i = this->hostales.begin(); i != this->hostales.end(); i++)
	{
		h = DtHostal(i->second->getNombre(), i->second->getDireccion(), i->second->getTelefono(), i->second->getCalificacionPromedio());
		hostales.insert(make_pair(i->second->getNombre(),h));
	}
	if ( hostales.empty())
		throw logic_error("No hay hostales registrados") ;
	return res;

}  

DtHostal ControladorHostal::infoHostal(string nombreHostal){
    map<string,Hostal*>::iterator i ;
    i = this->SetHostales.find(nombreHostal) ;
    DtHostal h = DtHostal(i->second->getNombre(), i->second->getDireccion(), i->second->getTelefono(), i->second->getCalificacionPromedio()); 
    this->nombrerecordado = nombreHostal ;

    return h ;
}

void ControladorHostal::agregarHabitacion(numero,precio,capacidad,nombreH){
    Habitacion *hab = new Habitacion(numero,precio,capacidad,nombreH);
    map<string,Hostal*>::iterator i;
    i = this->SetHostales.find(nombreH)->second;
    i.setHabitacion(hab);
    hab.setHostal(i);
}


//set<DtCalificacion> ControladorHostal::listarCalificaciones(string nomhos){ //de un hostal en particular.
    
//}


//map<string , DtHostal> ControladorHostal::top3hostales(){}

//map<int , DtHabitacion> ControladorHostal::listarHabitaciones(){}

//Hostal* ControladorHostal::encontrarHostal(string nombreHostal){} //originalmente era el objeto Hostal. Debería devolver un puntero a un Hostal.

//map<int , DtHabitacion> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal){}




