#include "Grafo.h"

void DFS(int i, int mat[][6], int visited[], int tam, int cor[]){
    int j = 0;
    int colora = 1;


    visited[i]=1;
    while(j<tam){
        if(visited[j]&&mat[i][j]&&cor[j]==colora){
            j = 0;
            colora++;
        }
        cor[i] = colora;
        j++;
    }

    printf("\n%d COR: %d", i+1, cor[i]);

    for(j=0;j<tam;j++)
       if(!visited[j]&&mat[i][j]==1)
            DFS(j,mat,visited,tam,cor);
}

void LimpaVisitados(int visited[], int tam){
    int i;
    for(i = 0; i<tam; i++){
        visited[i] = 0;
    }
}

void LimpaCor(int cor[], int tam){
    int i;
    for(i = 0; i<tam; i++){
        cor[i] = 0;
    }
}

void BFS(int i, int mat[][6], TipoDFila* Fila, int visited[], int tam, int cor[]){
    int j;
    int colora = 1;
    visited[i] = 1;
    InserirFila(&Fila,i);

    while(!VaziaFila(Fila)){
        j = 0;
        colora = 1;

        RemoverFila(&Fila,&i);

        while(j<tam){
            if(visited[j]&&mat[i][j]&&cor[j]==colora){
                j = 0;
                colora++;
            }
            cor[i] = colora;
            j++;
        }
        printf("\n%d COR: %d", i+1, cor[i]);

        for(j=0;j<tam;j++)
            if(!visited[j]&&mat[i][j]==1){
                InserirFila(&Fila,j);
                visited[j] = 1;
            }

    }


}


