/*
	binaryTree.h

	PELLOIN Valentin

	GNU General Public License v3.0
	https://github.com/valentinp72/abstractDataTypes/

*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string.h>
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

// Return the depth of the tree (distance between the given tree and the root)
int tree_depth(tree * t);

// Return the height of the tree (maximum distance between a tree and it's childs)
int tree_height(tree * t);

// Return true if the tree exist
bool tree_exist(tree * t);

// Return true if the tree is a leaf
bool tree_isLeaf(tree * t);

// Return true if the tree is father
bool tree_isFather(tree * t);

// Return the pointer to the tree with the number given
tree * tree_numberSearch(tree * t, int number);

// Create a tree
tree * tree_create(int number, void * label, size_t size, tree * father, tree * left, tree * right);

// Set the label of the tree
void tree_setLabel(tree * t, void * label, size_t size);

// Update the pointers for the father for all the tree
void tree_updateFathers(tree * t);

// Destroy the tree and their childs
void tree_destroy(tree ** t);

// Print a tree (must give a function pointer to print the label)
void tree_print(tree * t, void (*labelPrint)(void *));


#endif
