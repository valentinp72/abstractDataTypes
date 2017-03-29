#include "binaryTree.h"

int main(){
	
	// STRING TESTING

	node * strNodes = 
			node_create(0, "ROOT", 
				node_create(1, "First child", 
					node_create(3, "I am your father",
						node_create(4, "You must unlearn", NULL, NULL), 
						node_create(5, "What you have learned", NULL, NULL)), 
					node_create(6, "NO YOU ARE NOT MY FATHER", NULL, NULL)), 
				node_create(2, "Second child", NULL, NULL));

	binaryTree * strTree = tree_create(1, strNodes);

	tree_print(strTree, label_printString);

	tree_destroy(&strTree);

	// INT TESTING

	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6;
	int *pA = &a, *pB = &b, *pC = &c, *pD = &d, *pE = &e, *pF = &f, *pG = &g;

	node * intNodes = 
			node_create(0, pA, 
				node_create(1, pB, 
					node_create(3, pD,
						node_create(4, pF, NULL, NULL), 
						node_create(5, pG, NULL, NULL)), 
					node_create(6, pE, NULL, NULL)), 
				node_create(2, pC, NULL, NULL));

	binaryTree * intTree = tree_create(1, intNodes);
	
	tree_print(intTree, label_printInt);

	tree_destroy(&intTree);

}
