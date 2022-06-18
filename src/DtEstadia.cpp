#include "../include/DtEstadia.hpp"

using namespace std ;

DtEstadia::DtEstadia() {} 

DtEstadia::~DtEstadia() {} 

DtEstadia::DtEstadia(DtFechaHora checkIn, DtFechaHora checkOut, string emailHuesped, int numeroHabitacion){
    this->checkIn = checkIn ;
    this->checkOut = checkOut ;
	this->emailHuesped = emailHuesped ;
	this->numeroHabitacion = numeroHabitacion ;
}

DtFechaHora DtEstadia::getCheckIn(){
    return this->checkIn ;
}

DtFechaHora DtEstadia::getCheckOut(){
    return this->checkOut ;
}

string DtEstadia::getEmailHuesped(){
	return this->emailHuesped ;
}

int DtEstadia::getNumeroHabitacion(){
	return this->numeroHabitacion ;
}



