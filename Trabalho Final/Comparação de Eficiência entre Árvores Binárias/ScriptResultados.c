#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, j;
	char saida[50], tabela[50], entrada[50], chamada[200];

	for (i = 1; i < 4; i++){
		for (j = 1; j < 11; j++)
		{
			sprintf(saida, "Tabela%dEntrada%d.txt", i, j);
			sprintf(tabela, "Tabela%d.txt", i);
			sprintf(entrada, "Entrada%d.txt", j);
			sprintf(chamada, "TrabED.exe Testes\\%s Testes\\%s Testes\\Saida.txt > Resultados\\%s", tabela, entrada, saida);
			system(chamada);
			puts(chamada);
		}
	}

	return 0;
}