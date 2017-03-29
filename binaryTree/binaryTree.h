#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR    1
#define NO_ERROR 0

/* ----------------- */
/* TYPES DEFINITIONS */
/* ----------------- */

typedef struct node_s{
	int number;
	void * label;
	struct node_s * left;
	struct node_s * right;
} node;

typedef struct binaryTree_s{
	int size;
	node * root;
	int (*assign)(void * e1, void * e2);
	int (*destroy)(void * e);
} binaryTree;


/* ----------------------- */
/* FUNCTIONS FOR THE NODES */
/* ----------------------- */

// Return the number of a node
int node_numberRead(node * n);

// Write the number in a node 
void node_numberWrite(node * n, int number);

// Return the label of a node
void * node_labelRead(node * n);

// Write the label of a node
void node_labelWrite(node * n, void * label);

// Return the left tree of a node
node * node_leftTreeRead(node * n);

// Return the right tree of a node
node * node_rightTreeRead(node * n);

// Write the left tree of a node
void node_leftTreeWrite(node * n, node * left);

// Write the right tree of a node
void node_rightTreeWrite(node * n, node * right);

// Return true if the node exist
bool node_exist(node * n);

// Return true if the node is a leaf
bool node_isLeaf(node * n);

// Return true if the node is father
bool node_isFather(node * n);

// Create a node
node * node_create(int number, void * label, node * left, node * right);

// Destroy the node
void node_destroy(node ** n);

// Print a node (must give a function pointer to print the label)
void node_print(node * n, void (*labelPrint)(void *));

// Return the pointer to the node with the number given
node * node_numberSearch(node * n, int number);



#endif
