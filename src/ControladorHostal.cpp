#include ../include/ControladorHostal.hpp

//usan una biblioteca <cstddef>.
//tengo que poner lo de include la biblioteca <iostream>?

using namespace std ;

ControladorHostal::ControladorHostal(){}

ControladorHostal::~ControladorHostal(){}

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
    
    return (SetHostales.find(nomh) != SetHostales.end()) ;
}

std::map<string , DtHostal *> ControladorHostal::listarHostales(){} //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
//a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
map<int , DtHabitacion *> ControladorHostal::listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal){}
void ControladorHostal::ingresarDatos(string nombreHostal, DtHabitacion habitacion){}
void ControladorHostal::agregarHabitacion(){}
void ControladorHostal::cancelarHabitacion(){}
std::map<string , DtHostal *> ControladorHostal::top3hostales(){}
DtHostal ControladorHostal::infoHostal(string nombreHostal){}
map<int , DtHabitacion *> ControladorHostal::listarHabitaciones(){}
DtHostal ControladorHostal::encontrarHostal(string nombreHostal){} //acá puse que se devuelva el DtHostal. Porque no se devuelven objetos.
map<int , DtHabitacion *> ControladorHostal::devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout){}
        




