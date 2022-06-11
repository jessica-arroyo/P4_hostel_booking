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
    bool ControladorUsuario::ingresarEmpleado(DtEmpleado *dte){
    Estudiante* res = NULL;
	std::map<std::string, Usuario*>::iterator e = empleados.find(emailEst);
	if (e != usuarios.end()) 
		res = dynamic_cast<Estudiante*>(u->second);
	return (res != NULL);
    }
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

bool ControladorUsuario::existeEst(std::string emailEst)
{
	Estudiante* res = NULL;
	std::map<std::string, Usuario*>::iterator u = usuarios.find(emailEst);
	if (u != usuarios.end()) 
		res = dynamic_cast<Estudiante*>(u->second);
	return (res != NULL);
}

