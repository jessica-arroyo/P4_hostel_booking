#include "../include/ControladorUsuario.hpp"


ControladorUsuario::ControladorUsuario() {
    this->dte = NULL;
    this->dth = NULL;
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
    bool ControladorUsuario::ingresarEmpleado(DtEmpleado *dte){
  	Empleado* res = NULL;
	this->dte = dte;
	std::map<std::string, Empleado*>::iterator e = empleados.find(dte->getEmail());
	if (e != empleados.end()) 
		res = dynamic_cast<Empleado*>(e->second);
	return (res != NULL);
    }
    bool ControladorUsuario::ingresarHuesped(DtHuesped *dth){
        Huesped* res = NULL;
	this->dth = dth;
	std::map<std::string, Huesped*>::iterator h = huespedes.find(dth->getEmail());
	if (h != huespedes.end()) 
		res = dynamic_cast<Huesped*>(h->second);
	return (res != NULL);
    }

bool ControladorUsuario::reingresarEmail(string emailUser)
{
	if (this->dth == NULL){
		this->dte->setEmail(emailUser);
		Empleado* res = NULL;
		std::map<std::string, Empleado*>::iterator e = empleados.find(emailUser);
		if (e != empleados.end()) 
			res = dynamic_cast<Empleado*>(e->second);
		return (res != NULL);
	}else{
		this->dth->setEmail(emailUser);
		Huesped* res = NULL;
		std::map<std::string, Huesped*>::iterator h = huespedes.find(emailUser);
		if (h != huespedes.end()) 
			res = dynamic_cast<Huesped*>(h->second);
		return (res != NULL);
	}
	
}

void ControladorUsuario::confirmarAlta()
{
    if (this->dth == NULL)
    {
        //caso ingreso Empleado
        Empleado *e = new Empleado(
            this->dte->getNombre(),
            this->dte->getEmail(),
            this->dte->getPassword(),
	    this->dte->getCargo());
        this->usuarios[this->dte->getEmail()] = e;
    }
    else
    {
        Huesped *h = new Huesped(
            this->dth->getNombre(),
            this->dth->getEmail(),
            this->dth->getPassword(),
            this->dth->getEsFinger());
        this->usuarios[this->dth->getEmail()] = h;
    }
    this->dte = NULL;
    this->dth = NULL;
}

void ControladorUsuario::cancelarAlta()
{
    this->dte = NULL;
    this->dth = NULL;
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


