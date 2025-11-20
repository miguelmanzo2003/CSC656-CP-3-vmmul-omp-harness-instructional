#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include <string.h>
#include <iomanip>


const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

      printf("entered dgemv: OPENMP\n");


   #pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
      printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   }

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings
   //taken from lecture 22
   /*
   for row in 0,M:
      for col in 0,N:
         index = col + row * N
         A[index] += 1
   */

   //int index = 0;

   //outer loop is over each row of A
   #pragma omp parallel for
   for(int row = 0; row < n; row++){
      double sum = 0.0;

      //inner loop is dot product of whatever row of A you're on
      for(int column = 0; column < n; column++){

         //since its row major format index = col + row * N
         //index = column + row * n;

         //index * the vector computation is the dot product we will accumulate for each row
         sum += A[column + row * n] * x[column];
      }
      
      //y = y + A * x (sum is the holder for this)
      //here is where we accumulate, this is the y + part in y = y + A * x
      y[row] += sum;
   }


}

