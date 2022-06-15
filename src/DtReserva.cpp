#include "../include/DtReserva.hpp"

		DtReserva::DtReserva(){}
		
		DtReserva::DtReserva(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, std::string estado, float costo){
			codigo = codigo ;
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
		}
		
		DtReserva::~DtReserva(){}
		
		int DtReserva::getCodigo () {
			return this->codigo;
		}
		
		DtFechaHora DtReserva::getCheckIn () {
			return this->checkIn;
		}
		
		DtFechaHora DtReserva::getCheckOut () {
			return this->checkOut;
		}
		
		DtFechaHora DtReserva::getFechaRealizada () {
			return this->fechaRealizada;
		}
		
		std::string DtReserva::getEstado () {
			return this->estado;
		}
		
		float DtReserva::getCosto (){
			return this->costo;
		}
		