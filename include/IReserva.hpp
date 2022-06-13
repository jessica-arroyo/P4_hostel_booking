#ifndef IRESERVA_H
#define IRESERVA_H

#include "Reserva.hpp"
#include "Estadia.hpp"
#include "Calificacion.hpp"
// poner include "Habitacion.hpp"?
#include <map>
#include <iostream>

class IReserva
{
public:
    IReserva();
    virtual ~IReserva() = 0;
    virtual void confirmarReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual std::map<int,DtCalificacion> chequearCalificacion(string nombreHostal) = 0;
    virtual std::map<int,DtReserva> listarReservas(string nombreHostal, string emailHuesped) = 0;
    virtual void inscribirEstadia(DtReserva reserva) = 0;
    virtual void finalizarEstadia(string nombreHostal, string emailHuesped) = 0;
    virtual std::map<int,DtEstadia> obtenerEstadiasFinalizadas(string emailHuesped,string nombreHostal) = 0;
    virtual DtReserva obtenerReservaAsociada(string nombreEstadia) = 0;
    virtual DtCalificacion obtenerCalificacion(string nombreEstadia) = 0;
    virtual DtEstadiaobtenerEstadia(string nombreEstadia) = 0;
    virtual std::map<int,DtEstadia> listarEstadias(string nombreHostal) = 0;
    virtual std::map<int,DtReserva> obtenerReservas(string nombreHostal) = 0;
    virtual std::map<int,DtReserva> listarReservas() = 0;
    virtual std::map<int,DtCalificacion> listarCalificaciones() = 0;
    virtual void ingresarComentario(string comentario,string respuesta) = 0; 
    virtual std::map<string,string>listarComentariosSinR(string emailEmpleado) = 0; //pongo asi string string en map o solo un map<string> basta
    virtual void insertarCalificacion(string comentario, int puntaje, DtEstadia estadia) = 0;
    virtual void confirmarBaja() = 0;
    virtual void cancelarBaja() = 0;
};

#endif