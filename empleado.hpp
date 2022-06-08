// faltan las funciones del dcd, estoy mirando el teórico para entender cómo van
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <iostream>
#include "usuario.hpp"
using namespace std;

enum TipoCargo
{
  Administracion,
  Limpieza,
  Recepcion,
  Infraestructura
};

class Empleado: public Usuario  {
    
    private:
    TipoCargo cargo;
    
    public:
    Empleado();
    ~Empleado();
    Empleado(string , string, string, TipoCargo) ;
    bool getCargo() ;
    void setCargo(TipoCargo);
};

+find(emailHuesped: string)
  
#endif
