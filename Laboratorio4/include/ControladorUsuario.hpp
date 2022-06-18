#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Reserva.hpp" 
#include "DtEmpleado.hpp"
#include "DtHuesped.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
#include "Usuario.hpp"
#include "IUsuario.hpp"
#include "ControladorHostal.hpp"
#include "ControladorReserva.hpp"
#include "DtUsuario.hpp"
#include <map>
#include <iostream>
using namespace std;

class ControladorUsuario: public IUsuario {
  private:
    ControladorUsuario() ;
    static ControladorUsuario *instancia ;

    map<string , Empleado*> empleados;
    map<string , Huesped*> huespedes;
  
  public:
    ~ControladorUsuario() ;
    static ControladorUsuario *getInstancia();
    
    bool existeEmpleado(string emailUser) ;
    bool existeHuesped(string emailUser) ;
    // alta de usuario 
    void confirmarAltaEmpleado(string nombre, string email, string password, TipoCargo cargo) ;
    void confirmarAltaHuesped(string nombre, string email, string password, bool esFinger) ;
    
    //consulta de usuario

    DtEmpleado mostrarEmpleado(string emailEmpleado);  
    DtHuesped mostrarHuesped(string emailHuesped); 


    //las siguientes 5 no van más.
    //bool ingresarEmpleado(DtEmpleado dte);
    //bool ingresarHuesped(DtHuesped dth);
    //void confirmarAlta();
    //void cancelarAlta();
    //void reingresarEmail(string emailUser);
    
    
    //las que comenté de acá abajo son para que compile sin que estén hechas aun.
    //map<string, Empleado *> listarEmpleadosNoAsignados(string nombreHostal);
    //void asignarEmpleado(string emailEmpleado, TipoCargo cargo); //el TipoCargo se pasó al crear el usuario.
    //void cancelarAsignarEmpleado();  
    map<string, DtHuesped> listarHuespedes();
	map<string, DtEmpleado> listarEmpleados();
	//a
    //map<string, Huesped *> listarHuespedes(int codigoHabitacion);
    //void confirmarHuesped(string emailHuespedReserva);
    //void agregarHuesped(string emailHuesped);
    
    
    //void encontrarHuesped(string emailHuespedReserva);
    
    //map<string, Reserva *> listarReservas(string nombreHostal, string email);
        
  };





#endif
