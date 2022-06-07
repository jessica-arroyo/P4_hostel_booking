#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "Hostal.hpp"
#include "DtHostal.hpp"
#include "IHostal.hpp"
#include <map>
#include <iostream>

class ControladorHostal: public: IHostal {
    private:
        ControladorHostal() ;
        static ControladorHostal *_instancia ;
        std::map<string,Hostal*> SetHostales ;
    public:
        ControladorHostal() ;
  }
