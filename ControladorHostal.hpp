#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "IHostal.hpp"
#include <map>
#include <iostream>

class ControladorHostal: public: IHostal {
    private:
        ControladorHostal() ;
        static ControladorHostal *_instancia ;
        std::map<string,Hostal*> SetHostales ;
        //acá guardan usuarios y otros objetos que se precisen recordar.
    public:
        ~ControladorHostal() ;
        static ControladorHostal *getInstancia() ;
    
        altaHostal(DtHostal hostal) ;
        std::map<string , DtHostal *> hos listarHostales() ; //La colección de Hostales va a ser un map o un set (porque podríamos querer tener ordenados 
        //a los Hostales en base a su calificacionPromedio para tener más fácil lo de Top 3 Hostales)
        map<int , DtHabitacion *> habs listarHabitaciones(DtFechaHora checkIn, DtFechaHora checkOut, bool esGrupal, string nombreHostal) ;
        ingresarDatos(string nombreHostal, DtHabitacion habitacion) ;
        agregarHabitacion() ;
        cancelarHabitacion() ;
        std::map<string , DtHostal *> hos top3hostales() ;
        DtHostal infoHostal(string nombreHostal) ;
        map<int , DtHabitacion *> habs listarHabitaciones() ;
        Hostal encontrarHostal(string nombreHostal) ; //acá creo que tiene que devolver el DtHostal. Porque no se devuelven objetos.
        map<int , DtHabitacion *> habs devolverHabitacionesDisponibles(DtFechaHora checkin, DtFechaHora checkout) ;
        
        
  };

#endif

