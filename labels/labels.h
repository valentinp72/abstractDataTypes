/*
	labels.h

	PELLOIN Valentin

	GNU General Public License v3.0
	https://github.com/valentinp72/abstractDataTypes/

*/
#ifndef LABELS_H
#define LABELS_H

#include <stdio.h>
#include <stdbool.h>

/* --------------- */
/* SIZE FOR LABELS */
/* --------------- */

extern const size_t size_int;
extern const size_t size_long;
extern const size_t size_float;
extern const size_t size_double;
extern const size_t size_bool;
extern const size_t size_pointer;
extern const size_t size_char;

/* ---------------------------------------- */
/* FUNCTIONS FOR PRINTING SOME LABELS TYPES */
/* ---------------------------------------- */

// Print a label that is an int
void label_printInt(void * e);

// Print a label that is a long
void label_printLong(void * e);

// Print a label that is a float
void label_printFloat(void * e);

// Print a label that is a double
void label_printDouble(void * e);

// Print a label that is a boolean
void label_printBool(void * e);

// Print a label that is a pointer
void label_printPointer(void * e);

// Print a label that is a char
void label_printChar(void * e);

// Print a label that is a string
void label_printString(void * e);

#endif
