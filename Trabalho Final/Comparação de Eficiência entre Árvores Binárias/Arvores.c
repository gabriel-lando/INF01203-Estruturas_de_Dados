/****************************************************

	BIBLIOTECA COM FUNÇÕES PADROES
	 PARA OS DOIS TIPOS DE ARVORE


	Aqui estão incluidas as seguintes funções:
	-> criarArvore()
		Inicializa a arvore.
	-> buscaChar()
		Retorna a string em morse correspondente
		ao char que está sendo buscado.
	-> processaEntrada()
		Gera o arquivo de saida, usando a arvore
		desejada, calculando a quantidade de compa-
		rações necessárias para realizar a operação.
	-> AlturaArvore()
		Calcula a altura de cada árvore, para com-
		paração com os resultados.
	-> removeAcento()
		Recebe um char como parâmetro e retorna
		este char sem acento, caso ele possua.

****************************************************/

#include "Arvores.h"

Nodo* criarArvore(void){ 			//Retorna NULL no ponteiro de nodo pra dizer que a árvore está vazia
	return NULL;
}

void buscaChar(Nodo* nodo, char c, char *str, int *enc, int *comp) {
	if(nodo && !(*enc)){ 							//Verifica se o nodo já existe e se ainda não foi encontrado o caractere
		(*comp)+=2;
		if (nodo->dado.letra == c){					//Se for o caractere correspondente, copia o morse para a string
			(*comp)--;
			strcpy(str, nodo->dado.morse); 
			(*enc) = 1;
		}
		else if (nodo->dado.letra > c){				//Senao, verifica se é menor, para ir para a esquerda
			buscaChar(nodo->esq, c, str, enc, comp);
		}
		else{										//Se for maior, busca para a direita
			buscaChar(nodo->dir, c, str, enc, comp);
		}
	}
}

void processaEntrada(Nodo *nodo, char *entrada, char *saida, int *comp){			//Gera a saida de acordo com a entrada
	int auxP = 0;			//Variaveis auxiliares
	wchar_t carac; 			//Char diferencido, para poder remover os acentos
	char aux[TAM]; 			//Armazena o código morse que será retornado pela busca

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
			buscaChar(nodo, carac, aux, &auxP, comp);
			if(auxP) 									//Se encontrar, salva no arquivo de saida o Morse. Senao, não faz nada
				fprintf(sai, "%s ", aux);
		}
	}

	fclose(ent); 		//Fecha os arquivos
	fclose(sai);
}

int AlturaArvore(Nodo *nodo){ 		//Calcula a altura da árvore
	int Alt_Esq, Alt_Dir;
	if (!nodo)
		return 0;
	else
	{
		Alt_Esq = AlturaArvore(nodo->esq);
		Alt_Dir = AlturaArvore(nodo->dir);
		if (Alt_Esq > Alt_Dir)
			return (1 + Alt_Esq);
		else
			return (1 + Alt_Dir);
	}
}

wchar_t removeAcento(wchar_t c){ 	//Remove os caracteres especiais, usando algumas bibliotecas do C e um switch case
	switch (c) { 					//AS COMPARAÇÕES NECESÁRIAS PARA REMOÇÃO DOS ACENTOS NAO FORAM CONTABILIZADAS.
		case L'Ä':  
		case L'Å':
		case L'Á':
		case L'Â':
		case L'À':
		case L'Ã':
		case L'ä':
		case L'á':
		case L'â':
		case L'à':
		case L'ã': c=L'a'; break;
		case L'É':
		case L'Ê':
		case L'Ë':
		case L'È':
		case L'é':
		case L'ê':
		case L'ë':
		case L'è': c=L'e';break;
		case L'Í':
		case L'Î':
		case L'Ï':
		case L'Ì':
		case L'í':
		case L'î':
		case L'ï':
		case L'ì': c=L'i';break;
		case L'Ö':  
		case L'Ó':
		case L'Ô':
		case L'Ò':
		case L'Õ':
		case L'ö':
		case L'ó':
		case L'ô':
		case L'ò':
		case L'õ': c=L'o';break;
		case L'Ü':
		case L'Ú':
		case L'Û':
		case L'ü':
		case L'ú':
		case L'û':
		case L'ù': c=L'u';break;
		case L'Ç':
		case L'ç': c=L'c';break;
		default:	break;
	}
	return c;
}