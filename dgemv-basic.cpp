const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply

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
      y[row] = 0.0;

      //inner loop is dot product of whatever row of A you're on
      for(int column = 0; column < n; column++){

         //since its row major format index = col + row * N
         //index = column + row * n;

         //index * the vector computation is the dot product we will accumulate for each row
         y[row] += A[column + row * n] * x[column];
      }

   }
}
