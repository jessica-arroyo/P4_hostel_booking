#ifndef HUESPED_H
#define HUESPED_H
#include <string>
#include <iostream>
#include "usuario.hpp"
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
};
#endif
