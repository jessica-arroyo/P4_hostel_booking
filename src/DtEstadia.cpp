#include "../include/DtEstadia.hpp"

DtEstadia::DtEstadia() {} 

DtEstadia::~DtEstadia() {} 

DtFechaHora DtEstadia::getCheckIn(){
    return this->checkIn ;
}

string DtEstadia::getPromo(){
    return this->promo;
}

DtFechaHora DtEstadia::getCheckOut(){
    return this->checkOut ;
}