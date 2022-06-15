#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H
#include <string>
#include <iostream>
#include "DtUsuario.hpp"
using namespace std;

class DtEmpleado: public DtUsuario {
    private:
    string cargo;
    string nombreHostal;

    public:
    DtEmpleado();
    ~DtEmpleado();
    DtEmpleado(string nombre, string email ,string password , string cargo, string nombreHostal) ;
    string getCargo() ;
    string getNombreHostal() ;
};

#endif

