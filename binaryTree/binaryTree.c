#include "binaryTree.h"

// Default value for debug. Don't touch this, change it within your code
bool tree_printDebug = false;


/* ----------------------- */
/* FUNCTIONS FOR THE TREES */
/* ----------------------- */

// Return the number of a tree
int tree_numberRead(tree * t){
	if(t != NULL)
		return t->number;
	return ERROR;
}

// Write the number in a tree
void tree_numberWrite(tree * t, int number){
	if(t != NULL)
		t->number = number;
}

// Return the label of a tree
void * tree_labelRead(tree * t){
	if(t != NULL)
		return t->label;
	return NULL;
}

// Write the label of a tree
void tree_labelWrite(tree * t, void * label){
	if(t != NULL)
		t->label = label;
}

// Return the left tree of a tree
tree * tree_leftTreeRead(tree * t){
	if(t != NULL)
		return t->left;
	return NULL;
}

// Return the right tree of a tree
tree * tree_rightTreeRead(tree * t){
	if(t != NULL)
		return t->right;
	return NULL;
}

// Write the left tree of a tree
void tree_leftTreeWrite(tree * t, tree * left){
	if(t != NULL)
		t->left = left;
}

// Write the right tree of a tree
void tree_rightTreeWrite(tree * t, tree * right){
	if(t != NULL)
		t->right = right;
}

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

// Create a tree
tree * tree_create(int number, void * label, tree* father, tree * left, tree * right){
	tree * t = malloc(sizeof(tree));

	t->number = number;
	t->label  = label;
	t->father = father;
	t->left   = left;
	t->right  = right;

	return t;
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

// Destroy the tree
void tree_destroyOnly(tree ** t){
	if(*t != NULL)
		free(*t);
	*t = NULL;
}

// Destroy the tree and their childs
void tree_destroy(tree ** t){
	if(*t != NULL){
		tree_destroy(&((*t)->left));
		tree_destroy(&((*t)->right));
		tree_destroyOnly(t);
	}
}

// Return the height of the tree
int tree_height(tree * t){
	if(t != NULL)
		return 1 + tree_height(t->father);
	return 0;
}

// A table for knowing if we have to display vertical bars
bool bar[1024] = {true};

// Print a givent amount of space (for drawing the tree)
void printDepth(int depth){
	int i;
	printf("%s", TREE_COLOR_YELLOW);
	for(i = 0 ; i < depth ; i++)
		if(bar[i] == true)
			printf("│   ");
		else
			printf("    ");
}

// Print a tree and all their childs
void tree_printChilds(tree * t, void (*labelPrint)(void *), int depth, int base){
	if(t != NULL){

		// Print the tree
		printf("%s", TREE_COLOR_RESET);
		labelPrint(t->label);
		printf("%s", TREE_COLOR_RESET);

		if(tree_printDebug){
			printf(" | {n°: %s%i%s} - {@: %s%p%s} - {father: %s%p%s} - {left: %s%p%s | right: %s%p%s}", 
							TREE_COLOR_BLUE, 
							t->number,
							TREE_COLOR_RESET,
							TREE_COLOR_BLUE,
							t, 
							TREE_COLOR_RESET,
							TREE_COLOR_BLUE,
							t->father,
							TREE_COLOR_RESET,
							TREE_COLOR_BLUE,
							t->left,
							TREE_COLOR_RESET,
							TREE_COLOR_BLUE,
							t->right,
							TREE_COLOR_RESET);
		}

		// Print the left child
		if(t->left != NULL){
			printf("\n");
			printDepth(depth);

			// Choose between a simple and multiple corner
			if(t->right != NULL){
				printf("├");
				bar[depth] = true;
			}
			else {
				printf("└");
				bar[depth] = false;
			}

			printf("── ");
			tree_printChilds(t->left, labelPrint, depth + 1, base + depth);
		}


		// Print the right child
		if(t->right != NULL){
			printf("\n");
			printDepth(depth);
			printf("└── ");
			bar[depth] = false;
			tree_printChilds(t->right, labelPrint, depth + 1, base + depth);
		}
	}
}

// Print all a tree
void tree_print(tree * t, void (*labelPrint)(void *)){
	tree_printChilds(t, labelPrint, 0, 0);
	printf("\n");
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


