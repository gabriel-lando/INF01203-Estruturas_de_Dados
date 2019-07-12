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

void preOrder(Node* node){
	if(node){
		printf("%d  ", node->key);
		preOrder(node->left);
		preOrder(node->right);
	}
}

int nodeCount(Node *node){
	if(node){
		return 1 + nodeCount(node->left) + nodeCount(node->right);
	}
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