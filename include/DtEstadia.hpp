#ifndef DTESTADIA_HPP
#define DTESTADIA_HPP

#include "DtFechaHora.hpp"

#include <map>
#include <set>
#include <iterator>
#include <iostream>

class DtEstadia
{
private:
    DtFechaHora checkIn, checkout;
    std::string promo;
public:
    DtEstadia();
    ~DtEstadia();
    std::string getPromo ();
	DtFechaHora getCheckIn ();
	DtFechaHora getCheckOut ();
};


#endif