#ifndef CONTROLADORRESERVA_H
#define CONTROLADORRESERVA_H

#include "Reserva.hpp"
#include "Calificacion.hpp"
#include "Estadia.hpp"
#include "IReserva.hpp"
#include <map>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;

class ControladorReserva: public IReserva
{
private:
    ControladorReserva() ;
    static ControladorReserva *_instancia;
    std::map<int,Reserva*> SetReservas;
    std::map<int,Estadia*> SetEstadias;
    std::map<int,Calificacion*> SetCalificaciones;
public:
    ~ControladorReserva();
    static ControladorReserva *getInstancia() ;
    void confirmarReserva();
    void cancelarReserva();
    std::map<int,DtCalificacion> chequearCalificacion(string nombreHostal);
    std::map<int,DtReserva> listarReservas(string nombreHostal, string emailHuesped);
    void inscribirEstadia(DtReserva reserva);
    void finalizarEstadia(string nombreHostal, string emailHuesped);
    std::map<int,DtEstadia> obtenerEstadiasFinalizadas(string emailHuesped,string nombreHostal);
    DtReserva obtenerReservaAsociada(string nombreEstadia);
    DtCalificacion obtenerCalificacion(string nombreEstadia);
    DtEstadiaobtenerEstadia(string nombreEstadia);
    std::map<int,DtEstadia> listarEstadias(string nombreHostal);
    std::map<int,DtReserva> obtenerReservas(string nombreHostal);
    std::map<int,DtReserva> listarReservas();
    std::map<int,DtCalificacion> listarCalificaciones();
    void ingresarComentario(string comentario,string respuesta);
    std::map<string,string>listarComentariosSinR(string emailEmpleado); //pongo asi string string en map o solo un map<string> basta
    void insertarCalificacion(string comentario, int puntaje, DtEstadia estadia);
    void confirmarBaja();
    void cancelarBaja();
};

#endif