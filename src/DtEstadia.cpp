#include "../include/DtEstadia.hpp"

using namespace std ;

DtEstadia::DtEstadia() {} 

DtEstadia::~DtEstadia() {} 

DtEstadia::DtEstadia(DtFechaHora checkIn, DtFechaHora checkOut, string promo){
    this->checkIn = checkIn ;
    this->checkOut = checkOut ;
    this->promo = promo ;
}

DtFechaHora DtEstadia::getCheckIn(){
    return this->checkIn ;
}

string DtEstadia::getPromo(){
    return this->promo;
}

DtFechaHora DtEstadia::getCheckOut(){
    return this->checkOut ;
}