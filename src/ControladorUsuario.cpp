#include "../include/ControladorUsuario.hpp"

using namespace std;

ControladorUsuario::ControladorUsuario() {
}

ControladorUsuario::~ControladorUsuario() 
{
	map<string , Empleado*>::iterator i = empleados.begin();
	while (i != empleados.end())
	{
		delete i->second;
		i++;
	}
	map<string , Huesped*>::iterator i = huespedes.begin();
	while (i != huespedes.end())
	{
		delete i->second;
		i++;
	}
}

ControladorUsuario *ControladorUsuario::_instancia = NULL;

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

// alta de usuario 
bool ControladorUsuario::existeEmpleado(string emailUser)
{
	return (empleados.find(emailUser)!= empleados.end()) ;
}

bool ControladorUsuario::existeHuesped(string emailUser)
{
	return (huespedes.find(emailUser)!= huespedes.end()) ;
}

void ControladorUsuario::confirmarAltaEmpleado(string nombre, string email, string password, TipoCargo cargo)
{     
	Empleado *e = new Empleado(nombre,email,password,cargo);
        this->empleados[email] = e;
	e->hostal=NULL;
}
void ControladorUsuario::confirmarAltaHuesped(string nombre, string email, string password, bool esFinger)
{     
	Huesped *h = new Huesped(nombre,email,password,esFinger);
        this->huespedes[email] = h;
}


// consulta de Usuario 

map<string, Usuario *> ControladorUsuario::listarUsuarios() 
{
	map<string, DtUsuario> res;
	map<string , Empleado*>::iterator i = empleados.begin();
	Empleado *e;
	while(i != empleados.end())
	{
		e = i->second;
		res.insert(make_pair(i->first, e.getDtUsuario()));
	
		i++;
	}
	map<string , Huesped*>::iterator i = huespedes.begin();
	Huesped *h;
	while(i != huespedes.end())
	{
		h = i->second;
		res.insert(make_pair(i->first, h.getDtUsuario()));
	
		i++;
	}
	
	return res;
}

DtEmpleado ControladorUsuario::mostrarEmpleado(string emailEmpleado)
{
    return empleados.find(emailEmpleado)->second->getDtEmpleado();
} 

DtHuesped ControladorUsuario::mostrarHuesped(string emailHuesped)
{
    return huespedes.find(emailHuesped)->second->getDtHuesped();
} 

    //map<string, Empleado *> ControladorUsuario::listarEmpleadosNoAsignados(string nombreHostal){}
    //void ControladorUsuario::asignarEmpleado(string emailEmpleado, TipoCargo cargo){} //el TipoCargo se pasó al crear el usuario.
    //void ControladorUsuario::cancelarAsignarEmpleado(){}
    //map<string, Huesped *> ControladorUsuario::listarHuespedes(int codigoHabitacion){}
    //void ControladorUsuario::confirmarHuesped(string emailHuespedReserva){}
    //void ControladorUsuario::agregarHuesped(string emailHuesped){}
    //DtEmpleado ControladorUsuario::mostrarEmpleado(DtEmpleado empleado){} 
    //DtHuesped ControladorUsuario::mostrarHuesped(DtHuesped huesped){}
    //void ControladorUsuario::encontrarHuesped(string emailHuespedReserva){}
    
    //map<string, Reserva *> ControladorUsuario::listarReservas(string nombreHostal, string email){}


