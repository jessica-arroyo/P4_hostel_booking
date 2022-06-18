#include "../include/ControladorUsuario.hpp"

using namespace std;



ControladorUsuario::~ControladorUsuario() 
{
	/*map<string , Empleado*>::iterator i = empleados.begin();
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
	}*/
}

ControladorUsuario *ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {
}

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == NULL){
        instancia = new ControladorUsuario();
	}
    return instancia;
}


map<string , Empleado*>	ControladorUsuario::getEmpleados(){
	return empleados;
}
map<string , Huesped*> ControladorUsuario::getHuespedes(){
	return huespedes;
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
	e->setHostal(NULL);
}
void ControladorUsuario::confirmarAltaHuesped(string nombre, string email, string password, bool esFinger)
{     
	Huesped *h = new Huesped(nombre,email,password,esFinger);
        this->huespedes[email] = h;
}


// consulta de Usuario 

map<string, DtEmpleado> ControladorUsuario::listarEmpleados() 
{
	map<string, DtEmpleado> res;
	map<string , Empleado*>::iterator i = empleados.begin();
	Empleado *e;
	while(i != empleados.end())
	{
		e = i->second;
		res.insert(make_pair(i->first, e->getDtEmpleado()));
	
		i++;
	}
	return res;
}
map<string, DtHuesped> ControladorUsuario::listarHuespedes() 
{
	map<string, DtHuesped> res;
	map<string , Huesped*>::iterator m = huespedes.begin();
	Huesped *h;
	while(m != huespedes.end())
	{
		h = m->second;
		res.insert(make_pair(m->first, h->getDtHuesped()));
	
		m++;
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
//map<string, DtHuesped> ControladorUsuario::listarHuespedes(){}
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


