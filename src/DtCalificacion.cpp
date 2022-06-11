#include "../include/DtCalificacion.hpp"
    
    
    DtCalificacion::DtCalificacion(){}
		
	DtCalificacion::~DtCalificacion(){}
		
	std::string DtCalificacion::getRespuesta() {
			return this->respuesta;
		}
		
	DtFechaHora DtCalificacion::getFecha() {
			return this->fecha;
		}
		
	std::string DtCalificacion::getComentario () {
			return this->comentario;
		}
		
	int DtCalificacion::getPuntaje() {
			return this->puntaje;
		}

#endif        