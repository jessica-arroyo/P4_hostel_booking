#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H
#include <string>
#include <iostream>
#include "DtUsuario.hpp"
using namespace std;

class DtEmpleado: public DtUsuario {
    private:
    TipoCargo cargo;

    public:
    DtEmpleado();
    ~DtEmpleado();
    DtEmpleado(string , string ,string , TipoCargo) ;
    TipoCargo getCargo() ;
};

#endif

