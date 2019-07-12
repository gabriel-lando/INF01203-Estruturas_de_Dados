#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i = 0, j, k, l;
	char saida[100][100];
	int jafoi[100] = {0};

	srand(time(0));

	FILE *arq = fopen("Tabela2.txt", "r");
	FILE *arq2 = fopen("Tabela22.txt", "w");

	while(!feof(arq)){
		fgets(saida[i], 100, arq);
		i++;
	}

	for(k = 0; k < i; k++){
		do{
			j = rand() % i;
		}while(jafoi[j]);
		jafoi[j] = 1;
		fputs(saida[j], arq2);
	}

	fclose(arq);
	fclose(arq2);

	return 0;
}