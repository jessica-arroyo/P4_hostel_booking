/*
#include "include/altaAsignatura.hpp"
#include "include/asignarDocenteAAsignatura.hpp"
#include "include/finalizacionDeClase.hpp"
#include "include/altaUsuario.hpp"
#include "include/inicioDeClase.hpp"
#include "include/asistenciaAClaseEnVivo.hpp"
#include "include/inscripcionAAsignatura.hpp"
#include "include/finalizacionDeAsistenciaAClaseEnVivo.hpp"
#include "include/envioDeMensaje.hpp"
#include "include/tiempoDeDictadoDeClases.hpp"
#include "include/eliminacionAsignatura.hpp"
#include "include/tiempoDeAsistenciaAClase.hpp"
#include "include/consultaNotificaciones.hpp"
#include "include/subscribir.hpp" */

#include "include/Fabrica.hpp"
#include <iostream>
#include <istream>
#include <limits>
#include <ios>
#include <map>
#include <set>

using namespace std;

/*int cargarMensaje(DtFechaHora fecha, string email, int idClase, int aResponder, string texto){ // pasar -1 al aResponder para no resp.
	Fabrica* f = Fabrica::getInstancia();
	IClase *iClase = f->getIClase();
	IReloj *iReloj = f->getIReloj();
	
	iReloj->setFechaHora( fecha );
	iClase->clasesActUser(email);
	iClase->listarMensajes(idClase);
	if(aResponder != (-1))
		iClase->responderA(aResponder);
	return iClase->registrarMensaje(texto) ; 
}
*/
/*
void cargarDatosPrueba(IAsignatura *iAsignatura, IClase *iClase, IUsuario *iUsuario, IReloj *iReloj)
{
	//Docentes
	string emailDocente[3] = {"juan@mail.com", "maria@mail.com", "jorge@mail.com"};
	string nombreDocente[3] = {"Juan Perez", "Maria Pires", "Jorge Chacho"};
	string institutoDocente[3] = {"INCO", "INCO", "INCO"};
	for (int i = 0; i < 3; i++)
	{
		iUsuario->crearDocente (nombreDocente[i], emailDocente[i], "", "", DtSuscripcion::ninguna, institutoDocente[i]);
		iUsuario->agregarUsuario();
	}

	
	//Estudiantes
	string emailEstudiante[3] = {"roberto@mail.com", "ana@mail.com", "ramon@mail.com"};
	string nombreEstudiante[3] = {"Roberto Parra", "Ana Rodriguez", "Ramon Valdez"};
	std::string ciEstudiante[3] = {"12345678", "23456789", "34567890"};
	for (int i = 0; i < 3; i++)
	{
		iUsuario->crearEstudiante (nombreEstudiante[i], emailEstudiante[i], "", "", DtSuscripcion::ninguna, ciEstudiante[i]);
		iUsuario->agregarUsuario();
	}
	
	//Asignaturas
	string codAsignatura[3] = {"P1", "P2", "P3"};
	string nombreAsignatura[3] = {"Programacion 1", "Programacion 2", "Programacion 3"};
	bool instanciasAsignatura[3][3] = {{1,1,1}, {1,1,1}, {1,1,0}};
	for (int i = 0; i < 3; i++)
    {
		iAsignatura->crearAsignatura(nombreAsignatura[i], codAsignatura[i]);
		iAsignatura->getAsignaturaCreada()->setTeo(instanciasAsignatura[i][0]);
		iAsignatura->getAsignaturaCreada()->setPrac(instanciasAsignatura[i][1]);
		iAsignatura->getAsignaturaCreada()->setMoni(instanciasAsignatura[i][2]);
        iAsignatura->agregarAsignatura(); 
    }
	
	//Asignacion de docentes a asignaturas
	iAsignatura->asignarDocente("P1", "juan@mail.com", DtModalidad::teorico);
	iAsignatura->asignarDocente("P1", "maria@mail.com", DtModalidad::practico);
	iAsignatura->asignarDocente("P1", "jorge@mail.com", DtModalidad::monitoreo);
	
	//Inscripcion de estudiantes a asignaturas
	iAsignatura->inscribirEstudiante("P1", "roberto@mail.com" );
	iAsignatura->inscribirEstudiante("P1", "ana@mail.com" );
	iAsignatura->inscribirEstudiante("P2", "ana@mail.com" );
	iAsignatura->inscribirEstudiante("P1", "ramon@mail.com" );
	
	//Clases
	string nombreClase[6] = {"Intro", "Tema 1 ", "Tema 2", "Pra 1", "Pra 2", "06/01/20" };
	string tipoClase[6] = {"Teorico", "Teorico", "Teorico", "Practico", "Practico", "Monitoreo"};
	
	int inicioClase[6][5] = {{9,0,1,5,2020}, {9,0,3,5,2020}, {9,0,8,5,2020},{16,0,2,5,2020},{ 16,0,3,5,2020}, {16,0,4,5,2020}};
	
	string emailDocentesC[6] = {"juan@mail.com","juan@mail.com","juan@mail.com", "maria@mail.com","maria@mail.com", "jorge@mail.com"};
	
	int idClase[6] ;
	DtModalidad tipoMod;
	for (int i = 0 ; i < 6 ; i ++ ){
		DtFechaHora inicio = DtFechaHora(inicioClase[i][0], inicioClase[i][1], inicioClase[i][2], inicioClase[i][3], inicioClase[i][4]);
		if (tipoClase[i] == "Teorico"){
			tipoMod = DtModalidad::teorico;
		}
		else if(tipoClase[i] == "Practico") {
			tipoMod = DtModalidad::practico;
		}
		else {
			tipoMod = DtModalidad::monitoreo;
		}
		idClase[i] = iAsignatura->crearClase("P1", emailDocentesC[i], nombreClase[i], tipoMod, inicio) ;// Se recuerda en un atributo en controladorAsignatura
		if(i == 5)
		{
				iAsignatura->habilitarEstudiante("ana@mail.com",idClase[5], "P1") ;
				iAsignatura->habilitarEstudiante("ramon@mail.com",idClase[5], "P1") ;
		}
		iAsignatura->agregarClase("P1", emailDocentesC[i]);
	}

	//Asistencia a clases
	DtFechaHora i1 = DtFechaHora ( 9,1,1,5,2020 ) ;
	DtFechaHora f1 = DtFechaHora ( 9,21,1,5,2020 ) ;
	DtFechaHora i2 = DtFechaHora ( 9,2,1,5,2020 ) ;
	DtFechaHora f2 = DtFechaHora ( 9,32,1,5,2020 ) ;
	DtFechaHora i3 = DtFechaHora ( 9,3,1,5,2020 ) ;
	DtFechaHora f3 = DtFechaHora ( 9,43,1,5,2020 ) ;
	DtFechaHora i4 = DtFechaHora ( 16,0,4,5,2020 ) ; 
	DtFechaHora f4 = DtFechaHora ( 17,0,4,5,2020 ) ; 
	
	iReloj->setFechaHora( i1 );
	iAsignatura->seleccionClase(idClase[0], "P1");
	iAsignatura->altaAsistencia(emailEstudiante[0], idClase[0]) ;//Agrega asistencia al mapa de asistencias con el emailEst como Key
	iReloj->setFechaHora( f1 );
	iUsuario->finAsistencia(emailEstudiante[0], idClase[0]) ;//Busca en todas las asistencias la que tiene key emailEst 
	
	iReloj->setFechaHora( i2 );
	iAsignatura->seleccionClase(idClase[0], "P1");
	iAsignatura->altaAsistencia(emailEstudiante[1], idClase[0]) ;
	iReloj->setFechaHora( f2 );
	iUsuario->finAsistencia(emailEstudiante[1], idClase[0]) ;
	
	iReloj->setFechaHora( i3 );
	iAsignatura->seleccionClase(idClase[0], "P1");
	iAsignatura->altaAsistencia(emailEstudiante[2],idClase[0]) ;
	iReloj->setFechaHora( f3 );
	iUsuario->finAsistencia(emailEstudiante[2], idClase[0]) ;
	
	iReloj->setFechaHora( i4 );
	iAsignatura->seleccionClase(idClase[5], "P1");
	iAsignatura->altaAsistencia(emailEstudiante[2],idClase[5]) ;
	iReloj->setFechaHora( f4 );
	iUsuario->finAsistencia(emailEstudiante[2], idClase[5]) ;
	
	//Mensajes
	
	i1 = DtFechaHora (9,1,1,5,2020) ;
	i2 = DtFechaHora (9,2,1,5,2020) ;
	i3 = DtFechaHora (16,1,4,5,2020) ;
	i4 = DtFechaHora (9,5,1,5,2020) ;
	DtFechaHora i5 = DtFechaHora (9,6,1,5,2020) ;
	DtFechaHora i6 = DtFechaHora (9,6,1,5,2020) ;
	DtFechaHora i7 = DtFechaHora (16,5,4,5,2020) ;
	
	int id1 = cargarMensaje(i1, "juan@mail.com"   ,  idClase[0],   -1, "Bienvenidos!"); 
	int id2 = cargarMensaje(i2, "juan@mail.com"   ,  idClase[0],   -1, "Confirmen materiales por favor."); 
	int id3 = cargarMensaje(i3, "jorge@mail.com"  ,  idClase[5],   -1, "Comparto pantalla."); 
	int id4 = cargarMensaje(i4, "roberto@mail.com",  idClase[0],  id1, "Listo para aprender"); 
	          cargarMensaje(i5, "juan@mail.com"   ,  idClase[0],  id4, "Me alegro"); 
	          cargarMensaje(i6, "ana@mail.com"    ,  idClase[0],  id2, "Todo listo"); 
	          cargarMensaje(i7, "ramon@mail.com"  ,  idClase[5],  id3, "Ya la vemos"); 
	
	int finClase[6][5] = { {10,0,1,5,2020},{10,0,3,5,2020},{10,0,8,5,2020},{17,0,2,5,2020},{17,0,3,5,2020},{17,0,4,5,2020 }} ;
	for (int i = 0 ; i < 6 ; i ++ ){
		DtFechaHora fin = DtFechaHora(finClase[i][0], finClase[i][1], finClase[i][2], finClase[i][3], finClase[i][4]);
		iReloj->setFechaHora(fin);
		iClase->iniciarFinalizacion(idClase[i]);
		iClase->finalizarClase();		
	}
	//Reproduccion de clases
	
	i1 = DtFechaHora ( 9,1,12,5,2020 ) ;
	f1 = DtFechaHora (9,31,12,5,2020 ) ;
	i2 = DtFechaHora (  9,1,12,5,2020) ;
	f2 = DtFechaHora ( 9,41,12,5,2020 ) ;
	i3 = DtFechaHora(10, 1, 13, 5, 2020);
    f3 = DtFechaHora(11, 41, 13, 5, 2020);
    i4 = DtFechaHora(9, 1, 14, 5, 2020);
    f4 = DtFechaHora(9, 41, 14, 5, 2020);
	
	iReloj->setFechaHora( i1 );
	iAsignatura->seleccionClase(idClase[0], "P1");
	iAsignatura->altaReproduccion("roberto@mail.com", idClase[0]) ;//Agrega reproducicion al mapa de reproducciones con el emailEst como Key
	iReloj->setFechaHora( f1 );
	iUsuario->finReproduccion(emailEstudiante[0], idClase[0]) ;//Busca en todas las reproduccion: la que tiene key emailEst 
	
	iReloj->setFechaHora( i2 );
	iAsignatura->seleccionClase(idClase[1], "P1");
	iAsignatura->altaReproduccion(emailEstudiante[1], idClase[1]) ;
	iReloj->setFechaHora( f2 );
	iUsuario->finReproduccion(emailEstudiante[1], idClase[1]) ;
	
	iReloj->setFechaHora( i3 );
	iAsignatura->seleccionClase(idClase[1], "P1");
	iAsignatura->altaReproduccion(emailEstudiante[1],idClase[1]) ;
	iReloj->setFechaHora( f3 );
	iUsuario->finReproduccion(emailEstudiante[1], idClase[1]) ;
	
	iReloj->setFechaHora( i4 );
	iAsignatura->seleccionClase(idClase[1], "P1");
	iAsignatura->altaReproduccion(emailEstudiante[1],idClase[1]) ;
	iReloj->setFechaHora( f4 );
	iUsuario->finReproduccion(emailEstudiante[1], idClase[1]) ;
}
*/
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
										}
										else
										{
											cout<<"Se canceló el alta" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
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
								}
								else
								{
									cout<<"Se canceló el alta" ;
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
										}
										else
										{
											cout<<"Se canceló el alta" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
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
								}
								else
								{
									cout<<"Se canceló el alta" ;
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
										}
										else
										{
											cout<<"Se canceló el alta" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
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
								}
								else
								{
									cout<<"Se canceló el alta" ;
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
										}
										else
										{
											cout<<"Se canceló el alta" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
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
								}
								else
								{
									cout<<"Se canceló el alta" ;
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
										}
										else
										{
											cout<<"Se canceló el alta" ;
										}
									}
									if(i==0){ //Si salió del while (el while de i==1 y esta), porque quiso cancelar.
										cout<<"Se canceló el alta" ;
									}
							
								}		
								else if(i==0) //Si desea cancelar, sin haber reingresado el email.
								{
									cout<<"Se canceló el alta" ;
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
								}
								else
								{
									cout<<"Se canceló el alta" ;
								}
							}
					
						}

				}
				break ; 
				case 2: //Alta de Hostal
				{
					string nombreHostal ;
					string direccion ;
					int telefono ; 
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
				}
				break ;  

				case 3: //Alta de Habitación
				{
					map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						throw invalid_argument ("No hay hostales registrados") ;
					}
					else 
					{
    					int j = 1;
    					cout<< "\nLista de Hostales\n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<"Nombre: " << i->second.getNombre() << "\n";
        					j++;
    					}

						int numero ;
						int precio ;
						int capacidad ;
						string nombreH ; 
						cout<< "Ingrese el nombre del hostal al que pertenece la habitación\n" ;
						cin>> nombreH ;
						cout<< "Ingrese el numero\n" ;
						cin>> numero ;
						cout<< "Ingrese el precio\n" ; //hay que aclarar que es sin el signo de pesos?
						cin>> precio ;
						cout<< "Ingrese la capacidad\n" ;
						cin>> capacidad ;
						while(iHostal->existeHostal(nombreH) == false){
							cout<< "Hostal no registrado\n" ;
							cout<< "Ingrese nuevamente el nombre" ;
							cin>> nombreH ;
						}
						
						while(iHostal->existeHabitacion(numero, nombreH) == true){
							cout<< "Habitacion ya registrada\n" ;
							cout<< "Ingrese nuevamente el numero" ;
							cin>> numero ;
						}

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
                        }
                        else
                        {
                            cout<<"Se canceló el alta" ;
                        }
					
					}

				}
				break ;

				case 4:
           		{
					cout << "Hasta luego.\n";
                	//Asignar Empleado a Hostal
            	}
            	break;

				case 5:
           		{
					map<string, DtHostal> hostales = iHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						throw invalid_argument ("No hay hostales registrados") ;
					}
					else 
					{
    					int j = 1;
    					cout<< "Lista de Hostales /n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<"Nombre: " << i->second.getNombre() << "/n";
							cout<< "Dirección:" << i->second.getDireccion() << "/n";
							cout<< "Teléfono:" << i->second.getTelefono() << "/n";
							cout<< "Calificación Promedio:" << i->second.getCalificacionPromedio() << "/n";
        					j++;
    					}

						cout<<"Ingrese el nombre del hostal del que desea ver la información. /n" ;
						string nomhos ;
						cin>> nomhos ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "El nombre ingresado no corresponde a un hostal del sistema./n" ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema./n" ;
							cin>>nomhos ;
						}
						int dia, anio,mes, hora;
						cout<<"Ingrese fecha de entrada. /n";
						cout<<"Ingrese dia de entrada. /n";
						cin>>dia;
						cout<<"Ingrese mes de entrada. /n";
						cin>>mes;
						cout<<"Ingrese anio de entrada. /n";
						cin>>anio;
						cout<<"Ingrese hora de entrada. /n";
						cin>>hora;
						DtFechaHora fechaCheckIn = DtFechaHora(hora, dia,mes,anio);
						cout<<"Ingrese fecha de salida. /n";
						cout<<"Ingrese dia de salida. /n";
						cin>>dia;
						cout<<"Ingrese mes de salida. /n";
						cin>>mes;
						cout<<"Ingrese anio de salida. /n";
						cin>>anio;
						cout<<"Ingrese hora de salida. /n";
						cin>>hora;
						DtFechaHora fechaCheckOut = DtFechaHora(hora, dia,mes,anio);
						long int f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
						long int f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
					    while ((f2 - f1) < 0) {
							cout<<"Fecha invalida.Fecha de salida debe ser mayor a la fecha de entrada./n";
							cout<<"Ingrese fecha de entrada. /n";
							cout<<"Ingrese dia de entrada. /n";
							cin>>dia;
							cout<<"Ingrese mes de entrada. /n";
							cin>>mes;
							cout<<"Ingrese anio de entrada. /n";
							cin>>anio;
							cout<<"Ingrese hora de entrada. /n";
							cin>>hora;
							fechaCheckIn = DtFechaHora(hora, dia,mes,anio);
							cout<<"Ingrese fecha de salida. /n";
							cout<<"Ingrese dia de salida. /n";
							cin>>dia;
							cout<<"Ingrese mes de salida. /n";
							cin>>mes;
							cout<<"Ingrese anio de salida. /n";
							cin>>anio;
							cout<<"Ingrese hora de salida. /n";
							cin>>hora;
							fechaCheckOut = DtFechaHora(hora, dia,mes,anio);
							 f1 = fechaCheckIn.getHora() + fechaCheckIn.getDia()*24 + fechaCheckIn.getMes()*24*30 + fechaCheckIn.getAnio()*24*12*30;
							 f2 = fechaCheckOut.getHora() + fechaCheckOut.getDia()*24 + fechaCheckOut.getMes()*24*30 + fechaCheckOut.getAnio()*24*12*30;
						}
						bool esGrupal;
                        cout << "Ingrese 0 si la reserva sera individual o 1 si sera grupal. /n";
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
						if (j==0) esGrupal = false;
						else esGrupal = true;

						 map<int , DtHabitacion> setHabitOp = iHostal->devolverHabitacionesDisponibles(fechaCheckIn, fechaCheckOut, nomhos);

					map<int , DtHabitacion> :: iterator iR2;
					if(setHabitOp.empty())
					{
						throw invalid_argument ("No hay habitaciones disponibles") ;
					}
					else 
					{
    					int y = 1;
    					cout<< "Lista de Habitaciones disponibles /n" ;
    					for(iR2=setHabitOp.begin(); iR2 != setHabitOp.end(); iR2++){
        					cout<< y <<"Numero: " << iR2->second.getNumero() << "/n";
							y++;
						}
					}
					int numhab;
					cout<<"Ingrese el numero  de la habitacion que desea seleccionar. /n" ;
						cin>> numhab ;
						while(!cin.good())
                            {
                            cout << "ERROR NO ES UN NUMERO VALIDO\n";
                            cin.clear();
                            cin.ignore(1000,'\n');
							cout<<"Ingrese el numero  de la habitacion que desea seleccionar. /n" ;
							cin>> numhab;
                            }
						while(!iHostal->existeHabitacion(numhab,nomhos)){
							cout<< "El numero ingresado no corresponde a una habitacion del sistema." ;
							cout<<"Ingrese un numero correspondiente a una habitacion del sistema." ;
							cin>>numhab;
						}
						map<string , DtHuesped> conjuntoHuespedes = iUsuario->listarHuespedes();

						map<string , DtHuesped> :: iterator iR3;
						if(conjuntoHuespedes.empty())
						{
							throw invalid_argument ("No hay huespedes registrados. /n") ;
						}
						else 
						{
    						int y = 1;
    						cout<< "Lista de Huespedes registrados. /n" ;
    						for(iR3=conjuntoHuespedes.begin(); iR3 != conjuntoHuespedes.end(); iR3++){
        						cout<< y <<"Email: " << iR3->second.getEmail() << "/n";
								y++;
							}
						}
							cout<<"Ingrese el email del huesped el cual realiza la reserva. /n" ;
							string mailHuesped ;
							cin>> mailHuesped ;
							while(!iUsuario->existeHuesped(mailHuesped)){
								cout<< "El email ingresado no corresponde a un huesped del sistema." ;
								cout<<"Ingrese un email correspondiente a un huesped del sistema." ;
								cin>>mailHuesped;
							}
							if (esGrupal) {
								bool deseaHuespedes = true;
								std::map<std::string, Huesped> grupoHues;
								while (deseaHuespedes) {
								cout<<"Ingrese el email del huesped al cual desea agregar a la reserva. /n" ;
								string otroHuesped ;
								cin>> otroHuesped ;
								while(!iUsuario->existeHuesped(otroHuesped)){
									cout<< "El email ingresado no corresponde a un huesped del sistema." ;
									cout<<"Ingrese un email correspondiente a un huesped del sistema." ;
									cin>>otroHuesped;
								}
								// meter pa q vaya agregar al map los huespedes
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
									if (j == 0) {deseaHuespedes = false;}
									}
								}
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
							if (j == 1) iReserva->confirmarReserva();
							else iReserva->cancelarReserva();

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
					cout << "Hasta luego.\n";
                	//Registrar Estadía
            	}
            	break;

				case 8:
           		{
					cout << "Hasta luego.\n";
                	//Finalizar Estadía
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
					cout << "Hasta luego.\n";
                	//Consulta de Usuario
            	}
            	break;

				case 12 : //Consulta de Hostal
				{
					cout << "Hasta luego.\n";
					/*map<string, DtHostal> hostales = IHostal->listarHostales();
    				map<string , DtHostal> :: iterator i;
					if(hostales.empty())
					{
						throw invalid_argument ("No hay hostales registrados") ;
					}
					else 
					{
    					int j = 1;
    					cout<< "Lista de Hostales /n" ;
    					for(i=hostales.begin(); i != hostales.end(); i++){
        					cout<< j <<"Nombre: " << i->second.getNombre() << "/n";
							cout<< "Dirección:" << i->second.getDireccion() << "/n";
							cout<< "Teléfono:" << i->second.getTelefono() << "/n";
							cout<< "Calificación Promedio:" << i->second.getCalificacionPromedio() << "/n";
        					j++;
    					}

						cout<<"Ingrese el nombre del hostal del que desea ver la información." ;
						string nomhos ;
						cin>> nomhos ;
						while(!iHostal->existeHostal(nomhos)){
							cout<< "El nombre ingresado no corresponde a un hostal del sistema." ;
							cout<<"Ingrese un nombre correspondiente a un hostal del sistema." ;
							cin>>nomhos ;
						}
						DtHostal infoh = iHostal->infoHostal(nomhos) ;

						cout<< "Información básica del hostal seleccionado:/n" ;
						cout<<"Nombre: " << infohos->getNombre() << "/n";
						cout<< "Dirección:" << infohos->getDireccion() << "/n";
						cout<< "Teléfono:" << infohos->getTelefono() << "/n";
						cout<< "Calificación Promedio:" << infohos->getCalificacionPromedio() << "/n";

						set<DtCalificacion> calificaciones = IHostal->listarCalificaciones();
    					set<DtCalificacion> :: iterator i;
						if(calificaciones.empty())
						{
							throw invalid_argument ("No hay calificaciones de ese hostal") ;
						}
						else 
						{
    						int j = 1;
    						cout<< "Lista de Hostales /n" ;
    						for(i=hostales.begin(); i != hostales.end(); i++){
        						cout<< j <<"Nombre: " << i->second.getNombre() << "/n";
								cout<< "Dirección:" << i->second.getDireccion() << "/n";
								cout<< "Teléfono:" << i->second.getTelefono() << "/n";
								cout<< "Calificación Promedio:" << i->second.getCalificacionPromedio() << "/n";
        						j++;
    						}
						
						} 
					}*/
				}
				break ; 
				case 13:
           		{
					cout << "Hasta luego.\n";
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
				case 0:
           		{
                	cout << "Hasta luego.\n";
                	bandera = true;
            	}
            	break;
            	
				default:
                cout << "Ingrese un número del 0 al 20\n";   
		

        //if(c == "1")
        //{}	
        	/*while(!termino && !retroceder)
        	{
				cout << "\nElija la opción.\n\n";
	        	cout << "1. Alta de usuario\n";
	        	cout << "2. Alta de asignatura\n";
	        	cout << "3. Asignar docente a una asignatura\n";
	        	cout << "4. Tiempo de dictado de clases\n";
	        	cout << "5. Eliminar asignatura\n";
	        	cout << "6. Salir\n";
				cout << "0. Retroceder\n\n";
	        	cout << "Opción:";
	        	cin >> c;

	        	if(c == "1")//Administrador->Alta de usuario
	        	{
					altaUsuario(iUsuario);
	        	}
	        	else if(c == "2")//Administrador->Alta de asignatura
	        	{
	        		altaAsignatura(iAsignatura);
	        	}
	        	else if(c == "3")//Administrador->Asignar docente a una asignatura
	        	{
					asignarDocenteAAsignatura(iAsignatura);
	        	}
	        	else if(c == "4")//Administrador->Tiempo de dictado de clases
	        	{
					tiempoDeDictadoDeClases(iAsignatura);
	        	}
	        	else if(c == "5")//Administrador->Eliminar asignatura
	        	{
					eliminacionAsignatura(iAsignatura);
	        	}
	        	else if(c == "6")//Administrador->Salir
	        	{
	        		cout << "Hasta luego.\n";
	          	    termino = true;
	        	}
				else if(c == "0")
				{
					retroceder = true;
				}
	        	else//Opcion inexistente
	        	{
	        		cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        		cout << "Error, debe ingresar numero entre 0 y 6\n";
	        	}
        	}
        }
        else if(c == "2")//Docente
        {	
			try
			{
				if(iUsuario->listarDocentes().empty())
					throw invalid_argument ("no hay docentes en el sistema.");
				
				string emailDocente;
				cout << "\nIngrese su email:\n";
				cin >> emailDocente;
				
				while(!(iUsuario->existeDoc(emailDocente)))
				{
					cout << "\nDebe ingresar el email de un docente que esté en el sistema\n";
					cout << "Ingréselo ahora:\n";
					cin >> emailDocente;
				}
				while (!termino && !retroceder)
				{
					cout << "\nElija la opción.\n\n";
					cout << "1. Inicio de clase\n";
					cout << "2. Finalizacion de clase\n";
					cout << "3. Enviar mensaje\n";
					cout << "4. Tiempo de asistencia a clase\n";
					cout << "5. Consultar notificaciones\n";
					cout << "6. Suscribir a notificaciones\n";
					cout << "7. Salir\n";
					cout << "0. Retroceder\n\n";
					cout << "Opción:";
					cin >> c;

					if(c == "1")//Docente->inicio de clase
					{
						inicioDeClase(iAsignatura, emailDocente);
					}
					else if(c == "2")//Docente->Finalizacion de clase
					{
						finalizacionDeClase(iClase, emailDocente);
					}
					else if(c == "3")//Docente->Enviar mensaje
					{
						envioDeMensaje(iClase, emailDocente);
					}
					else if(c == "4")//Docente->Tiempo de asistencia a clase
					{
						tiempoDeAsistenciaAClase(iAsignatura, emailDocente);
					}
					else if(c == "5")//Docente->Consultar notificaciones
					{
						consultaNotificaciones(iUsuario, emailDocente);
					}
					else if(c == "6")//Docente->Suscribir a notificaciones
					{
						subscribir(iUsuario, emailDocente);
					}
					else if(c == "7")//Docente->Salir
					{
						cout << "Hasta luego.\n";
						termino = true;
					}
					else if(c == "0")
					{
						retroceder = true;
					}
					else//Opcion inexistente
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Error, debe ingresar numero entre 0 y 7\n";
					}
				}
			}catch (const logic_error& le){
				cout << "\nError: " << le.what() << "\n";
			}				
        }
        else if(c == "3")//Estudiante
        {
			try
			{
				if(iUsuario->listarDocentes().empty())
					throw invalid_argument ("no hay estudiantes en el sistema.");
				
				string emailEstudiante;
				cout << "\nIngrese su email:\n";
				cin >> emailEstudiante;
				while(!(iUsuario->existeEst(emailEstudiante)))
				{
					cout << "\nDebe ingresar el email de un docente que esté en el sistema\n";
					cout << "Ingréselo ahora:\n";
					cin >> emailEstudiante;
				}
				while (!termino && !retroceder)
				{
					cout << "\nElija la opción.\n\n";
					cout << "1. Inscripcion a asignatura\n";
					cout << "2. Enviar mensaje\n";
					cout << "3. Asistir a clase en vivo\n";
					cout << "4. Finalizacion de asistencia a clase en vivo\n";
					cout << "5. Consultar notificaciones\n";
					cout << "6. Suscribir a notificaciones\n";
					cout << "7. Salir\n";
					cout << "0. Retroceder\n\n";
					cout << "Opción:";
					cin >> c;

					if(c == "1")//Estudiante->Inscripcion a asignatura
					{
						inscripcionAAsignatura(iAsignatura, emailEstudiante);
					}
					else if(c == "2")//Estudiante->Enviar mensaje
					{
						envioDeMensaje(iClase, emailEstudiante);
					}
					else if(c == "3")//Estudiante->Asistir a clase en vivo
					{
						asistenciaAClaseEnVivo(iAsignatura, emailEstudiante);
					}
					else if(c == "4")//Estudiante->Reproducir clase en diferido
					{
						finalizacionDeAsistenciaAClaseEnVivo(iUsuario, emailEstudiante);
					}
					else if(c == "5")//Estudiante->Consultar notificaciones
					{
						consultaNotificaciones(iUsuario, emailEstudiante);
					}
					else if(c == "6")//Estudiante->Suscribir a notificaciones
					{
						subscribir(iUsuario, emailEstudiante);	        	
					}
					else if(c == "7")//Estudiante->Salir
					{
						cout << "Hasta luego.\n";
						termino = true;
					}
					else if(c == "0")
					{
						retroceder = true;
					}
					else//Opcion inexistente
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Error, debe ingresar numero entre 0 y 7\n";
					}
				}	
			}catch (const logic_error& le){
					cout << "\nError: " << le.what() << "\n";
			}					
        }
        else if(c == "4")//Carga de datos
        {
			cargarDatosPrueba(iAsignatura, iClase, iUsuario, iReloj);
        }
		else if(c == "5")
		{
			cout << "\nHora actual: " << iReloj->getFechaHora() << "\n";
		}
		else if(c == "6")
		{	
			int hora;
			int min;
			int dia;
			int mes;
			int anio;
			cout << "Ingrese fecha y hora: \n";
			cout << "Hora: ";
			cin >> hora;
			cout << "Minutos: ";
			cin >> min;
			cout << "Dia: ";
			cin >> dia;
			cout << "Mes: ";
			cin >> mes;
			cout << "Año[aaaa]: ";
			cin >> anio;
			try{
			DtFechaHora horaActual = DtFechaHora(hora, min, dia, mes, anio);
			iReloj->setFechaHora(horaActual);
			}catch (const invalid_argument& ia){
				cout << "\nError: " << ia.what() << "\n";
			}
		}
        else if(c == "7")//Salir
        {
        	cout << "Hasta luego.\n";
            termino = true;
        }
        else
        {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cout << "Error, debe ingresar numero entre 1 y 7\n";
        }
	}*/
	}
	delete iHostal;
	delete iReserva;
	delete iUsuario;
	delete f;
	return 0;
}
}

