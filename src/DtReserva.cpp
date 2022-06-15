#include "../include/DtReserva.hpp"

		DtReserva::DtReserva(){}
		
		DtReserva::DtReserva(int codigo,DtFechaHora checkIn, DtFechaHora checkOut, DtFechaHora fechaRealizada, TipoEstado estado, float costo, string emailHuesped){
			codigo = codigo ;
			checkIn = checkIn ;
			checkOut = checkOut ;
			fechaRealizada = fechaRealizada ;
			estado = estado ;
			costo = costo ;
			emailHuesped = emailHuesped ;
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
		
		TipoEstado DtReserva::getEstado () {
			return this->estado;
		}
		
		float DtReserva::getCosto (){
			return this->costo;
		}
		
		string DtReserva::getEmailHuesped (){
			return this->emailHuesped;
		}
		
		