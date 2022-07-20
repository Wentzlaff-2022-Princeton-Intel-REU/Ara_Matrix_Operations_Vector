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
    matrix_A.m = 10;
    matrix_A.n = 10;
    matrix_B.m = 10;
    matrix_B.n = 10;
    int32_t arr[100] = {59, 63, 63, 28, 76, 64, 32, 43, 36, 92, 28, 23, 67, 47, 2, 100, 49, 47, 40, 66, 26, 93, 27, 58, 5, 86, 47, 51, 16, 60, 78, 88, 81, 25, 29, 81, 85, 73, 64, 15, 2, 63, 70, 36, 75, 53, 43, 3, 77, 1, 66, 31, 35, 38, 26, 10, 54, 4, 10, 27, 74, 7, 26, 81, 71, 9, 44, 61, 54, 18, 27, 22, 30, 73, 49, 97, 68, 25, 63, 9, 7, 56, 98, 20, 15, 71, 64, 64, 26, 13, 9, 2, 100, 79, 62, 55, 32, 37, 44, 1};
    int32_t arr2[100] = {81, 39, 49, 58, 19, 96, 26, 67, 67, 6, 4, 21, 32, 49, 64, 30, 43, 20, 45, 74, 58, 85, 1, 14, 56, 97, 27, 1, 34, 27, 34, 93, 10, 54, 53, 83, 65, 57, 73, 53, 15, 40, 49, 40, 41, 16, 79, 41, 41, 24, 96, 29, 33, 47, 87, 52, 88, 30, 84, 76, 23, 40, 30, 12, 41, 26, 5, 26, 65, 84, 78, 14, 21, 7, 24, 88, 26, 85, 53, 73, 60, 4, 69, 59, 81, 62, 18, 30, 57, 69, 54, 100, 92, 64, 46, 36, 61, 83, 10, 59};
    matrix_A.elements = arr;
    matrix_B.elements = arr2;

    Matrix_t sum;
    int32_t arr3[100];
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

    printf("Runtime (cycles): %x\n", cycle_time);

    Matrix_t product;
    int32_t arr4[100];
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

    printf("Runtime (cycles): %x\n", cycle_timeb);

    return 0;
}
