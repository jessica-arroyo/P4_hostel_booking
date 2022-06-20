#ifndef DTFECHAHORA_H
#define DTFECHAHORA_H

class DtFechaHora {
    private:
    int hora, dia, mes, anio;

    public:
    DtFechaHora();
    DtFechaHora(int, int , int , int);
    int getHora();
    int getDia();
    int getMes();
    int getAnio();
    ~DtFechaHora();
};
#endif 