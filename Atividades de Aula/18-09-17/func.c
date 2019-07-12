#include "func.h"

TipoPtNo *Busca_Insere(TipoPtNo *PtLista, TipoInfoNo dados){
	TipoPtNo *PtAnt = NULL, *PtAux = PtLista;

	if(!PtAux)
		return NULL;

	while(PtAux && PtAux->info.cod < dados.cod){
		PtAnt = PtAux;
		PtAux = PtAux->prox;
	}
	
	return PtAnt;
}

TipoPtNo *Inicializa_Lista(){
	return NULL;
}

TipoPtNo *Insere_Produto(TipoPtNo *PtLista, TipoInfoNo dados){
	TipoPtNo *novo, *PtAnt;
	novo = malloc(sizeof(TipoPtNo));
	novo->info = dados;

	PtAnt = Busca_Insere(PtLista, dados);

	if(PtAnt){
		novo->prox = PtAnt->prox;
		PtAnt->prox = novo;
	}
	else{
		novo->prox = PtLista;
		PtLista = novo;
	}

	return PtLista;
}

void Imprime_Lista(TipoPtNo *PtLista){
	TipoPtNo *PtAux = PtLista;

	while(PtAux){
		printf("Codigo: %d\n", PtAux->info.cod);
		printf("Nome: %s\n", PtAux->info.nome);
		printf("Preco: R$ %.2f\n\n", PtAux->info.preco);
		PtAux = PtAux->prox;
	}

}