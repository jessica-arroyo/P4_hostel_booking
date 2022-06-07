#ifndef DTHUESPED_H
#define DTHUESPED_H
#include <string>
#include <iostream>
using namespace std;

class DtHuesped {
    private:
    string nombre;
    string email;
    bool esFinger;

    public:
    DtHuesped();
    ~DtHuesped();
    DtHuesped(string , string , bool) ;

    string getNombre() ;
    string getEmail() ;
    bool getEsFinger() ;
};

#endif
