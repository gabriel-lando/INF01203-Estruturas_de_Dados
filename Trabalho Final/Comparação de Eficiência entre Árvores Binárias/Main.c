/****************************************************

	TRABALHO DE ESTRUTURA DE DADOS

		Alunos:
			Eduardo Fischer 	(290399)
			Gabriel Lando 		(291399)

	O objetivo do programa é criar um arquivo
	com um código morse e testar dois tipos de
	árvores bonárias para saber qual delas é mais
	eficiente para converter um texto para o código
	norse. Para isso, uma tabela com o código é
	utilizada. Essa tabela é convertida para uma
	árvore (ABP, AVL e Splay), a qual irá gerar um novo
	arquivo de saída. Em todos os casos, sao medidas
	a quantidade de comparações para gerar a árvore
	e a quantidade para gerar o arquivo de saida de
	acordo com a árvore.

	No arquivo "Main.c" encontram-se as chamadas das
	funções, as quais estão em outros arquivos, listados
	abaixo:

	Arvore.h -> Headers de todas as funções + structs
	Arvore.c -> Funções em comum para ambas as arvores
	ABP.c -> Funcoes para formação da ABP
	AVL.c -> Funcoes para formação da AVL
	Splay.c -> Funcoes para formação da Splay


****************************************************/

#include "Arvores.h"

int main(int argc, char *argv[]){
	setlocale(LC_CTYPE, ""); 					//Usada para remover os acentos
	
//================ Verifica a passagem dos parametros ========================
	if(argc != 4){
		printf("Passagem de parametros incorreta!\n");
		exit(1);
	}

//======================= Trabalha com a Splay ===============================

	Nodo *arvMorseSplay = criarArvore();		//Cria arvore vazia

	int compMorseSplay = 0, compSaidaSplay = 0; 	//Variaveis para armazenar comparacoes

	arvMorseSplay = insereMorseSplay(arvMorseSplay, argv[1], &compMorseSplay); 	//Cria uma AVL com o codigo morse

	processaEntradaSplay(arvMorseSplay, argv[2], argv[3], &compSaidaSplay); 		//Faz as comparacoes para formar o arquivo de saida

	printf("\nSPLAY:\n%d comparacoes para montar a Splay.\n", compMorseSplay); 		//Imprime os valores de comparações
	printf("%d comparacoes para gerar a saida.\n", compSaidaSplay);
	printf("TOTAL de %d comparacoes com Splay\n\n", compMorseSplay + compSaidaSplay);

//======================= Trabalha com a AVL =================================

	Nodo *arvMorseAVL = criarArvore();		//Cria arvore vazia

	int compMorseAVL = 0, compSaidaAVL = 0; 	//Variaveis para armazenar comparacoes

	arvMorseAVL = insereMorseAVL(arvMorseAVL, argv[1], &compMorseAVL); 	//Cria uma AVL com o codigo morse

	processaEntrada(arvMorseAVL, argv[2], argv[3], &compSaidaAVL); 		//Faz as comparacoes para formar o arquivo de saida

	printf("AVL:\n%d comparacoes para montar a AVL.\n", compMorseAVL); 		//Imprime os valores de comparações
	printf("%d comparacoes para gerar a saida.\n", compSaidaAVL);
	printf("TOTAL de %d comparacoes com AVL\n", compMorseAVL + compSaidaAVL);
	printf("Altura da AVL: %d\n\n", AlturaArvore(arvMorseAVL));

//===================== Trabalha com a ABP ===================================

	Nodo *arvMorseABP = criarArvore(); 			//Cria arvore vazia
	
	int compMorseABP = 0, compSaidaABP = 0; 	//Variaveis para armazenar comparacoes

	arvMorseABP = insereMorseABP(arvMorseABP, argv[1], &compMorseABP); 	//Cria a arvore com o codigo morse

	processaEntrada(arvMorseABP, argv[2], argv[3], &compSaidaABP); 		//Cria o arquivo de saida, de acordo com o de entrada

	printf("ABP:\n%d comparacoes para montar a ABP.\n", compMorseABP); 		//Imprime os valores de comparações
	printf("%d comparacoes para gerar a saida.\n", compSaidaABP);
	printf("TOTAL de %d comparacoes com ABP\n", compMorseABP + compSaidaABP);
	printf("Altura da ABP: %d\n", AlturaArvore(arvMorseABP));

	return 0;
}