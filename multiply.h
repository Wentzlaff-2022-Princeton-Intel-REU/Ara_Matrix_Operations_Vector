#pragma once
/*------------------------------------------------------------*/
/* multiply.h                                                 */
/*------------------------------------------------------------*/

#include "matrix.h"

/*------------------------------------------------------------*/

/* The multiply function takes in three matrices as inputs and
modifies the resultingMatrix to be the product of the two factor
matrices. The number of columns of the first matrix must be equal
to the number of rows of the second matrix.*/
void multiply(Matrix_t mat1, Matrix_t mat2, Matrix_t* resultingMatrix);
