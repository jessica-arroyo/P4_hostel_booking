#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Usuario.hpp"
#include "DtUsuario.hpp"
#include "Hostal.hpp"

#include <string>
#include <iostream>

class DtEmpleado ;

using namespace std;

enum TipoCargo
{
  ADMINISTRACION,
  LIMPIEZA,
  RECEPCION,
  INFRAESTRUCTURA
};

class Empleado: public Usuario  {
  
  private:
    TipoCargo cargo;
    Hostal *hostal;
  
  public:
    Empleado();
    ~Empleado();
    Empleado(string nombre , string email, string password, TipoCargo cargo) ;
    TipoCargo getCargo() ;
    Hostal * getHostal();
    void setCargo(TipoCargo cargo);
    bool estaAsignado(string nombreHostal);
    DtEmpleado getDtEmpleado();
    void setHostal(Hostal *nuevohostal);
    //void entrarHostal();
  
    
};

#include "DtEmpleado.hpp"

#endif


