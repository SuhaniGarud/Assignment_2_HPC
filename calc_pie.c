#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

#define NUM_TERMS 100000000

double calculate_pi(int num)
{
   double pi=0.0;
   #pragma omp parallel
   {
       double sum = 0.0;
       #pragma omp for
       for(int i=0;i<num;i++){
          double x = ((i%2==0? 1.0: -1.0)/(2.0*i+1.0));
          sum += x;
       }
       #pragma omp atomic
       pi+=sum;
    }
    return 4.0*pi;
}
int main(){
  int num;
  printf("Enter the number: \n");
  scanf("%d",&num);
  
  double st = omp_get_wtime();
  double pi = calculate_pi(num);
  double et = omp_get_wtime();
  printf("Estimated value of Pi: %.15f\n",pi);
  printf("Time taken for calculation of value of pie: %f sec\n",et-st);
  return 0;
}
