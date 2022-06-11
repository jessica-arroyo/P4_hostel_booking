#include "../include/ControladorUsuario.hpp"


ControladorUsuario::ControladorUsuario() {
    this->dte = NULL;
    this->dth = NULL;
}

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

bool ControladorUsuario::reingresarEmail(string emailUser)
{
	if (this->dth == NULL){
		this->dte->setEmail(emailUser);
	}else{
		this->dth->setEmail(emailUser);
	}
	Usuario* res = NULL;
	std::map<std::string, Usuario*>::iterator u = usuarios.find(emailUser);
	if (u != usuarios.end()) 
		res = dynamic_cast<Usuario*>(u->second);
	return (res != NULL);
}
      
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


