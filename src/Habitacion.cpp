#include ../include/Habitacion.hpp
//en el .hpp está incluído en el hostal.hpp.
//los constructores por defecto, los que no tienen parámetros hay que ponerlos. Es una pregunta jeje.

Habitacion::Habitacion(int numero, int precio, int capacidad){
    this->numero = numero ;
    this->precio = precio ;
    this->capacidad = capacidad ;
    //tengo que crear un puntero al Hostal al que pertenezca la Habitacion, por lo que debería saber cuál es el Hostal. Pasarlo por parámetro?
}

//Habitacion::Habitacion() ; es el destructor que no encontré para poner el símbolo del ñoqui.

int Habitacion::getNumero(){
   return numero ;
}

int Habitacion::getPrecio(){
    return precio ;
}

int Habitacion::getCapacidad(){
    return capacidad ;
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

/*
//Habitacion::create(DtHabitacion habitacion); //el constructor sería este, el de arriba, o ambos?
Habitacion::add(Habitacion hab){}
Habitacion::linkeohab(Hostal hostal){}
DtHabitacion Habitacion::getDtHabitacion(){}
bool Habitacion::estadisponibleHabitacion(DtFechaHora checkin, DtFechaHora checkout){}
int Habitacion::getPrecio(Habitacion hab){} // es el mismo de arriba?
//Habitacion::encontrarHabitacion(int codigoHabitacion, string nombreHostal){}//verificar que esta efectivamente no devuelva nada (por lo de encontrar pero no devuelve nada).
Habitacion Habitacion::buscarHab(){} //esto debería estar acá o en el Hostal correspondiente? Porque es el Hostal correspondiente el que tiene la colección de Habitaciones.
//Habitacion::find(int codigoHabitacion){} //en tanto que find, no debería devolver algo? Una Habitacion en este caso.
//Habitacion::accederHab(int codigoHabitacion){}
int Habitacion::encontrarPrecio(Habitacion hab){}
Habitacion::agregarHabitacion(Habitacion hab){}
//int Habitacion::getCodigoHab(){} // es el mismo de arriba?
*/
