#ifndef CALIFICACION_HPP
#define CALIFICACION_HPP

#include <map>
//#include <set> si usamos.
#include <iterator>
#include <iostream>

#include "../include/DtFechaHora.hpp"
#include "../include/DtCalificacion.hpp"

using namespace std ;

class Calificacion{
private:
    DtFechaHora fecha;
    string comentario, respuesta;
    int puntaje;
public:
    Calificacion();
    Calificacion(DtFechaHora fecha, string comentario, string respuesta, int puntaje) ;
    ~Calificacion();
    void setFecha(DtFechaHora fecha) ;
	void setComentario(string comentario);
    void setPuntaje(int puntaje) ;
    void SetRespuesta(string respuesta) ;

    string getComentario() ;
	DtFechaHora getFecha();
	int getPuntaje() ;
	string getRespuesta() ;

    DtCalificacion getDtCalificacion();
    //create(DtFechaHora fecha, string comentario, int puntaje, string respuesta);
    //notificarEvento();
    //add(Calificacion cal);
    //Calificacion find(string comentario);
};

#endif

/* como resuelvo lo de dependencias como lo codeo y tambien como hago lo de observer */