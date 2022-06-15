#include "../include/ControladorHostal.hpp"

#include "../include/Habitacion.hpp" //Ya se incluye porque Hostal incluye a Habitacion?

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
    
    Hostal *hos = new Hostal(nombre, direccion, telefono, calificacionProm) ;
    this->SetHostales.insert(make_pair(hos->getNombre(), hos));
    
}

bool ControladorHostal::existeHostal(string nombre){
    return (SetHostales.find(nombre) != SetHostales.end()) ; // ver el end funca
}

bool ControladorHostal::existeHabitacion(int numero, string nombreHostal){
	 Hostal *hostal = SetHostales.find(nombreHostal)->second;
     return (hostal->getHabitaciones().find(numero) != hostal->getHabitaciones().end());
}

map<string, DtHostal> ControladorHostal::listarHostales(){
    
	map<string, DtHostal> hostales;
	DtHostal h = DtHostal();
	map<string, Hostal*>::iterator i; 
	for(i = this->SetHostales.begin(); i != this->SetHostales.end(); i++)
	{
		h = DtHostal(i->second->getNombre(), i->second->getDireccion(), i->second->getTelefono(), i->second->getCalificacionPromedio());
		hostales.insert(make_pair(i->second->getNombre(),h));
	}
	if ( hostales.empty())
		throw logic_error("No hay hostales registrados") ;
	return hostales;

}  

DtHostal ControladorHostal::infoHostal(string nombreHostal){
    map<string,Hostal*>::iterator i ;
    i = this->SetHostales.find(nombreHostal) ;
    DtHostal h = DtHostal(i->second->getNombre(), i->second->getDireccion(), i->second->getTelefono(), i->second->getCalificacionPromedio());
    return h ;
}

void ControladorHostal::agregarHabitacion(int numero,int precio,int capacidad,string nombreH){
    Habitacion *hab = new Habitacion(numero,precio,capacidad);
    map<string,Hostal*>::iterator i;
    i = this->SetHostales.find(nombreH);
    i->second->setHabitacion(hab);
    hab->setHostal(i->second);
}


//set<DtCalificacion> ControladorHostal::listarCalificaciones(string nomhos){ //de un hostal en particular.
    
//}


//map<string , DtHostal> ControladorHostal::top3hostales(){}

//map<int , DtHabitacion> ControladorHostal::listarHabitaciones(){}

//Hostal* ControladorHostal::encontrarHostal(string nombreHostal){} //originalmente era el objeto Hostal. Debería devolver un puntero a un Hostal.

map<int , DtHabitacion> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal){}




