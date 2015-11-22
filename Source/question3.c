#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <omp.h>

int main (int argc, char *argv[])
{
    //int number, input;
	
	srand ( time(NULL) );
	int x[100000000];
	for(int a = 0; a < 100000000; a++){
		x[a] = rand() % 100;
	}
	
	int norm = 0;
	double start = omp_get_wtime();
	for(int i = 0; i < 100000000; i++){
    	norm += fabs(x[i]);
	}
	double end = omp_get_wtime();
	double dif = end - start;
	printf("The time without using omp: %f\n", dif);
	
	double start2 = omp_get_wtime();
	#pragma omp parallel for reduction(+: norm)
    for(int i = 0; i < 100000000; i++){
    	norm += fabs(x[i]);
    }
	double end2 = omp_get_wtime();
	double dif2 = end2 - start2;
	printf("The time using omp: %f\n", dif2);
}