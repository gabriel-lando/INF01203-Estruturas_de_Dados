#include "Grafo.h"

void limpaVisitados(int *visitados, int tam){
	int i;
	for (i = 0; i < tam; ++i)
		visitados[i] = 0;
}

void depthFirstSearch(int i, int matrix[][9], int *visit, int tam)
{
	int j;
	printf("%d  ",i);
	visit[i]=1;

	for (j = 1; j < tam; j++)
		if(!(visit[j]) && matrix[i][j]==1)
			depthFirstSearch(j, matrix, visit, tam);
}

void breadthFirstSearch(int i, int matrix[][9], TipoDFila* Fila, int *visit, int tam){
	int j;
	visit[i] = 1;
	InserirFila(&Fila,i);

	while(!VaziaFila(Fila)){

		RemoverFila(&Fila,&i);
		printf("%d  ", i);

		for(j = 1; j < tam; j++)
			if(!visit[j] && matrix[i][j]==1){
				InserirFila(&Fila,j);
				visit[j] = 1;
			}
	}
}