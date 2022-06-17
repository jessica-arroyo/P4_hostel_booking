#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "IHostal.hpp"

#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std ;

class ControladorHostal: public IHostal {
    private:
        ControladorHostal() ;
        static ControladorHostal *_instancia ;
        map<string, Hostal*> SetHostales ;
    

    public:
        ~ControladorHostal() ;
        static ControladorHostal *getInstancia() ;

        bool existeHostal(string nombre) ; 
        bool existeHabitacion(int numero, string nombreHostal) ; 
        void agregarHabitacion(int numero,int precio,int capacidad,string nombreH) ; 
        void altaHostal(string nombre, string direccion, int telefono, int calificacionProm) ; 
        map<string , Hostal*> getSetHostales() ; 
		map<string , DtHostal> listarHostales() ; 
        DtHostal infoHostal(string nombreHostal) ; 
        map<int, DtCalificacion> listarCalificaciones(string nombreHostal) ; 
        //void map<string , DtHostal> top3hostales() ; 
        map<int , DtHabitacion> listarHabitaciones(string nombreHostal) ;
        map<int , DtReservaGrupal> listarReservasGrupal(string nombreHostal) ; 
		map<int , DtReservaIndividual> listarReservasIndividual(string nombreHostal) ;  
        //Hostal* encontrarHostal(string nombreHostal) ;  
        map<int , DtHabitacion> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout, string nombreHostal) ; 
        

       //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
        //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
        
  };

#endif


