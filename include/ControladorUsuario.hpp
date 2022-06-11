#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Reserva.hpp"
#include "DtEmpleado.hpp"
#include "DtHuesped.hpp"
#include "Empleado.hpp"
#include "Huesped.hpp"
#include "Usuario.hpp"
#include <map>
#include <iostream>
using namespace std;

class ControladorUsuario: public: IUsuario {
  private:
    ControladorUsuario() ;
    static ControladorUsuario *instancia ;
  
  public:
    ~ControladorUsuario() ;
    static ControladoUsuario *getInstancia();
    
    // alta de usuario 
    void ingresarEmpleado(DtEmpleado *dte);
    void ingresarHuesped(DtHuesped *dth);
    void confirmarAlta();
    void cancelarAlta();
    void reingresarEmail(string emailUser);  
      
    map<string, Empleado *> listarEmpleadosNoAsignados(string nombreHostal);
    void asignarEmpleado(string emailEmpleado, TipoCargo cargo);
    void cancelarAsignarEmpleado();
    map<string, Huesped *> listarHuespedes(int codigoHabitacion);
    void confirmarHuesped(string emailHuespedReserva);
    void agregarHuesped(string emailHuesped);
    map<string, Usuario *> listarUsuarios();
    DtEmpleado mostrarEmpleado(DtEmpleado empleado);  
    DtHuesped mostrarHuesped(DtHuesped huesped); 
    void encontrarHuesped(string emailHuespedReserva);
    
    map<string, Reserva *> listarReservas(string nombreHostal, string email);
        
  };





#endif
