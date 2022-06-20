#ifndef DTHOSTAL_H
#define DTHOSTAL_H

#include <iostream>
using namespace std;

class DtHostal {
    private:
      string nombre ;
      string direccion ;
      string telefono ;
      float calificacionPromedio ;
  
    public:
      DtHostal(string nom, string direc, string tel, float calificacionPromedio) ;
      DtHostal();
	  ~DtHostal(); 
      string getNombre() ;
      string getDireccion() ;
      string getTelefono();
      float getCalificacionPromedio() ;
};


#endif
