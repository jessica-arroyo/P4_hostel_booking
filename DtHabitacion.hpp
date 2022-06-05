#ifndef DTHABITACION_H
#define DTHABITACION_H

class DtHabitacion {
    private:
      int codigo ;
      int precio ;
      int capacidad ;
  
    public:
      DtHabitacion(int codigo, int precio, int capacidad) ;
      //DtHabitacion() el destructor. No encuentro el símbolo de ñoqui para ponerle.
      int getCodigo();
      int getPrecio();
      int getCapacidad();
};


#endif
