# include <stdio.h>
# include <stdlib.h>
#include <math.h>
# include "data.h"
/* lê data */
void le_data (Data *d) {
	printf("Dia:"); scanf("%d",&d->dia);
	printf("Mes:"); scanf("%d",&d->mes);
	printf("Ano:"); scanf("%d",&d->ano);
}
/* Valida data */
int valida_data(Data d) {
	if ((d.dia >31) || (d.ano>2100) || (d.mes>12))
		return 0;
	else
		return 1;
}
/* Imprime data */
void imprime_data(Data d) {
	printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

/* Retorna a qtde de dias entre duas datas*/
int num_dias(Data d1, Data d2){
	return abs((d2.ano - d1.ano)*365 + (d2.mes-d1.mes)*30 + (d2.dia-d1.dia));
}

/* Retorna, por referencia, o dia e mes da pascoa em determinado ano*/
void data_pascoa(Data *d){
	int c, i, j, k, l, n;
	c = d->ano/100;
	n = d->ano - (19*(d->ano/19));
	k = (c - 17)/25;
	i = c - c/4 - ((c-k)/3) +(19*n) + 15;
	i = i - (30*(i/30));
	i = i - ((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
	j = d->ano + d->ano/4 + i + 2 -c + c/4;
	j = j - (7*(j/7));
	l = i - j;
	d->mes = 3 + ((l+40)/44);
	d->dia = l + 28 - (31*(d->mes/4));
}