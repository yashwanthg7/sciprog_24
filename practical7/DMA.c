#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *allocatearray(int size) {
    return (int *)malloc(size * sizeof(int));
}

void fillwithones(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

void printarray(int *array, int size) {
    //size of the array is required taditional to iterate through the elements 
    //and assign the value 1.
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void freepointer(int *array) {
    free(array);
}

int main() {
    int size = 10;
    int *array = allocatearray(size);

    fillwithones(array, size);

    printf("Array with ones: ");
    printarray(array, size);

    freepointer(array);

    return 0;
}

