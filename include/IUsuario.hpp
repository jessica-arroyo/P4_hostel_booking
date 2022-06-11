#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "DtEmpleado.hpp"
#include "DtHuesped.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
#include "Usuario.hpp"


#include <map>
#include <string>
#include <set>
#include <iostream>

class IUsuario {
  public:
    IUsuario(){}
    virtual ~IUsuario(){}=0 ;
    
    // alta de usuario 
    virtual bool ingresarEmpleado(DtEmpleado *dte);
    virtual bool ingresarHuesped(DtHuesped *dth);
    virtual void confirmarAlta() = 0;
    virtual void cancelarAlta() = 0;
    virtual void reingresarEmail(string emailUser) = 0;
  
    virtual map<string, Empleado *> listarEmpleadosNoAsignados(string nombreHostal);
    virtual void asignarEmpleado(string emailEmpleado, TipoCargo cargo) = 0;
    virtual void cancelarAsignarEmpleado() = 0;
    virtual map<string, Huesped *> listarHuespedes(int codigoHabitacion);
    virtual void confirmarHuesped(string emailHuespedReserva) = 0;
    virtual void agregarHuesped(string emailHuesped) = 0;
    virtual map<string, Usuario *> listarUsuarios();
    virtual DtEmpleado mostrarEmpleado(DtEmpleado empleado);  
    virtual DtHuesped mostrarHuesped(DtHuesped huesped); 
    virtual void encontrarHuesped(string emailHuespedReserva);
      
};

#endif
