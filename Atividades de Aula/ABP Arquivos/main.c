#include "BinarySearchTree.h"

int main(void){
	Node *tree = createTree();
	tree = insertNode(tree, 500);
	tree = insertNode(tree, 300);
	tree = insertNode(tree, 800);
	tree = insertNode(tree, 150);
	tree = insertNode(tree, 400);
	tree = insertNode(tree, 600);
	tree = insertNode(tree, 900);
	tree = insertNode(tree, 550);
	tree = insertNode(tree, 650);

	removeNode(tree, 500);

	inOrder(tree);

	return 0;
}