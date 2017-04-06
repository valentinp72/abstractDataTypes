/*
	test.c

	PELLOIN Valentin

	GNU General Public License v3.0
	https://github.com/valentinp72/abstractDataTypes/

*/
#include "labels.h"

int main(){
	int    aInt     = 1;
	long   aLong    = 2;
	float  aFloat   = 1.5;
	double aDouble  = 2.5;
	bool   aBool1   = true;
	bool   aBool2   = false;
	int *  aPointer = NULL;
	char   aChar    = 'A';
	char * aString  = "Hello world!";

	printf("Int\t: ");
	label_printInt(&aInt);

	printf("\nLong\t: ");
	label_printLong(&aLong);

	printf("\nFloat\t: ");
	label_printFloat(&aFloat);

	printf("\nDouble\t: ");
	label_printDouble(&aDouble);

	printf("\nBool\t: ");
	label_printBool(&aBool1);
	printf("\nBool\t: ");
	label_printBool(&aBool2);

	printf("\nPointer\t: ");
	label_printPointer(&aPointer);
	
	printf("\nChar\t: ");
	label_printChar(&aChar);

	printf("\nString\t: ");
	label_printString(aString);

	printf("\n");
}
