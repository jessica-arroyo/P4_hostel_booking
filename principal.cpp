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
#include "include/subscribir.hpp"
#include <iostream>
#include <limits>
#include <ios>

using namespace std;

int cargarMensaje(DtFechaHora fecha, string email, int idClase, int aResponder, string texto){ // pasar -1 al aResponder para no resp.
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

int main()
{
	
	Fabrica *f = NULL;
	f = Fabrica::getInstancia();
	IAsignatura *iAsignatura = f->getIAsignatura();
	IUsuario *iUsuario = f->getIUsuario();
	IClase *iClase = f->getIClase();
	IReloj *iReloj = f->getIReloj();
	DtFechaHora horaActual = DtFechaHora(0, 0, 1, 1, 2020);
	iReloj->setFechaHora(horaActual);


	bool termino = false;
	while (!termino)
	{
		bool retroceder = false;
		string c;
		cout << "\nBienvenido. Elija la opción.\n\n";
        cout << "1. Administrador\n";
        cout << "2. Docente\n";
        cout << "3. Estudiante\n";
        cout << "4. Cargar datos de prueba\n";
		cout << "5. Consultar hora actual\n";
		cout << "6. Cambiar hora\n";
        cout << "7. Salir\n\n";
        cout << "Opción:";
        cin >> c;

        if(c == "1")//Administrador
        {	
        	while(!termino && !retroceder)
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
	}
	delete iClase;
	delete iAsignatura;
	delete iUsuario;
	delete f;
	return 0;
}
