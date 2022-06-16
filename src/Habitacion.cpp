#include "../include/Habitacion.hpp"
//en el .hpp está incluído en el hostal.hpp.

Habitacion::Habitacion(int numero, int precio, int capacidad){
    this->numero = numero ;
    this->precio = precio ;
    this->capacidad = capacidad ;
    this->hostal = NULL ;
    
}

Habitacion::~Habitacion(){} 

int Habitacion::getNumero(){
   return numero ;
}

int Habitacion::getPrecio(){
    return precio ;
}

int Habitacion::getCapacidad(){
    return capacidad ;
}

Hostal* Habitacion::getHostal(){
    return hostal ;
}

void Habitacion::setNumero(int numero){
    this->numero = numero ;
}

void Habitacion::setPrecio(int precio){
    this->precio = precio ;
}

void Habitacion::setCapacidad(int capacidad){
    this->capacidad = capacidad ;
}

void Habitacion::setHostal(Hostal* hostal){
    this->hostal = hostal ;
}

/


DtHabitacion Habitacion::getDtHabitacion(){
    DtHabitacion habdt = DtHabitacion(this->numero,this->precio,this->capacidad) ;
    return habtdt ;
}

//bool Habitacion::estadisponibleHabitacion(DtFechaHora checkin, DtFechaHora checkout){} 
//int Habitacion::getPrecio(Habitacion hab){} // es el mismo de arriba?
//Habitacion::encontrarHabitacion(int codigoHabitacion, string nombreHostal){}//debería estar en el ControladorHostal.
//Habitacion Habitacion::buscarHab(){} //debería estar en el objeto Hostal ya que no se especifica un hostal.

//Habitacion::find(int codigoHabitacion){} //en tanto que find, no debería devolver algo? Una Habitacion en este caso.
//Habitacion::accederHab(int codigoHabitacion){}
//int Habitacion::encontrarPrecio(Habitacion hab){}
//Habitacion::agregarHabitacion(Habitacion hab) ; //ya está en ControladorHostal.

//Habitacion::linkeohab(Hostal hostal){} //ya está arriba

