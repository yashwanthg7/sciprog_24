// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double artanh1(double x, double delta) {
    double val,sum=0;
	int i=0;
	do{
	
		val=pow(x,2*i+1)/(2*i+1);
		sum += val;
		i++;
	}while (fabs(val) >= delta);
	//printf("%d \n", sum);
	return sum;
}

double artanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}
int main() {
    double delta;

    printf("Enter the precision delta: ");
    scanf("%lf", &delta);
    if (delta <= 0) {
        printf("Delta must be a positive number.\n");
        return 1;
    }
    
    double x, artanh1_res, artanh2_res, diff;
    double step = 0.01;

    for (x = -0.9; x <= 0.9; x += step) 
    {
        artanh1_res = artanh1(x, delta);
        artanh2_res = artanh2(x);
        diff = fabs((artanh1_res - artanh2_res)/  artanh2_res);
        
        printf("\nRelative Difference of tan1 and tan2 at %.2lf is: %.10lf",x,fabs(artanh1_res-artanh2_res)/artanh2_res);

    }

    return 0;
}
