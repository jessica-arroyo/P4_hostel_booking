#include "../include/ControladorUsuario.hpp"


ControladorUsuario::ControladorUsuario() {}

ControladorUsuario::~ControladorUsuario() 
{
	map<std::string , Usuario*>::iterator i = usuarios.begin();
	while (i != usuarios.end())
	{
		delete i->second;
		i++;
	}
}

ControladorUsuario *ControladorUsuario::instancia = NULL;

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

// alta de usuario 
    void ControladorUsuario::ingresarEmpleado(DtEmpleado *dte){}
    void ControladorUsuario::ingresarHuesped(DtHuesped *dth){}
    void ControladorUsuario::confirmarAlta(){}
    void ControladorUsuario::cancelarAlta(){}
    void ControladorUsuario::reingresarEmail(string emailUser){}
      
    map<string, Empleado *> ControladorUsuario::listarEmpleadosNoAsignados(string nombreHostal){}
    void ControladorUsuario::asignarEmpleado(string emailEmpleado, TipoCargo cargo){}
    void ControladorUsuario::cancelarAsignarEmpleado(){}
    map<string, Huesped *> ControladorUsuario::listarHuespedes(int codigoHabitacion){}
    void ControladorUsuario::confirmarHuesped(string emailHuespedReserva){}
    void ControladorUsuario::agregarHuesped(string emailHuesped){}
    map<string, Usuario *> ControladorUsuario::listarUsuarios(){}
    DtEmpleado ControladorUsuario::mostrarEmpleado(DtEmpleado empleado){} 
    DtHuesped ControladorUsuario::mostrarHuesped(DtHuesped huesped){}
    void ControladorUsuario::encontrarHuesped(string emailHuespedReserva){}
    
    map<string, Reserva *> ControladorUsuario::listarReservas(string nombreHostal, string email){}



