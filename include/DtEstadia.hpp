#ifndef DTESTADIA_HPP
#define DTESTADIA_HPP

#include "DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

using namespace std ;

class DtEstadia
{
private:
    DtFechaHora checkIn, checkOut;
    string promo;
public:
    DtEstadia();
    DtEstadia(DtFechaHora checkIn, DtFechaHora checkOut, string promo);
    ~DtEstadia();
    string getPromo();
	DtFechaHora getCheckIn();
	DtFechaHora getCheckOut();
};


#endif


