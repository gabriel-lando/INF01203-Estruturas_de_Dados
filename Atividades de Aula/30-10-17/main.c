#include "BinarySearchTree.h"

int main(void){
	Node *tree = createTree();
	tree = insertNode(tree, 8);
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 9);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 1);

	printf("Caminhamento pre-fixado a esquerda:\n");
	preOrder(tree);
	printf("\n\n");

	int qtd = nodeCount(tree);

	printf("Quantidade de nos da arvode: %d\n\n", qtd);

	preOrderEx1(tree, 0);

	return 0;
}