/****************************************************

	BIBLIOTECA COM FUNÇÕES PARA A AVL


	Aqui estão incluidas as seguintes funções:
	-> insereMorseAVL()
		Função chamada na Main, que irá processar
		o arquivo com a tabela Morse e irá criar
		a árvore ABP.
	-> InsereAVL()
		Função auxiliar na criação da árvore. Ela
		é responsável por inserir os nós.
	-> rotacao_direita()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao simples
		a direita.
	-> rotacao_esquerda()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao simples
		a esquerda.
	-> rotacao_dupla_direita()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao dupla
		a direita.
	-> rotacao_dupla_esquerda()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao dupla
		a esquerda.
	-> Caso1()
		Função auxiliar na criação da árvore. Ela
		realiza o Caso 1.
	-> Caso2()
		Função auxiliar na criação da árvore. Ela
		realiza o Caso 2.


****************************************************/

#include "Arvores.h"

Nodo* insereMorseAVL(Nodo *nodo, char *morse, int *comp){ 		//Funcao de inserção na árvore
	char aux[TAM], cod[TAM], carac;   		//variaveis auxiliares
	int ok = 0;

	FILE *arq;

	if(!(arq = fopen(morse, "r"))){ 		//Testa se a tabela pode ser lida
		printf("Erro na leitura da tabela Morse!\n");
		exit(1);
	}

	while(!feof(arq)){ 			//Gera a arvore avl de acordo com a tabela
		ok = 0;
		fgets(aux, TAM, arq);  	//Para isso, copia uma string do arquivo texto
		sscanf(aux, " %c %s", &carac, cod); 	//e separa a letra do código, passando os dados para a função abaixo
		carac = toupper(carac);
		nodo = InsereAVL(nodo, carac, cod, comp, &ok);  //Função que insere os dados da tabela na arvore
	}

	fclose(arq); 	//Após isso, fecha o arquivo

	return nodo;
}
	
Nodo* InsereAVL(Nodo *nodo, char carac, char *cod, int *comp, int *ok){  	//Função de inserção na AVL
	(*comp)+=2;
	if (!nodo) { 		//Se o nodo não existir, insere o dado aqui
		(*comp)--;
		nodo = (Nodo*) malloc(sizeof(Nodo));
		nodo->dado.letra = carac;
		strcpy(nodo->dado.morse, cod);
		nodo->esq = NULL;
		nodo->dir = NULL;
		nodo->FB = 0;
		*ok = 1;
	}
	else if (carac < nodo->dado.letra){ 	//Se existir, procura pelo fim dela, para que possa inserir o elemento
		nodo->esq = InsereAVL(nodo->esq, carac, cod, comp, ok);
		(*comp)++;
		if (*ok) { 							//E verifica se a árvore está devidamente balanceada
			switch (nodo->FB) {
				case -1:
					nodo->FB = 0;
					*ok = 0;
					break;
				case 0:
					nodo->FB = 1;
					break;
				case 1:
					nodo = Caso1(nodo, ok);
					break;
			}
		}
	}
	else { 									//Verifica para qual lado deve ser inserido o caractere e se a AVL está balanceada
		nodo->dir = InsereAVL(nodo->dir, carac, cod, comp, ok);
		(*comp)++;
		if (*ok) {
			switch (nodo->FB) {
				case 1:
					nodo->FB = 0;
					*ok = 0;
					break;
				case 0:
					nodo->FB = -1;
					break;
				case -1:
					nodo = Caso2(nodo, ok);
					break;
			}
		}
	}
	return nodo;
}

Nodo* rotacao_direita(Nodo* p){
	Nodo *u;
	u = p->esq;
	p->esq = u->dir;
	u->dir = p;
	p->FB = 0;
	p = u;
	return p; 		//Faz a rotação quando necessário
}

Nodo* rotacao_esquerda(Nodo *p){
	Nodo *u;
	u = p->dir;
	p->dir = u->esq;
	u->esq = p;
	p->FB = 0;
	p = u;
	return p; 		//Faz a rotação quando necessário
} 

Nodo* rotacao_dupla_direita(Nodo* p){
	Nodo *u, *v;
	u = p->esq;
	v = u->dir;
	u->dir = v->esq;
	v->esq = u;
	p->esq = v->dir;
	v->dir = p;
	if (v->FB == 1)
		p->FB = -1;
	else
		p->FB = 0;
	if (v->FB == -1)
		u->FB = 1;
	else
		u->FB = 0;
	p = v;
	return p; 	//Faz a rotação quando necessário
}

Nodo* rotacao_dupla_esquerda(Nodo *p){
	Nodo *z, *y;
	z = p->dir;
	y = z->esq;
	z->esq = y->dir;
	y->dir = z;
	p->dir = y->esq;
	y->esq = p;
	if (y->FB == -1)
		p->FB = 1;
	else
		p->FB = 0;
	if (y->FB == 1)
		z->FB = -1;
	else
		z->FB = 0;
	p = y;
	return p; 	//Faz a rotação quando necessário
}

Nodo* Caso1(Nodo *nodo , int *ok){
	Nodo *z;
	z = nodo->esq;
	if (z->FB == 1)
		nodo = rotacao_direita(nodo);
	else
		nodo = rotacao_dupla_direita(nodo);
	nodo->FB = 0;
	*ok = 0;
	return nodo; 		//Testa qual rotação será feita
}

Nodo* Caso2(Nodo *nodo , int *ok){
	Nodo *z;
	z = nodo->dir;
	if (z->FB == -1)
		nodo = rotacao_esquerda(nodo);
	else
		nodo = rotacao_dupla_esquerda(nodo);
	nodo->FB = 0;
	*ok = 0;
	return nodo; 		//Testa qual rotação será feita
}