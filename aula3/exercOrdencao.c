#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VETOR 100

void bubbleSort(int *vNumbers, int amountElements);
void selectionSort(int *vNumbers, int amountElements);
void insertionSort(int *vNumbers, int amountElements);

int main() {
//Declarações
	int vNumbers1[MAX_VETOR] = {0}, vNumbers2[MAX_VETOR] = {0}, vNumbers3[MAX_VETOR] = {0};
	int countAmount;
//Inicializações
	srand(time(NULL));
//Instruções
	for(countAmount = 0; countAmount < MAX_VETOR; countAmount++) {
		vNumbers1[countAmount] = rand() % MAX_VETOR;
	}

	memcpy(vNumbers2, vNumbers1, sizeof(vNumbers1));
	memcpy(vNumbers3, vNumbers1, sizeof(vNumbers1));

	bubbleSort(vNumbers1, MAX_VETOR);
	selectionSort(vNumbers2, MAX_VETOR);
	insertionSort(vNumbers3, MAX_VETOR);
	
	
	printf("+--------+-----------+-----------+\n");
	printf("| Bubble | Selection | Insertion |\n");
	printf("+--------+-----------+-----------+\n");
	for(countAmount = 0; countAmount < MAX_VETOR; countAmount++) {
		printf("| %-6.3i | %-9.3i | %-9.3i |\n", vNumbers1[countAmount], vNumbers2[countAmount], vNumbers3[countAmount]);
	}
	printf("+--------+-----------+-----------+");

	return 0;
}

void bubbleSort(int *vNumbers, int amountElements) {
//Declarações
	int countAmount, countAux, tempNumber;
//Instruções
	for(countAmount = 0; countAmount < amountElements; countAmount++) {
		for(countAux = 1; countAux < amountElements; countAux++) {
			if(vNumbers[countAux - 1] > vNumbers[countAux]) {
				tempNumber = vNumbers[countAux - 1];
				vNumbers[countAux - 1] = vNumbers[countAux];
				vNumbers[countAux] = tempNumber;
			}
		}
	}
}

void selectionSort(int *vNumbers, int amountElements){
//Declarações
	int countAmount, countAux, min, tempNumber;
//Instruções
	for(countAmount = 0; countAmount < amountElements -1 ; countAmount++) {
		min = countAmount;
		for(countAux = countAmount + 1; countAux < amountElements; countAux++) {
			if(vNumbers[countAux] < vNumbers[min]) {
				min = countAux;
			}
		}
		tempNumber = vNumbers[countAmount];
		vNumbers[countAmount] = vNumbers[min];
		vNumbers[min] = tempNumber;
	}
}

void insertionSort(int *vNumbers, int amountElements){
//Declarações
	int countAmount, countAux, tempNumber;
//Instruções
	for(countAux = 1; countAux < amountElements; countAux++) {
		tempNumber = vNumbers[countAux];
		countAmount = countAux - 1;
		while((countAmount >= 0) && (vNumbers[countAmount] > tempNumber)){
			vNumbers[countAmount + 1] = vNumbers[countAmount--];
		}
		vNumbers[countAmount + 1] = tempNumber;
	}
}
