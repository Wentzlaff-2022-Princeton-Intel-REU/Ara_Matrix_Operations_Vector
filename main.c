/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/


#include "matrix.h"
#include "add.h"
#include "multiply.h"
#include "print.h"
#include "runtime.h"

/*--------------------------------------------------------------------*/

int main() {
    
    Matrix_t matrix_A, matrix_B;
    matrix_A.m = 7;
    matrix_A.n = 7;
    matrix_B.m = 7;
    matrix_B.n = 7;
    int32_t arr[49] = {59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36};
    int32_t arr2[49] = {59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 59, 63, 63, 28, 76, 64, 32, 43, 36};
    matrix_A.elements = arr;
    matrix_B.elements = arr2;


    Matrix_t sum;
    int32_t arr3[49];
    sum.elements = arr3;

    // printf("Vector Addition: \n");

   //  printMatrix(matrix_A);
    // printf("\n");
   //  printMatrix(matrix_B);
   //  printf("\n");
    
    start_timer();
    add(matrix_A, matrix_B, &sum);
    stop_timer();
    int64_t cycle_time = get_timer();

   // printMatrix(sum);

    printf("Runtime (cycles): %d\n", cycle_time);

    Matrix_t product;
    int32_t arr4[49];
    product.elements = arr4;

   // printf("Vector Multiplication: \n");

   // printMatrix(matrix_A);
   // printf("\n");
// printMatrix(matrix_B);
  //  printf("\n");

    start_timer();
    multiply(matrix_A, matrix_B, &product);
    stop_timer();
    int64_t cycle_timeb = get_timer();
    
   // printMatrix(product);

    printf("Runtime (cycles): %d\n", cycle_timeb);

    return 0;
}
