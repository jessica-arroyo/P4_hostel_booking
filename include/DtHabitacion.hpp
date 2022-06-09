#ifndef DTHABITACION_H
#define DTHABITACION_H

class DtHabitacion {
    private:
      int numero ;
      int precio ;
      int capacidad ;
  
    public:
      DtHabitacion(int numero, int precio, int capacidad) ;
      ~DtHabitacion();
      int getNumero();
      int getPrecio();
      int getCapacidad();
};


#endif
