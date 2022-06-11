#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>
#include <iostream>
using namespace std;

class DtUsuario {
    private:
    string nombre;
    string email;
    string password;

    public:
    DtUsuario();
    ~DtUsuario();
    DtUsuario(string , string , string);

    string getNombre();
    string getEmail();
    string getPassword();
};

#endif
