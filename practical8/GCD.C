#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int GCD_iterative ( int a , int b)
{
    int temp;
    while ( b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int GCD_recursive ( int a, int b)
{
    if ( b == 0)
    {
        return a;
    }
    else
    {
        return GCD_recursive(b , a%b);
    }
}
int main()
{
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a < 0) a = -a; // Handle negative inputs
    if (b < 0) b = -b;

    int gcd1 = GCD_iterative(a, b);
    int gcd2 = GCD_recursive(a, b);

    printf("GCD of %d and %d using iterative function: %d\n", a, b, gcd1);
    printf("GCD of %d and %d using recursive function: %d\n", a, b, gcd2);

    return 0;
}

