# include <stdio.h>
# include <stdlib.h>
# include "data.h"
int main (){
	Data d1, d2, pascoa;
	
	do{
		printf("Entre com uma data valida:\n");
		le_data(&d1);
		if (valida_data(d1))
			printf("Data valida\n");
		else
			printf("Data invalida\n");
	}while(!(valida_data(d1)));

	do{
		printf("\nEntre com outra data valida:\n");
		le_data(&d2);
		if (valida_data(d2))
			printf("Data valida\n");
		else
			printf("Data invalida\n");
	}while(!(valida_data(d2)));

	printf("\nNumero de dias: %d\n", num_dias(d1, d2));

	printf("\nEntre com um ano: ");
	scanf("%d", &pascoa.ano);
	data_pascoa(&pascoa);
	printf("\nPascoa: %02d/%02d/%04d\n", pascoa.dia, pascoa.mes, pascoa.ano);

	return 0;

}