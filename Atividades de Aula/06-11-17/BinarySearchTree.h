#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int Data;

typedef struct node{
	Data key;
	struct node *left;
	struct node *right;
} Node;

Node* createTree(void);

Node* insertNode(Node *node, Data key);

void preOrderEx1(Node* node, int level);

int Altura (Node *a);

int Balanceamento(Node* a);

void maiorFator(Node* a, int *maior);