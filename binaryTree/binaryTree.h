#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../labels/labels.h"

#define ERROR    1
#define NO_ERROR 0

// Print debugging
extern bool tree_printDebug;

/* ----------------- */
/* TYPES DEFINITIONS */
/* ----------------- */

typedef struct tree_s{
	int number;
	void * label;
	struct tree_s * left;
	struct tree_s * right;
	struct tree_s * father;
} tree;

/* ----------------------- */
/* FUNCTIONS FOR THE TREES */
/* ----------------------- */

// Return the number of a tree
int tree_numberRead(tree * t);

// Write the number in a tree 
void tree_numberWrite(tree * t, int number);

// Return the label of a tree
void * tree_labelRead(tree * t);

// Write the label of a tree
void tree_labelWrite(tree * t, void * label);

// Return the left tree of a tree
tree * tree_leftTreeRead(tree * t);

// Return the right tree of a tree
tree * tree_rightTreeRead(tree * nt);

// Write the left tree of a tree
void tree_leftTreeWrite(tree * t, tree * left);

// Write the right tree of a tree
void tree_rightTreeWrite(tree * t, tree * right);

// Return true if the tree exist
bool tree_exist(tree * t);

// Return true if the tree is a leaf
bool tree_isLeaf(tree * t);

// Return true if the tree is father
bool tree_isFather(tree * t);

// Create a tree
tree * tree_create(int number, void * label, tree * father, tree * left, tree * right);

// Update the pointers for the father for all the tree
void tree_updateFathers(tree * t);

// Destroy the tree and their childs
void tree_destroy(tree ** t);

// Return the height of the tree
int tree_height(tree * t);

// Print a tree (must give a function pointer to print the label)
void tree_print(tree * t, void (*labelPrint)(void *));

// Return the pointer to the tree with the number given
tree * tree_numberSearch(tree * t, int number);


/* ---------------------- */
/* FUNCTIONS FOR COLORING */
/* ---------------------- */

#define TREE_COLOR_RED     "\x1b[31m"
#define TREE_COLOR_GREEN   "\x1b[32m"
#define TREE_COLOR_YELLOW  "\x1b[33m"
#define TREE_COLOR_BLUE    "\x1b[34m"
#define TREE_COLOR_MAGENTA "\x1b[35m"
#define TREE_COLOR_CYAN    "\x1b[36m"
#define TREE_COLOR_RESET   "\x1b[0m"

#endif
