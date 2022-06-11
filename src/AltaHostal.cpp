void altaHostal(IHostal* iHostal){// es un IHostal* iHostal el parámetro.
   
    //le pide el nombre al usuario. Corregir eso.
     string nomh ;
     cout<<"Ingrese el nombre del Hostal a crear" ;
     cin>> nomh ;
    //esto iria en bool existeHostal(std::string nomH) 
    //return (SetHostales.find(nomh) != SetHostales.end()) ;
    if(iHostal->existeHostal(std::string nomH)==true){
         cout<<"Hostal ya registrado");
         cin>>nomh ;
    }
    else{
         cout<<"Ingrese la direccion" ;
         string direc ;
         cin>> direc ;
         cout<<"Ingrese el telefono" ;
         int tel ;
         cin>> tel ;
         int calProm = 0 ;
         iHostal->crearHostal(nomh,direc,tel,calProm) ; //en esta función se crea el Hostal en el ControladorHostal. 
      //y se la guarda en un puntero a un hostal llamado hostalcreado.
      //Así: this->hostalCreado = new Hostal(nomh,direc,tel,calProm);
      //Poner que ControladorHostal tenga en private un campo Hostal* hostalCreado ;
      iHostal->addHostal() //Luego en esta función, también en ControladorHostal, se añade hostalcreado a la coleccion de Hostales.
      //Así: this->SetHostales.insert(make_pair(hostalCreado->getNombre(), hostalCreado));
	         //this->hostalCreado = NULL;
        
    }
          
}
