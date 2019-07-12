#include <stdio.h>
#include "Fila.h"

void limpaVisitados(int *visitados, int tam);

void depthFirstSearch(int i, int matrix[][9], int *visit, int tam);

void breadthFirstSearch(int i, int matrix[][9], TipoDFila* Fila, int *visit, int tam);