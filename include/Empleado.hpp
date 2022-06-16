#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <iostream>
#include "Usuario.hpp"
#include "DtUsuario.hpp"
#include "DtEmpleado.hpp"
#include "Hostal.hpp"

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
    void setCargo(TipoCargo cargo);
    bool estaAsignado(string nombreHostal);
    DtEmpleado getDtEmpleado(); //va sin puntero creo. 
    void setHostal(Hostal *nuevohostal);
    //void entrarHostal();
  
    
};


#endif
