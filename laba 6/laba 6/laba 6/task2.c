#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include "laba6.h"
void task2() {

	int** matrixOfNums;
	int rows;
	int columns;
	int continueFlag;
	int tempRows = 2;

	do {
		printf("This program calculates the sum of elements with even column numbers and sorts them in descending order using shell sort");
		matrixLength(&rows, &columns);
		matrixOfNums = randomMatrix(&rows, &columns);
		printMatrix(matrixOfNums, rows, columns, 1);
		int** tempMatrix = sumOfEvenElements(matrixOfNums, &rows, &columns);
		shellSort(tempMatrix, rows);
		printMatrix(tempMatrix, tempRows, rows, 2);
		int** sortedMatrix = makeSortedArray(matrixOfNums, tempMatrix, &rows, &columns);
		printMatrix(sortedMatrix, rows, columns, 3);
		deleteMatrix(matrixOfNums, &rows);
		deleteMatrix(tempMatrix, &tempRows);
		deleteMatrix(sortedMatrix, &rows);
		printf("\nDo you want to continue to use this task?(1 - yes; 2 - no) - ");
		continueFlag = scan(1, 2);
	} while (continueFlag == 1);
	
}