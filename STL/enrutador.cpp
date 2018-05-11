#include "enrutador.h"

Enrutador::Enrutador(string nombre)
{
    this->nombreNodo = nombre;
}

void Enrutador::agregarNodoCercano(Enrutador nodo, int costo)
{
    nodosCercanos.push_back(nodo);
    Costos.push_back(costo);
}

void Enrutador::imprimirNodosCercano()
{
    cout << "Nodos cercanos al nodo: " << this->nombreNodo << endl;
    for(int i=0;i<nodosCercanos.size();i++)
        cout << nodosCercanos[i].nombreNodo << '\t' << Costos[i] << endl;
}
