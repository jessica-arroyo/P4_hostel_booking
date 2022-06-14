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
    Usuario(string nombre, string email, string password) ;
    string getNombre() ;
    string getEmail() ;
    string getPassword() ;
    void setNombre(string nombre);
    void setEmail(string email);
    void setPassword(string password);
    DtUsuario getDataUs(); //por lo que vi, cuando difiere la info que tenés que mandar según 
                            //si sea de una subclase o de otra, se pone la operación en la clase genérica como virtual y =0.
                            //y creo que en ese caso, el destructor de usuario va también virtual con =0.
};
#endif
