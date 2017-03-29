#include <stdio.h>
#include "binaryTree.h"

void printLabel_String(void * e){
	char * str = e;
	printf("%s", str);
}

int main(){
	char * labelNode = "I'm the root";
	node * testNode = node_create(0, labelNode, NULL, NULL);

	node_print(testNode, printLabel_String);

	node_destroy(&testNode);
}
