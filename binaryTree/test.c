#include "binaryTree.h"

int main(){

	tree_printDebug = false;

	// STRING TESTING

	tree * strTree = 
			tree_create(0, "ROOT", NULL, 
				tree_create(1, "First child", NULL, 
					tree_create(3, "I am your father", NULL,
						tree_create(4, "You must unlearn", NULL, NULL, NULL), 
						tree_create(5, "What you have learned", NULL, NULL, NULL)), 
					tree_create(6, "NO YOU ARE NOT MY FATHER", NULL, NULL, NULL)), 
				tree_create(2, "Second child", NULL, NULL, NULL));

	tree_updateFathers(strTree);

	tree_print(strTree, label_printString);

	tree_destroy(&strTree);

	// INT TESTING

	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6;
	int *pA = &a, *pB = &b, *pC = &c, *pD = &d, *pE = &e, *pF = &f, *pG = &g;

	tree * intTree = 
			tree_create(0, pA, NULL, 
				tree_create(1, pB, NULL,
					tree_create(3, pD, NULL,
						tree_create(4, pF, NULL, NULL, NULL), 
						tree_create(5, pG, NULL, NULL, NULL)), 
					tree_create(6, pE, NULL, NULL, NULL)), 
				tree_create(2, pC, NULL, NULL, NULL));

	tree_updateFathers(intTree);
	
	tree_print(intTree, label_printInt);

	tree_destroy(&intTree);

}
