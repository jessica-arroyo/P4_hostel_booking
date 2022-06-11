#include ../include/AltaHabitacion.hpp
#include ../include/IHostal.hpp

void altaHabitacion(IHostal* iHostal){
    
    std::map<std::string, DtHostal> hostales = IHostal->listarHostales();
    std::map<std::string , DtHostal> :: iterator i;
    int j = 1;
    cout<< "Lista de Hostales /n"
    for(i=hostales.begin(); i != hostales.end(); i++){
        cout<< j <<": " << i->second.getNombre() << "/n";
        j++;
    }

    string numh ;
     cout<<"Ingrese el número de habitación" ;
     cin>> numh ;
}