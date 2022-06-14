#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "IHostal.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
//#include "DtHabitacion.hpp" 
//#include "DtCalificacion.hpp"
#include <map>
#include <iostream>
#include <string>

using namespace std ;

class ControladorHostal: public: IHostal {
    private:
        ControladorHostal() ;
        static ControladorHostal *_instancia ;
        map<std::string,Hostal*> SetHostales ;

    public:
        ~ControladorHostal() ;
        static ControladorHostal *getInstancia() ;

        bool existeHostal(string nombre) ; 
        bool existeHabitacion(int numero, string nombreHostal) ; 
        void agregarHabitacion(numero,precio,capacidad,nombreH) ; 
        void altaHostal(string nombre, string direccion, int telefono, int calificacionProm) ; 
        map<string , DtHostal> listarHostales() ; 
        DtHostal infoHostal(string nombreHostal) ; 
        //map<int , DtCalificacion> listarCalificaciones(string nomhos) ; 
        //void map<string , DtHostal> top3hostales() ; 
        //map<int , DtHabitacion> listarHabitaciones() ; 
        //Hostal* encontrarHostal(string nombreHostal) ;  //Originalmente estaba puesto que devuelva un Hostal. Tiene que devolver un puntero a un Hostal.
        //map<int , DtHabitacion> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal) ; 
        

       //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
        //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
        
  };

#endif


