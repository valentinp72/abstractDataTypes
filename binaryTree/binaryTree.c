#include "binaryTree.h"

/* ----------------------- */
/* FUNCTIONS FOR THE NODES */
/* ----------------------- */

// Return the number of a node
int node_numberRead(node * n){
	if(n != NULL)
		return n->number;
	return ERROR;
}

// Write the number in a node 
void node_numberWrite(node * n, int number){
	if(n != NULL)
		n->number = number;
}

// Return the label of a node
void * node_labelRead(node * n){
	if(n != NULL)
		return n->label;
	return NULL;
}

// Write the label of a node
void node_labelWrite(node * n, void * label){
	if(n != NULL)
		n->label = label;
}

// Return the left tree of a node
node * node_leftTreeRead(node * n){
	if(n != NULL)
		return n->left;
	return NULL;
}

// Return the right tree of a node
node * node_rightTreeRead(node * n){
	if(n != NULL)
		return n->right;
	return NULL;
}

// Write the left tree of a node
void node_leftTreeWrite(node * n, node * left){
	if(n != NULL)
		n->left = left;
}

// Write the right tree of a node
void node_rightTreeWrite(node * n, node * right){
	if(n != NULL)
		n->right = right;
}

// Return true if the node exist
bool node_exist(node * n){
	return n != NULL;
}

// Return true if the node is a leaf
bool node_isLeaf(node * n){
	return n != NULL && n->left == NULL && n->right == NULL; 
}

// Return true if the node is father
bool node_isFather(node * n){
	return !node_isLeaf(n);
}

// Create a node
node * node_create(int number, void * label, node * left, node * right){
	node * n = malloc(sizeof(node));

	n->number = number;
	n->label  = label;
	n->left   = left;
	n->right  = right;

	return n;
}

// Destroy the node
void node_destroy(node ** n){
	if(n != NULL)
		free(*n);
	*n = NULL;
}

// Print a node (must give a function pointer to print the label)
void node_print(node * n, void (*labelPrint)(void *)){
	if(n != NULL){
		printf("Node n°%i:\n\tLabel: ", n->number);
		labelPrint(n->label);
		printf("\n\tLeft-tree: %p | Right-tree: %p\n", n->left, n->right);
	}
}

// Return the pointer to the node with the number given
node * node_numberSearch(node * n, int number){
	node * leftSearch, * rightSearch;

	if(n != NULL){
		if(n->number == number){
			return n;		
		}
		leftSearch  = node_numberSearch(n->left, number);
		rightSearch = node_numberSearch(n->right, number);

		if(leftSearch != NULL)
			return leftSearch;
		return rightSearch;
	}
	return NULL;
}


