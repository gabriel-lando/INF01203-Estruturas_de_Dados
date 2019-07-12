#include "BinarySearchTree.h"

Node* createTree(void){
	return NULL;
}

Node* insertNode(Node *node, Data key){
	if(!node){
		node = (Node*)malloc(sizeof(Node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
	}else
		if(key < node->key)
			node->left = insertNode(node->left, key);
		else
			node->right = insertNode(node->right, key);
	
	return node;
}

void preOrderEx1(Node* node, int level){
	if(node){
		int aux;
		for(aux = 0; aux <= level; aux++)
			printf("=");
		printf("%d\n", node->key);
		preOrderEx1(node->left, level+1);
		preOrderEx1(node->right, level+1);
		
	}
}

int Altura (Node *a){
	int Alt_Esq, Alt_Dir;
	if (a == NULL)
		return 0;
	else
	{
		Alt_Esq = Altura (a->left);
		Alt_Dir = Altura (a->right);
		if (Alt_Esq > Alt_Dir)
			return (1 + Alt_Esq);
		else
			return (1 + Alt_Dir);
	}
}

int Balanceamento(Node* a){
	int FatorEsq, FatorDir;

	if(!a)
		return 0;
	else{
		FatorEsq = Altura(a->left);
		FatorDir = Altura(a->right);
		return FatorEsq - FatorDir;
	}
}

void maiorFator(Node* a, int *maior){
	int fator;
	if(a){
		fator = abs(Balanceamento(a));
		if(fator > *maior)
			*maior = fator;
		maiorFator(a->left, maior);
		maiorFator(a->right, maior);
	}

}