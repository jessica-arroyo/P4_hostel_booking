#ifndef DTHUESPED_H
#define DTHUESPED_H
#include <string>
#include <iostream>
#include "../include/DtUsuario.hpp"
using namespace std;

class DtHuesped: public DtUsuario {
    private:
    bool esFinger;
    public:
    DtHuesped();
    ~DtHuesped();
    DtHuesped(string nombre, string email, string password, bool esFinger) ;
    bool getEsFinger() ;
};

#endif
