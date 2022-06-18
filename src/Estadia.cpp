#include "../include/Estadia.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

    Estadia::Estadia() {} 
    Estadia::~Estadia(){}

    Estadia::Estadia(DtFechaHora checkIn, DtFechaHora checkOut, Habitacion *hab, Huesped *hues){
        this->checkIn = checkIn ;
        this->checkOut = checkOut ;
		this->calificacion = NULL;
		this->habitacion = hab;
		this->huesped = hues ;
    }

    void Estadia::setCheckIn (DtFechaHora checkIn){
        this->checkIn = checkIn;
    }

	void Estadia::setCheckOut (DtFechaHora checkOut){
        this->checkOut = checkOut;
    }

    void Estadia::agregarCalificacion(Calificacion *cal) {
        this->calificacion = cal;
    }

    void Estadia::agregarHabitacionAEstadia(Habitacion *hab) {
        this->habitacion = hab;
    }

	void Estadia::setHuesped(Huesped *hues){
		this->huesped = hues ;
	}

	Huesped* Estadia::getHuesped(){
		return this->huesped ;
	}

	DtFechaHora Estadia::getCheckIn () {
        return this->checkIn;
    }

	DtFechaHora Estadia::getCheckOut () {
        return this->checkOut;
    }

	Calificacion* Estadia::getCalificacion (){
        return this->calificacion;
    }

	Habitacion* Estadia::getHabitacion(){
        return this->habitacion;
    }

	DtEstadia Estadia::getDtEstadia(){
		DtEstadia dtest = DtEstadia(this->checkIn,this->checkOut,this->huesped->getEmail(), this->habitacion->getNumero()) ;
		return dtest ;
	}

    //Estadia::create(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab){};  
    //Estadia::setearValoresIniciales(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab){};
    //Estadia::add(Estadia esta){}; //va aca o controlador??
    //Estadia::entrarCal(){};
    //Estadia::linkeoHab(){};  //en el dcd dice linkeo habitacion pero faltaria entrarHab no???
    //Estadia Estadia::find(DtEstadia estadia){};
    //Estadia::aniadirCalificacionAEstadia(Calificacion cal){};