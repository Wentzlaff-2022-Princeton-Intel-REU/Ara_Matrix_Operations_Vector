/*--------------------------------------------------------------------*/
/* multiply.c                                                         */
/*--------------------------------------------------------------------*/

#include <riscv_vector.h>
#include "multiply.h"

/*--------------------------------------------------------------------*/

void multiply(Matrix_t mat1, Matrix_t mat2, Matrix_t* resultingMatrix) {
    // p = mat1 row size, n = mat1 col and mat2 row size, q = mat2 col size
    size_t p = mat1.m;
    size_t n = mat1.n;
    size_t q = mat2.n;

    // init result matrix
    resultingMatrix->m = p;
    resultingMatrix->n = q;

    vint32m1_t rowOfMat2, prodRow;
    
    // iter through rows of mat1
    for(size_t i = 0; i < p; i++) {
        // set vector length to be mat2 col size
        size_t avl = q;
        // find the longest vl possible for the avl we have left
        for (size_t vl; (vl = vsetvl_e32m1(avl)) > 0; avl -= vl) {
            // clear prodRow to hold all 0s
            prodRow = vmv_v_x_i32m1(0, vl);
            // for each col of mat1
            for (size_t j = 0; j < n; j++) {
                // load the row of mat2 up to vl for this iter. 
                rowOfMat2 = vle32_v_i32m1(&mat2.elements[j * q + (q - avl)], vl);
                // use vector multiply and accumulate in vector prodRow
                prodRow = vmacc_vx_i32m1(prodRow, mat1.elements[i * n + j], rowOfMat2, vl);
            }
            // once the whole row of mat1 has been iterated through, save the
            // prodRow register to the correct location in memory at resultingMatrix
            vse32_v_i32m1(&resultingMatrix->elements[i * q + (q - avl)], prodRow, vl);
        }
    }
}