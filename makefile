#el makefile tiene dos comandos: all y testing, testing no lo prueben por ahora.

.PHONY: all compilar clean ejecutar

CC = g++
CCFLAGS = -Wall -g -lstdc++
# -DNDEBUG
#descomentar la linea anterior para sacar los assert

HDIR    = include
CPPDIR  = src
ODIR    = obj
#TESTDIR = test

PRINCIPAL=principal
#TESTER=tester
FABRICA=Fabrica

MODULOS = $(FABRICA) Calificacion ControladorHostal ControladorReserva ControladorUsuario DtCalificacion \
		  DtEmpleado DtEstadia DtFechaHora DtHabitacion DtHostal DtHuesped DtNotificaion DtReserva DtReservaGrupal \
		  DtReservaIndividual DtUsuario Empleado Estadia Fecha Habitacion Hostal Huesped IFecha IHostal \
		  IReserva IUsuario Reserva ReservaGrupal ReservaIndividual Usuario

HPPS = $(MODULOS:%=$(HDIR)/%.hpp)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

all: $(PRINCIPAL)

compilar: $(OS)

ejecutar: $(PRINCIPAL)
	./$(PRINCIPAL)

clean: @-rm $(ODIR)/*.o 2>/dev/null || : ;\
	rm $(PRINCIPAL) 2>/dev/null || : ;\
	rm test/*.sal 2>/dev/null || : ;\
	echo Limpio.
	

$(PRINCIPAL): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@
	
$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).cpp 
	$(CC) $(CCFLAGS) -c $^ -o $@

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.hpp
	-$(CC) $(CCFLAGS) -c $< -o $@
