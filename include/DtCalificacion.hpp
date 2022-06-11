#ifndef DTCALIFICACION_HPP
#define DTCALIFICACION_HPP

#include "../include/DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtCalificacion
{
private:
    DtFechaHora fecha;
    std::string comentario, respuesta;
    int puntaje;
public:
    DtCalificacion();
    ~DtCalificacion();
    std::string getComentario() ;
	DtFechaHora getFecha();
	int getPuntaje() ;
	std::string getRespuesta() ;
};
#endif