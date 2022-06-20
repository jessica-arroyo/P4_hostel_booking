#ifndef DTCALIFICACION_HPP
#define DTCALIFICACION_HPP

#include "DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

class DtCalificacion
{
private:
    DtFechaHora fecha;
    string comentario, respuesta;
    int puntaje;
public:
    DtCalificacion();
    DtCalificacion(DtFechaHora fecha, string comentario, string respuesta, int puntaje);
    ~DtCalificacion();
    string getComentario() ;
	DtFechaHora getFecha();
	int getPuntaje() ;
	string getRespuesta() ;
};
#endif

