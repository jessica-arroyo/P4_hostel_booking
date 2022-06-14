#include "../include/Calificacion.hpp"

 using namespace std ;   

    Calificacion::Calificacion(){};

    Calificacion::Calificacion(DtFechaHora fecha, string comentario, string respuesta, int puntaje){
        this->fecha = fecha ;
        this->comentario = comentario ;
        this->respuesta = respuesta ;
        this->puntaje = puntaje ;
    }

    Calificacion::~Calificacion(){};

    void Calificacion::setFecha(DtFechaHora fecha) {
        this->fecha = fecha;
    };

	void Calificacion::setComentario(string comentario){
        this->comentario = comentario;
    };

    void Calificacion::setPuntaje(int puntaje) {
        this->puntaje = puntaje;
    };

    void Calificacion::SetRespuesta(string respuesta) {
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
    

    DtCalificacion Calificacion::getDtCalificacion(){
        DtCalificacion c = DtCalificacion(this->fecha,this->comentario,this->respuesta,this->puntaje) ;
    };

    //Calificacion::create(DtFechaHora fecha, string comentario, int puntaje, string respuesta){};
    //Calificacion::notificarEvento(){};
    //Calificacion::add(Calificacion cal){};
    //Calificacion Calificacion::find(string comentario){};