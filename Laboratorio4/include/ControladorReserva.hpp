#ifndef CONTROLADORRESERVA_H
#define CONTROLADORRESERVA_H

#include "Reserva.hpp"
#include "DtReserva.hpp"
#include "DtReservaGrupal.hpp"
#include "DtReservaIndividual.hpp"
#include "ReservaGrupal.hpp"
#include "ReservaIndividual.hpp"
#include "DtCalificacion.hpp"
#include "DtEstadia.hpp"
#include "Calificacion.hpp"
#include "Estadia.hpp"
#include "IReserva.hpp"
#include "Huesped.hpp"
#include "Fecha.hpp"
#include "ControladorHostal.hpp"
#include "ControladorUsuario.hpp"
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include "Fecha.hpp"

using namespace std;

class ControladorReserva: public IReserva
{
private:
    ControladorReserva() ;
    static ControladorReserva *_instancia;
    map<int,Reserva*> SetReservas;
    //map<int,Estadia*> SetEstadias;
    //map<int,Calificacion*> SetCalificaciones;

    //no era que no íbamos a tener una colección genérica ni para Estadias ni para Calificaciones?

public:
    ~ControladorReserva();
    static ControladorReserva *getInstancia() ;
    map<int , Reserva*> getSetReservas() ; 
    void confirmarReservaGrupal(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped, set<string> grupoHues, int cont);
	void confirmarReservaIndividual(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped);
    map<int, Reserva*> getSetReservas();

    map<int,DtReserva> listarReservas(string nombreHostal, string emailHuesped);
    bool existeReserva(int codigo);
    void inscribirEstadia(int codigo, string emailHuesped);
    

    //void cancelarReserva();
    //set<DtCalificacion> chequearCalificacion(string nombreHostal);
    //map<int,DtReserva> listarReservas(string nombreHostal, string emailHuesped);
    //void inscribirEstadia(DtReserva reserva);
    void finalizarEstadia(string emailHuesped);
    //set<DtEstadia> obtenerEstadiasFinalizadas(string emailHuesped,string nombreHostal);
    //DtReserva obtenerReservaAsociada(string nombreEstadia); //la estadia no tiene atributo nombre.
    //DtCalificacion obtenerCalificacion(string nombreEstadia); //la estadia no tiene atributo nombre.
    //DtEstadia obtenerEstadia(string nombreEstadia); //la estadia no tiene atributo nombre.
    //set<DtEstadia> listarEstadias(string nombreHostal);
    //map<int,DtReservaIndividual> listarIndividuales(string nombreHostal);
    //map<int,DtReserva> listarGrupales(string nombreHostal);
    //map<int,DtReserva> listarReservas();
    //set<DtCalificacion> listarCalificaciones();
    //void ingresarComentario(string comentario,string respuesta);
    //set<string> listarComentariosSinR(string emailEmpleado); 
    //void insertarCalificacion(string comentario, int puntaje, DtEstadia estadia);
    //void confirmarBaja();
    //void cancelarBaja();
};

#endif


