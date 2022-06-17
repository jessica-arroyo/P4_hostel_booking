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

// registrar estadia
map<int,DtReserva> ControladorReserva::listarReservas(string nombreHostal, string emailHuesped){
	ControladorHostal *inshostal =  ControladorHostal::getInstancia();
	Hostal *hostal=	inshostal->listarHostales().find(nombreHostal)->second;
	map<string, DtReserva> SetReservas;
	map<string, Reserva*>::iterator i; 
	for(i->second = hostal->getReservas().begin(); i->second != hostal->getReservas().end(); i++)
	{
		if (dynamic_cast<ReservaGrupal *>(i->second)!=NULL){ //ver como era el dynamic cast 
			DtReservaGrupal r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto(), i->second->getNombresHuespedes());
			if (i->second->getNombresHuespedes().find(emailHuesped)!= i->second->getNombresHuespedes().end() and i->second->getEstado()!=2)
			{
				SetReservas.insert(make_pair(i->second->getCodigo(),r));
			}
		
		}
		if (dynamic_cast<ReservaIndividual *>(i->second)!=NULL){
			DtReservaIndividual r = DtReserva(i->second->getCodigo(), i->second->getCheckIn(), i->second->getCheckOut(), i->second->getFechaRealizada(), i->second->getEstado(),i->second->getCosto());
			if (i->second->huesped->getEmail==emailHuesped  and i->second->getEstado()!=2)
			{
				SetReservas.insert(make_pair(i->second->getCodigo(),r));
			}
		
		}
		
	}
	return SetReservas;
}

bool ControladorReserva::existeReserva(string codigo){
    return (SetReservas.find(codigo) != SetReservas.end()) ; // ver el end funca
}

void ControladorReserva::inscribirEstadia(int codigo, string emailHuesped){
	Fecha *insFecha = Fecha::getInstancia();
	ControladorUsuario *insUsuario =  ControladorUsuario::getInstancia();
	Reserva *reserva=SetReservas.find(codigo)->second;
	reserva->setEstado(1);
	Estadia *estadia= new Estadia(insFecha->getFechaHora(), insFecha->getFechaHora(), N/A);
	if (dynamic_cast<ReservaGrupal *>(reserva)!=NULL){
		reserva->estadiasReserva.insert(estadia);
	}
	if (dynamic_cast<ReservaIndividual *>(reserva)!=NULL){
		reserva->estadia=estadia;
	}
	insUsuario->huespedes.find(emailHuesped)->second->estadia=estadia;
	estadia->habitacion=reserva->habitacion;
	estadia->calificacion=NULL;
}

void ControladorAsignatura::asignarDocente(string codAsignatura, string emailDocente, DtModalidad tipoDictado)
{
	map<string , Asignatura*>::iterator i;
	i = asignaturas.find(codAsignatura);
	Asignatura *a = i->second;
	ControladorUsuario *cU = ControladorUsuario::getInstancia();
	Docente *d = cU->encontrarDocente(emailDocente);
	a->asignarDocente(d, tipoDictado);
	d->agregarAsignacion(a);
	DtSuscripcion tipo = d->getTipoSub();
	if (tipo == DtSuscripcion::porAsignatura)
	{
		d->addSub(a);
	}
}

void ControladorHostal::agregarHabitacion(int numero,int precio,int capacidad,string nombreH){
    Habitacion *hab = new Habitacion(numero,precio,capacidad);
    map<string,Hostal*>::iterator i;
    i = this->SetHostales.find(nombreH);
    i->second->setHabitacion(hab);
    hab->setHostal(i->second);
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

