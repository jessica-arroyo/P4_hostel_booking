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



// realizar reserva

map<int, Reserva*> ControladorReserva::getSetReservas(){
    return this->SetReservas;
}

void ControladorReserva::confirmarReservaGrupal(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped, set<string> grupoHues, int cont){
    int codigo = 1000 + (this->SetReservas.size());
    DtFechaHora fechaRealizada =  Fecha::getInstancia()->getFechaHora();
    IHostal *insHostal = ControladorHostal::getInstancia();
    Hostal *hos = insHostal->encontrarHostal(nomhos);
    Habitacion *habu = hos->obtenerHabitacion(numhab);
    long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
    long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
    int dife = (f2 - f1)/24;
	int precio = habu->getPrecio() ;
    float costo = cont*precio * dife; 
    IUsuario *insUsuario = ControladorUsuario::getInstancia();
    Huesped *hues = insUsuario->obtenerHuesped(mailHuesped);
    int contador = 0;
	map <string,Huesped*> huespedesRes ;
    set<string>::iterator jo;
	Huesped *cadaotro = NULL ;
    for(jo = grupoHues.begin(); jo != grupoHues.end(); jo++) {
		 string email = *jo ;
		 cout<< "\nEmail:" << email << "\n" ;
         cadaotro = insUsuario->obtenerHuesped(email) ;
		 huespedesRes.insert(make_pair(email,cadaotro)) ; //grupo de punteros originales a huespedes a ser insertados en la Reserva Grupal.
		 if (cadaotro->getEsFinger()) {
			contador++;
		 }
		 if(! (hos->getHuespedes().find(email) != hos->getHuespedes().end())){ //acá no me importa que sea la copia de la colección de huespedes porque solo estoy consultando.
			 hos->agregarHuespedAHostal(cadaotro) ; //Si no estaban ya en la colección de Huespedes del Hostal, se los agrega.
		 }
    }
    if (contador >= 2) {costo = costo - (costo*0.3);}

    ReservaGrupal *res = new ReservaGrupal(codigo, fechaCheckIn, fechaCheckOut, fechaRealizada, ABIERTA, costo, habu, hues, cont, huespedesRes); 

	cout<<"\nCodigo:" << res->getCodigo() << "\n" ;

    this->SetReservas.insert(make_pair(codigo, res)); //se añade la Reserva a la colección de Reservas.
    hos->agregarReservaAHostal(res); 
    
}

void ControladorReserva::confirmarReservaIndividual(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped){
    int codigo = 1000 + (this->getSetReservas().size());
    DtFechaHora fechaRealizada =  Fecha::getInstancia()->getFechaHora();
    IHostal *insHostal = ControladorHostal::getInstancia();
    Hostal *hos = insHostal->encontrarHostal(nomhos);
    Habitacion *habu = hos->obtenerHabitacion(numhab);
    long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
    long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
    int dife = (f2 - f1)/24;
    int precio = habu->getPrecio() ;
    float costo = precio * dife; 
    IUsuario *insUsuario = ControladorUsuario::getInstancia();
    Huesped *hues = insUsuario->obtenerHuesped(mailHuesped);
	if(! (hos->getHuespedes().find(mailHuesped) != hos->getHuespedes().end())){ //acá no me importa que sea la copia de la colección de huespedes porque solo estoy consultando.
		hos->agregarHuespedAHostal(hues) ;
	}

    ReservaIndividual *res = new ReservaIndividual(codigo,fechaCheckIn, fechaCheckOut, fechaRealizada, ABIERTA,costo, habu, hues); 
	
	cout<<"\nCodigoInd:" << res->getCodigo() << "\n" ;

    this->SetReservas.insert(make_pair(codigo, res));
    hos->agregarReservaAHostal(res);
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

