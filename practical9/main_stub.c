#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

// Declare the getlines function
int getlines(char filename[MAX_FILE_NAME]);

int main() {
    FILE *file ;  
    char filename[MAX_FILE_NAME];
    scanf("%s", filename);

    int n = getlines(filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }


    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Read matrix elements from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is a magic square
    if (isMagicSquare(matrix, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Close the file
    fclose(file);

    return 0;
}

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1); // Exit if file cannot be opened
    }

    int ch_read;
    int count = 0;

    // Count the number of lines in the file
    while ((ch_read = fgetc(fp)) != EOF) {
        if (ch_read == '\n') {
            count++;
        }
    }

    fclose(fp);
    return count;
}
