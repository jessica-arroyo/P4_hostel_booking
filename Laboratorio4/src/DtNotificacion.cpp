#include "../include/DtNotificacion.hpp"
#include "../include/DtFechaHora.hpp"

using namespace std;

DtNotificacion::DtNotificacion(string autor, int puntaje, string comentario){
	this->autor = autor;
	this->puntaje = puntaje;
	this->comentario = comentario;
}

string DtNotificacion::getAutor(){
	return this->autor;
}

int DtNotificacion::getPuntaje(){
	return this->puntaje;
}

string DtNotificacion::getComentario(){
	return this->comentario;
}
