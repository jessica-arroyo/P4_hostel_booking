#include "../include/ControladorUsuario.hpp"


ControladorUsuario::ControladorUsuario() {
}

ControladorUsuario::~ControladorUsuario() 
{
	map<std::string , Empleado*>::iterator i = empleados.begin();
	while (i != empleados.end())
	{
		delete i->second;
		i++;
	}
	map<std::string , Huesped*>::iterator i = huespedes.begin();
	while (i != huespedes.end())
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
    else
    {
        Huesped *h = new Huesped(nombre,email,password,esFinger);
        this->huespedes[email] = h;
    }
}



// consulta de Usuario EN PROCESO

map<string, Usuario *> ControladorUsuario::listarUsuarios() 
{
	std::map<string, DtUsuario> res;
	std::map<string , Empleado*>::iterator i = empleados.begin();
	Empleado *e;
	while(i != empleados.end())
	{
		e = i->second;
		res.insert(make_pair(i->first, DtUsuario(e->getNombre() , e->getEmail() , e->getPassword())));
	}
		i++;
	}
	std::map<string , Huesped*>::iterator i = huespedes.begin();
	Huesped *h;
	while(i != huespedes.end())
	{
		h = i->second;
		res.insert(make_pair(i->first, DtUsuario(h->getNombre() , h->getEmail() , h->getPassword())));
	}
		i++;
	}
	return res;
}


    map<string, Empleado *> ControladorUsuario::listarEmpleadosNoAsignados(string nombreHostal){}
    void ControladorUsuario::asignarEmpleado(string emailEmpleado, TipoCargo cargo){}
    void ControladorUsuario::cancelarAsignarEmpleado(){}
    map<string, Huesped *> ControladorUsuario::listarHuespedes(int codigoHabitacion){}
    void ControladorUsuario::confirmarHuesped(string emailHuespedReserva){}
    void ControladorUsuario::agregarHuesped(string emailHuesped){}
    DtEmpleado ControladorUsuario::mostrarEmpleado(DtEmpleado empleado){} 
    DtHuesped ControladorUsuario::mostrarHuesped(DtHuesped huesped){}
    void ControladorUsuario::encontrarHuesped(string emailHuespedReserva){}
    
    map<string, Reserva *> ControladorUsuario::listarReservas(string nombreHostal, string email){}


