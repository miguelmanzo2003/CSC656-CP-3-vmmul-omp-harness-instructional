#include <string.h>
#include <iomanip>


const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply

   printf("entered dgemv: VECTORIZED\n");
   //it seems that the same code from dgemv basic was able to be vectorized, 
   //taken from lecture 22
   /*
   for row in 0,M:
      for col in 0,N:
         index = col + row * N
         A[index] += 1
   */

   //int index = 0;

   //outer loop is over each row of A
   for(int row = 0; row < n; row++){
      //sum is where we will hold the accumulation
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
