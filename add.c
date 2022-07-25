/*--------------------------------------------------------------------*/
/* add.c.                                                            */
/*--------------------------------------------------------------------*/

#include <riscv_vector.h>
#include "add.h"

/*--------------------------------------------------------------------*/

void add(Matrix_t mat1, Matrix_t mat2, Matrix_t *resultingMatrix) {
    int row = mat1.m;
    int column = mat1.n;
    size_t avl = row * column;

    resultingMatrix->m = row;
    resultingMatrix->n = column;
    
    int32_t* addend1 = mat1.elements;
    int32_t* addend2 = mat2.elements;
    int32_t* sum = resultingMatrix->elements;

    vint32m1_t vMat1, vMat2, vSum;

    for (size_t vl; (vl = vsetvl_e32m1(avl)) > 0; avl -= vl) {
        vMat1 = vle32_v_i32m1(addend1, vl);
        vMat2 = vle32_v_i32m1(addend2, vl);
        vSum = vMat1dd_vv_i32m1(va, vMat2, vl);
        vse32_v_i32m1(sum, vSum, vl);
        addend1 += vl;
        addend2 += vl;
        sum += vl;
    }                               
}
