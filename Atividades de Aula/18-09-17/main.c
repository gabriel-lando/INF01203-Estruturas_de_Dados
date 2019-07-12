#include "func.h"

int main(){
	int menu;
	TipoPtNo *PtLista;
	TipoInfoNo dados;

	PtLista = Inicializa_Lista();

	do{
		printf("\tMENU:\n");
		printf("1- Inserir Produto\n");
		printf("2- Imprimir Lista\n");
		printf("3- Sair\n");
		printf("\nOpcao: ");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("Entre com os dados:\n");
				printf("Codigo: ");
				scanf("%d", &dados.cod);
				printf("Nome: ");
				fflush(stdin);
				gets(dados.nome);
				printf("Preco: ");
				scanf("%f", &dados.preco);
				PtLista = Insere_Produto(PtLista, dados);
				printf("Dado inserido!\n");
				break;
			case 2:
				printf("\n*** INICIO DA LISTAGEM ***\n\n");
				Imprime_Lista(PtLista);
				printf("\n\n**** FIM DA LISTAGEM ****\n");
				break;

		}
	}while(menu != 3);

	return 0;
}