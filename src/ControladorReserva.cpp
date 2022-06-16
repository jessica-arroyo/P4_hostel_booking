#include "../include/ControladorReserva.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;

ControladorReserva::ControladorReserva() {
}

ControladorReserva::~ControladorReserva() 
{
	map<int , Reserva*>::iterator i = SetReservas.begin();
	while (i != SetReservas.end())
	{
		delete i->second;
		i++;
	}
	
}

ControladorReserva *ControladorReserva::_instancia = NULL;

ControladorReserva *ControladorReserva::getInstancia()
{
    if (_instancia == NULL)
        _instancia = new ControladorReserva();
    return _instancia;
}

// consulta de reserva 
map<int,DtReserva> ControladorReserva::obtenerReservas(string nombreHostal)
{
	IHostal *inshostal =  ControladorHostal::getInstancia();
	Hostal *hostal=	inshostal->listarHostales().find(nombreHostal)->second;
	map<string, DtReserva> SetReservas;
	map<string, Reserva*>::iterator i; 
	for(i->second = hostal->getReservas().begin(); i->second != hostal->getReservas().end(); i++)
	{
		if (dynamic_cast<DtReservaGrupal *>(i->second)!=NULL){ //ver como era el dynamic cast 
			DtReservaGrupal r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto(), i->second->getNombresHuespedes());
		}
		if (dynamic_cast<DtReservaIndividual *>(i->second)!=NULL){
			DtReservaIndividual r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto());
		}
		SetReservas.insert(make_pair(i->second->getCodigo(),r));
	}
	return SetReservas;
}

// registrar estadia
map<int,DtReserva> ControladorReserva::listarReservas(string nombreHostal, string emailHuesped){
	IHostal *inshostal =  ControladorHostal::getInstancia();
	Hostal *hostal=	inshostal->listarHostales().find(nombreHostal)->second;
	map<string, DtReserva> SetReservas;
	map<string, Reserva*>::iterator i; 
	for(i->second = hostal->getReservas().begin(); i->second != hostal->getReservas().end(); i++)
	{
		if (dynamic_cast<DtReservaGrupal *>(i->second)!=NULL){ //ver como era el dynamic cast 
			DtReservaGrupal r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto(), i->second->getNombresHuespedes());
			if (i->second->getNombresHuespedes().find(emailHuesped)!= i->second->getNombresHuespedes().end() and i->second->getEstado()!=2)
			{
				SetReservas.insert(make_pair(i->second->getCodigo(),r));
			}
		
		}
		if (dynamic_cast<DtReservaIndividual *>(i->second)!=NULL){
			DtReservaIndividual r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto());
			if (i->second->huesped->getEmail==emailHuesped  and i->second->getEstado()!=2)
			{
				SetReservas.insert(make_pair(i->second->getCodigo(),r));
			}
		
		}
		
	}
	return SetReservas;
}

void ControladorReserva::confirmarReserva(){}
void ControladorReserva::cancelarReserva(){}
//set<DtCalificacion> ControladorReserva::chequearCalificacion(string nombreHostal){}
//void ControladorReserva::inscribirEstadia(DtReserva reserva){}
//void ControladorReserva::finalizarEstadia(string nombreHostal, string emailHuesped){}
//set<DtEstadia> ControladorReserva::obtenerEstadiasFinalizadas(string emailHuesped,string nombreHostal){}
//DtReserva ControladorReserva::obtenerReservaAsociada(string nombreEstadia){} //la estadia no tiene atributo nombre.
//DtCalificacion ControladorReserva::obtenerCalificacion(string nombreEstadia){} //la estadia no tiene atributo nombre.
//DtEstadia ControladorReserva::obtenerEstadia(string nombreEstadia){} //la estadia no tiene atributo nombre.
//set<DtEstadia> ControladorReserva::listarEstadias(string nombreHostal){}
//map<int,DtReserva> ControladorReserva::listarReservas(){}
//set<DtCalificacion> ControladorReserva::listarCalificaciones(){}
//void ControladorReserva::ingresarComentario(string comentario,string respuesta){}
//set<string> ControladorReserva::listarComentariosSinR(string emailEmpleado){} 
//void ControladorReserva::insertarCalificacion(string comentario, int puntaje, DtEstadia estadia){}
//void ControladorReserva::confirmarBaja(){}
//void cancelarBaja(){}

