#ifndef HUESPED_H
#define HUESPED_H

#include "Usuario.hpp"
#include "DtUsuario.hpp"
#include "DtHuesped.hpp"
#include "Huesped.hpp"
#include "DtEstadia.hpp"

#include <string>
#include <iostream>
#include <map>

class Estadia ;
class Hostal ;

using namespace std;

class Huesped: public Usuario  {
    
    private:
    bool esFinger;
    Estadia *estadia ;
    map<string , Hostal *> hostalesHuesped; //hostales con los que está relacionado el huesped

    //la estadia es una sola por huesped. Dos estadías creo que no se solapan.
    public:
    Huesped();
    ~Huesped();
    Huesped(string nombre, string email, string password, bool esFinger) ;
    bool getEsFinger() ;
    void setEsFinger(bool esFinger);
    Estadia* getEstadia() ;
    void setEstadia(Estadia *estadia) ;
    map<string , Hostal *> getHostalesHuesped() ;
    void anadirHostalAlHuesped(Hostal *hostal) ; 
    DtHuesped getDtHuesped();
    //void accesoHuesped(string);
    //void obtenerEstadiasHuesped();
    //void accederEstadia(DtEstadia); // como pongo DtEstadia aca la tengo que incluir?
    
};

#include "Estadia.hpp"
#include "Hostal.hpp"

#endif
