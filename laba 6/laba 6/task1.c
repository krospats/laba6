#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "laba6.h"



void task1() {
	int continueFlag;
	do {
	printf("this program can sort different kinds of arrays (random, sorted, inverted sorted) by insertion and bubble method");
	printf("\nChoose array length(1 - 1 million)");
	int arrayLength = scan(1, 1000000);
	int* arrayOfNums = NULL;

	timer(arrayOfNums, arrayLength);
	free(arrayOfNums);
	arrayOfNums = NULL;
	printf("\nDo you want to continue to use this task?(1 - yes; 2 - no) - ");
	continueFlag = scan(1, 2);
	} while (continueFlag == 1);
}
