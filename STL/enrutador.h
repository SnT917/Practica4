#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <vector>
#include <iostream>

using namespace std;

class Enrutador
{
public:
    Enrutador(string nombre);
    string nombreNodo;
    vector<Enrutador> nodosCercanos;
    vector<int> Costos;
    void agregarNodoCercano(Enrutador nodo, int costo);
    void imprimirNodosCercano();
};

#endif // ENRUTADOR_H
