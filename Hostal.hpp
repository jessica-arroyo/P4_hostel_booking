

// Puse las operaciones que estaban en el DCD, pero capaz que hay más.
//A las operaciones que no aparecía como que devolvieran algo, les puse void.
//Vamos a usar -> o . (dinámico o estático)?

//std::map<std::string , Estudiante > estudiantes;

#ifndef HOSTAL_H
#define HOSTAL_H


class Hostal {
  private:
    string nombre ;
    string direccion ;
    int telefono ;
    float calificacionPromedio ;
    //linkeo a las Habitacion. map<int, Habitacion *> HabitacionesdelHostal.
    //linkeo a las Reserva. map<int, Reserva *> ReservasdelHostal.
    //linkeo a los Empleados. map<string, Empleado *> EmpleadosdelHostal.
    //linkeo a los Huespedes. map<string, Huesped *> HuespedesdelHostal.
    //El linkeo sería un puntero a un map (o vector)? O como? 
    //Las colecciones irian en los controladores? Y en cada clase se define un puntero a esa colección? Y algunas colecciones se guaradarían en cada clase?
    //Comentario/Recordatorio para los maps no es necesario pedir memoria dinámica explícitamente.
  public:
    Hostal(nombre string, direccion string, telefono int,0) ; //empieza con calificacionPromedio=0.
    //Hostal() ; es el destructor que no encontré para poner el símbolo del ñoqui.
    string getNombre() ;
    string getDireccion() ;
    int getTelefono() ;
    int getCalificacionPromedio() ;
    void setNombre(string nom) ;
    void setDireccion(string direc) ;
    void setTelefono(int tel) ;
    void setCalPromedio(int calProm) ;
    
  
   /* bool exists(hostal.nombre string) ; //esto no se debe de poder: hostal.nombre ?
 void create(hostal DtHostalInicial) ; //el constructor sería este,el de arriba, o ambos? Aparte creo que es DtHostal normal.
 void add(nuevo Hostal) ;
 DtHostal getDtHostal() ;
 Hostal find(nombreHostal string) ;
 void linkeohos(hab Habitacion) ;
 void asignarEmpleadoAHostal(emp Empleado) ;
 void accesoHostal() ;
 void agregarReservaAlHostal(res Reserva) ;
 void entrarRes() ;
 void obtenerReservas() ;
 string getNombreHostal() ; // es el mismo de arriba?
 void obtenerEstadiasdelHostal(emailHuesped string) ; //verificarque esta efectivamente no devuelva nada (por lo de obtener pero no devuelve nada).

 //Pregunta: va el destructor?
 
 */
}; 

#endif

