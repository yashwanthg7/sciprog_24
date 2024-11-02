#include<stdio.h>
#include<math.h>

int main(){
   int N = 12;
   float a = 0;
   float b = M_PI / 3;
   float points = (b-a) / (N-1);
   float result;
   float actual_result = log(2);
   float sum =0;

   for( int i =1; i < N-1; i++){
	   float xi = a + (i* points);
	   sum += 2 * tan(xi);
	}
   sum += tan(a) + tan(b);
   result = (b-a) * sum / (2*N);

   printf("Result computed %f\n",result);
   printf("Actual result %f\n",actual_result);
   printf("Difference : %f", (result- actual_result));
}

   

