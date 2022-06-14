#ifndef DTHUESPED_H
#define DTHUESPED_H
#include <string>
#include <iostream>
using namespace std;

class DtHuesped: public DtUsuario {
    private:
    bool esFinger;

    public:
    DtHuesped();
    ~DtHuesped();
    DtHuesped(string nombre, string email, string password, bool esFinger) ;
    bool getEsFinger() ;
};

#endif
