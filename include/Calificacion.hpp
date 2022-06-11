#ifndef CALIFICACION_HPP
#define CALIFICACION_HPP

#include <map>
//#include <set> si usamos.
#include <iterator>
#include <iostream>

#include "../include/DtFechaHora.hpp"
#include "../include/DtCalificacion.hpp"

class Calificacion
{
private:
    DtFechaHora fecha;
    std::string comentario, respuesta;
    int puntaje;
public:
    Calificacion();
    virtual ~Calificacion() = 0;
    void setFecha(DtFechaHora fecha) ;
	void setComentario(std::string comentario);
    void setPuntaje(int puntaje) ;
    void SetRespuesta(std::string respuesta) ;

    std::string getComentario() ;
	DtFechaHora getFecha();
	int getPuntaje() ;
	std::string getRespuesta() ;

    DtCalificacion getDtCalificacion();
    create(DtFechaHora fecha, std::string comentario, int puntaje, std::string respuesta);
    notificarEvento();
    add(Calificacion cal);
    Calificacion find(std::string comentario);
};

#endif

/* como resuelvo lo de dependencias como lo codeo y tambien como hago lo de observer */