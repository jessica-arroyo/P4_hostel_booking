#ifndef DTHUESPED_H
#define DTHUESPED_H
#include <string>
#include <iostream>
using namespace std;

class DtHuesped: DtHuesped {
    private:
    bool esFinger;

    public:
    DtHuesped();
    ~DtHuesped();
    DtHuesped(string , string , string, bool) ;
    bool getEsFinger() ;
};

#endif
