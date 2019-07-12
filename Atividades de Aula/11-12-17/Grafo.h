#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void DFS(int i, int mat[][6], int visited[], int tam, int cor[]);

void LimpaVisitados(int visited[], int tam);

void LimpaCor(int cor[], int tam);

void BFS(int i, int mat[][6], TipoDFila* Fila, int visited[], int tam, int cor[]);
