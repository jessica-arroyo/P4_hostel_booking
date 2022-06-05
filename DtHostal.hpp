#ifndef DTHOSTAL_H
#define DTHOSTAL_H

class DtHostal {
    private:
      string nombre ;
      string direccion ;
      int telefono ;
      int calificacionPromedio ;
  
    public:
      DtHostal(string nom, string direc, int tel, string calProm) ;
      //DtHostal() el destructor. No encuentro el símbolo de ñoqui para ponerle.
      string getNombre() ;
      string getDireccion() ;
      int getTelefono();
      int getCalPromedio() ;
};


#endif
