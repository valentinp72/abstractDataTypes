/*
	binaryTree.c

	PELLOIN Valentin

	GNU General Public License v3.0
	https://github.com/valentinp72/abstractDataTypes/

*/
#include "binaryTree.h"


// Used to know if we have to draw the vertical lines
#define MAX_BAR 1024

// ANSI colors
#define TREE_COLOR_RED     "\x1b[31m"
#define TREE_COLOR_GREEN   "\x1b[32m"
#define TREE_COLOR_YELLOW  "\x1b[33m"
#define TREE_COLOR_BLUE    "\x1b[34m"
#define TREE_COLOR_MAGENTA "\x1b[35m"
#define TREE_COLOR_CYAN    "\x1b[36m"
#define TREE_COLOR_RESET   "\x1b[0m"

// Color of the characters used to display the bars and corners
#define TREE_DISPLAY_COLOR TREE_COLOR_BLUE

// Characters used to display the tree
#define TREE_CORNER         "└"
#define TREE_CENTER         "├"
#define TREE_HORIZONTAL_BAR "──"
#define TREE_VERTICAL_BAR   "│"


// Default value for debug
// Don't touch this, change it within your code
bool tree_printDebug = false;


/* ----------------------- */
/* FUNCTIONS FOR THE TREES */
/* ----------------------- */

// Return true if the tree exist
bool tree_exist(tree * t){
	return t != NULL;
}

// Return true if the tree is a leaf
bool tree_isLeaf(tree * t){
	return t != NULL && t->left == NULL && t->right == NULL;
}

// Return true if the tree is father
bool tree_isFather(tree * t){
	return !tree_isLeaf(t);
}

// Return the depth of the tree (distance between the given tree and the root)
int tree_depth(tree * t){
	if(t != NULL)
		return 1 + tree_depth(t->father);
	return 0;
}

// Return the max between a and b
int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

// Return the height of the tree (maximum distance between a tree and it's childs)
int tree_height(tree * t){
	if(t != NULL){
		return 1 + max(tree_height(t->left), tree_height(t->right));	
	}
	return 0;
}

// Return the pointer to the node in the tree with the number given
tree * tree_numberSearch(tree * t, int number){
	tree * leftSearch, * rightSearch;

	if(t != NULL){
		if(t->number == number)
			return t;

		leftSearch  = tree_numberSearch(t->left, number);
		rightSearch = tree_numberSearch(t->right, number);

		if(leftSearch != NULL)
			return leftSearch;
		return rightSearch;
	}
	return NULL;
}

// Create a tree
tree * tree_create(int number, void * label, size_t size, tree* father, tree * left, tree * right){
	tree * t = malloc(sizeof(tree));

	t->number = number;
	t->label  = NULL;
	t->father = father;
	t->left   = left;
	t->right  = right;

	tree_setLabel(t, label, size);

	return t;
}

// Set the label of the tree (by creating a copy)
void tree_setLabel(tree * t, void * label, size_t size){
	if(t != NULL){
		if(t->label != NULL)
			free(t->label);		
		t->label = malloc(size);
		memcpy(t->label, label, size);
	}
}

// Update the pointers for the father for all the tree
void tree_updateFathers(tree * t){
	if(t != NULL){
		if(t->left != NULL){
			t->left->father = t;
			tree_updateFathers(t->left);
		}
		if(t->right != NULL){
			t->right->father = t;
			tree_updateFathers(t->right);
		}
	}
}

// Destroy the node only
void tree_destroyOnlyNode(tree ** t){
	if(*t != NULL){
		free((*t)->label);
		(*t)->label = NULL;
		free(*t);
	}
	*t = NULL;
}

// Destroy the tree and their childs
void tree_destroy(tree ** t){
	if(*t != NULL){
		tree_destroy(&((*t)->left));
		tree_destroy(&((*t)->right));
		tree_destroyOnlyNode(t);
	}
}

// A table for knowing if we have to display vertical bars
bool bar[MAX_BAR] = {true};

// Print a givent amount of space (for drawing the tree)
void printDepth(int depth){
	int i;
	printf("%s", TREE_DISPLAY_COLOR);
	for(i = 0 ; i < depth ; i++)
		if(i < MAX_BAR && bar[i] == true)
			printf("%s   ", TREE_VERTICAL_BAR);
		else
			printf("    ");
}

// Print a tree (source function for tree_print)
void tree_printSRC(tree * t, void (*labelPrint)(void *), int depth, int base){
	if(t != NULL){

		// Print the tree
		printf("%s", TREE_COLOR_RESET);
		labelPrint(t->label);
		printf("%s", TREE_COLOR_RESET);

		if(tree_printDebug){
			printf(" | {n°: %s%i%s} - {@: %s%p%s} - {father: %s%p%s} - {left: %s%p%s | right: %s%p%s}", 
				TREE_COLOR_BLUE, t->number, TREE_COLOR_RESET,
				TREE_COLOR_BLUE, t,         TREE_COLOR_RESET,
				TREE_COLOR_BLUE, t->father, TREE_COLOR_RESET,
				TREE_COLOR_BLUE, t->left,   TREE_COLOR_RESET,
				TREE_COLOR_BLUE, t->right,  TREE_COLOR_RESET
			);
		}

		// Print the left child
		if(t->left != NULL){
			printf("\n");
			printDepth(depth);

			// Choose between a simple and multiple corner
			if(t->right != NULL){
				printf("%s", TREE_CENTER);
				bar[depth] = true;
			}
			else {
				printf("%s", TREE_CORNER);
				bar[depth] = false;
			}

			printf("%s ", TREE_HORIZONTAL_BAR);
			tree_printSRC(t->left, labelPrint, depth + 1, base + depth);
		}


		// Print the right child
		if(t->right != NULL){
			printf("\n");
			printDepth(depth);
			printf("%s%s ", TREE_CORNER, TREE_HORIZONTAL_BAR);
			bar[depth] = false;
			tree_printSRC(t->right, labelPrint, depth + 1, base + depth);
		}
	}
}

// Print all a tree
void tree_print(tree * t, void (*labelPrint)(void *)){
	tree_printSRC(t, labelPrint, 0, 0);
	printf("\n");
}

