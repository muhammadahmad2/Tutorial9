#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	if(argc <= 1){
		puts("Usage: question2 <number of threads>");
		return 1;
	}
	int nthreads = atoi(argv[1]);
	omp_set_num_threads(nthreads);
	
	int n = 100000000;
	double y[n];
	double dx = 1/(n+1);
	double x;

	#pragma omp parallel for private(x)
	for(int i = 0; i < n; i++){
		x = i * dx;
		y[i] = exp(x) * cos(x) * sin(x) * sqrt(5*x + 6.0);
	}
}
