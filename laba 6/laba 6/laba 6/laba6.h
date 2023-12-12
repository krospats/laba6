void task1();


int* randomArray(int arrayLength);
int* reverseArray(int arrayLength);
int* normalArray(int arrayLength);

void insertionSort(int* arrayOfNums, int arrayLength);
void insertionSortOdd(int* arrayOfNums, int arrayLength);
void insertionSortEven(int* arrayOfNums, int arrayLength);

void bubbleSort(int* arrayOfNums, int arrayLength);
void bubbleSortOdd(int* arrayOfNums, int arrayLength);
void bubbleSortEven(int* arrayOfNums, int arrayLength);

void printArray(int* arrayOfNums, int arrayLength);
int scan(int a, int b);

void timer(int* arrayOfNums, int arrayLength);

void task2();

void matrixLength(int* rows, int* columns);
int** randomMatrix(int* rows, int* columns);
void printMatrix(int** matrixOfNums, int rows, int columns, int choose);

int** sumOfEvenElements(int** matrixOfNums, int *rows, int *columns);
void shellSort(int** tempMatrix, int rows);
int** makeSortedArray(int** matrixOfNums, int** tempMatrix, int* rows, int* columns);
void deleteMatrix(int** matrixOfNums, int *rows);