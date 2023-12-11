#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "laba6.h"
int* randomArray(int arrayLength) {
	int* arrayOfNums = (int*)malloc(arrayLength * sizeof(int));
	for (int i = 0; i < arrayLength; i++) {
		srand(time(NULL) * (i + rand() % 100));
		arrayOfNums[i] = rand() % 100;
	}
	return arrayOfNums;
}
int* normalArray(int arrayLength) {
	int* arrayOfNums = (int*)malloc(arrayLength * sizeof(int));
	for (int i = 0; i < arrayLength; i++) {
		if (i % 2 == 0) arrayOfNums[i] = i / 2 + 1;
		else arrayOfNums[i] = (arrayLength - i + 1)/2;
	}
	return arrayOfNums;
}
int* reverseArray(int arrayLength) {
	int* arrayOfNums = (int*)malloc(arrayLength * sizeof(int));
	for (int i = 0; i < arrayLength; i++) {
		if (i % 2 == 0) arrayOfNums[i] = (arrayLength - i) / 2;
		else arrayOfNums[i] = i / 2 + 1;
	}
	return arrayOfNums;
}
void insertionSortEven(int* arrayOfNums, int arrayLength) {
	int buferVariable;
	for (int i = 0; i < arrayLength; i += 2) {
		buferVariable = arrayOfNums[i];
		for (int step = 2; i - step >= 0 && arrayOfNums[i] < arrayOfNums[i - 2]; step += 2) {
			if (arrayOfNums[i] >= arrayOfNums[i - step] && step != 2) {
				for (int j = i - 2; j >= i - step; j -= 2) {
					arrayOfNums[j + 2] = arrayOfNums[j];
				}
				arrayOfNums[i - step + 2] = buferVariable;
				break;
			}
			if ((i - step == 0) && (arrayOfNums[i] < arrayOfNums[i - step])) {
				for (int j = i - 2; j >= i - step; j -= 2) {
					arrayOfNums[j + 2] = arrayOfNums[j];
				}
				arrayOfNums[i - step] = buferVariable;
				break;
			}
			
		}
	}
}
void insertionSortOdd(int* arrayOfNums, int arrayLength) {
	int buferVariable;
	for (int i = 1; i < arrayLength; i += 2) {
		buferVariable = arrayOfNums[i];
		for (int step = 2; i - step >= 1 && arrayOfNums[i] > arrayOfNums[i - 2]; step += 2) {
			if (arrayOfNums[i] <= arrayOfNums[i - step] && step != 2) {
				for (int j = i - 2; j >= i - step; j -= 2) {
					arrayOfNums[j + 2] = arrayOfNums[j];
				}
				arrayOfNums[i - step + 2] = buferVariable;
				break;
			}
			if ((i - step == 1) && (arrayOfNums[i] > arrayOfNums[i - step])) {
				for (int j = i - 2; j >= i - step; j -= 2) {
					arrayOfNums[j + 2] = arrayOfNums[j];
				}
				arrayOfNums[i - step] = buferVariable;
				break;
			}

		}
	}
}
void printArray(int* arrayOfNums, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (i % 2 == 0) printf("[%d] ", arrayOfNums[i]);
		else printf("%d ", arrayOfNums[i]);
	}
	printf("\n\n");
}
void insertionSort(int* arrayOfNums, int arrayLength) {
	insertionSortOdd( arrayOfNums, arrayLength); 
	insertionSortEven(arrayOfNums, arrayLength);
}
void bubbleSort(int* arrayOfNums, int arrayLength) {
	bubbleSortOdd(arrayOfNums, arrayLength);
	bubbleSortEven(arrayOfNums, arrayLength);
}
void bubbleSortOdd(int* arrayOfNums, int arrayLength) {
	int buferVariable;
	for (int move = 0; move < arrayLength / 2; move++) {
		for (int i = 3; i < arrayLength; i += 2) {
			if (arrayOfNums[i] > arrayOfNums[i - 2]) {
				buferVariable = arrayOfNums[i];
				arrayOfNums[i] = arrayOfNums[i - 2];
				arrayOfNums[i - 2] = buferVariable;
			}
		}
	}
}
void bubbleSortEven(int* arrayOfNums, int arrayLength) {
	int buferVariable;
	for (int move = 0; move < arrayLength / 2; move ++) {
		for (int i = 2; i < arrayLength; i += 2) {
			if (arrayOfNums[i] < arrayOfNums[i - 2]) {
				buferVariable = arrayOfNums[i];
				arrayOfNums[i] = arrayOfNums[i - 2];
				arrayOfNums[i - 2] = buferVariable;
			}
		}
	}
}
void timer(int* arrayOfNums, int arrayLength) {
	int chooseArray;
	int chooseSort;
	int continueFlag;
	int printAllow;
	clock_t start, end;
	do {
		printf("1 - random array, 2 - sorted array, 3 - reversed array - ");
		chooseArray = scan(1, 3);
		switch (chooseArray) {
		case 1:
			arrayOfNums = randomArray(arrayLength);
			break;
		case 2:
			arrayOfNums = normalArray(arrayLength);
			break;
		case 3:
			arrayOfNums = reverseArray(arrayLength);
			break;
		}
		printf("Do you want to print array?\n(1 - yes, any other number - no)");
		printAllow = scan(-10000000000, 1000000000);
		if (printAllow == 1) printArray(arrayOfNums, arrayLength);
		printf("1 - bubble sort , 2 - insertion sort - ");
		chooseSort = scan(1, 2);
		start = clock();
		if (chooseSort == 1) bubbleSort(arrayOfNums, arrayLength);
		else insertionSort(arrayOfNums, arrayLength);
		end = clock();

		printf("\ntime is %d ms\n", (end - start));

		printf("Do you want to print array?\n(1 - yes, any other number - no)");
		printAllow = scan(-10000000000, 1000000000);
		if (printAllow == 1) printArray(arrayOfNums, arrayLength);
		printf("\nDo you want to continue to use this sorts?(1 - yes; 2 - no) - ");
		continueFlag = scan(1, 2);
	} while (continueFlag == 1);
	
}












int scan(int a, int b) {
	int variable;
	while (scanf_s("%8d", &variable) == 0 || getchar() != '\n' || variable < a || variable > b) {
		printf("\nIncorrect input\n");
		rewind(stdin);
	}
	return variable;
}













void matrixLength(int* rows, int* columns) {
	printf("\nChoose amount of rows(1 - 100) - ");
	*rows = scan(1, 100);
	printf("Choose length of columns(1 - 100) - ");
	*columns = scan(1, 100);
}
int** randomMatrix(int rows, int columns) {
	int** matrixOfNums = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrixOfNums[i] = (int*)malloc(columns * sizeof(int));
	}
		for (int i = 0; i < rows; i++) {
			srand(time(NULL) * (i + rand() % 100));
			for (int j = 0; j < columns; j++) {
				matrixOfNums[i][j] = rand() % 100;
			}
		}
		return matrixOfNums;
	
}
void printMatrix(int** matrixOfNums, int rows, int columns, int choose) {
	printf("\n");
	if (choose == 1) printf("original matrix:\n");
	else if (choose == 2) printf("sums and indexes:\n");
	else  printf("sorted matrix:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%d ", matrixOfNums[i][j]);
		}
		printf("\n");
	}
}
int** sumOfEvenElements(int** matrixOfNums, int rows, int columns) {
	int** tempMatrix = (int**)malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; i++) {
		tempMatrix[i] = (int*)malloc(rows * sizeof(int));
	}
	for (int i = 0; i < rows; i++) {
		tempMatrix[0][i] = 0;
		for (int j = 0; j < columns; j++) {
			if (j % 2 == 0) tempMatrix[0][i] += matrixOfNums[i][j];
		}
		for (int i = 0; i < rows; i++) {
				tempMatrix[1][i] = i;
		}
	}
	return tempMatrix;
}
void shellSort(int** tempMatrix, int rows) {
	int buferVariable;
	int buferIndex;
	int i;
	for (int step = rows / 2; step != 0; step /=2) {
		for (i = 0; i < rows; i++) {
			buferVariable = tempMatrix[0][i];
			buferIndex = tempMatrix[1][i];
			for (int j = step; i - j >= 0; j += step) {
				if (tempMatrix[0][i] <= tempMatrix[0][i - j]) {
					for (int k = i - step; k >= i - j; k-=step) {
						tempMatrix[0][k + step] = tempMatrix[0][k];
						tempMatrix[1][k + step] = tempMatrix[1][k];
					}
					tempMatrix[0][i - j + step] = buferVariable;
					tempMatrix[1][i - j + step] = buferIndex;

					break;
				}
				if ((i - j == 0) && (tempMatrix[0][i]  > tempMatrix[0][i - j])) {
					for (int k = i - step; k >= i - j; k-=step) {
						tempMatrix[0][k + step] = tempMatrix[0][k];
						tempMatrix[1][k + step] = tempMatrix[1][k];
					}
					tempMatrix[0][i - j] = buferVariable;
					tempMatrix[1][i - j] = buferIndex;
					break;
				}
			}
		}
	}
}
int** makeSortedArray(int** matrixOfNums, int** tempMatrix, int rows, int columns) {
	int** sortedMatrix = (int**)malloc(rows * sizeof(int*));
	int element;
	for (int i = 0; i < rows; i++) {
		sortedMatrix[i] = (int*)malloc(columns * sizeof(int));
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			element = tempMatrix[1][i];
			sortedMatrix[i] = matrixOfNums[element];
		}
	}
	return sortedMatrix;
}
void deleteMatrix(int** matrixOfNums, int rows) {
	for (int i = 0; i < rows; i++) {
		matrixOfNums[i] = NULL;
		free(matrixOfNums[i]);
	}
	matrixOfNums = NULL;
	free(matrixOfNums);
}
