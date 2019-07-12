#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int Data;

typedef struct node{
	Data key;
	struct node *left;
	struct node *right;
} Node;

// --- MAIN METHODS ---

// Create a empty tree
Node* createTree(void);

// Insert a right child at the node with the given key
Node* insertNode(Node *node, Data key);

// Remove the node with the given key
Node* removeNode(Node *node, Data key);

// Search for the node with the given key
Node* search(Node *node, Data key);

// Delete the tree
Node* destructTree(Node *node);

// --- TRAVERSAL METHODS ---

// Print the tree using pre-order
void preOrder(Node* node);

// Print the tree using in-order
void inOrder(Node* node);

// Print the tree using post-order
void postOrder(Node* node);

// --- AUXILIAR METHODS ---

// Return the minimum node in a tree or subtree
Node* minNode(Node *node);