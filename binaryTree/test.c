/*
	test.c

	PELLOIN Valentin

	GNU General Public License v3.0
	https://github.com/valentinp72/abstractDataTypes/

*/
#include "binaryTree.h"

#include <time.h> // Random

float random_float(){
	return ((float)rand() / (float)RAND_MAX);
}

int main(){

	// Change this to true if you want to print debug informations
	tree_printDebug = false;


	//
	// STRING TESTING
	//

	printf("******************\n");
	printf("* STRING TESTING *\n");
	printf("******************\n");

	tree * strTree = 
			tree_create(0, "ROOT", strlen("ROOT "), NULL, 
				tree_create(1, "First child", strlen("First child "), NULL, 
					tree_create(3, "I am your father", strlen("I am your father "), NULL,
						tree_create(4, "You must unlearn", strlen("You must unlearn "), NULL, NULL, NULL), 
						tree_create(5, "What you have learned", strlen("What you have learned "), NULL, NULL, NULL)), 
					tree_create(6, "NO YOU ARE NOT MY FATHER", strlen("NO YOU ARE NOT MY FATHER "), NULL, NULL, NULL)), 
				tree_create(2, "Second child", strlen("Second child "), NULL, 
						tree_create(7, "Hello world!", strlen("Hellow world! "), NULL, NULL, NULL), NULL));

	tree_updateFathers(strTree);

	tree_print(strTree, label_printString);

	tree_destroy(&strTree);
	printf("\n");

	
	
	//
	// INT TESTING
	//
	
	printf("***************\n");
	printf("* INT TESTING *\n");
	printf("***************\n");

	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 1000;

	// Initial
	printf("\n > Initial tree : \n");

	tree * intTree = 
			tree_create(0, &a, size_int, NULL, 
				tree_create(1, &b, size_int, NULL,
					tree_create(3, &d, size_int, NULL,
						tree_create(4, &f, size_int, NULL, NULL, NULL), 
						tree_create(5, &g, size_int,NULL, NULL, NULL)), 
					tree_create(6, &e, size_int, NULL, NULL, NULL)), 
				tree_create(2, &c, size_int, NULL, 
						tree_create(7, &h, size_int, NULL, NULL, NULL), NULL));

	tree_updateFathers(intTree);

	tree_print(intTree, label_printInt);

	// Modification of initial values
	printf("\n > Initial values modifications (values should not change): \n");
	a = 100;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	h = 0;

	tree_print(intTree, label_printInt);

	// Update of the labels
	printf("\n > Update of labels (root's label shoud change): \n");

	tree_setLabel(intTree, &a, size_int);
	tree_setLabel(intTree->left, &b, size_int);

	tree_print(intTree, label_printInt);


	tree_destroy(&intTree);
	printf("\n");



	//
	// Random float testing
	//

 	printf("************************\n");
	printf("* RANDOM FLOAT TESTING *\n");
	printf("************************\n");

	int i;
	float value;
	tree * last = NULL;
	tree * floatTree = NULL;

	// Init random
	srand(time(NULL));

	// We create the root
	value = random_float();
	floatTree = tree_create(0, &value, size_float, NULL, NULL, NULL);
	last = floatTree;

	// Creation of all the sub-trees
	for(i = 1 ; i < 20 ; i += 2){
		// Create the sub-left tree
		value = random_float();
		last->left  = tree_create(i, &value, size_float, last, NULL, NULL);

		// Create the sub-right tree
		value = random_float();
		last->right = tree_create(i + 1, &value, size_float, last, NULL, NULL);
		
		// Alternate between left and right (tree's shape is random)
		if(value < 0.5)
			last = last->left;
		else
			last = last->right;
	}

	tree_print(floatTree, label_printFloat);

	tree_destroy(&floatTree);

}
