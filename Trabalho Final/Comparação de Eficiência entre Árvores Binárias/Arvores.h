/****************************************************

	BIBLIOTECA COM CABEÇALHOS DE TODAS AS FUNÇÕES

	Nesse arquivo está incluida as Structs neces-
	sárias para o funcionamento das árvores e os
	includes de bibliotecas do C para o funciona-
	mento do nosso programa, além dos cabeçalhos
	de todas as funções usadas no programa.


****************************************************/

#include <stdio.h> 				//Biliotecas necessárias para o funcionamento do programa
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>

#define TAM 50 					//Constante para definir tamanho das strings

typedef struct DADO{ 			//Struct para armazenar o caractere e seu respectivo codigo morse
	char letra;					//Armazena o caractere
	char morse[TAM];			//Armazena se codigo morse
} Dado;

typedef struct NODO{ 			//Struct padrao para trabalhar com ABP
	Dado dado;					//Aqui vai ser armazenada a palavra
	int FB;						//Fator de balanceamento para a AVL
	struct NODO *esq;			//Aqui vai o endereco do filho da esquerda
	struct NODO *dir;			//E aqui o da direita
} Nodo;

//======================= Funções gerais ==================================

Nodo* criarArvore(void);

void buscaChar(Nodo* nodo, char c, char *str, int *enc, int *comp);

void processaEntrada(Nodo *nodo, char *entrada, char *saida, int *comp);

int AlturaArvore(Nodo *nodo);

wchar_t removeAcento(wchar_t c);

//======================= Funções para ABP ==================================

Nodo* insereMorseABP(Nodo *nodo, char *morse, int *comp);

Nodo* inserirNodoABP(Nodo *nodo, char carac, char *cod, int *comp);

//======================= Funções para AVL ==================================

Nodo* insereMorseAVL(Nodo *nodo, char *morse, int *comp);	

Nodo* InsereAVL(Nodo *nodo, char carac, char *cod, int *comp, int *ok);

Nodo* rotacao_direita(Nodo* p);

Nodo* rotacao_esquerda(Nodo *p);

Nodo* rotacao_dupla_direita(Nodo* p);

Nodo* rotacao_dupla_esquerda(Nodo *p);

Nodo* Caso1(Nodo *nodo, int *ok);

Nodo* Caso2(Nodo *nodo, int *ok);

//======================= Funções para Splay ==================================

Nodo* giraDir(Nodo* k2);

Nodo* giraEsq(Nodo* k2);

Nodo* Splay(char carac, Nodo* root, int *comp);

Nodo* novoNodo(char carac, char *cod);

Nodo* insereMorseSplay(Nodo *nodo, char *morse, int *comp);

Nodo* insereSplay(char carac, char *cod, Nodo* root, int *comp);

void processaEntradaSplay(Nodo *nodo, char *entrada, char *saida, int *comp);