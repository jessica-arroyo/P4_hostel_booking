#ifndef IFECHA_HPP
#define IFECHA_HPP

#include "DtFechaHora.hpp"

class IFecha{
public:
	virtual DtFechaHora getFechaHora() = 0;
	virtual	void setFechaHora(DtFechaHora horaActual) = 0;
};

#endif