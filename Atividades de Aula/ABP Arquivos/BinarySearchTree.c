#include "BinarySearchTree.h"

// --- MAIN METHODS ---

// Create a empty tree
Node* createTree(void){
	return NULL;
}

// Insert a right child at the node with the given key
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

// Remove the node with the given key
Node* removeNode(Node *node, Data key){
	if(!node)	
		return node;

	if(key < node->key)
		node->left = removeNode(node->left, key);
	else if(key > node->key)
		node->right = removeNode(node->right, key);
	else{
		if(!(node->left)){
			Node *temp = node->right;
			free(node);
			return temp;
		}else if(!(node->right)){
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node *temp = minNode(node->right);
		node->key = temp->key;
		node->right = removeNode(node->right, temp->key);
	}
	return node;
}

// Search for the node with the given key
Node* search(Node *node, Data key){
	while(node){
		if(node->key == key)
			return node;
		else
			if(node->key > key)
				node = node->left;
			else
				node = node->right;
	}

	return NULL;
}

// Delete the tree
Node* destructTree(Node *node){
	if(node){
		destructTree(node->left);
		destructTree(node->right);
		printf("Destruindo %d\n", node->key);
		free(node);
	}
	return NULL;
}

// --- TRAVERSAL METHODS ---

// Print the tree using pre-order
void preOrder(Node* node){
	if(node){
		printf("%d\n", node->key);
		preOrder(node->left);
		preOrder(node->right);
	}
}

// Print the tree using in-order
void inOrder(Node* node){
	if(node){
		inOrder(node->left);
		printf("%d\n", node->key);
		inOrder(node->right);
	}
}

// Print the tree using post-order
void postOrder(Node* node){
	if(node){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d\n", node->key);
	}
}

// --- AUXILIAR METHODS ---

// Return the minimum node in a tree or subtree
Node* minNode(Node *node){
	Node *aux = node;

	while(aux->left)
		aux = aux->left;

	return aux;
}