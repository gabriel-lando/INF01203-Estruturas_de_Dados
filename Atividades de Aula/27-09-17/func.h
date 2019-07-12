#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct s_InfoNo{
	int cod;
	char nome[TAM];
	float preco;
}TipoInfoNo;

typedef struct s_PtNo{
	TipoInfoNo info;
	struct s_PtNo *prox;
	struct s_PtNo *ant;
}TipoPtNo;

TipoPtNo *Busca_Insere(TipoPtNo *PtLista, TipoInfoNo dados);

TipoPtNo *Inicializa_Lista();

TipoPtNo *Insere_Produto(TipoPtNo *PtLista, TipoInfoNo dados);

void Imprime_Lista(TipoPtNo *PtLista);

void Imprime_Lista_Reversa(TipoPtNo *PtLista);

TipoPtNo *Destroi_Lista(TipoPtNo *PtLista);