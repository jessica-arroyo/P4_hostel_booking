#ifndef FECHA_HPP
#define FECHA_HPP
#include "DtFechaHora.hpp"
#include "IFecha.hpp"

class Fecha : public IFecha
{
private:
	DtFechaHora horaActual;
	static Fecha* _instancia;
protected:
	Fecha();
public:
	static Fecha* getInstancia();
	DtFechaHora getFechaHora();
	void setFechaHora(DtFechaHora horaActual);
};

#endif