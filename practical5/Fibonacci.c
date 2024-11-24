#include <stdio.h>


void next_fibonacci(int *f_0, int *f_1, int *f_n) {
    *f_n = *f_0 + *f_1;
    *f_0 = *f_1;       
    *f_1 = *f_n;
}

void fibonacci_series(int n) {
    int f_0 = 0;
    int f_1 = 1;
    int f_n = 0;

    printf("Fibonacci Series up to %d: %d %d ", n, f_0, f_1);

    
    for (int i = 2; i < n; i++) {
        next_fibonacci(&f_0, &f_1, &f_n);
        printf("%d ", f_n); 
    }
    printf("\n");
}

int main() {
    // Fibonacci Series
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 1) { // Handle invalid input
        printf("Error: n must be greater than 1.\n");
        return 1;
    }

    fibonacci_series(n);
    return 0;
}

