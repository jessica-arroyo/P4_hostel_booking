#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "IHostal.hpp"
#include <map>
#include <iostream>
#include <string>

class ControladorHostal: public: IHostal {
    private:
        ControladorHostal() ;
        static ControladorHostal *_instancia ;
        std::map<string,Hostal*> SetHostales ;
        //acá guardan usuarios y otros objetos que se precisen recordar.
        Hostal * hostalCreado ;
        string nombrerecordado ;

    public:
        ~ControladorHostal() ;
        static ControladorHostal *getInstancia() ;
    
        void altaHostal(string nombre, string direccion, int telefono, int calificacionProm) ;
        std::map<string , DtHostal> listarHostales() ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
        //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
        map<int , DtHabitacion > listarHabitacionesDisp(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal) ;
        map<int , DtCalificacion> listarCalificaciones() ;
        void ingresarDatos(string nombreHostal, DtHabitacion habitacion) ;
        void agregarHabitacion() ;
        void cancelarHabitacion() ;
        void std::map<string , DtHostal> top3hostales() ;
        DtHostal infoHostal(string nombreHostal) ;
        map<int , DtHabitacion> listarHabitaciones() ;
        DtHostal encontrarHostal(string nombreHostal) ; //acá puse que se devuelva el DtHostal. Porque no se devuelven objetos.
        map<int , DtHabitacion> devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout) ;
        
        
  };

#endif

