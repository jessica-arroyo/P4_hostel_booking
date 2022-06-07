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

void ControladorHostal::altaHostal(DtHostal hostal){}
std::map<string , DtHostal *> ControladorHostal::listarHostales() ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
        //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
        map<int , DtHabitacion *> listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal) ;
        void ingresarDatos(string nombreHostal, DtHabitacion habitacion) ;
        void agregarHabitacion() ;
        void cancelarHabitacion() ;
        void std::map<string , DtHostal *> top3hostales() ;
        DtHostal infoHostal(string nombreHostal) ;
        map<int , DtHabitacion *> listarHabitaciones() ;
        DtHostal encontrarHostal(string nombreHostal) ; //acá puse que se devuelva el DtHostal. Porque no se devuelven objetos.
        map<int , DtHabitacion *> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout) ;
        




