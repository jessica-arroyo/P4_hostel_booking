void altaHostal(DtHostal hostal){// es un IHostal* iHostal el parámetro.
    string nomh = hostal->getNombre() ;
    //le pide el nombre al usuario. Corregir eso.
     ;
    //esto iria en bool existeHostal(std::string nomH) 
    //map<string, Hostal*>::iterator h = SetHostales.find(nomh) ; 
    //if(h!= SetHostales.end()){
        //throw exception "Hostal ya registrado" ;
    //}
    if(iHostal->existeHostal(std::string nomH)==true){
         throw exception "Hostal ya registrado" ;
    }
    else{
        //le pide los otros datos.Corregir eso.
        string direc = hostal->getDireccion() ;
        int tel = hostal->getTelefono() ;
        int calProm = hostal->getCalificacionPromedio() ;
        
      iHostal->crearHostal(nomh,direc,tel,calProm) ; //en esta función se crea el Hostal en el ControladorHostal. 
      //y se la guarda en un puntero a un hostal llamado hostalcreado.
      iHostal->add() //Luego en esta función, también en ControladorHostal, se añade hostalcreado a la coleccion de Hostales.
        
    }
          
}
