#include ../include/Hostal.hpp


Hostal::Hostal(std::string nombre, std::string direccion, int telefono,0){
    this->nombre = nombre ;
    this->direccion = direccion ;
    this->telefono = telefono ;
    this->calificacionPromedio = 0 ; //se crea con calificacionPromedio igual a cero.
}

Hostal::~Hostal(){}

string Hostal::getNombre(){
   return nombre ;
}

string Hostal::getDireccion(){
    return direccion ;
}

int Hostal::getTelefono(){
    return telefono ;
}

int Hostal::getCalificacionPromedio(){
    return calificacionPromedio ;
}

void Hostal::setNombre(string nom){
    this->nombre = nom ;
}

void Hostal::setDireccion(string direc){
    this->direccion = direc ;
}

void Hostal::setTelefono(int tel){
    this->telefono = tel ;
}

void Hostal::setCalPromedio(int calProm){
    this->calificacionPromedio = calProm ;
}

/* bool Hostal::exists(string hostal.nombre) ; //esto no se debe de poder: debería ser std::string hostal.getNombre() 
 void create(DtHostalInicial hostal) ; //el constructor sería este,el de arriba, o ambos? Aparte creo que es DtHostal normal.
 
 //veo que siempre le pasan una referencia al objeto, en vez del objeto en sí.
 void Hostal::add(Hostal nuevo){}
 DtHostal Hostal::getDtHostal(){}
 Hostal Hostal::find(std::string nombreHostal){} 
 void Hostal::linkeohos(Habitacion hab){}
 void Hostal::asignarEmpleadoAHostal(Empleado emp){}
 void Hostal::accesoHostal(){}
 void Hostal::agregarReservaAlHostal(Reserva res){}
 void Hostal::entrarRes(){}
 // void Hostal::obtenerReservas(){} es un void? No debería devolver un conjunto o un map más bien de Reserva?
 //string Hostal::getNombreHostal(){} // es el mismo de arriba?
 //void Hostal::obtenerEstadiasdelHostal(std::string emailHuesped){} verificar que esta efectivamente no devuelva nada (por lo de obtener pero no devuelve nada).
 */
