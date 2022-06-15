#ifndef DTHOSTAL_H
#define DTHOSTAL_H

#include <iostream>
using namespace std;

class DtHostal {
    private:
      string nombre ;
      string direccion ;
      int telefono ;
      float calificacionPromedio ;
  
    public:
      DtHostal(string nom, string direc, int tel, float calificacionPromedio) ;
      DtHostal();
	  ~DtHostal(); 
      string getNombre() ;
      string getDireccion() ;
      int getTelefono();
      float getCalificacionPromedio() ;
};


#endif
