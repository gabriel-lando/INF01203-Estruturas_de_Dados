#include "func.h"

int main(){
	int menu;
	TipoPtNo *PtLista;
	TipoInfoNo dados;

	PtLista = Inicializa_Lista();

	do{
		printf("\n\n\tMENU:\n");
		printf("1- Inserir Produto\n");
		printf("2- Imprimir Lista\n");
		printf("3- Imprimir Lista Reversa\n");
		printf("4- Destruir\n");
		printf("5- Sair\n");
		printf("\nOpcao: ");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("\nEntre com os dados:\n");
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
				printf("\n**** FIM DA LISTAGEM ****\n");
				break;
			case 3:
				printf("\n*** INICIO DA LISTAGEM REVERSA ***\n\n");
				Imprime_Lista_Reversa(PtLista);
				printf("\n**** FIM DA LISTAGEM REVERSA ****\n");
				break;
			case 4:
				PtLista = Destroi_Lista(PtLista);
				printf("\nLista destruida!\n");
				break;

		}
	}while(menu != 5);

	return 0;
}