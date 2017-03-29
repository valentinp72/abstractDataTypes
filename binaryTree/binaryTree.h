#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

#if __STDC_VERSION__ >= 199901L
	#include <stdbool.h>
#else
	typedef enum {false, true} bool;
#endif

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

// Destroy the node and their childs
void node_destoryChilds(node ** n);

// Print a node (must give a function pointer to print the label)
void node_print(node * n, void (*labelPrint)(void *));

// Print a node and all their childs
void node_printChilds(node * n, void (*labelPrint)(void *), int depth);

// Return the pointer to the node with the number given
node * node_numberSearch(node * n, int number);


/* ---------------------------------------- */
/* FUNCTIONS FOR PRINTING SOME LABELS TYPES */
/* ---------------------------------------- */

// Print a label that is an int
void label_printInt(void * e);

// Print a label that is a long
void label_printLong(void * e);

// Print a label that is a float
void label_printFloat(void * e);

// Print a label that is a double
void label_printDouble(void * e);

// Print a label that is a boolean
void label_printBool(void * e);

// Print a label that is a pointer
void label_printPointer(void * e);

// Print a label that is a char
void label_printChar(void * e);

// Print a label that is a string
void label_printString(void * e);


/* ----------------------- */
/* FUNCTIONS FOR THE TREES */
/* ----------------------- */

// Return true if the tree is empty
bool tree_isEmpty(binaryTree * t);

// Create and return a pointer to a tree
binaryTree * tree_create(int size, node * root);

// Destory a tree (and all it's nodes)
void tree_destroy(binaryTree ** t);

// Print a tree
void tree_print(binaryTree * t, void (*labelPrint)(void *));



#endif
