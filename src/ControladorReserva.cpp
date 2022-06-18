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

map<int, Reserva*> ControladorReserva::getSetReservas(){
	return this->SetReservas;
} 

// consulta de reserva 
map<int,DtReserva> ControladorReserva::obtenerReservas(string nombreHostal)
{
	IHostal *inshostal =  ControladorHostal::getInstancia();
	Hostal *hostal=	inshostal->getSetHostales().find(nombreHostal)->second;
	map<int, DtReserva> reservas;
	map<int, Reserva*>::iterator i; 
	for(i->second = hostal->getReservas().begin()->second; i->second != hostal->getReservas().end()->second; i++)
	{
		DtReserva r = i->second->getDtReserva();
		reservas.insert(make_pair(r.getCodigo(),r));
	}
	return reservas;
}


void ControladorReserva::confirmarReservaGrupal(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped, map<string, Huesped*> grupoHues, int cont){
	int codigo = 1000 + (this->getSetReservas().size());
	DtFechaHora fechaRealizada =  Fecha::getInstancia()->getFechaHora();
	IHostal *insHostal = ControladorHostal::getInstancia();
	Habitacion *habu = insHostal->getSetHostales().find(nomhos)->second->getHabitaciones().find(numhab)->second;
	long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
	long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
	int dife = (f2 - f1)/24;
	float costo = cont * habu->getPrecio() * dife; 
	IUsuario *insUsuario = ControladorUsuario::getInstancia();
	Huesped *hues = insUsuario->getHuespedes().find(mailHuesped)->second;
	int contador = 0;
	map<string, Huesped*> :: iterator jo;
	for(jo = grupoHues.begin(); jo != grupoHues.end(); jo++) {
		if (jo->second->getEsFinger()) {contador++;}
	}
	if (contador >= 2) {costo = costo - (costo* 0.3);}

	ReservaGrupal *res = new ReservaGrupal(codigo, fechaCheckIn, fechaCheckOut, fechaRealizada, ABIERTA, costo, cont,  habu, hues, grupoHues); 

	this->getSetReservas().insert(make_pair(codigo, res));
}


void ControladorReserva::confirmarReservaIndividual(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped){
	int codigo = 1000 + (this->getSetReservas().size());
	DtFechaHora fechaRealizada =  Fecha::getInstancia()->getFechaHora();
	IHostal *insHostal = ControladorHostal::getInstancia();
	Habitacion *habu = insHostal->getSetHostales().find(nomhos)->second->getHabitaciones().find(numhab)->second;
	long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
	long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
	int dife = (f2 - f1)/24;
	float costo = habu->getPrecio() * dife; 
	IUsuario *insUsuario = ControladorUsuario::getInstancia();
	Huesped *hues = insUsuario->getHuespedes().find(mailHuesped)->second;

	ReservaIndividual *res = new ReservaIndividual(codigo,fechaCheckIn, fechaCheckOut, fechaRealizada, ABIERTA,costo, habu, hues); 

	this->getSetReservas().insert(make_pair(codigo, res));
}


//void ControladorReserva::cancelarReserva(){}
//set<DtCalificacion> ControladorReserva::chequearCalificacion(string nombreHostal){}
//map<int,DtReserva> ControladorReserva::listarReservas(string nombreHostal, string emailHuesped){}
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

