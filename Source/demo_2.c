#include <stdio.h>
#include <omp.h>
int main (int argc, char *argv[])
{
    int thread_num, nthreads = 16;
	// Between here and #endif only compiles if _OPENMP is defined
    #ifdef _OPENMP
    omp_set_num_threads(nthreads);
    #endif
    printf("Testing OpenMP, you should see each thread print...\n");
	// Runs the following block of code in 16 parallel threads
    #pragma omp parallel
    {
		// Only one thread can run the following block at a time
        #pragma omp critical
        {
		  // Between here and #endif only compiles if _OPENMP is defined
          #ifdef _OPENMP
          thread_num = omp_get_thread_num();
          printf("This thread = %d\n", thread_num);
          #endif
        }
    }
    return 0;
}
