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
#include <map>
#include <iostream>
using namespace std;

class ControladorUsuario: public: IUsuario {
  private:
    ControladorUsuario() ;
    static ControladorUsuario *instancia ;

    std::map<std::string , Empleado*> empleados;
    std::map<std::string , Huesped*> huespedes;
  
  public:
    ~ControladorUsuario() ;
    static ControladoUsuario *getInstancia();
    
    bool existeEmpleado(string emailUser) ;
    bool existeHuesped(string emailUser) ;
    // alta de usuario 
    void confirmarAltaEmpleado(string nombre, string email, string password, TipoCargo cargo) ;
    void confirmarAltaHuesped(string nombre, string email, string password, bool esFinger) ;
    
    DtEmpleado mostrarEmpleado(DtEmpleado emailEmpleado);  
    DtHuesped mostrarHuesped(DtHuesped emailHuesped); 


    //las siguientes 5 no van más.
    //bool ingresarEmpleado(DtEmpleado dte);
    //bool ingresarHuesped(DtHuesped dth);
    //void confirmarAlta();
    //void cancelarAlta();
    //void reingresarEmail(string emailUser);
    
    
    //las que comenté de acá abajo son para que compile sin que estén hechas aun.
    //map<string, Empleado *> listarEmpleadosNoAsignados(string nombreHostal);
    //void asignarEmpleado(string emailEmpleado, TipoCargo cargo);
    //void cancelarAsignarEmpleado();  
    //map<string, Huesped *> listarHuespedes(int codigoHabitacion);
    //void confirmarHuesped(string emailHuespedReserva);
    //void agregarHuesped(string emailHuesped);
    //map<string, Usuario *> listarUsuarios();
    
    //void encontrarHuesped(string emailHuespedReserva);
    
    //map<string, Reserva *> listarReservas(string nombreHostal, string email);
        
  };





#endif
