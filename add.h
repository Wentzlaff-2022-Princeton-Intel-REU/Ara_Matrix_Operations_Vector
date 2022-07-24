#pragma once
/*------------------------------------------------------------*/
/* add.h                                                      */
/*------------------------------------------------------------*/

#include "matrix.h"

/*------------------------------------------------------------*/

/* The add function takes in three matrices as inputs and
modifies the resultingMatrix to be the sum of the two addend
matrices. Both matrices must has the same dimensions. */
void add(Matrix_t mat1, Matrix_t mat2, Matrix_t* resultingMatrix);
