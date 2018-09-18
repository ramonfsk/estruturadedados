#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VETOR 10

void merge(int *array, int left, int medium, int right);
void mergeSort(int *array, int lef, int right);
void quickSort(int *array, int begin, int end);

int main() {
//Declarações
	int vNumbers1[MAX_VETOR] = {0};
	int arraySize = sizeof(vNumbers1)/sizeof(vNumbers1[0]);
	int countAmount;
//Inicializações
	srand(time(NULL));
//Instruções
	for(countAmount = 0; countAmount < MAX_VETOR; countAmount++) {
		vNumbers1[countAmount] = rand() % MAX_VETOR;
	}

	printf("| Array ");
	for(countAmount = 0; countAmount < MAX_VETOR; countAmount++) {
		printf("| %-3.3i ", vNumbers1[countAmount]);
	}
	printf("|\n");
	
	//mergeSort(vNumbers1, 0, (arraySize - 1));
	quickSort(vNumbers1, 0, (arraySize - 1));

	printf("| QuickSort ");
	for(countAmount = 0; countAmount < MAX_VETOR; countAmount++) {
		printf("| %-3.3i ", vNumbers1[countAmount]);
	}
	printf("|\n");

	return 0;
}

int binarySearch(int data){
	
}

void quickSort(int *array, int begin, int end){
	int pivot = array[begin], i = begin, f = end, aux;
	
	do{
		while(array[i] < pivot) i++;
		while(array[f] > pivot) f--;
		if(i <= f){
			aux = array[i];
			array[i++] = array[f];
			array[f--] = aux;
		}
	}while(i < f);
	
	if(begin < f)
		quickSort(array, begin, f);
	if(i < end)
		quickSort(array, i, end);
}

void mergeSort(int *array, int left, int right){
	int medium;
	if(left < right){
		medium = (left + right)/2;
		mergeSort(array, left, medium);
		mergeSort(array, medium+1, right);
		merge(array, left, medium, right);
	}
}

void merge(int *array, int left, int medium, int right){
    int i, j, k;
    int n1 = medium - left + 1; 
    int n2 =  right - medium; 
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = array[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = array[medium + 1+ j]; 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            array[k] = L[i]; 
            i++; 
        }else{ 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1){ 
        array[k] = L[i]; 
        i++; 
        k++; 
    }
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2){ 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 
}
