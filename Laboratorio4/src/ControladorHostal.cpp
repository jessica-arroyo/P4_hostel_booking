#include "../include/ControladorHostal.hpp"


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

void ControladorHostal::altaHostal(string nombre, string direccion, string telefono, int calificacionProm){
    
    Hostal *hos = new Hostal(nombre, direccion, telefono, calificacionProm) ;
    this->SetHostales.insert(make_pair(hos->getNombre(), hos));
    
}

bool ControladorHostal::existeHostal(string nombre){
    return (SetHostales.find(nombre) != SetHostales.end()) ; // ver el end funca
}

bool ControladorHostal::existeHabitacion(int numero, string nombreHostal){
	   Hostal *hostal = SetHostales.find(nombreHostal)->second;
     bool existeh  = false ;
     map<int, Habitacion *> habshostal= hostal->getHabitaciones() ;
     map<int, Habitacion *>::iterator h = habshostal.find(numero) ;
     if(h != habshostal.end()){
        existeh = true ;
}
return existeh ; 
}

map<string, Hostal*> ControladorHostal::getSetHostales(){
	return this->SetHostales;
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

map<int,DtHabitacion> ControladorHostal::listarHabitaciones(string nombreHostal){
	Hostal *hos = SetHostales.find(nombreHostal)->second ;
	map<int,Habitacion*> habs = hos->getHabitaciones() ;
	map<int,Habitacion*>::iterator habhos ;
	map<int,DtHabitacion> res ;
	for(habhos=habs.begin(); habhos!=habs.end(); habhos++){
		DtHabitacion a = habhos->second->getDtHabitacion() ;
		res.insert(make_pair(a.getNumero(),a));
	}
	return res ;
}

map<int,DtReservaGrupal> ControladorHostal::listarReservasGrupal(string nombreHostal){
	Hostal *hos = SetHostales.find(nombreHostal)->second ;
	map<int,Reserva*> reser = hos->getReservas() ;
	map<int,Reserva*>::iterator reshos ;
	map<int,DtReservaGrupal> resdehos ;
	for(reshos=reser.begin(); reshos!=reser.end(); reshos++){
		if(dynamic_cast <ReservaGrupal*> (reshos->second) != NULL){
			
			DtReservaGrupal a = dynamic_cast <ReservaGrupal*> (reshos->second)->getDtReservaGrupal() ;
			resdehos.insert(make_pair(a.getCodigo(),a)) ;
		}
	}
	return resdehos ;
}

map<int,DtReservaIndividual> ControladorHostal::listarReservasIndividual(string nombreHostal){
	Hostal *hos = SetHostales.find(nombreHostal)->second ;
	map<int,Reserva*> reser = hos->getReservas() ;
	map<int,Reserva*>::iterator reshos ;
	map<int,DtReservaIndividual> resdehos ;
 
	for(reshos=reser.begin(); reshos!=reser.end(); reshos++){
		
		if(dynamic_cast <ReservaIndividual*> (reshos->second)){
			ReservaIndividual *rind = dynamic_cast <ReservaIndividual*> (reshos->second) ;
			DtReservaIndividual a = rind->getDtReservaIndividual() ;
			resdehos.insert(make_pair(a.getCodigo(),a)) ;
		}
	}
	return resdehos ;
}

map<int, DtCalificacion> ControladorHostal::listarCalificaciones(string nombreHostal){
	Hostal *hos = SetHostales.find(nombreHostal)->second ;
	map<int,Reserva*> reser = hos->getReservas() ;
	map<int,Reserva*>::iterator reshos ;
	map<int, DtCalificacion> caldehos ;
	for(reshos=reser.begin(); reshos!=reser.end(); reshos++){
		if(reshos->second->getEstadia() != NULL){
			Estadia *est = reshos->second->getEstadia() ;
			if(est->getCalificacion() != NULL){
				DtCalificacion cal = est->getCalificacion()->getDtCalificacion() ;
				caldehos.insert(make_pair(reshos->first,cal)) ;
			}	
		}
		
	}
	return caldehos ;
}

//map<string , DtHostal> ControladorHostal::top3hostales(){}

Hostal* ControladorHostal::encontrarHostal(string nombreHostal){
  Hostal *hostal= SetHostales.find(nombreHostal)->second;
  return hostal;
} 

map<int , DtHabitacion> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal){
    //Hostal* pHostal = encontrarHostal(nombreHostal)
	cout<<"llega" ;
   Hostal* pHostal = this->SetHostales.find(nombreHostal)->second;
    map<int , Habitacion *> jaque = pHostal->getHabitaciones();
    map<int , Reserva *>  loqhay = pHostal->getReservas();
    map<int , DtHabitacion> res; 
    map<int , Habitacion*>:: iterator w;
	cout<<"llega" ;
	if (jaque.empty()) {
			cout<<"llegaemptyhabs" ;
			return res;
		} 
		else {
			cout<<"llega1" ;
		for(w = jaque.begin(); w != jaque.end(); w++)  {
			res.insert(make_pair(w->second->getNumero(), w->second->getDtHabitacion()));
			}
			cout<<"llega luego insertar habs" ;
		if(loqhay.empty()){
			cout<<"llega no hay reservas" ;
			return res;
			} 
			else {
			cout<<"llega hay reservas" ;
			map<int , Reserva*> :: iterator i;
			long int f1, f2, f3, f4;
			cout<<"llega" ;
			for(i = loqhay.begin(); i != loqhay.end(); i++){
				f1 = i->second->getCheckIn().getHora() + i->second->getCheckIn().getDia()*24 + i->second->getCheckIn().getMes()*24*30 + i->second->getCheckIn().getAnio()*24*12*30;
				f2 = checkin.getHora() + checkin.getDia()*24 + checkin.getMes()*24*30 + checkin.getAnio()*24*12*30;
				f3 = i->second->getCheckOut().getHora() + i->second->getCheckOut().getDia()*24 + i->second->getCheckOut().getMes()*24*30 + i->second->getCheckOut().getAnio()*24*12*30;
				f4 = checkout.getHora() + checkout.getDia()*24 + checkout.getMes()*24*30 + checkout.getAnio()*24*12*30;
				cout<<"llegafor fechas" ;
				if ((((f2 - f1) <= 0) && ((f2 - f3) <= 0)) || (((f1 - f4) <= 0) && ((f3 - f4) <= 0))) {
					res.erase(i->second->getHabitacion()->getNumero());
					cout<<"llegaforif" ;
				}
			}
			cout<<"llega fin" ;
			return res;
		}
	}

	}




