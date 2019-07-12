#include "Fila.h"
#include "Grafo.h"

int main()
{
	int matrix[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 1, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 1, 0, 0, 0},
						{0, 0, 0, 0, 0, 1, 1, 0, 1},
						{0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 1, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 1, 0}};
	int visitados[9] = {0};

	printf("Depth First Search:\n");

	depthFirstSearch(1, matrix, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");
	depthFirstSearch(3, matrix, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");
	depthFirstSearch(5, matrix, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");

	TipoDFila* Fila;
	Fila = InicializaFila(Fila);

	printf("\nBreadth First Search:\n");

	breadthFirstSearch(1, matrix, Fila, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");

	breadthFirstSearch(3, matrix, Fila, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");

	breadthFirstSearch(5, matrix, Fila, visitados, 9);
	limpaVisitados(visitados, 9);
	printf("\n");

	return 0;
}