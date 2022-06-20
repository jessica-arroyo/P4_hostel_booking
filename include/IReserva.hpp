#ifndef IRESERVA_H
#define IRESERVA_H

#include "DtReserva.hpp"
#include "DtEstadia.hpp"
#include "DtCalificacion.hpp"
#include "Reserva.hpp"
#include "Estadia.hpp"
#include "Calificacion.hpp"

using namespace std ;

#include <map>
#include <set>
#include <iostream>

class IReserva
{
public:
    IReserva();
    virtual ~IReserva() = 0;
    virtual void confirmarReservaGrupal(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped, map<string, Huesped*> grupoHues, int cont) = 0;
	virtual void confirmarReservaIndividual(string nomhos, int numhab, DtFechaHora fechaCheckIn, DtFechaHora fechaCheckOut, string mailHuesped) = 0;
    virtual map<int, Reserva*> getSetReservas() = 0 ;
    //virtual void cancelarReserva() = 0;
    //virtual set<DtCalificacion> chequearCalificacion(string nombreHostal) = 0;
    //virtual map<int,DtReserva> listarReservas(string nombreHostal, string emailHuesped) = 0;
    //virtual void inscribirEstadia(DtReserva reserva) = 0;
    virtual void finalizarEstadia(string emailHuesped) = 0;
    //virtual set<DtEstadia> obtenerEstadiasFinalizadas(string emailHuesped,string nombreHostal) = 0;
    //virtual DtReserva obtenerReservaAsociada(string nombreEstadia) = 0; //la estadia no tiene atributo nombre.
    //virtual DtCalificacion obtenerCalificacion(string nombreEstadia) = 0; //la estadia no tiene atributo nombre.
    //virtual DtEstadia obtenerEstadia(string nombreEstadia) = 0; //la estadia no tiene atributo nombre.
    //virtual set<DtEstadia> listarEstadias(string nombreHostal) = 0;
    //virtual map<int,DtReserva> obtenerReservas(string nombreHostal) = 0;
    //virtual map<int,DtReserva> listarReservas() = 0;
    //virtual set<DtCalificacion> listarCalificaciones() = 0;
    //virtual void ingresarComentario(string comentario,string respuesta) = 0; 
    //virtual set<string> listarComentariosSinR(string emailEmpleado) = 0; 
    //virtual void insertarCalificacion(string comentario, int puntaje, DtEstadia estadia) = 0;
    //virtual void confirmarBaja() = 0;
    //virtual void cancelarBaja() = 0;
};

#endif

