#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include "laba6.h"
void task2() {

	int** matrixOfNums;
	int rows;
	int columns;
	
	printf("his program calculates the sum of elements with even column numbers and sorts them in descending order using shell sort");
	matrixLength(&rows, &columns);
	matrixOfNums = randomMatrix(rows, columns);
	printMatrix(matrixOfNums, rows, columns, 1);
	int** tempMatrix = sumOfEvenElements(matrixOfNums, rows, columns);
	shellSort(tempMatrix, rows);
	printMatrix(tempMatrix, 2, rows, 2);
	int** sortedMatrix = makeSortedArray(matrixOfNums, tempMatrix, rows, columns);
	printMatrix(sortedMatrix, rows, columns, 3);
	deleteMatrix(matrixOfNums, rows);
	deleteMatrix(sortedMatrix, rows);
	deleteMatrix(tempMatrix, 2);
}