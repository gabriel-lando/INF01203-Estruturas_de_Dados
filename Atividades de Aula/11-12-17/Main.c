#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

#define TAM 6

int main(){
    int matrix[TAM][TAM] = {{0, 1, 0, 0, 0, 1},
                            {1, 0, 1, 1, 0, 0},
                            {0, 1, 0, 1, 1, 0},
                            {0, 1, 1, 0, 1, 1},
                            {0, 0, 1, 1, 0, 1},
                            {1, 0, 0, 1, 1, 0}};
    int visitados[TAM] = {0};
    int cor[TAM] = {0};
    TipoDFila *Fila;

    Fila = InicializaFila(Fila);

    printf("DFS:");
    DFS(3,matrix,visitados,TAM,cor);

    LimpaVisitados(visitados, TAM);

    printf("\n\n\n");

    LimpaCor(cor,TAM);


    printf("BFS:");

    BFS(3,matrix,Fila,visitados,TAM,cor);

    LimpaVisitados(visitados, TAM);

    printf("\n\n\n");







    return 0;
}
