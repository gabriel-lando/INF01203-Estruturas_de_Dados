/*TAD DATA (dd,mm,aaaa)*/
/* TIPO DE DADO exportado */
struct data {
	int dia;
	int mes;
	int ano;
};

typedef struct data Data;
/* OPERAÇÕES Exportadas */
/* lê data */
void le_data (Data *d);
/* Valida data */
int valida_data(Data d);
/* Imprime data */
void imprime_data(Data d);

/* Retorna a qtde de dias entre duas datas*/
int num_dias(Data d1, Data d2);

/* Retorna, por referencia, o dia e mes da pascoa em determinado ano*/
void data_pascoa(Data *d);