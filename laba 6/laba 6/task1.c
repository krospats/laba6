#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "laba6.h"



void task1() {
	printf("this program can sort different kinds of arrays (random, sorted, inverted sorted) by insertion and bubble method");
	printf("\nChoose array length(1 - 1 million)");
	int arrayLength = scan(1, 1000000);
	int* arrayOfNums = NULL;

	timer(arrayOfNums, arrayLength);
	free(arrayOfNums);
	
	arrayOfNums = NULL;
}
