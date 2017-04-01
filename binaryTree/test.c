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
				tree_create(2, "Second child", NULL, 
						tree_create(7, "Hello world!", NULL, NULL, NULL), NULL));

	tree_updateFathers(strTree);

	tree_print(strTree, label_printString);

	tree_destroy(&strTree);

	// INT TESTING

	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 1000;

	tree * intTree = 
			tree_create(0, &a, NULL, 
				tree_create(1, &b, NULL,
					tree_create(3, &d, NULL,
						tree_create(4, &f, NULL, NULL, NULL), 
						tree_create(5, &g, NULL, NULL, NULL)), 
					tree_create(6, &e, NULL, NULL, NULL)), 
				tree_create(2, &c, NULL, 
						tree_create(7, &h, NULL, NULL, NULL), NULL));

	tree_updateFathers(intTree);
	
	tree_print(intTree, label_printInt);

	tree_destroy(&intTree);

}
