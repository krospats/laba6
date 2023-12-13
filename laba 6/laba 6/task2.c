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
		printf("This program finds the maximum element in each column and sorts the columns in descending order of the maximum element in them using shell sort.");
		matrixLength(&rows, &columns);
		matrixOfNums = randomMatrix(&rows, &columns);
		printMatrix(matrixOfNums, rows, columns, 1);
		int** tempMatrix = findMaxElements(matrixOfNums, &rows, &columns);
		shellSort(tempMatrix, columns);
		printMatrix(tempMatrix, tempRows, columns, 2);
		int** sortedMatrix = makeSortedMatrix(matrixOfNums, tempMatrix, &rows, &columns);
		printMatrix(sortedMatrix, rows, columns, 3);
		deleteMatrix(matrixOfNums, &rows);
		deleteMatrix(tempMatrix, &tempRows);
		deleteMatrix(sortedMatrix, &rows);
		printf("\nDo you want to continue to use this task?(1 - yes; 2 - no) - ");
		continueFlag = scan(1, 2);
	} while (continueFlag == 1);
	
}