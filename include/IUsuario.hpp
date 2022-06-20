#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "DtEmpleado.hpp"
#include "DtHuesped.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
#include "Usuario.hpp"
#include "DtUsuario.hpp"


#include <map>
#include <string>
#include <set>
#include <iostream>

class IUsuario {
  public:
    IUsuario();
    virtual ~IUsuario()=0 ;
    
	virtual map<string , Empleado*>	getEmpleados()=0;
    virtual map<string , Huesped*> getHuespedes()=0;
    virtual bool existeEmpleado(string emailUser)=0 ;
    virtual bool existeHuesped(string emailUser)=0 ;
    // alta de usuario 
    virtual void confirmarAltaEmpleado(string nombre, string email, string password, TipoCargo cargo)=0 ;
    virtual void confirmarAltaHuesped(string nombre, string email, string password, bool esFinger)=0 ;
    
    //consulta de usuario
    //virtual map<string, Usuario *> listarUsuarios()=0;

    virtual DtEmpleado mostrarEmpleado(string emailEmpleado)=0;  
    virtual DtHuesped mostrarHuesped(string emailHuesped)=0; 


    //las siguientes 5 no van más.
    //virtual bool ingresarEmpleado(DtEmpleado dte)=0;
    //virtual bool ingresarHuesped(DtHuesped dth)=0;
    //virtual void confirmarAlta()=0;
    //virtual void cancelarAlta()=0;
    //virtual void reingresarEmail(string emailUser)=0;
  
  virtual Huesped* obtenerHuesped(string emailHuesped)=0;
  
    virtual map<string, DtEmpleado> listarEmpleadosNoAsignados()=0;
	virtual void asignarEmpleado(string emailEmpleado, TipoCargo cargo, Hostal *hostal) = 0;

    //virtual void cancelarAsignarEmpleado() = 0;
    virtual map<string, DtHuesped> listarHuespedes()=0;
	virtual map<string, DtEmpleado> listarEmpleados()=0;	//a
    //virtual map<string, Huesped *> listarHuespedes(int codigoHabitacion)=0;
    //virtual void confirmarHuesped(string emailHuespedReserva) = 0;
    //virtual void agregarHuesped(string emailHuesped) = 0;
    
    //virtual void encontrarHuesped(string emailHuespedReserva)=0;
    //virtual map<string, Reserva *> listarReservas(string nombreHostal, string email)=0;
      
};

#endif
