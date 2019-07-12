/****************************************************

	BIBLIOTECA COM FUNÇÕES PARA A ABP


	Aqui estão incluidas as seguintes funções:
	-> insereMorseABP()
		Função chamada na Main, que irá processar
		o arquivo com a tabela Morse e irá criar
		a árvore ABP.
	-> inserirNodoABP()
		Função auxiliar na criação da árvore. Ela
		é responsável por inserir os nós.


****************************************************/

#include "Arvores.h"

Nodo* insereMorseABP(Nodo *nodo, char *morse, int *comp){ 		//Funcao de inserção na árvore
	char aux[TAM], cod[TAM], carac; 							//Variaveis auxiliares

	FILE *arq;

	if(!(arq = fopen(morse, "r"))){ 			//Testa se o arquivo da tabela morse pode ser lido
		printf("Erro na leitura da tabela Morse!\n");
		exit(1);
	}

	while(!feof(arq)){ 							//Le o arquivo e cria uma tabela com ele
		fgets(aux, TAM, arq);
		sscanf(aux, " %c %s", &carac, cod);
		carac = toupper(carac);
		nodo = inserirNodoABP(nodo, carac, cod, comp); 	//Chama essa função para a inserção dos nodos
	}

	fclose(arq);

	return nodo;
}

Nodo* inserirNodoABP(Nodo *nodo, char carac, char *cod, int *comp){		//Função de inserção de nodo
	if(!nodo){		//Testa se o nodo existe, se nao existir, insere a palavra como o nodo para onde está apontando a árvore
		nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->dado.letra = carac;
		strcpy(nodo->dado.morse, cod);
		nodo->esq = NULL;
		nodo->dir = NULL;
	}
	else{
		(*comp)++;
		if(carac < nodo->dado.letra)	//Se existir o nodo, calcula para que lado deve inserir o proximo elemento
			nodo->esq = inserirNodoABP(nodo->esq, carac, cod, comp);
		else
			nodo->dir = inserirNodoABP(nodo->dir, carac, cod, comp);
	}
	
	return nodo;
}