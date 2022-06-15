#include "../include/Estadia.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

    Estadia::Estadia() {} 
    Estadia::~Estadia(){}

    Estadia::Estadia(DtFechaHora checkIn, DtFechaHora checkOut, string promo){
        this->checkIn = checkIn ;
        this->checkOut = checkOut ;
        this->promo = promo ;
    }

    void Estadia::setCheckIn (DtFechaHora checkIn){
        this->checkIn = checkIn;
    }

	void Estadia::setCheckOut (DtFechaHora checkOut){
        this->checkOut = checkOut;
    }

    void Estadia::setPromo (string promo){
        this->promo = promo;
    } 

    void Estadia::agregarCalificacion(Calificacion *cal) {
        this->calificacion = cal;
    }

    void Estadia::agregarHabitacionAEstadia(Habitacion *hab) {
        this->habitacion = hab;
    }

    string Estadia::getPromo () {
        return this->promo;
    }

	DtFechaHora Estadia::getCheckIn () {
        return this->checkIn;
    }

	DtFechaHora Estadia::getCheckOut () {
        return this->checkOut;
    }

	Estadia* Estadia::getCalificacion (){
        return this->calificacion;
    }

	Habitacion* Estadia::getHabitacion(){
        return this->habitacion;
    }

    //Estadia::create(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab){};  
    //Estadia::setearValoresIniciales(DtFechaHora checkin,DtFechaHora checkout,std::string promo,Calificacion *cal,Habitacion *hab){};
    //Estadia::add(Estadia esta){}; //va aca o controlador??
    //Estadia::entrarCal(){};
    //Estadia::linkeoHab(){};  //en el dcd dice linkeo habitacion pero faltaria entrarHab no???
    //Estadia Estadia::find(DtEstadia estadia){};
    //Estadia::aniadirCalificacionAEstadia(Calificacion cal){};