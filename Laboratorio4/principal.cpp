//error grande ControladorHostal.cpp: 133

#include "include/Fabrica.hpp"
#include <iostream>
#include <istream>
#include <limits>
#include <ios>
#include <map>
#include <set>

using namespace std;

void cargarDatosPrueba(IHostal *iHostal, IUsuario *iUsuario, IReserva *iReserva,IFecha *iFecha)
{
	//Empleados
    string emailEmpleado[4] = {"emilia@mail.com", "leo@mail.com", "alina@mail.com","barli@mail.com"};
    string nombreEmpleado[4] = {"Emilia", "Leonardo", "Alina", "Barliman"};
    TipoCargo cargo[4] = {RECEPCION, RECEPCION, ADMINISTRACION, RECEPCION};
    for (int i = 0; i < 4; i++)
    {
        iUsuario->confirmarAltaEmpleado (nombreEmpleado[i],emailEmpleado[i], "123", cargo[i]);
    }
          	
          	
    //Huespedes
    string emailHuespedes[6] = {"sofia@mail.com", "frodo@mail.com", "sam@mail.com","merry@mail.com","pippin@mail.com","seba@mail.com"};
    string nombreHuespedes[6] = {"Sofia","Frodo", "Sam", "Merry", "Pippin", "Seba"};
    bool esFinger[6] = {true, true, false,false,false,true};
    for (int i = 0; i < 6; i++)
    {
        iUsuario->confirmarAltaHuesped(nombreHuespedes[i],emailHuespedes[i], "123", esFinger[i]);
    }
          	
          
          	
    //Hostels
    string nombresHostales[5] = {"La posada del finger", "Mochileros", "El Pony Pisador","Altos de Fing","Caverna Lujosa"};
    string direccionesHostales[5] = {"Av de la playa 123, Maldonado", "Rambla Costanera 333, Rocha", "Bree (preguntar por Gandalf)","Av del   Toro 1424","Amaya 2515"};
    string telefonosHostales[5]={"099111111", "42579512", "000", "099892992", "233233235"};
          	
    for (int i = 0; i < 5; i++)
    {
        iHostal->altaHostal(nombresHostales[i],direccionesHostales[i],telefonosHostales[i],0) ;
    }
          	
    //Habitaciones
    int numerosHabitaciones[6] = {1, 2, 3, 4, 1,1};
    int preciosHabitaciones[6] = {40, 10, 30, 5, 3,9};
    int capacidadHabitaciones[6] = {2, 7, 3, 12, 2,5};
    string nombresHostalesH[6]= {"La posada del finger", "La posada del finger", "La posada del finger","La posada del finger","Caverna Lujosa","El Pony Pisador"};
    for (int i = 0; i < 6; i++)
    {
        iHostal->agregarHabitacion(numerosHabitaciones[i],preciosHabitaciones[i],capacidadHabitaciones[i],nombresHostalesH[i]) ;
    }
	
	//Asignar Empleados a Hostales
	string emailEmpleadoHostal[4] = {"emilia@mail.com", "leo@mail.com", "alina@mail.com","barli@mail.com"};
	TipoCargo cargoHostal[4] = {RECEPCION, RECEPCION, ADMINISTRACION, RECEPCION};
	string hostel[4] = {"La posada del finger", "Mochileros", "Mochileros", "El Pony Pisador"};
	for (int i = 0; i < 4; i++)
	{
		Hostal *hostal = iHostal->encontrarHostal(hostel[i]);
        iUsuario->asignarEmpleado(emailEmpleadoHostal[i], cargoHostal[i], hostal);
	}
	
	//Reservas 
	string nomhos[3] = {"La posada del finger", "La posada del finger", "Caverna Lujosa"};
	int numhab[3] = {1, 3, 1} ;
	int checkIn[3][4] = {{14,1,5,2022}, {14,7,6,2022}, {14,10,6,2022}};
	int checkOut[3][4] = {{10,10,5,2022}, {11,30,6,2022}, {11,30,6,2022}};
	string emailHuespedesReserva[3] = {"sofia@mail.com", "sofia@mail.com", "seba@mail.com"};
	for (int i = 0; i < 3; i++)
	{
		DtFechaHora fechaCheckIn = DtFechaHora(checkIn[i][0], checkIn[i][1], checkIn[i][2], checkIn[i][3]);
		DtFechaHora fechaCheckOut = DtFechaHora(checkOut[i][0], checkOut[i][1], checkOut[i][2], checkOut[i][3]);
		iReserva->confirmarReservaIndividual(nomhos[i], numhab[i], fechaCheckIn, fechaCheckOut, emailHuespedesReserva[i]);
	}
	DtFechaHora fig = DtFechaHora ( 20,4,1,2001 ) ;
	DtFechaHora fog = DtFechaHora ( 2,5,1,2001 ) ;
	string emailHuespedesGrup[3] = {"sam@mail.com", "merry@mail.com", "pippin@mail.com"};
	set<string> grupoHues;
	for (int i = 0; i < 3; i++)
	{
		grupoHues.insert(emailHuespedesGrup[i]);
	}
	iReserva->confirmarReservaGrupal("El Pony Pisador", 1, fig, fog, "frodo@mail.com", grupoHues, 4);
	
	//Estadias 

	string nomhosEst[6] = {"La posada del finger", "El Pony Pisador", "El Pony Pisador", "El Pony Pisador", "El Pony Pisador", "Caverna Lujosa"};
	string emailHuespedesEst[6] = {"sofia@mail.com", "frodo@mail.com", "sam@mail.com","merry@mail.com","pippin@mail.com","seba@mail.com"};
	int checkInEst[6][4] = {{14,01,05,2022}, {20,04,01,2001}, {20,04,01,2001}, {20,04,01,2001}, {20,04,01,2001}, {14,10,06,2022}};
	int checkOutEst[6][4] = {{10,10,05,2022}, {2,05,01,2001}, {2,05,01,2001}, {2,05,01,2001}, {2,05,01,2001}, {11,30,06,2022}};
  int codres[6]={1000,1003,1003,1003,1003,1002};

	for (int i = 0; i < 6; i++)
	{
		DtFechaHora fechaCheckIn = DtFechaHora(checkInEst[i][0], checkInEst[i][1], checkInEst[i][2], checkInEst[i][3]);
		DtFechaHora fechaCheckOut = DtFechaHora(checkOutEst[i][0], checkOutEst[i][1], checkOutEst[i][2], checkOutEst[i][3]);

		//int codres = iReserva->encontrarCodigoReservadelHuesped(emailHuespedesEst[i],nomhosEst[i],fechaCheckIn, fechaCheckOut)
		iReserva->inscribirEstadia(codres[i], emailHuespedesEst[i]);
	}
	
	/* //Finalizacion de Estadias

	string emailHuespedesFin[3] = {"sofia@mail.com", "frodo@mail.com", "seba@mail.com"};
	for (int i = 0; i < 3; i++)
	{
		iReserva->finalizarEstadia(emailHuespedesFin[i]);
	}
	
	*/
	

}

int main()
{
	
	Fabrica *f = NULL;
	f = Fabrica::getInstancia();
	IHostal *iHostal = f->getIHostal();
	IUsuario *iUsuario = f->getIUsuario();
	IReserva *iReserva = f->getIReserva();

	IFecha *iFecha = f->getIFecha();
	DtFechaHora horaActual = DtFechaHora(0, 1, 1, 2022);
	iFecha->setFechaHora(horaActual);

	bool bandera = false;
	while (!bandera)
	{
		//bool retroceder = false;
		int  numingresado;
		cout << "\nBienvenido. Elija la opción.\n\n";
        cout << "1. Alta de Usuario\n";
        cout << "2. Alta de Hostal\n";
        cout << "3. Alta de Habitacion\n";
		cout << "4. Asignar Empleado a Hostal\n";
		cout << "5. Realizar Reserva\n";
		cout << "6. Consultar Top 3 Hostales\n";
		cout << "7. Registrar Estadía\n";
		cout << "8. Finalizar Estadía\n";
		cout << "9. Calificar Estadía\n";
		cout << "10. Comentar Calificación\n";
		cout << "11. Consulta de Usuario\n";
		cout << "12. Consulta de Hostal\n";
		cout << "13. Consulta de Reserva\n";
		cout << "14. Consulta de Estadía\n";
		cout << "15. Baja de Reserva\n";
		cout << "16. Suscribirse a Notificaciones\n";
		cout << "17. Consulta de Notificaciones\n";
		cout << "18. Eliminar suscripción\n";
		cout << "19. Modificar fecha y hora\n";
		cout << "20. Cargar datos de prueba\n";
        cout << "0. Salir\n\n";
        cout << "Opción:";

		while (bandera == false){
					cin >> numingresado;
					if(!cin.good())
					{
					  cout << "ERROR\n";
					  cin.clear();
					  cin.ignore(1000,'\n');
					  cout << "Ingrese un número válido\n";
					}else bandera = true;
                }
		bandera = false;
		
        switch (numingresado)
        {
            case 1: //Alta de Usuario
			{
				int tipoUsuario ;
				cout<< "\nIngrese '0' si desea dar de alta a un empleado, '1' en caso de querer dar de alta un huesped\n" ;
				cin>> tipoUsuario ;
					if(!cin.good())
					{
					  cout << "ERROR\n";
					  cin.clear();
					  cin.ignore(1000,'\n');
					  tipoUsuario = 2;
					}
				while (tipoUsuario != 0 && tipoUsuario != 1){
                    cout << "Ingrese '0' o '1'\n";
                    cin >> tipoUsuario;
					if(!cin.good())
					{
					  cout << "ERROR\n";
					  cin.clear();
					  cin.ignore(1000,'\n');
					  tipoUsuario = 2;
					}
                }
				if(tipoUsuario == 0){//Empleado
					bool esta ;
					string nombre ;
					string email ;
					string password ;
					int cargo ; 
					cout<< "\n" ;
					cout<< "Ingrese el nombre\n" ;
					cin>> nombre ;
					cout<< "Ingrese el email\n" ;
					cin>> email ;
					cout<< "Ingrese el password\n" ;
					cin>> password ;
					cout<< "Ingrese el tipo de cargo: '0': Administración, '1': Limpieza, '2': Recepción, '3': Infraestructura\n" ;
					cin>> cargo ;
						if(!cin.good())
						{
					  		cout << "ERROR\n";
					  		cin.clear();
					  		cin.ignore(1000,'\n');
					  		cargo = 4;
						}
						while ( cargo!= 0 && cargo != 1 && cargo != 2 && cargo != 3){
                    		cout << "Ingrese: '0' Administración, '1' Limpieza, '2' Recepción, '3' Infraestructura\n";
                    		cin >> cargo;
							if(!cin.good())
							{
					  			cout << "ERROR\n";
					  			cin.clear();
					  			cin.ignore(1000,'\n');
					  			cargo = 4;
							}
                		}
						if(cargo==0) //Administración
						{
							cout<< "\n" ;
							esta = iUsuario->existeEmpleado(email) ; //devuelve true si está registrado el email.
							if(esta) //Si el email ya está registrado.
							{
								int i ;
								cout << "\nEmail ya registrado\n";
								cout << "Si desea reingresar el email, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> i ;
									if(!cin.good())
									{
					  				cout << "ERROR\n";
					  				cin.clear();
					  				cin.ignore(1000,'\n');
					  				i = 2;
									}
								while (i != 0 && i != 1){
                    				cout << "Ingrese '0' o '1'\n";
                    				cin >> i;
									if(!cin.good())
									{
					  					cout << "ERROR\n";
					  					cin.clear();
					  					cin.ignore(1000,'\n');
					  					i = 2;
									}
                				}
								if(i==1) //Si desea reingresar el email.
								{
						
									cout << "\nEmail ya registrado\n";
									cout << "Ingrese un email que no esté registrado:\n";
									cin >> email;
									esta = iUsuario->existeEmpleado(email) ;

									while(i==1 && esta) //Mientras quiera reingresar y el email ya esté registrado.
									{
										cout << "\nEmail ya registrado\n";
										cout << "Si desea reingresar el email, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> i ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            			}
                        				while (i != 0 && i != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> i;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            				}
                        				}		
										if(i==1) //Si desea seguir reingresando.
										{
											cout << "Ingrese un email que no esté registrado:\n";
											cin >> email;
											esta = iUsuario->existeEmpleado(email) ;
										}
										//Sino va a la próxima iteración del while (el while de i==1 && esta) y sale.
										
									} 
									//Salió del while de reingresar, ya sea porque quedó bien ingresado o porque quiso cancelar.
									if(!esta) //Si quedó bien ingresado.
									{
										int j ; 
										cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            			}
                        				while (j != 0 && j != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> j;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            				}
                        				}

										if(j==1)
										{
											iUsuario->confirmarAltaEmpleado(nombre,email,password,ADMINISTRACION) ;
											cout<< "Se ingresó el empleado" ;
											cout<< "\n" ;
										}
										else
										{
											cout<<"Se canceló el alta" ;
											cout<< "\n" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
										cout<< "\n" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							
							}
							else 
							{ //Si no estaba ingresado el email la primera vez que se leyó el email.
								int j ; 
								cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> j ;
								if(!cin.good())
                            	{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            	}
                        		while (j != 0 && j != 1){
                            		cout << "Ingrese '0' o '1'\n";
                            		cin >> j;
                            		if(!cin.good())
                            		{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            		}
                        		}
								if(j==1) 
								{
									iUsuario->confirmarAltaEmpleado(nombre,email,password, ADMINISTRACION) ;
									cout<<"Se ingresó el empleado" ;
									cout<< "\n" ;
								}
								else
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							}

						}
						else if(cargo==1) { //Limpieza
							esta = iUsuario->existeEmpleado(email) ; //devuelve true si está registrado el email.
							if(esta) //Si el email ya está registrado.
							{
								int i ;
								cout << "\nEmail ya registrado\n";
								cout << "Si desea reingresar el email, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> i ;
									if(!cin.good())
									{
					  				cout << "ERROR\n";
					  				cin.clear();
					  				cin.ignore(1000,'\n');
					  				i = 2;
									}
								while (i != 0 && i != 1){
                    				cout << "Ingrese '0' o '1'\n";
                    				cin >> i;
									if(!cin.good())
									{
					  					cout << "ERROR\n";
					  					cin.clear();
					  					cin.ignore(1000,'\n');
					  					i = 2;
									}
                				}
								if(i==1) //Si desea reingresar el email.
								{
						
									cout << "\nEmail ya registrado\n";
									cout << "Ingrese un email que no esté registrado:\n";
									cin >> email;
									esta = iUsuario->existeEmpleado(email) ;

									while(i==1 && esta) //Mientras quiera reingresar y el email ya esté registrado.
									{
										cout << "\nEmail ya registrado\n";
										cout << "Si desea reingresar el email, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> i ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            			}
                        				while (i != 0 && i != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> i;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            				}
                        				}		
										if(i==1) //Si desea seguir reingresando.
										{
											cout << "Ingrese un email que no esté registrado:\n";
											cin >> email;
											esta = iUsuario->existeEmpleado(email) ;
										}
										//Sino va a la próxima iteración del while (el while de i==1 && esta) y sale.
										
									} 
									//Salió del while de reingresar, ya sea porque quedó bien ingresado o porque quiso cancelar.
									if(!esta) //Si quedó bien ingresado.
									{
										int j ; 
										cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            			}
                        				while (j != 0 && j != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> j;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            				}
                        				}

										if(j==1)
										{
											iUsuario->confirmarAltaEmpleado(nombre,email,password,LIMPIEZA) ;
											cout<<"Se ingresó el empleado" ;
											cout<< "\n" ;
										}
										else
										{
											cout<<"Se canceló el alta" ;
											cout<< "\n" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
										cout<< "\n" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							
							}
							else 
							{ //Si no estaba ingresado el email la primera vez que se leyó el email.
								int j ; 
								cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> j ;
								if(!cin.good())
                            	{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            	}
                        		while (j != 0 && j != 1){
                            		cout << "Ingrese '0' o '1'\n";
                            		cin >> j;
                            		if(!cin.good())
                            		{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            		}
                        		}
								if(j==1) 
								{
									iUsuario->confirmarAltaEmpleado(nombre,email,password, LIMPIEZA) ;
									cout<<"Se ingresó el empleado" ;
									cout<< "\n" ;
								}
								else
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							}

						}
						
						else if(cargo==2) {//Recepción
							esta = iUsuario->existeEmpleado(email) ; //devuelve true si está registrado el email.
							if(esta) //Si el email ya está registrado.
							{
								int i ;
								cout << "\nEmail ya registrado\n";
								cout << "Si desea reingresar el email, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> i ;
									if(!cin.good())
									{
					  				cout << "ERROR\n";
					  				cin.clear();
					  				cin.ignore(1000,'\n');
					  				i = 2;
									}
								while (i != 0 && i != 1){
                    				cout << "Ingrese '0' o '1'\n";
                    				cin >> i;
									if(!cin.good())
									{
					  					cout << "ERROR\n";
					  					cin.clear();
					  					cin.ignore(1000,'\n');
					  					i = 2;
									}
                				}
								if(i==1) //Si desea reingresar el email.
								{
						
									cout << "\nEmail ya registrado\n";
									cout << "Ingrese un email que no esté registrado:\n";
									cin >> email;
									esta = iUsuario->existeEmpleado(email) ;

									while(i==1 && esta) //Mientras quiera reingresar y el email ya esté registrado.
									{
										cout << "\nEmail ya registrado\n";
										cout << "Si desea reingresar el email, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> i ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            			}
                        				while (i != 0 && i != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> i;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            				}
                        				}		
										if(i==1) //Si desea seguir reingresando.
										{
											cout << "Ingrese un email que no esté registrado:\n";
											cin >> email;
											esta = iUsuario->existeEmpleado(email) ;
										}
										//Sino va a la próxima iteración del while (el while de i==1 && esta) y sale.
										
									} 
									//Salió del while de reingresar, ya sea porque quedó bien ingresado o porque quiso cancelar.
									if(!esta) //Si quedó bien ingresado.
									{
										int j ; 
										cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            			}
                        				while (j != 0 && j != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> j;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            				}
                        				}

										if(j==1)
										{
											iUsuario->confirmarAltaEmpleado(nombre,email,password,RECEPCION) ;
											cout<<"Se ingresó el empleado" ;
											cout<< "\n" ;
										}
										else
										{
											cout<<"Se canceló el alta" ;
											cout<< "\n" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
										cout<< "\n" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							
							}
							else 
							{ //Si no estaba ingresado el email la primera vez que se leyó el email.
								int j ; 
								cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> j ;
								if(!cin.good())
                            	{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            	}
                        		while (j != 0 && j != 1){
                            		cout << "Ingrese '0' o '1'\n";
                            		cin >> j;
                            		if(!cin.good())
                            		{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            		}
                        		}
								if(j==1) 
								{
									iUsuario->confirmarAltaEmpleado(nombre,email,password, RECEPCION) ;
									cout<<"Se ingresó el empleado" ;
									cout<< "\n" ;
								}
								else
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							}
							
						}
						else if(cargo==3) {//Infraestructura
							esta = iUsuario->existeEmpleado(email) ; //devuelve true si está registrado el email.
							if(esta) //Si el email ya está registrado.
							{
								int i ;
								cout << "\nEmail ya registrado\n";
								cout << "Si desea reingresar el email, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> i ;
									if(!cin.good())
									{
					  				cout << "ERROR\n";
					  				cin.clear();
					  				cin.ignore(1000,'\n');
					  				i = 2;
									}
								while (i != 0 && i != 1){
                    				cout << "Ingrese '0' o '1'\n";
                    				cin >> i;
									if(!cin.good())
									{
					  					cout << "ERROR\n";
					  					cin.clear();
					  					cin.ignore(1000,'\n');
					  					i = 2;
									}
                				}
								if(i==1) //Si desea reingresar el email.
								{
						
									cout << "\nEmail ya registrado\n";
									cout << "Ingrese un email que no esté registrado:\n";
									cin >> email;
									esta = iUsuario->existeEmpleado(email) ;

									while(i==1 && esta) //Mientras quiera reingresar y el email ya esté registrado.
									{
										cout << "\nEmail ya registrado\n";
										cout << "Si desea reingresar el email, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> i ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            			}
                        				while (i != 0 && i != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> i;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            				}
                        				}		
										if(i==1) //Si desea seguir reingresando.
										{
											cout << "Ingrese un email que no esté registrado:\n";
											cin >> email;
											esta = iUsuario->existeEmpleado(email) ;
										}
										//Sino va a la próxima iteración del while (el while de i==1 && esta) y sale.
										
									} 
									//Salió del while de reingresar, ya sea porque quedó bien ingresado o porque quiso cancelar.
									if(!esta) //Si quedó bien ingresado.
									{
										int j ; 
										cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            			}
                        				while (j != 0 && j != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> j;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            				}
                        				}

										if(j==1)
										{
											iUsuario->confirmarAltaEmpleado(nombre,email,password,INFRAESTRUCTURA) ;
											cout<<"Se ingresó el empleado" ;
											cout<< "\n" ;
										}
										else
										{
											cout<<"Se canceló el alta" ;
											cout<< "\n" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
										cout<< "\n" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							
							}
							else 
							{ //Si no estaba ingresado el email la primera vez que se leyó el email.
								int j ; 
								cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> j ;
								if(!cin.good())
                            	{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            	}
                        		while (j != 0 && j != 1){
                            		cout << "Ingrese '0' o '1'\n";
                            		cin >> j;
                            		if(!cin.good())
                            		{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            		}
                        		}
								if(j==1) 
								{
									iUsuario->confirmarAltaEmpleado(nombre,email,password, INFRAESTRUCTURA) ;
									cout<<"Se ingresó el empleado" ;
									cout<< "\n" ;
								}
								else
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							}

						} 	

				} else if (tipoUsuario == 1){//Huesped
					bool esta ;
					string nombre ;
					string email ;
					string password ;
					int finger ; 
					bool esFinger ;
					cout<< "\n" ;
					cout<< "Ingrese el nombre\n" ;
					cin>> nombre ;
					cout<< "Ingrese el email\n" ;
					cin>> email ;
					cout<< "Ingrese el password\n" ;
					cin>> password ;
					cout<< "Ingrese '0' si esFinger, '1' si no lo es\n" ;
					cin>> finger ;
						if(!cin.good())
						{
					  		cout << "ERROR\n";
					  		cin.clear();
					  		cin.ignore(1000,'\n');
					  		finger = 2;
						}
						while (finger != 0 && finger != 1){
                    		cout << "Ingrese '0' o '1'\n";
                    		cin >> finger;
							if(!cin.good())
							{
					  			cout << "ERROR\n";
					  			cin.clear();
					  			cin.ignore(1000,'\n');
					  			finger = 2;
							}
                		}
					if(finger == 0){
						esFinger = true;
					} else { //ya chequeaste que solo se ingresó 0 o 1, por lo que si no es 0 es 1 el valor ingresado.
						esFinger = false;
					}
					//ponemos lo de try y catch?
					cout<< "\n" ;
					esta = iUsuario->existeHuesped(email) ; //devuelve true si está registrado el email.
							if(esta) //Si el email ya está registrado.
							{
								int i ;
								cout << "\nEmail ya registrado\n";
								cout << "Si desea reingresar el email, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> i ;
									if(!cin.good())
									{
					  				cout << "ERROR\n";
					  				cin.clear();
					  				cin.ignore(1000,'\n');
					  				i = 2;
									}
								while (i != 0 && i != 1){
                    				cout << "Ingrese '0' o '1'\n";
                    				cin >> i;
									if(!cin.good())
									{
					  					cout << "ERROR\n";
					  					cin.clear();
					  					cin.ignore(1000,'\n');
					  					i = 2;
									}
                				}
								if(i==1) //Si desea reingresar el email.
								{
						
									cout << "\nEmail ya registrado\n";
									cout << "Ingrese un email que no esté registrado:\n";
									cin >> email;
									esta = iUsuario->existeHuesped(email) ;

									while(i==1 && esta) //Mientras quiera reingresar y el email ya esté registrado.
									{
										cout << "\nEmail ya registrado\n";
										cout << "Si desea reingresar el email, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> i ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            			}
                        				while (i != 0 && i != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> i;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				i = 2;
                            				}
                        				}		
										if(i==1) //Si desea seguir reingresando.
										{
											cout << "Ingrese un email que no esté registrado:\n";
											cin >> email;
											esta = iUsuario->existeHuesped(email) ;
										}
										//Sino va a la próxima iteración del while (el while de i==1 && esta) y sale.
										
									} 
									//Salió del while de reingresar, ya sea porque quedó bien ingresado o porque quiso cancelar.
									if(!esta) //Si quedó bien ingresado.
									{
										int j ; 
										cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
                            			{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            			}
                        				while (j != 0 && j != 1){
                            				cout << "Ingrese '0' o '1'\n";
                            				cin >> j;
                            				if(!cin.good())
                            				{
                            				cout << "ERROR\n";
                            				cin.clear();
                            				cin.ignore(1000,'\n');
                            				j = 2;
                            				}
                        				}

										if(j==1)
										{
											iUsuario->confirmarAltaHuesped(nombre,email,password,esFinger);
											cout<<"Se ingresó el huesped" ;
											cout<< "\n" ;
										}
										else
										{
											cout<<"Se canceló el alta" ;
											cout<< "\n" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
										cout<< "\n" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							
							}
							else 
							{ //Si no estaba ingresado el email la primera vez que se leyó el email.
								int j ; 
								cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
								cin>> j ;
								if(!cin.good())
                            	{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            	}
                        		while (j != 0 && j != 1){
                            		cout << "Ingrese '0' o '1'\n";
                            		cin >> j;
                            		if(!cin.good())
                            		{
                            		cout << "ERROR\n";
                            		cin.clear();
                            		cin.ignore(1000,'\n');
                            		j = 2;
                            		}
                        		}
								if(j==1) 
								{
									iUsuario->confirmarAltaHuesped(nombre,email,password, esFinger) ;
									cout<<"Se ingresó el huesped" ;
									cout<< "\n" ;
								}
								else
								{
									cout<<"Se canceló el alta" ;
									cout<< "\n" ;
								}
							}
					
						}

				}
				break ; 
				case 2: //Alta de Hostal
				{
					string nombreHostal ;
					string direccion ;
					string telefono ; 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
					cout<< "Ingrese el nombre del hostal\n" ;
					getline(cin,nombreHostal) ;
					while(iHostal->existeHostal(nombreHostal) == true){
						cout<< "Hostal ya registrado\n" ;
						cout<< "Ingrese nuevamente el nombre\n" ;
						getline(cin,nombreHostal) ;
					}
					cout<< "Ingrese la dirección\n" ;
					getline(cin,direccion) ;
					cout<< "Ingrese el teléfono\n" ;
					cin>> telefono;
					iHostal->altaHostal(nombreHostal,direccion,telefono,0) ; //se crea el Hostal con calificacionPromedio=0.
					cout<<"Se ingresó el hostal" ;
					cout<< "\n" ;
					
				}
				break ;  

				case 3: //Alta de Habitación
				{
					map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "\n" ;
						cout<< "No hay hostales registrados \n" ;
						cout<< "\n" ;
					}
					else 
					{
    					int j = 1;
						cout<< "\n" ;
    					cout<< "\nLista de Hostales\n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<"Nombre: " << i->second.getNombre() << "\n";
        					j++;
    					}
						
						cout<< "\n" ;
						int numero ;
						int precio ;
						int capacidad ;
						string nombreH ; 
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
           
						cout<< "Ingrese el nombre del hostal al que pertenece la habitación\n" ;
						getline(cin,nombreH) ;
						while(iHostal->existeHostal(nombreH) == false){
							cout<< "\n" ;
							cout<< "Hostal no registrado\n" ;
							cout<< "Ingrese nuevamente el nombre\n" ;
							getline(cin,nombreH) ;
						}
						cout<< "\n" ;
						cout<< "Ingrese el numero\n" ;
						cin>> numero ;
						while(iHostal->existeHabitacion(numero, nombreH) == true){
							cout<< "\n" ;
							cout<< "Habitacion ya registrada\n" ;
							cout<< "Ingrese nuevamente el numero\n" ;
							cin>> numero ;
						}             
                 
						cout<< "Ingrese el precio\n" ; //hay que aclarar que es sin el signo de pesos?
						cin>> precio ;
						cout<< "Ingrese la capacidad\n" ;
						cin>> capacidad ;
                            
              /*
              	while(iHostal->existeHostal(nombreH) == false){
						cout<< "Hostal no registrado\n" ;
						cout<< "Ingrese nuevamente el nombre\n" ;
						getline(cin,nombreH) ;
					}
              */
						
						cout<< "\n" ;
                        cout << "Si desea confirmar, ingrese '1', si desea cancelar ingrese '0'.\n";
                        cin>> j ;
                        if(!cin.good())
                            {
                            cout << "ERROR\n";
                            cin.clear();
                            cin.ignore(1000,'\n');
                            j = 2;
                            }
                        while (j != 0 && j != 1){
                            cout << "Ingrese '0' o '1'\n";
                            cin >> j;
                            if(!cin.good())
                            {
                            cout << "ERROR\n";
                            cin.clear();
                            cin.ignore(1000,'\n');
                            j = 2;
                            }
                        }
                        if(j==1)
                        {
                            iHostal->agregarHabitacion(numero,precio,capacidad,nombreH) ;
							cout<<"Se realizó el alta" ;
							cout<< "\n" ;
                        }
                        else
                        {
                            cout<<"Se canceló el alta" ;
							cout<< "\n" ;
                        }
					
					}

				}
				break ;

					case 4:
           		{
                  	//Asignar Empleado a Hostal
  			              
               map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "\n" ;
						cout<< "No hay hostales registrados\n" ;
						cout<< "\n" ;
					}
					else 
					{
    					int j = 1;
						cout<< "\n" ;
    					cout<< "Lista de Hostales \n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<") Nombre: " << i->second.getNombre() << "\n";
							cout<< "Dirección: " << i->second.getDireccion() << "\n";
							cout<< "Teléfono: " << i->second.getTelefono() << "\n";
							cout<< "Calificación Promedio: " << i->second.getCalificacionPromedio() << "\n";
							cout<< "\n" ;
        					j++;
    					}
						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Ingrese el nombre del hostal del que desea asignar el empleado. \n" ;
						string nomhos ;
						getline(cin, nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "\n" ;
							cout<< "El nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin, nomhos) ;
						}        
                            
                            
  						Hostal *hostal = iHostal->encontrarHostal(nomhos);
  						map<string , DtEmpleado> empleados = iUsuario->listarEmpleadosNoAsignados();
  						map<string , DtEmpleado> :: iterator e;
  						if(iUsuario->getEmpleados().empty())
  						{
  							cout<< "\n" ;
							cout<< "No hay empleados registrados" ;
							cout<< "\n" ;
  						}
  						else 
  						{
							cout<< "\n" ;
  							cout<< "Lista de Empleados no asignados \n" ;
							cout<< "\n" ;
							j=1;
  							for(e=empleados.begin(); e != empleados.end(); e++){
  								cout<< j <<") Nombre: " << e->second.getNombre() << "\n";
  								cout<< "Email: " << e->second.getEmail() << "\n";
								cout<< "\n" ;
  								j++;
  							}
  							cout<<"Ingrese el email del empleado que desea asignar al hostal. \n" ;
  							string emailEmp ;
  							cin>> emailEmp ;
  							while(empleados.find(emailEmp) == empleados.end()){
								cout<< "\n" ;
  								cout<< "El email ingresado no corresponde a un empleado del sistema.\n" ;
  								cout<<"Ingrese un email correspondiente a un empleado del sistema.\n" ;
  								cin>>emailEmp ;
  							}
  							int cargo ;
  							cout<< "Ingrese el tipo de cargo: '0': Administración, '1': Limpieza, '2': Recepción, '3': Infraestructura\n" ;
  							cin>> cargo ;
  							if(!cin.good())
  							{
  								cout << "ERROR\n";
  								cin.clear();
  								cin.ignore(1000,'\n');
  								cargo = 4;
  							}
  							while ( cargo!= 0 && cargo != 1 && cargo != 2 && cargo != 3){
  								cout << "Ingrese: '0' Administración, '1' Limpieza, '2' Recepción, '3' Infraestructura\n";
  								cin >> cargo;
  								if(!cin.good())
  								{
  									cout << "ERROR\n";
  									cin.clear();
  									cin.ignore(1000,'\n');
  									cargo = 4;
  								}
  							}
  							int p;
  							cout<<"Si desea asignar el nuevo empleado ingrese 1 sino ingrese 0.\n" ;
  							cin>> p ;
  							if(!cin.good())
  							{
  								cout << "ERROR\n";
  								cin.clear();
  								cin.ignore(1000,'\n');
  								p = 2;
  							}
  							while (p != 0 && p != 1){
  								cout << "Ingrese '0' o '1'\n";
  								cin >> p;
  								if(!cin.good())
  								{
  								cout << "ERROR\n";
  								cin.clear();
  								cin.ignore(1000,'\n');
  								p = 2;
  								}
  							}
  							if(cargo == 0 && p == 1){
  								iUsuario->asignarEmpleado(emailEmp, ADMINISTRACION, hostal);
								cout<<"Se asignó el empleado al hostal" ;
								cout<< "\n" ;
  							}
  							if(cargo == 1 && p == 1){
  								iUsuario->asignarEmpleado(emailEmp, LIMPIEZA, hostal);
								cout<<"Se asignó el empleado al hostal" ;
								cout<< "\n" ;
  							}
  							if(cargo == 2 && p == 1){
  								iUsuario->asignarEmpleado(emailEmp, RECEPCION, hostal);
								cout<<"Se asignó el empleado al hostal" ;
								cout<< "\n" ;
  							}
  							if(cargo == 3 && p == 1){
  								iUsuario->asignarEmpleado(emailEmp, INFRAESTRUCTURA, hostal);
								cout<<"Se asignó el empleado al hostal" ;
								cout<< "\n" ;
  							}
  							if (p == 1){
  								cout<<"Si desea asignar otro nuevo empleado ingrese 1 sino ingrese 0.\n" ;
  								cin>> p ;
  								if(!cin.good())
  								{
  									cout << "ERROR\n";
  									cin.clear();
  									cin.ignore(1000,'\n');
  									p = 2;
  								}
  								while (p != 0 && p != 1){
  									cout << "Ingrese '0' o '1'\n";
  									cin >> p;
  									if(!cin.good())
  									{
  									cout << "ERROR\n";
  									cin.clear();
  									cin.ignore(1000,'\n');
  									p = 2;
  									}
  								}
  								set<string> empleadosAsignados;
  								empleadosAsignados.insert(emailEmp);
  								while (p==1){
  									cout<<"Ingrese el email del empleado que desea asignar al hostal. \n" ;
  									cin>> emailEmp ;
  									while((empleados.find(emailEmp) == empleados.end()) || (empleadosAsignados.find(emailEmp) != empleadosAsignados.end())){
                      if (empleados.find(emailEmp) == empleados.end()){
											cout<< "\n" ;
    										cout<< "El email ingresado no corresponde a un empleado del sistema.\n" ;
    										cout<<"Ingrese un email correspondiente a un empleado del sistema.\n" ;
    										cin>>emailEmp ;
                      }
                      if (empleadosAsignados.find(emailEmp) != empleadosAsignados.end()){
											cout<< "\n" ;
    										cout<< "El email ingresado ya fue asignado.\n" ;
    										cout<<"Ingrese un email no asignado.\n" ;
    										cin>>emailEmp ;
                      }
                      
  									}
  									cout<< "Ingrese el tipo de cargo: '0': Administración, '1': Limpieza, '2': Recepción, '3': Infraestructura\n" ;
  									cin>> cargo ;
  									if(!cin.good())
  									{
  										cout << "ERROR\n";
  										cin.clear();
  										cin.ignore(1000,'\n');
  										cargo = 4;
  									}
  									while ( cargo!= 0 && cargo != 1 && cargo != 2 && cargo != 3){
  										cout << "Ingrese: '0' Administración, '1' Limpieza, '2' Recepción, '3' Infraestructura\n";
  										cin >> cargo;
  										if(!cin.good())
  										{
  											cout << "ERROR\n";
  											cin.clear();
  											cin.ignore(1000,'\n');
  											cargo = 4;
  										}
  									}
  									if(cargo == 0){
  										iUsuario->asignarEmpleado(emailEmp, ADMINISTRACION, hostal);
										cout<<"Se asignó el empleado al hostal" ;
										cout<< "\n" ;
  									}
  									if(cargo == 1){
  										iUsuario->asignarEmpleado(emailEmp, LIMPIEZA, hostal);
										cout<<"Se asignó el empleado al hostal" ;
										cout<< "\n" ;
  									}
  									if(cargo == 2){
  										iUsuario->asignarEmpleado(emailEmp, RECEPCION, hostal);
										cout<<"Se asignó el empleado al hostal" ;
										cout<< "\n" ;
  									}
  									if(cargo == 3){
  										iUsuario->asignarEmpleado(emailEmp, INFRAESTRUCTURA, hostal);
										cout<<"Se asignó el empleado al hostal" ;
										cout<< "\n" ;
  									}
  									cout<<"Si desea asignar nuevo empleado ingrese 1 sino ingrese 0.\n" ;
  									cin>> p ;
  									if(!cin.good())
  									{
  										cout << "ERROR\n";
  										cin.clear();
  										cin.ignore(1000,'\n');
  										p = 2;
  									}
  									while (p != 0 && p != 1){
  										cout << "Ingrese '0' o '1'\n";
  										cin >> p;
  										if(!cin.good())
  										{
  										cout << "ERROR\n";
  										cin.clear();
  										cin.ignore(1000,'\n');
  										p = 2;
  										}
  									}
  									empleadosAsignados.insert(emailEmp);
  								}
  							}
  						}
  					}
              	}
              	break;

				case 5: // Realizar reserva
           		{
					map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "\n" ;
						cout<< "No hay hostales registrados\n" ;
						cout<< "\n" ;
					}
					else 
					{
    					int j = 1;
						cout<< "\n" ;
    					cout<< "Lista de Hostales \n" ;
						cout<< "\n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<") Nombre: " << i->second.getNombre() << "\n";
							cout<< "Dirección: " << i->second.getDireccion() << "\n";
							cout<< "Teléfono: " << i->second.getTelefono() << "\n";
							cout<< "Calificación Promedio: " << i->second.getCalificacionPromedio() << "\n";
							cout<< "\n" ;
        					j++;
    					}
						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Ingrese el nombre del hostal del que desea ver la información. \n" ;
						string nomhos ;
						getline(cin, nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "\n" ;
							cout<< "El nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin, nomhos) ;
						}
						int dia, anio,mes, hora;
						cout<< "\n" ;
						cout<<"Ingrese fecha de entrada. \n";
						cout<< "\n" ;
						cout<<"Ingrese dia de entrada. \n";
						cin>>dia;
						cout<<"Ingrese mes de entrada. \n";
						cin>>mes;
						cout<<"Ingrese anio de entrada. \n";
						cin>>anio;
						cout<<"Ingrese hora de entrada. \n";
						cin>>hora;
						DtFechaHora fechaCheckIn = DtFechaHora(hora, dia,mes,anio);
						cout<< "\n" ;
						cout<<"Ingrese fecha de salida. \n";
						cout<< "\n" ;
						cout<<"Ingrese dia de salida. \n";
						cin>>dia;
						cout<<"Ingrese mes de salida. \n";
						cin>>mes;
						cout<<"Ingrese anio de salida. \n";
						cin>>anio;
						cout<<"Ingrese hora de salida. \n";
						cin>>hora;
						DtFechaHora fechaCheckOut = DtFechaHora(hora, dia,mes,anio);
						cout<< "\n" ;
						long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
						long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
					    while ((f2 - f1) < 0) {
							cout<< "\n" ;
							cout<<"Fecha invalida. Fecha de salida debe ser mayor a la fecha de entrada.\n";
							cout<< "\n" ;
							cout<<"Ingrese fecha de entrada. \n";
							cout<< "\n" ;
							cout<<"Ingrese dia de entrada. \n";
							cin>>dia;
							cout<<"Ingrese mes de entrada. \n";
							cin>>mes;
							cout<<"Ingrese anio de entrada. \n";
							cin>>anio;
							cout<<"Ingrese hora de entrada. \n";
							cin>>hora;
							fechaCheckIn = DtFechaHora(hora, dia,mes,anio);
							cout<< "\n" ;
							cout<<"Ingrese fecha de salida. \n";
							cout<< "\n" ;
							cout<<"Ingrese dia de salida. \n";
							cin>>dia;
							cout<<"Ingrese mes de salida. \n";
							cin>>mes;
							cout<<"Ingrese anio de salida. \n";
							cin>>anio;
							cout<<"Ingrese hora de salida. \n";
							cin>>hora;
							fechaCheckOut = DtFechaHora(hora, dia,mes,anio);
							cout<<"fechaaa" ;
							f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
							f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
							
						}
						bool esGrupal;
						cout<< "\n" ;
                        cout << "Ingrese 0 si la reserva sera individual o 1 si sera grupal. \n";
                        cin>> j ;
                        if(!cin.good())
                        {
                            cout << "ERROR\n";
                            cin.clear();
                            cin.ignore(1000,'\n');
                            j = 2;
                        }
                        while (j != 0 && j != 1){
                            cout << "Ingrese '0' o '1'\n";
                            cin >> j;
                            if(!cin.good())
                            {
                            cout << "ERROR\n";
                            cin.clear();
                            cin.ignore(1000,'\n');
                            j = 2;
                            }
                        }
						if (j==0) {esGrupal = false;}
						
						else {esGrupal = true;}
						
						map<int , DtHabitacion> setHabitOp = iHostal->devolverHabitacionesDisponibles(fechaCheckIn, fechaCheckOut, nomhos);
						map<int , DtHabitacion> :: iterator iR2;
						if(setHabitOp.empty())
						{
							cout<< "\n" ;
							cout<< "No hay habitaciones disponibles" ;
							cout<< "\n" ;
						}
						else 
						{
							int y = 1;
							cout<< "\n" ;
							cout<< "Lista de Habitaciones disponibles \n" ;
							cout<< "\n" ;
							for(iR2=setHabitOp.begin(); iR2 != setHabitOp.end(); iR2++){
								cout<< y <<") Numero: " << iR2->second.getNumero() << "\n";
								y++;
							}
							
							cout<< "\n" ;
							int numhab;
							cout<<"Ingrese el numero  de la habitacion que desea seleccionar. \n" ;
							cin>> numhab ;
							while(!cin.good())
							{
								cout << "ERROR NO ES UN NUMERO VALIDO\n";
								cin.clear();
								cin.ignore(1000,'\n');
								cout<<"Ingrese el numero  de la habitacion que desea seleccionar. \n" ;
								cin>> numhab;
							}
							while(!iHostal->existeHabitacion(numhab,nomhos)){
								cout<< "\n" ;
								cout<< "El numero ingresado no corresponde a una habitacion del sistema.\n" ;
								cout<<"Ingrese un numero correspondiente a una habitacion del sistema.\n" ;
								cin>>numhab;
							}
							map<string , DtHuesped> conjuntoHuespedes = iUsuario->listarHuespedes();

							map<string , DtHuesped> :: iterator iR3;
							if(conjuntoHuespedes.empty())
							{
								cout<< "\n" ;
								cout<< "No hay huespedes registrados. \n" ;
								cout<< "\n" ;
							}
							else 
							{
								int y = 1;
								cout<< "\n" ;
								cout<< "Lista de Huespedes registrados. \n" ;
								cout<< "\n" ;
								for(iR3=conjuntoHuespedes.begin(); iR3 != conjuntoHuespedes.end(); iR3++){
									cout<< y <<") Email: " << iR3->second.getEmail() << "\n";
									y++;
								}
								
								cout<< "\n" ;
								cout<<"Ingrese el email del huesped el cual realiza la reserva. \n" ;
								string mailHuesped ;
								cin>> mailHuesped ;
								while(!iUsuario->existeHuesped(mailHuesped)){
									cout<< "\n" ;
									cout<< "El email ingresado no corresponde a un huesped del sistema.\n" ;
									cout<<"Ingrese un email correspondiente a un huesped del sistema.\n" ;
									cin>>mailHuesped;
								}
								if (esGrupal) {
									set<string> mailsagregados;
									mailsagregados.insert(mailHuesped);
									bool deseaHuespedes = true;
									string otroHuesped ;
									int cont = 1;
									int capacidad = iHostal->encontrarHostal(nomhos)->obtenerHabitacion(numhab)->getCapacidad() ;
									while (deseaHuespedes && (cont<capacidad)){
										cont++;
										cout<<"Ingrese el email del huesped al cual desea agregar a la reserva. \n" ;
										cin>> otroHuesped ;
										while((!iUsuario->existeHuesped(otroHuesped)) || (mailsagregados.find(otroHuesped)!=mailsagregados.end() ) ) {
											cout<< "El email ingresado no corresponde a un huesped del sistema o ya fue agregado a la reserva.\n" ;
											cout<<"Ingrese un email correspondiente a un huesped del sistema, que no haya ingresado aún.\n" ;
											cin>>otroHuesped;
							
											if (mailsagregados.find(otroHuesped)!=mailsagregados.end()){
												cout<< "El email ingresado ya está registrado en la reserva.\n" ;
												cout<<"Ingrese un email no registrado.\n" ;
												cin>>otroHuesped;
											}
										}
										mailsagregados.insert(otroHuesped);                        
										int j ; 
										cout << "Si desea agregar otro huesped a la reserva, ingrese '1', de lo contrario ingrese '0'.\n";
										cin>> j ;
										if(!cin.good())
										{
											cout << "ERROR\n";
											cin.clear();
											cin.ignore(1000,'\n');
											j = 2;
										}
										while (j != 0 && j != 1){
											cout << "Ingrese '0' o '1'\n";
											cin >> j;
											if(!cin.good())
											{
												cout << "ERROR\n";
												cin.clear();
												cin.ignore(1000,'\n');
												j = 2;
											}
										}
										if (j == 0) {
											deseaHuespedes = false;
										}
									if(cont == capacidad &&  deseaHuespedes){
										cout<< "No se puede añadir más huespedes, capacidad llena. \n" ;
									} 
									} //se cierra el agregue de huespedes.
									cout << "Si desea confirmar la reserva, ingrese '1', si desea cancelar ingrese '0'.\n";
									cin>> j ;
									if(!cin.good())
									{
										cout << "ERROR\n";
										cin.clear();
										cin.ignore(1000,'\n');
										j = 2;
									}
									while (j != 0 && j != 1){
										cout << "Ingrese '0' o '1'\n";
										cin >> j;
										if(!cin.good())
										{
											cout << "ERROR\n";
											cin.clear();
											cin.ignore(1000,'\n');
											j = 2;
										}
									}
									if (j == 1 ){ 
										iReserva->confirmarReservaGrupal(nomhos, numhab, fechaCheckIn, fechaCheckOut, mailHuesped, mailsagregados, cont);
										cout<<"Se realizó la reserva" ;
										cout<< "\n" ;
									}
									else {
										cout<< "Se cancelo el la Reserva.\n";
										cout<< "\n" ;
									}
									//Acá debería cerrarse la grupal.
									//Se cierra el de existeHuesped.
								} else{
									cout << "Si desea confirmar la reserva, ingrese '1', si desea cancelar ingrese '0'.\n";
									cin>> j ;
									if(!cin.good())
									{
										cout << "ERROR\n";
										cin.clear();
										cin.ignore(1000,'\n');
										j = 2;
									}
									while (j != 0 && j != 1){
										cout << "Ingrese '0' o '1'\n";
										cin >> j;
										if(!cin.good())
										{
											cout << "ERROR\n";
											cin.clear();
											cin.ignore(1000,'\n');
											j = 2;
										}
									}
									if (j == 1) {
										iReserva->confirmarReservaIndividual(nomhos, numhab, fechaCheckIn, fechaCheckOut, mailHuesped);
										cout<<"Se realizó la reserva" ;
										cout<< "\n" ;
									}
									else {
										cout<< "Se cancelo el la Reserva.\n";
										cout<< "\n" ;
									}
									//cierra bien el else de Individual.
								} 
							}
						}
					}
				}
            	break;
				case 6:
           		{
					cout << "Hasta luego.\n";
                	//Consulta de Top 3 Hostales.
            	}
            	break;

				case 7:
           		{

					        map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "\n" ;
						cout<< "No hay hostales registrados\n" ;
						cout<< "\n" ;
					}
					else 
					{
    					int j = 1;
						cout<< "\n" ;
    					cout<< "Lista de Hostales \n" ;
						cout<< "\n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<") Nombre: " << i->second.getNombre() << "\n";
							cout<< "Dirección: " << i->second.getDireccion() << "\n";
							cout<< "Teléfono: " << i->second.getTelefono() << "\n";
							cout<< "Calificación Promedio: " << i->second.getCalificacionPromedio() << "\n";
							cout<< "\n" ;
        					j++;
    					}
						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Ingrese el nombre del hostal del que desea ver la información. \n" ;
						string nomhos ;
						getline(cin, nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "\n" ;
							cout<< "El nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin, nomhos) ;
						}
			
						cout<<"Ingrese el email del huesped del que desea ver las reservas." ;
						string nomus ;
						cin>> nomus ;
						while(!iUsuario->existeHuesped(nomus)){
							cout<< "El email ingresado no corresponde a un huesped del sistema." ;
							cout<<"Ingrese un email correspondiente a un huesped del sistema." ;
              cout<< "\n" ;
							cin>>nomus ;
						}
						map<int, DtReserva> reservas = iReserva->listarReservas(nomhos,nomus) ;
            map<int, DtReserva>::iterator i; 
						if(reservas.empty())
						{
							throw invalid_argument ("No hay reservas no canceladas en ese hostal para ese huesped ") ;
              cout<< "\n" ;
						}
						else 
						{
    						int j = 1;
    						cout<< "Lista de Reservas /n" ;
                cout<< "\n" ;
    						for(i=reservas.begin(); i != reservas.end(); i++){        
                  
                 	  cout<< j << "Código: " << i->second.getCodigo() << "\n";
										DtFechaHora DeCheckIn = i->second.getCheckIn() ;
										cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
										DtFechaHora DeCheckOut = i->second.getCheckOut() ;
										cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
                						DtFechaHora DeRealizada = i->second.getFechaRealizada() ;
										cout << "CheckIn: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
                                
										cout<<"Estado de la Reserva: ";
											if (i->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (i->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (i->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											
                						cout<< "Costo:" << i->second.getCosto() << "\n";
										cout<<"Email del Huesped: " << i->second.getEmailHuesped() ;
										cout<< "\n" ;
              							j++;
 					         }            
                              
               
							/*if (dynamic_cast<ReservaGrupal *>(i->second)!=NULL))
							{	
								set<string>::iterator it; 
								cout<< "Huespedes /n" ;
                cout<< "\n" ;
								int k = 1;
								for(it=i->second.begin(); it != i->second.end(); i++)
								{
									cout<< "Nombre:" << i->second << "/n";
                  cout<< "\n" ;
									k++;
								}
							}*/
        						j++;		
						} 
						cout<<"Ingrese el código de la reserva que desea registrar la estadía." ;
						int codres ;
						cin>> codres ;
						while(!iReserva->existeReserva(codres)){
							cout<< "El código ingresado no corresponde a una reserva del sistema." ;
							cout<<"Ingrese un código correspondiente a una reserva del sistema." ;
							cin>>codres ;
              cout<< "\n" ;
						}
						iReserva->inscribirEstadia(codres,nomus);
						
					}
				

                	//Registrar Estadía
            	}
            	break;

				case 8:
           		{
                	//Finalizar Estadía
					map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "No hay hostales registrados\n" ;
					}
					else 
					{
    					int j = 1;
    					cout<< "Lista de Hostales \n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<") Nombre: " << i->second.getNombre() << "\n";
							cout<< "Teléfono: " << i->second.getTelefono() << "\n";
        					j++;
    					}
						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Ingrese el nombre del hostal del que desea ver la información. \n" ;
						string nomhos ;
						getline(cin, nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "El nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin, nomhos) ;
						}
						cout<<"Ingrese el email del huesped del cual quiere finalizar su estadia. \n" ;
						string mailhues ;
						cin>> mailhues;
						if ((iUsuario->getHuespedes().find(mailhues)->second->getEstadia()) != NULL) {
							iReserva->finalizarEstadia(mailhues);
							cout<< "Se finalizo la estadia.\n";
						}
            		}
				}

            	break;

				case 9:
           		{
					cout << "Hasta luego.\n";
                	//Calificar Estadía
            	}
            	break;

				case 10:
           		{
					cout << "Hasta luego.\n";
                	//Comentar Calificación
            	}
            	break;

				case 11:
           		{
                        //Consulta de Usuario
   					        map<string, DtHuesped>  losHuespe = iUsuario->listarHuespedes();
          					map<string, DtEmpleado> losEmple = iUsuario->listarEmpleados();
          					map<string, DtHuesped> :: iterator iHu;
          					map<string, DtEmpleado> :: iterator iEm;
                    if (losHuespe.empty() and losEmple.empty()){
                      cout<<"No hay usuarios registrados.\n";
                    }else{
                        if(!losHuespe.empty())
              					{
                  					int j = 1;
                  					cout<< "Lista de Huespedes \n" ;
                  					for(iHu=losHuespe.begin(); iHu != losHuespe.end(); iHu++){
                      					cout<< j <<"Email: " << iHu->second.getEmail() << "\n";
              							j++;
                  					}
              					}
              					if(!losEmple.empty())
              					{
                  					int j = 1;
                  					cout<< "Lista de Empleados \n" ;
                  					for(iEm=losEmple.begin(); iEm != losEmple.end(); iEm++){
                      					cout<< j <<"Email: " << iEm->second.getEmail() << "\n";
              							j++;
                  					}
              					}
              					cout<<"Ingrese el email del usuario del cual desea ver la información. \n" ;
              					string nomus ;
              					cin>> nomus ;
              					while((!iUsuario->existeEmpleado(nomus)) && (!iUsuario->existeHuesped(nomus))){
              						cout<< "El nombre ingresado no corresponde a un usuario del sistema.\n" ;
              						cout<<"Ingrese un nombre correspondiente a un usuario del sistema.\n" ;
              						cin>>nomus ;
              						}
              						if (iUsuario->existeHuesped(nomus)) {
              							DtHuesped infoh = iUsuario->mostrarHuesped(nomus) ;
              							cout<< "\nInformación básica del Huesped seleccionado:\n" ;
              							cout<<"Nombre: " << infoh.getNombre() << "\n";
              							cout<< "Email: " << infoh.getEmail() << "\n";
              							if (infoh.getEsFinger()) {
              								cout<< "Es Finger.\n";
              							} else {
              								cout<< "No es Finger.\n";
              							}
              						} else {
              							DtEmpleado infoEm = iUsuario->mostrarEmpleado(nomus) ;
              							cout<< "\nInformación básica del Empleado seleccionado:\n" ;
              							cout<<"Nombre: " << infoEm.getNombre() << "\n";
              							cout<< "Email: " << infoEm.getEmail() << "\n";
              							cout<< "Trabaja en: " << infoEm.getNombreHostal() << "\n";
										cout<< "Cargo:";
      											if (infoEm.getCargo() == 0){
      												cout << "ADMINISTRACION\n";
      											}
      											else if (infoEm.getCargo()  == 1){
      												cout << "LIMPIEZA\n";
      											}
      											else if (infoEm.getCargo()  == 2){
      												cout << "RECEPCION\n";
      											} 
												else if (infoEm.getCargo()  == 3){
      												cout << "INFRAESTRUCTURA\n";
      											}
              						}
              
                    }
             	
            	}
            	break;

				case 12 : //Consulta de Hostal
				{	
					map<string, DtHostal> loshostales = iHostal->listarHostales();

					if(loshostales.empty())
					{
						cout<<"No hay hostales registrados\n" ;
					}
					else 
					{
						map<string , DtHostal> :: iterator ih;
    					int j = 1;
    					cout<< "\nLista de Hostales\n" ;
    					for(ih=loshostales.begin(); ih != loshostales.end(); ih++){
							cout<< j <<"Nombre: " << ih->second.getNombre() << "\n";
							cout<< "Dirección: " << ih->second.getDireccion() << "\n";
							cout<< "Teléfono: " << ih->second.getTelefono() << "\n";
							cout<< "Calificación Promedio: " << ih->second.getCalificacionPromedio() << "\n";
							cout<<"\n" ;
        					j++;
    					}

						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						cout<<"\nIngrese el nombre del hostal del que desea ver la información.\n" ;
						string nomhos ;
						getline(cin,nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<<"\n" ;
							cout<< "\nEl nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"\nIngrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin,nomhos) ;
						}
	
						DtHostal infoh = iHostal->infoHostal(nomhos) ;
						cout<< "\nInformación básica del hostal seleccionado:\n" ;
						cout<<"Nombre: " << infoh.getNombre() << "\n";
						cout<< "Dirección: " << infoh.getDireccion() << "\n";
						cout<< "Teléfono: " << infoh.getTelefono() << "\n";
						cout<< "Calificación Promedio: " << infoh.getCalificacionPromedio() << "\n";
						cout<<"\n" ;

						map<int, DtHabitacion> lashabitaciones = iHostal->listarHabitaciones(nomhos); 

						if(lashabitaciones.empty()){ 
							cout<<"\nNo hay calificaciones registradas\n" ; 
							cout<<"\nNo hay habitaciones registradas\n" ;
							cout<<"\nNo hay reservas registradas\n" ;
							cout<<"\n" ;
						}
						else{
							map<int , DtHabitacion> :: iterator ihab; // Sabiendo que hay habitaciones, se define ihab.
							map<int, DtReservaGrupal> lasreservasgrup = iHostal->listarReservasGrupal(nomhos); 
							map<int, DtReservaIndividual> lasreservasind = iHostal->listarReservasIndividual(nomhos);									
							if(lasreservasgrup.empty() && lasreservasind.empty()){
								cout<<"\n" ;
								cout<<"\nNo hay calificaciones registradas\n" ; 
								cout<<"\n" ;
								//Si no hay calificaciones ni reservas, pero sí habitaciones.
								int k = 1;
								cout<< "\nLista de Habitaciones del Hostal\n" ;
								for(ihab=lashabitaciones.begin(); ihab != lashabitaciones.end(); ihab++){
									cout<< k <<"Numero: " << ihab->second.getNumero() << "\n";
									cout<< "Precio:" << ihab->second.getPrecio() << "\n";
									cout<< "Capacidad:" << ihab->second.getCapacidad() << "\n";
									cout<<"\n" ;
									k++;
								}
								cout<<"No hay reservas registradas\n" ;
								cout<<"\n" ;
							}
							else {
								map<int,DtCalificacion> calificaciones = iHostal->listarCalificaciones(nomhos); 
							
								if(calificaciones.empty()){
									cout<<"\n" ;
									cout<<"\nNo hay calificaciones registradas\n" ; 
									cout<<"\n" ;
									//Si no hay calificaciones, pero sí reservas y habitaciones.
									map<int , DtHabitacion> :: iterator rhab;
									int l = 1;
									cout<< "\nLista de Habitaciones del Hostal\n" ;
									for(rhab=lashabitaciones.begin(); rhab != lashabitaciones.end(); rhab++){
										cout<< l <<"Numero: " << rhab->second.getNumero() << "\n";
										cout<< "Precio:" << rhab->second.getPrecio() << "\n";
										cout<< "Capacidad:" << rhab->second.getCapacidad() << "\n";
										cout<<"\n" ;
										l++;
									}
				
									int mr = 1 ;
									cout<< "\nLista de Reservas del Hostal\n" ;
									cout<<"\n" ;
									if (!lasreservasgrup.empty()){
										map<int , DtReservaGrupal> :: iterator iresg;
										for(iresg=lasreservasgrup.begin(); iresg != lasreservasgrup.end(); iresg++){
											cout<< mr <<"Codigo: " << iresg->second.getCodigo() << "\n";
								
											DtFechaHora DeCheckIn = iresg->second.getCheckIn() ;
											cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
											DtFechaHora DeCheckOut = iresg->second.getCheckOut() ;
											cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
								
											DtFechaHora DeRealizada = iresg->second.getFechaRealizada() ;
											cout<< "Realizada a las: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
											cout<<"Estado de la Reserva: ";
											if (iresg->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (iresg->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (iresg->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											cout<<"Costo de la Reserva: " << iresg->second.getCosto() << "\n";
											
											cout<<"Cantidad de Huespedes de la Reserva: " << iresg->second.getCantGrupHuespedes() << "\n";
											cout<<"Email del Huesped que realizó la reserva: " << iresg->second.getEmailHuesped() ;
											cout<<"\n" ;
											//ponemos los nombres de los huespedes de la reserva acá?
											
											mr++;
											}	
									}
									if (!lasreservasind.empty()){
										map<int , DtReservaIndividual> :: iterator iresi;
										for(iresi=lasreservasind.begin(); iresi != lasreservasind.end(); iresi++){
											cout<< mr <<"Codigo: " << iresi->second.getCodigo() << "\n";
								
											DtFechaHora DeCheckIn = iresi->second.getCheckIn() ;
											cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
											DtFechaHora DeCheckOut = iresi->second.getCheckOut() ;
											cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
								
											DtFechaHora DeRealizada = iresi->second.getFechaRealizada() ;
											cout<< "Realizada a las: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
											cout<<"Estado de la Reserva: ";
											if (iresi->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (iresi->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (iresi->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											cout<<"Costo de la Reserva: " << iresi->second.getCosto() << "\n";
											cout<<"Email del Huesped: " << iresi->second.getEmailHuesped() ;
											cout<<"\n" ;
											
											mr++;
										}	
									}
								}
								else {
									int lc = 1;
									cout<<"\n" ;
									cout<< "\nLista de Calificaciones del Hostal\n" ;
									map<int, DtCalificacion> :: iterator ical;
									for(ical=calificaciones.begin(); ical!=calificaciones.end(); ical++){ //nota:puse ++ical para ver la diferencia,
										DtCalificacion c = ical->second ; //lo que está current en ical.
										DtFechaHora cfecha = c.getFecha() ;
										cout<< lc << "Fecha: " << cfecha.getHora() << " del " << cfecha.getDia() << "/" << cfecha.getMes() << "/" << cfecha.getAnio() << "\n";
										cout<<"Puntaje: " << c.getPuntaje() << "\n" ;
										cout<<"Comentario:" << c.getComentario() << "\n" ;
										if(c.getRespuesta() != "vacio"){ //tengo que poner strcompare o así se compara bien? Aparte puedo hacer c->respuesta != NULL ?
											cout<<"Respuesta:" << c.getRespuesta() << "\n" ;
										}
										cout<<"\n" ;
										lc++ ;
									}
										
									map<int , DtHabitacion> :: iterator rchab;
									int lh = 1;
									cout<<"\n" ;
									cout<< "\nLista de Habitaciones del Hostal\n" ;
									for(rchab=lashabitaciones.begin(); rchab != lashabitaciones.end(); rchab++){
										cout<< lh <<"Numero: " << rchab->second.getNumero() << "\n";
										cout<< "Precio:" << rchab->second.getPrecio() << "\n";
										cout<< "Capacidad:" << rchab->second.getCapacidad() << "\n";
										cout<<"\n" ;
										lh++;
									}
									int lr = 1 ; 
									cout<< "\nLista de Reservas del Hostal\n" ;
									if (!lasreservasgrup.empty()){
										map<int , DtReservaGrupal> :: iterator cresg;
										for(cresg=lasreservasgrup.begin(); cresg != lasreservasgrup.end(); cresg++){
											cout<< lr <<"Codigo: " << cresg->second.getCodigo() << "\n";
													
											DtFechaHora DeCheckIn = cresg->second.getCheckIn() ;
											cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
											DtFechaHora DeCheckOut = cresg->second.getCheckOut() ;
											cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
													
											DtFechaHora DeRealizada = cresg->second.getFechaRealizada() ;
											cout<< "Realizada a las: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
											
											cout<<"Estado de la Reserva: ";
											if (cresg->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (cresg->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (cresg->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											cout<<"Costo de la Reserva: " << cresg->second.getCosto() << "\n";
											cout<<"Email del Huesped que realizó la reserva: " << cresg->second.getEmailHuesped() ;
												 
											cout<<"Cantidad de Huespedes de la Reserva: " << cresg->second.getCantGrupHuespedes() << "\n";
											cout<<"\n" ;
											//ponemos los nombres de los huespedes acá?
											
											lr++;
										}
									}
									if (!lasreservasind.empty()){
										map<int , DtReservaIndividual> :: iterator cresi;
										for(cresi=lasreservasind.begin(); cresi != lasreservasind.end(); cresi++){
											cout<< lr <<"Codigo: " << cresi->second.getCodigo() << "\n";
													
											DtFechaHora DeCheckIn = cresi->second.getCheckIn() ;
											cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
											DtFechaHora DeCheckOut = cresi->second.getCheckOut() ;
											cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
													
											DtFechaHora DeRealizada = cresi->second.getFechaRealizada() ;
											cout<< "Realizada a las: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
											
											cout<<"Estado de la Reserva: ";
											if (cresi->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (cresi->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (cresi->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											cout<<"Costo de la Reserva: " << cresi->second.getCosto() << "\n";
											cout<<"Email del Huesped: " << cresi->second.getEmailHuesped() ;
											cout<<"\n" ;
											
											lr++;
										}
									}
								}
							}
						}
					}	
				}
				break ; 
				case 13: // consulta de reserva
        {
           		   
           map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						cout<< "No hay hostales registrados\n" ;
					}
					else 
					{
    					int j = 1;
    					cout<< "Lista de Hostales \n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<") Nombre: " << i->second.getNombre() << "\n";
							cout<< "Dirección: " << i->second.getDireccion() << "\n";
							cout<< "Teléfono: " << i->second.getTelefono() << "\n";
							cout<< "Calificación Promedio: " << i->second.getCalificacionPromedio() << "\n";
							cout<< "\n" ;
        					j++;
    					}
						cin.clear(); 
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Ingrese el nombre del hostal del que desea ver las reservas. \n" ;
						string nomhos ;
						getline(cin, nomhos) ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "El nombre ingresado no corresponde a un hostal del sistema.\n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema.\n" ;
							getline(cin, nomhos) ;
						}

                    map<int, DtReservaIndividual>  individuales = iHostal->listarReservasIndividual(nomhos);
          					map<int, DtReservaGrupal> grupales = iHostal->listarReservasGrupal(nomhos);
          					map<int, DtReservaIndividual>::iterator iIn; 
          					map<int, DtReservaGrupal>::iterator iGp; 
                    if (individuales.empty() and grupales.empty()){
                      cout<<"No hay reservas registradas en el hostal seleccionado.\n";
                    }else{
                        if(!individuales.empty())
              					{
                  					int j = 1;
                  					cout<< "Lista de reservas individuales \n" ;
                  					for(iIn=individuales.begin(); iIn != individuales.end(); iIn++){
                      					cout<< j << "Código: " << iIn->second.getCodigo() << "\n";
										DtFechaHora DeCheckIn = iIn->second.getCheckIn() ;
										cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
										DtFechaHora DeCheckOut = iIn->second.getCheckOut() ;
										cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
                						DtFechaHora DeRealizada = iIn->second.getFechaRealizada() ;
										cout << "CheckIn: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
                                
										cout<<"Estado de la Reserva: ";
											if (iIn->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (iIn->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (iIn->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
											
                						cout<< "Costo:" << iIn->second.getCosto() << "\n";
										cout<<"Email del Huesped: " << iIn->second.getEmailHuesped() ;
										cout<< "\n" ;
              							j++;
                  					}
                             
                       
              					}
              					if(!grupales.empty())
              					{
                  					int j = 1;
                  					cout<< "Lista de reservas grupales \n" ;
                  					for(iGp=grupales.begin(); iGp != grupales.end(); iGp++){
                      					cout<< j <<"Código: " << iGp->second.getCodigo() << "\n";
										DtFechaHora DeCheckIn = iGp->second.getCheckIn() ;
										cout << "CheckIn: " << DeCheckIn.getHora() << " del " << DeCheckIn.getDia() << "/" << DeCheckIn.getMes() << "/" << DeCheckIn.getAnio() << "\n";
										DtFechaHora DeCheckOut = iGp->second.getCheckOut() ;
										cout<< "CheckOut: " << DeCheckOut.getHora() << " del " << DeCheckOut.getDia() << "/" << DeCheckOut.getMes() << "/" << DeCheckOut.getAnio() << "\n";
										DtFechaHora DeRealizada = iGp->second.getFechaRealizada() ;
										cout << "CheckIn: " << DeRealizada.getHora() << " del " << DeRealizada.getDia() << "/" << DeRealizada.getMes() << "/" << DeRealizada.getAnio() << "\n";
										
										cout<<"Estado de la Reserva: ";
											if (iGp->second.getEstado() == 0){
												cout << "ABIERTA\n";
											}
											else if (iGp->second.getEstado() == 1){
												cout << "CERRADA\n";
											}
											else if (iGp->second.getEstado() == 2){
												cout << "CANCELADA\n";
											}
										
                						cout<< "Costo:" << iGp->second.getCosto() << "\n";
										cout<<"Email del Huesped que realizó la reserva: " << iGp->second.getEmailHuesped() ;
										cout<< "\n" ;
										set<string> nomHuespedes = iGp->second.getNombresHuespedes() ;
										set<string>::iterator it; 
                								cout<< "Huespedes de la reserva\n" ;
                								int k = 1;

                								for(it=nomHuespedes.begin(); it != nomHuespedes.end(); it++)
                								{
													string elnombre = *it ;
                									cout<< k << ") Nombre:" << elnombre << "\n";
                									k++;
                								}
												
										cout<< "\n" ;

              							j++;
                  					}
              					}
						} 
					}
				
            	}
				break ; 
				case 14:
           		{
					cout << "Hasta luego.\n";
            	}
				break ; 
				case 15:
           		{
					cout << "Hasta luego.\n";
            	}
				break ;
				case 16:
           		{
					cout << "Hasta luego.\n";
            	}
				break ;
				case 17:
           		{
					cout << "Hasta luego.\n";
            	}
				break ;
				case 18:
           		{
					cout << "Hasta luego.\n";
            	}
				break ;
				case 19:
				{
					int hora;
					int dia;
					int mes;
					int anio;
					cout << "Ingrese fecha y hora: \n";
					cout << "Hora: ";
					cin >> hora;
					cout << "Dia: ";
					cin >> dia;
					cout << "Mes: ";
					cin >> mes;
					cout << "Año[aaaa]: ";
					cin >> anio;
					try{
						DtFechaHora horaActual = DtFechaHora(hora, dia, mes, anio);
						iFecha->setFechaHora(horaActual);
					}catch (const invalid_argument& ia){
						cout << "\nError: " << ia.what() << "\n";
					}
				}
				break;
				case 20:
				{ 
					cargarDatosPrueba(iHostal, iUsuario, iReserva, iFecha);
					cout << "Datos cargados.\n";
				}
				break ; 
				case 0:
           		{
                	cout << "Hasta luego.\n";
                	bandera = true;
            	}
            	break;
            	
				default:
                cout << "Ingrese un número del 0 al 20\n";
                
		delete iHostal;
		delete iReserva;
		delete iUsuario;
		delete f;
		return 0;
		}
	}
}

