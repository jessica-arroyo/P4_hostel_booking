#include "../include/DtCalificacion.hpp"
    
using namespace std ;

    DtCalificacion::DtCalificacion(){}
	
	DtCalificacion::DtCalificacion(DtFechaHora fecha, string comentario, string respuesta){
		this->fecha = fecha ;
		this->comentario = comentario ;
		this->respuesta = respuesta ;
		this->puntaje = puntaje ;
	}

	DtCalificacion::~DtCalificacion(){}
		
	string DtCalificacion::getRespuesta() {
			return this->respuesta;
		}
		
	DtFechaHora DtCalificacion::getFecha() {
			return this->fecha;
		}
		
	string DtCalificacion::getComentario () {
			return this->comentario;
		}
		
	int DtCalificacion::getPuntaje() {
			return this->puntaje;
		}

#endif        