#include "../include/Calificacion.hpp"

    Calificacion::Calificacion(){};

    Calificacion::~Calificacion(){};
    
    void Calificacion::setFecha(DtFechaHora fecha) {
        this->fecha = fecha;
    };

	void Calificacion::setComentario(std::string comentario){
        this->comentario = comentario;
    };

    void Calificacion::setPuntaje(int puntaje) {
        this->puntaje = puntaje;
    };

    void Calificacion::SetRespuesta(std::string respuesta) {
        this->respuesta = respuesta;
    };

    std::string Calificacion::getComentario() {
        return this->comentario;
    };

	DtFechaHora Calificacion::getFecha(){
        return this->fecha;
    };

	int Calificacion::getPuntaje() {
        return this->puntaje;
    };

	std::string Calificacion::getRespuesta() {
        return this->respuesta;
    };
    

    DtCalificacion Calificacion::getDtCalificacion(){};
    Calificacion::create(DtFechaHora fecha, std::string comentario, int puntaje, std::string respuesta){};
    Calificacion::notificarEvento(){};
    Calificacion::add(Calificacion cal){};
    Calificacion Calificacion::find(std::string comentario){};