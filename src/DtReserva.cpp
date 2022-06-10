#include "../include/DtReserva.hpp"

		Reserva::Reserva(){}
		
		Reserva::~Reserva(){}
		
		int Reserva::getCodigo () {
			return this->codigo;
		}
		
		DtFechaHora Reserva::getCheckIn () {
			return this->checkIn;
		}
		
		DtFechaHora Reserva::getCheckOut () {
			return this->checkOut;
		}
		
		DtFechaHora Reserva::getFechaRealizada () {
			return this->fechaRealizada;
		}
		
		TipoEstado Reserva::getEstado () {
			return this->estado;
		}
		
		float Reserva::getCosto (){
			return this->costo;
		}
		
#endif