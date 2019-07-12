/****************************************************

	BIBLIOTECA COM FUNÇÕES PARA A SPLAY


	Aqui estão incluidas as seguintes funções:

	-> giraDir()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao a direita.
	-> giraEsq()
		Função auxiliar na criação da árvore. Ela
		é responsável por realizao rotacao a esquerda.
	-> Splay()
		Função principal na movimentação da árvore Splay.
		Responsável por determinar quais rotações são 
		necessárias para colocar o nodo procurado na raiz
		da árvore.
	-> novoNodo()
		Cria um novo nodo com os dados a serem inseridos
		na raiz da árvore.
	-> insereMorseSplay()
		Função chamada na Main, que irá processar
		o arquivo com a tabela Morse e irá criar
		a árvore Splay.
	-> insereSplay()
		Função chamada pela insereMorseSplay() e é
		ela que chama a Splay() para inserir o novo nodo
	-> processaEntradaSplay()
		Função padrão de saída, responsável por gerar o
		arquivo de saída, porém, adaptada à arvore Splay


****************************************************/

#include "Arvores.h"

Nodo* giraDir(Nodo* k2){ 			//Realiza a rotação para a direita
	Nodo* k1 = k2->esq;
	k2->esq = k1->dir;
	k1->dir = k2;
	return k1;
}

Nodo* giraEsq(Nodo* k2){			//Realiza arotaçãi para a esquerda
	Nodo* k1 = k2->dir;
	k2->dir = k1->esq;
	k1->esq = k2;
	return k1;
}

Nodo* Splay(char carac, Nodo* root, int *comp){ 	//Coloca o nodo desejado na raiz da árvore
	if(!root) 					//Vereifica se o nodo existe
		return NULL;

	Nodo header;

	header.esq = header.dir = NULL;
	Nodo* LeftTreeMax = &header;
	Nodo* RightTreeMin = &header;

	while(1){ 					//Enquanto nao encontrar o nodo desejado, fica em loop infinito
		(*comp)+=2;				//Incrementa as comparações
		if(carac < root->dado.letra){
			if(!root->esq) 		//Se o nodo esquerdo não existe, encerra o loop
				break;
			(*comp)++;
			if(carac < root->esq->dado.letra){
				root = giraDir(root); 	//Realiza a rotação para a direita
				(*comp)++;
				if(!root->esq)
					break;
			}
			
			RightTreeMin->esq = root;
			RightTreeMin = RightTreeMin->esq;
			root = root->esq;
			RightTreeMin->esq = NULL;
		}
		else if(carac > root->dado.letra){
			(*comp)++;
			if(!root->dir) 		//Se o nodo direito nao existe, encerra o loop
				break;
			(*comp)++;
			if(carac > root->dir->dado.letra){
				root = giraEsq(root); 	//Realiza a rotação para a direita
				(*comp)++;
				if(!root->dir)
					break;
			}
			LeftTreeMax->dir = root;
			LeftTreeMax = LeftTreeMax->dir;
			root = root->dir;
			LeftTreeMax->dir = NULL;
		}
		else
			break;
	}
	LeftTreeMax->dir = root->esq;
	RightTreeMin->esq = root->dir;
	root->esq = header.dir;
	root->dir = header.esq;
	
	return root;
}

Nodo* novoNodo(char carac, char *cod){ 			//Cria um novo nodo para a inserção de dados na arvore
	Nodo* nodo = (Nodo*) malloc(sizeof(Nodo)); 	//Aloca o espaço na memória para o nodo
	nodo->dado.letra = carac; 					//Insere os dados
	strcpy(nodo->dado.morse, cod);
	nodo->esq = NULL; 							//Guarda nos filhos direito e esquerdo o valor NULL para saber que está vazio
	nodo->dir = NULL;
	return nodo;
}

Nodo* insereMorseSplay(Nodo *nodo, char *morse, int *comp){ 		//Funcao de inserção na árvore
	char aux[TAM], cod[TAM], carac; 							//Variaveis auxiliares

	FILE *arq;

	if(!(arq = fopen(morse, "r"))){ 			//Testa se o arquivo da tabela morse pode ser lido
		printf("Erro na leitura da tabela Morse!\n");
		exit(1);
	}

	while(!feof(arq)){ 							//Le o arquivo e cria uma tabela com ele
		fgets(aux, TAM, arq);
		sscanf(aux, " %c %s", &carac, cod); 	//Separa o caractere e seu codigo morse lidos da string
		carac = toupper(carac);
		nodo = insereSplay(carac, cod, nodo, comp); 	//Chama essa função para a inserção dos nodos
	}

	fclose(arq);

	return nodo;
}

Nodo* insereSplay(char carac, char *cod, Nodo* root, int *comp){ 	//Responsável por inserir o nodo na árvore
	static Nodo* nodo = NULL;

	if(!nodo) 			//Se o nodo não existe, cria um e armazena os dados
		nodo = novoNodo(carac, cod);
	else{				//Se já existe, salva no nodo existente
		nodo->dado.letra = carac;
		strcpy(nodo->dado.morse, cod);
	}
	if(!root){
		root = nodo;
		nodo = NULL;
		return root;
	}
	root = Splay(carac, root, comp); 	//Coloca o nodo a ser inserido como raiz

	(*comp)+=2; 						//Incrementa a quantidade de comparações para formação da árvore
	if(carac < root->dado.letra){
		(*comp)--;
		nodo->esq = root->esq;
		nodo->dir = root;
		root->esq = NULL;
		root = nodo;
	}
	else if(carac > root->dado.letra){
		nodo->dir = root->dir;
		nodo->esq = root;
		root->dir = NULL;
		root = nodo;
	}
	else
		return root;
	nodo = NULL;
	return root;
}

void processaEntradaSplay(Nodo *nodo, char *entrada, char *saida, int *comp){			//Gera a saida de acordo com a entrada
	int auxP = 0;			//Variaveis auxiliares
	wchar_t carac; 			//Char diferencido, para poder remover os acentos
	char aux[TAM]; 			//Armazena o código morse que será retornado pela busca

	Nodo *busca;

	FILE *ent, *sai; 		//Arquivos de entrada e saida

	if(!(ent = fopen(entrada, "r")) || !(sai = fopen(saida, "w"))){ 		//Testa se os arquivos podem ser abertos
		printf("Erro na abertura dos arquivos de entrada e saida!\n");
		exit(1);
	}

	while((carac = fgetwc(ent)) != WEOF){ 				//Pega um caractere por vez do arquivo de entrada, ate acabar o arquivo
		auxP = 0;
		carac = removeAcento(carac); 					//Remove a acentuação
		carac = toupper(carac); 						//Coloca em maiúsculo, pois não é case sensitive
		if(carac == ' '){ 								//Verifica se é espaço
			fputc('/', sai); 							//Se for, coloca uma '/'
			fputc(' ', sai);
		}
		else{ 											//Se não for, busca-o na árvore
			busca = Splay(carac, nodo, comp);
			if(busca) 									//Se encontrar, salva no arquivo de saida o Morse. Senao, não faz nada
				fprintf(sai, "%s ", busca->dado.morse);
		}
	}

	fclose(ent); 		//Fecha os arquivos
	fclose(sai);
}