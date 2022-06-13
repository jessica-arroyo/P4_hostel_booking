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
map<string, Usuario *> ControladorUsuario::listarUsuarios(){

}

map<string, Usuario *> ControladorUsuario::listarUsuarios() 
{
	std::map<std::string , Empleado*>::iterator i = empleados.begin();
	Empleado *e;
	while(i != usuarios.end())
	{
		u = i->second;
		if (dynamic_cast <Estudiante*> (u))
		{
			e = dynamic_cast <Estudiante*> (u);
			res.insert();
		}
		i++;
	}
	return res;
}

map<string, DtAsignatura> ControladorAsignatura::listarAsignaturas()
{
	map<string, DtAsignatura> res;
	DtAsignatura aux;
	map<string, Asignatura*>::iterator i;
	for(i = this->asignaturas.begin(); i != this->asignaturas.end(); i++)
	{
		aux = DtAsignatura(i->second->getCodigo(), i->second->getNombre(), i->second->getSumaTiempoDictado());
		res.insert(make_pair(i->second->getCodigo(),aux));
	}
	if ( res.empty())
		throw logic_error("no existen asignaturas") ;
	return res;
}

std::map<std::string, DtEstudiante> ControladorUsuario::listarEstudiantes() 
{
	std::map<std::string, DtEstudiante> res;
	std::map<std::string , Usuario*>::iterator i = usuarios.begin();
	Usuario *u;
	Estudiante *e;
	while(i != usuarios.end())
	{
		u = i->second;
		if (dynamic_cast <Estudiante*> (u))
		{
			e = dynamic_cast <Estudiante*> (u);
			res.insert(std::make_pair(i->first, e->getDataEst()));
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


