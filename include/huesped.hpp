#ifndef HUESPED_H
#define HUESPED_H
#include <string>
#include <iostream>
#include "usuario.hpp"
#include "DtHuesped.hpp"
#include "DtEstadia.hpp"

using namespace std;

class Huesped: public Usuario  {
    
    private:
    bool esFinger;
    
    public:
    Huesped();
    ~Huesped();
    Huesped(string , string, string, bool) ;
    bool getEsFinger() ;
    void setEsFinger(bool);
    DtHuesped *getDtHuesped();
    void accesoHuesped(string);
    void obtenerEstadiasHuesped();
    void accederEstadia(DtEstadia); // como pongo DtEstadia aca la tengo que incluir?
    
};
#endif
