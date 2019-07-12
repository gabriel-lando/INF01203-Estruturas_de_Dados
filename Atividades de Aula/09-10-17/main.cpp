#include "Pilha.h"

int main ()
{
    TipoPilha *Pilha1 = InicializaPilha(), *Pilha2 = InicializaPilha(), *Pilha3 = InicializaPilha(), *Pilha4 = InicializaPilha();

    Pilha1 = PushPilha(Pilha1, 1);
    Pilha1 = PushPilha(Pilha1, 2);
    Pilha1 = PushPilha(Pilha1, 3);
    Pilha1 = PushPilha(Pilha1, 4);

    Pilha2 = PushPilha(Pilha2, 2);
    Pilha2 = PushPilha(Pilha2, 3);
    Pilha2 = PushPilha(Pilha2, 4);

    Pilha3 = PushPilha(Pilha3, 1);
    Pilha3 = PushPilha(Pilha3, 2);
    Pilha3 = PushPilha(Pilha3, 3);
    Pilha3 = PushPilha(Pilha3, 4);

    Pilha4 = PushPilha(Pilha4, 1);
    Pilha4 = PushPilha(Pilha4, 2);
    Pilha4 = PushPilha(Pilha4, 3);
    Pilha4 = PushPilha(Pilha4, 4);

    ImprimirPilha(Pilha1);
    ImprimirPilha(Pilha2);
    ImprimirPilha(Pilha3);
    ImprimirPilha(Pilha4);

    if(comparaPilha(Pilha1, Pilha2))
        printf("\nAs pilhas 1 e 2 sao iguais\n");
    else
        printf("\nAs pilhas 1 e 2 sao diferentes\n");

    if(comparaPilha(Pilha3, Pilha4))
        printf("\nAs pilhas 3 e 4 sao iguais\n");
    else
        printf("\nAs pilhas 3 e 4 sao diferentes\n");

    return 0;
}
