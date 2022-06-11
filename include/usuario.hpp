#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include "DtUsuario.hpp"

using namespace std;

class Usuario  {
    
    private:
    string nombre;
    string email;
    string password;
    
    public:
    Usuario();
    ~Usuario();
    Usuario(string , string, string) ;
    string getNombre() ;
    string getEmail() ;
    string getCargo() ;
    void setNombre(string );
    void setEmail(string);
    void setCargo(string);
    DtUsuario *getDataUs(); 
};
#endif
