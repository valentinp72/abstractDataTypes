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
	if(*n != NULL)
		free(*n);
	*n = NULL;
}

// Destroy the node and their childs
void node_destoryChilds(node ** n){
	if(*n != NULL){
		node_destoryChilds(&((*n)->left));
		node_destoryChilds(&((*n)->right));
		node_destroy(n);
	}
}

// Print a node (must give a function pointer to print the label)
void node_print(node * n, void (*labelPrint)(void *)){
	if(n != NULL){
		printf("Node n°%i:\n\tLabel: ", n->number);
		labelPrint(n->label);
		printf("\n\tLeft-tree: %p | Right-tree: %p\n", n->left, n->right);
	}
}

// Print a givent amount of space (for drawing the tree) 
void printDepth(int depth){
	int i;
	for(i = 0 ; i < depth ; i++)
		printf("│   ");
}

// Print a node and all their childs
void node_printChilds(node * n, void (*labelPrint)(void *), int depth){
	if(n != NULL){

		// Print the node
		labelPrint(n->label);


		// Print the left child
		if(n->left != NULL){
			printf("\n");
			printDepth(depth);
			
			// Choose between a simple and multiple corner
			if(n->right != NULL)
				printf("├");
			else 
				printf("└");

			printf("── ");
			node_printChilds(n->left, labelPrint, depth + 1);
		}


		// Print the right child
		if(n->right != NULL){
			printf("\n");
			printDepth(depth);
			printf("└── ");
			node_printChilds(n->right, labelPrint, depth + 1);
		}
	}
}

// Return the pointer to the node with the number given
node * node_numberSearch(node * n, int number){
	node * leftSearch, * rightSearch;

	if(n != NULL){
		if(n->number == number)
			return n;		

		leftSearch  = node_numberSearch(n->left, number);
		rightSearch = node_numberSearch(n->right, number);

		if(leftSearch != NULL)
			return leftSearch;
		return rightSearch;
	}
	return NULL;
}

/* ---------------------------------------- */
/* FUNCTIONS FOR PRINTING SOME LABELS TYPES */
/* ---------------------------------------- */

// Print a label that is an int
void label_printInt(void * e){
	int * i = e;
	printf("%i", *i);
}

// Print a label that is a long
void label_printLong(void * e){
	long * l = e;
	printf("%li", *l);
}

// Print a label that is a float
void label_printFloat(void * e){
	float * f = e;
	printf("%f", *f);
}

// Print a label that is a double
void label_printDouble(void * e){
	double * d = e;
	printf("%f", *d);
}

// Print a label that is a boolean
void label_printBool(void * e){
	bool * b = e;
	printf("%i", *b);
}

// Print a label that is a pointer
void label_printPointer(void * e){
	
	printf("%p", e);
}

// Print a label that is a char
void label_printChar(void * e){
	char * c = e;
	printf("%c", *c);
}

// Print a label that is a string
void label_printString(void * e){
	char * str = e;
	printf("%s", str);
}


/* ----------------------- */
/* FUNCTIONS FOR THE TREES */
/* ----------------------- */

// Return true if the tree is empty
bool tree_isEmpty(binaryTree * t){
	if(t != NULL)
		return t->size == 0;
	return true;
}

// Create and return a pointer to a tree
binaryTree * tree_create(int size, node * root){
	binaryTree * t = malloc(sizeof(binaryTree));

	t->size = size;
	t->root = root;

	return t;
}

// Destory a tree (and all it's nodes)
void tree_destroy(binaryTree ** t){
	if(t != NULL){
		node_destoryChilds(&((*t)->root));	
		free(*t);
	}
	*t = NULL;
}

// Print a tree
void tree_print(binaryTree * t, void (*labelPrint)(void *)){
	if(t != NULL){
		node_printChilds(t->root, labelPrint, 0);
		printf("\n");
	}
}
