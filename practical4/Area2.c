#include<stdio.h>
#include<math.h>

#define N 12
//Number of points from 0 to 60(in 5 degree increments)

float tan_values[N+1];
//Declaring the tan array globally


float degrees_to_radians_conversion(float degrees){
//Function to convert degrees to radians
	float res = M_PI * degrees / 180.0;
	return res;
}

float area_trapezoidal_rule(){
//Function to calculate the area under tan(x) using trapezoidal rule.
	float a = 0;
	float b = M_PI / 3;
	float points = (b-a) / (N-2);
       	float result;
	float sum =0;

        for( int i = 0; i < N; i++){
		sum += 2 * tan_values[i];
	}				           
	sum += tan(a) + tan(b);
	result = (b-a) * sum / (2*N);

	return result;
}

int main(){
	for( int i=0; i<=N;i++) {
		float degrees = i *5;
		tan_values[i] = tan(degrees_to_radians_conversion(degrees));
	}

	printf("Array of tan values:");
	for(int i = 0;i<=N;i++){
		printf("tan(%d) = %f\n",i,tan_values[i]);
	}
	
	float area = area_trapezoidal_rule();
 	printf("Area under tan(x) from 0 to 60 degrees: %f\n", area);
}
	
		
