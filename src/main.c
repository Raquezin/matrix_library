#include <stdio.h>
#include <string.h>

#include "matrix.h"
#include "operations.h"
#include "operations_basic.h"
#include "operations_utils.h"

#define M_AT(m, r, c) (m->data[(r) * m->col + (c)])

int main() {
    // 1. Inicialización de matrices
    Matrix a = create_matrix(3, 3, 0);
    Matrix L = create_matrix(3, 3, 0);
    Matrix U = create_matrix(3, 3, 0);
    Matrix P = create_matrix(3, 3, 0);
    Matrix b = create_matrix(3,1,0);
    Matrix x = create_matrix(3,1,0);

    a.data[0] = 1; a.data[1] = 2; a.data[2] = 3;
    a.data[3] = 2; a.data[4] = 4; a.data[5] = 5;
    a.data[6] = 3; a.data[7] = 1; a.data[8] = 6;

    ErrorCode er = decomp_PLU(a, L, U, P);
    printf("Código de error de la descomposición LU: %d\n\n", er);

    solve_PLU(a, L, U, P, b, x);

    free_registry();
    return 0;
}