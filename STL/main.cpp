#include <iostream>
#include "enrutador.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct integer{
    int value;
    unsigned short int infinity;
}
number;

number graph [100][100];
int x, nodesNumber;

void getGraph(){
    FILE *InputFile;
    char help[250], *token;
    InputFile=fopen("graph.txt","r");
    nodesNumber=0;
    int col=0;
    while (!feof(InputFile)){

        fgets(help, 255, InputFile);
        token=strtok(help, ",");
        col=0;

        while(token!=NULL){

            if (strcmp(token, "i")==0 || strcmp(token,"i\n")==0){
                graph[nodesNumber][col].infinity=1;
            }

            else{
                graph[nodesNumber][col].infinity=0;
                graph[nodesNumber][col].value=atoi(token);
            }

            token=strtok(NULL, ",");
            col++;
        }
        nodesNumber++;
    }
}
int printgraph(){
    ofstream file("matriz.txt");
    char fila='A';
    int cont=1;

    for (int i =0; i<nodesNumber; i++){
        cout<<fila;
        for (int j=0; j<nodesNumber; j++){
            if (graph[i][j].infinity==1){
                cout<<" i";
            }
            else{
                printf(" %d", graph[i][j].value);
                file<<graph[i][j].value<<',';
            }
        }
        fila++;
        cont++;
        cout<<endl;
        file<<endl;
    }
    return cont;
}
void floyd_warshall(){

    cout<<"Tabla de enrutamiento de menor costo: "<<endl;
    cout<<"  ";

    int b1,b2,s;
    char letra='A';
    for (int k=0; k<nodesNumber; k++){
        for (int i=0; i<nodesNumber; i++){
            for (int j=0; j<nodesNumber; j++){
                b1=((j!=k) && (i!=k));

                if (b1){

                    b2=(graph[i][k].infinity==0) && (graph[k][j].infinity==0);
                    if (b2){
                        s=graph[i][k].value + graph[k][j].value;

                        if(graph[i][j].infinity==1 || s<graph[i][j].value){
                            graph[i][j].value=s;
                            graph[i][j].infinity=0;
                        }
                    }
                }
            }

        }
        cout<<letra<<' ';
        letra++;
    }
    cout<<endl;
    printgraph();
    cout<<endl;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl;
}
void pausa();
void enrutadorcre(){
Enrutador primer("A");
Enrutador segundo("B");
Enrutador tercero("C");
Enrutador cuarto("D");
primer.agregarNodoCercano(segundo, 4);
primer.agregarNodoCercano(tercero, 5);

primer.imprimirNodosCercano();

primer.agregarNodoCercano(cuarto, 10);
primer.imprimirNodosCercano();
}

int main()
{
    bool bandera=false;
    char tecla;

    do
    {
        system("cls");
        cin.clear();
        cout << "Simulacion red de enrutadores" << endl;
        cout << "-----------------------------" << endl << endl;
        cout << "\t1. Entrar a editor de enrutadores." << endl;
        cout << "\t2. Cargar la red desde un archivo." << endl;
        cout << "\t3. Salir" << endl << endl;
        cout << "Elije una opcion: ";

        cin >> tecla;

        switch(tecla)
        {
            case '1':
                system("cls");
                cout << "Has elejido entrar a la red de enturadores.\n";
                enrutadorcre();
                pausa();
                break;

            case '2':
                system("cls");
                cout << "Has elejido cargar la red desde un archivo.\n";
                    getGraph();
                    printgraph();
                    floyd_warshall();
                pausa();
                break;

            case '3':
                bandera=true;
                exit(1);
                break;

            default:
                system("cls");
                cout << "Opcion no valida.\a\n";
                pausa();
                break;
        }
    }while(bandera!=true);

    return 0;
}

void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}

