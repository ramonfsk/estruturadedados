#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VETOR 10

void merge(int *array, int left, int medium, int right);
void mergeSort(int *array, int lef, int right);
void quickSort(int *array, int begin, int end);
int binarySearch(int data, int *array);

int main() {
//Declarações
	int numberSeek, locationIndex, vNumbers1[MAX_VETOR] = {0};
	int arraySize = sizeof(vNumbers1)/sizeof(vNumbers1[0]);
	int countAmount;
//Inicializações
	numberSeek = 0;
	locationIndex = 0;
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
	printf("|\n\n");
	
	printf("Informe um numero para realizar a busca: ");
	scanf("%i", &numberSeek);
	locationIndex = binarySearch(numberSeek, vNumbers1);
	
	if(locationIndex < 0){
		printf("\n\n*** Numero nao localizado! ***\n");
	}else{
		printf("\nO numero %i foi encontrado na posicao %i do vetor.", numberSeek, locationIndex);
	}

	return 0;
}

int binarySearch(int data, int *array){
	int lowerBound = 0;
	int upperBound = MAX_VETOR -1;
	int midPoint = -1;
	int comparisons = 0;      
	int index = -1;
	
	while(lowerBound <= upperBound) {
		printf("Comparison %d\n" , (comparisons +1) );
		printf("lowerBound : %d, intArray[%d] = %d\n",lowerBound, lowerBound, array[lowerBound]);
		printf("upperBound : %d, intArray[%d] = %d\n",upperBound, upperBound, array[upperBound]);
		comparisons++;
		// compute the mid point
		// midPoint = (lowerBound + upperBound) / 2;
		midPoint = lowerBound + (upperBound - lowerBound) / 2;
      // data found
		if(array[midPoint] == data) {
			index = midPoint;
			break;
		}else{
			// if data is larger 
			if(array[midPoint] < data) {
				// data is in upper half
				lowerBound = midPoint + 1;
				// data is smaller 
			}else{
				// data is in lower half 
				upperBound = midPoint -1;
			}
		}            
	}
   
	printf("Total comparisons made: %d" , comparisons);
   
	return index;
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
