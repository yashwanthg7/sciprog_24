#include <stdio.h>

#define n 5
#define p 3
#define q 4

void matmult(int A[n][p], int B[p][q], int C[n][q]);

int main() {
    int A[n][p], B[p][q], C[n][q] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            A[i][j] = i + j;
        }
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            B[i][j] = i - j;
        }
    }

    matmult(A, B, C);

    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

