#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	if(argc <= 1){
		puts("Usage: question5 <number of threads>");
		return 1;
	}
	int nthreads = atoi(argv[1]);
	omp_set_num_threads(nthreads);
	
	int n = 100000000;
	double y[n];
	double dx = 1/(n+1);
	double x;
	FILE *file = fopen("calculations.txt", "w");

	#pragma omp parallel for private(x)
	for(int i = 0; i < n; i++){
		x = (double)i * dx;
		y[i] = exp(x) * cos(x) * sin(x) * sqrt(5*x + 6.0);
		
		if((i+1) % 1000000 == 0){
			#pragma omp critical
			{
				fprintf(file, "%d, %f, %f\n", i, x, y[i]);
			}
		}
	}
	fclose(file);
}
