#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <omp.h>

int main (int argc, char *argv[])
{

	int size = 10;

	int a[size][size];
	int b[size][size];
	int c[size][size];

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			a[i][j] = i;
			b[i][j] = j;
		}
	}
	int sum = 0;
	#pragma omp parallel for private(sum)
	for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         sum = 0;
         for (int k = 0; k < size; k++) {
            sum = sum + a[i][k] * b[k][j];
         }
         c[i][j] = sum;
      }
	}

   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         printf(".%d", c[i][j]);
      }
      printf("\n");
   }

}