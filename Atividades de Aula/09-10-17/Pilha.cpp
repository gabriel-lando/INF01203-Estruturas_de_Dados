#include "Pilha.h"

struct TPtPilha{
        TipoInfo dado;
        struct TPtPilha *elo;
};


TipoPilha* InicializaPilha (void)
{
    return NULL;
}

int PilhaVazia (TipoPilha *Topo)
{
    if (Topo==NULL)
       return 1;
    else
       return 0;
}

void ImprimirPilha (TipoPilha *Topo)
{
     TipoPilha *ptaux;

     if (Topo != NULL)
     {
        puts("---Imprimindo pilha---");
        for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
            printf("%d\n",ptaux->dado);
        puts("-------Fim pilha------");
     }
     else
       puts("Pilha vazia");

}


TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)
{
       TipoPilha *novo; //novo elemento
       TipoPilha *ptaux = Topo; //ponteiro auxiliar para percorrer a lista

       /*aloca um novo nodo */
       novo = (TipoPilha*) malloc(sizeof(TipoPilha));
       novo->elo = NULL;

       /*insere a informação no novo nodo*/
       novo->dado = Dado;

       /*encaeia o elemento*/
       novo->elo = Topo;
       Topo = novo;
       return Topo;
}


int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //retorna 1 se exclui e zero se não exclui
{
   TipoPilha* ptaux;

   if (PilhaVazia(*Topo))
     return 0;   //não tem nada na pilha
   else
   {
        *Dado = (*Topo)->dado;     // devolve o valor do topo
        ptaux = *Topo;          //guarda o endereço do topo
        *Topo = (*Topo)->elo;     //o próximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        ptaux=NULL;
        return 1;
   }
}

TipoInfo ConsultaPilha (TipoPilha *Topo)
{
 if (Topo==NULL)
   return 0;
 else
   return Topo->dado;

}

TipoPilha* DestroiPilha (TipoPilha *Topo)
{
        TipoPilha *ptaux;
        while (Topo != NULL)
        {
          ptaux = Topo;          //guarda o endereço do topo
          Topo = Topo->elo;     //o próximo passa a ser o topo
          free(ptaux);           //libera o que estava no topo
        }
        return NULL;
}

int comparaPilha(TipoPilha *P1, TipoPilha *P2){
    TipoPilha *auxP1 = P1, *auxP2 = P2;
    TipoInfo auxD1, auxD2;
    int fimP1, fimP2;

    fimP1 = PopPilha(&auxP1, &auxD1);
    fimP2 = PopPilha(&auxP2, &auxD2);

    if(fimP1 && fimP2)
        do{
            if(fimP1 != fimP2 || auxD1 != auxD2)
                return 0;

            fimP1 = PopPilha(&auxP1, &auxD1);
            fimP2 = PopPilha(&auxP2, &auxD2);
        }while(fimP1 && fimP2);

    if(!fimP1 && !fimP2)
        return 1;
    return 0;
}

