void altaHostal(DtHostal hostal){// es un IHostal* iHostal el parámetro.
    string nomh = hostal->getNombre() ;
    map<string, Hostal*>::iterator h = SetHostales.find(nomh) ; 
    if(h!= SetHostales.end()){
        throw exception "Hostal ya registrado" ;
    }
    else{
        string direc = hostal->getDireccion() ;
        int tel = hostal->getTelefono() ;
        int calProm = hostal->getCalificacionPromedio() ;
        
      iHostal->crearAsignatura(nomh,direc,tel,calProm) ; //en esta función se crea la asignatura en el ControladorAsignatura 
      //y se la guarda en un puntero a una asignatura llamado asignaturacreada.
      iHostal->add() //Luego en esta función, también en ControladorAsignatura, se añade asignaturacreada a la coleccion de Asignaturas.
        
    }
          
}
