#include <stdio.h>

#define n 5
#define p 3
#define q 4

void matmult(int A[n][p], int B[p][q], int C[n][q]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

