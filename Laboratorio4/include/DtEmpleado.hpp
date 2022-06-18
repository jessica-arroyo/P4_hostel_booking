#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H
#include <string>
#include <iostream>
#include "DtUsuario.hpp"
#include "Empleado.hpp"

class Empleado ;

using namespace std;

class DtEmpleado: public DtUsuario {
    private:
    TipoCargo cargo;
    string nombreHostal;

    public:
    DtEmpleado();
    ~DtEmpleado();
    DtEmpleado(string nombre, string email ,string password , TipoCargo cargo, string nombreHostal) ;
    TipoCargo getCargo() ;
    string getNombreHostal() ;
};

#include "Empleado.hpp"

#endif

