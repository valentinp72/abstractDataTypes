#include "labels.h"

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


