#include <stdio.h> 
#include <locale.h>
#include <malloc.h>
#include "laba6.h"
int main() {
	int chooseTask;
	int continueFlag;
	
	do {
		printf("\nChoose task(1 or 2) - ");
		chooseTask = scan(1, 2);
		if (chooseTask == 1) task1();
		else task2();
		printf("\nDo you want to continue to use this code?(1 - yes; 2 - no) - ");
		continueFlag = scan(1, 2);
	} while (continueFlag == 1);
	
}