#ifndef DTNOTIFICACION_HPP
#define DTNOTIFICACION_HPP
#include <string>

class DtNotificacion
{
	private:
		std::string autor;
		int puntaje; // de 1 a 5
		std::string comentario;
	public:
		DtNotificacion(std::string autor, int puntaje, std::string comentario);
        
        std::string getAutor();
		int getPuntaje();
		std::string getComentario();

};
#endif