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
	string emailHuesped ;
	int numeroHabitacion ;
    
public:
    DtEstadia();
    DtEstadia(DtFechaHora checkIn, DtFechaHora checkOut, string emailHuesped, int numeroHabitacion);
    ~DtEstadia();
	DtFechaHora getCheckIn();
	DtFechaHora getCheckOut();
	string getEmailHuesped();
	int getNumeroHabitacion() ;
	
};


#endif


