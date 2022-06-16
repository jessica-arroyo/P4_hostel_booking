#include "../include/ControladorHostal.hpp"

#include "../include/Hostal.hpp"

#include "../include/Habitacion.hpp" 

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

map<int , DtHabitacion> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal){
    Hostal* pHostal = encontrarHostal(nombreHostal);
    map<int , Habitacion *> jaque = pHostal->getHabitaciones(); // aca al copiar si borro algo de la copia se borra en el original???
    map<int , Reserva *>  loqhay = pHostal->getReservas();
    map<int , DtHabitacion> res; 
    map<int , Habitacion*> :: iterator w;
    if(loqhay.empty())
    {
        if (jaque.empty()) {return res;}
        else {for(w = jaque.begin(); w != jaque.end(); w++)  {
            res.insert(w->second->getNumero(), w->second->getDtHabitacion()); //asi funciona el insert??
        }
        return res;
        }
        }
	else {
        map<int , Reserva*> :: iterator i;
        long int f1, f2, f3, f4;
        for(i = loqhay.begin(); i != loqhay.end(); i++){
            f1 = i->second->getCheckIn().getHora() + i->second->getCheckIn().getDia()*24 + i->second->getCheckIn().getMes()*24*30 + i->second->getCheckIn().getAnio()*24*12*30;
            f2 = checkin.getHora() + checkin.getDia()*24 + checkin.getMes()*24*30 + checkin.getAnio()*24*12*30;
            f3 = i->second->getCheckOut().getHora() + i->second->getCheckOut().getDia()*24 + i->second->getCheckOut().getMes()*24*30 + i->second->getCheckOut().getAnio()*24*12*30;
            f4 = checkout.getHora() + checkout.getDia()*24 + checkout.getMes()*24*30 + checkout.getAnio()*24*12*30;
            if ((((f2 - f1) <= 0) && ((f2 - f3) <= 0)) || (((f1 - f4) <= 0) && ((f3 - f4) <= 0))) {
                jaque.erase(i->second->getHabitacion()->getNumero());
            }
        } 
        for(w = jaque.begin(); w != jaque.end(); w++)  {
            res.insert(w->second->getNumero(), w->second->getDtHabitacion()); //asi funciona el insert??
        }
        return res;
        }

}




