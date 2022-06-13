#include "../include/ControladorHostal.hpp"

//usan una biblioteca <cstddef>.
//tengo que poner lo de include la biblioteca <iostream>?

using namespace std ;

ControladorHostal::ControladorHostal(){}

ControladorHostal::~ControladorHostal(){
    map<std::string , Hostal*>::iterator iH = SetHostales.begin();
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
    
    this->hostalCreado = new Hostal(nombre, direccion, telefono, calificacionProm) ;
    this->SetHostales.insert(make_pair(hostalCreado->getNombre(), hostalCreado));
	this->hostalCreado = NULL;
    
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
/*map<int , DtCalificacion> ControladorHostal::listarCalificaciones(){
    
}


map<int , DtHabitacion> ControladorHostal::listarHabitacionesDisp(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal){}
void ControladorHostal::ingresarDatos(string nombreHostal, DtHabitacion habitacion){}

void ControladorHostal::cancelarHabitacion(){}
std::map<string , DtHostal> ControladorHostal::top3hostales(){}

map<int , DtHabitacion> ControladorHostal::listarHabitaciones(){}
DtHostal ControladorHostal::encontrarHostal(string nombreHostal){} //acá puse que se devuelva el DtHostal. Porque no se devuelven objetos.
map<int , DtHabitacion> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal){}
*/



