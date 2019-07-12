#include "BinarySearchTree.h"

int main(void){
	Node *tree1 = createTree();
	Node *tree2 = createTree();
	int d = 0;

	tree2 = insertNode(tree2, 42);
	tree2 = insertNode(tree2, 15);
	tree2 = insertNode(tree2, 6);
	tree2 = insertNode(tree2, 27);
	tree2 = insertNode(tree2, 20);
	tree2 = insertNode(tree2, 88);
	tree2 = insertNode(tree2, 63);
	tree2 = insertNode(tree2, 57);
	tree2 = insertNode(tree2, 71);
	tree2 = insertNode(tree2, 94);

	tree1 = insertNode(tree1, 42);
	tree1 = insertNode(tree1, 50);
	tree1 = insertNode(tree1, 27);
	tree1 = insertNode(tree1, 20);

	printf("\n");

	preOrderEx1(tree1, 0);

	maiorFator(tree1, &d);

	printf("\nMaior fator: %d\n", d);


	printf("\n\n");

	preOrderEx1(tree2, 0);

	d = 0;

	maiorFator(tree2, &d);

	printf("\nMaior fator: %d\n", d);

	return 0;
}