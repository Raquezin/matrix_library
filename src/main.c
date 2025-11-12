#include <stdio.h>
#include <string.h>

#include "matrix.h"
#include "operations.h"
#include "operations_basic.h"
#include "operations_utils.h"

#define M_AT(m, r, c) (m->data[(r) * m->col + (c)])

int main() {
    Matrix a = create_matrix(3,3,0);
    Matrix L = create_matrix(3,3,0);
    Matrix U = create_matrix(3,3,0);
    Matrix P = create_matrix(3,3,0);
    Matrix r = create_matrix(3,3,0);

    a.data[0] = 1;
    a.data[1] = 3;
    a.data[2] = 2;
    a.data[3] = 3;
    a.data[4] = 2;
    a.data[5] = 6;
    a.data[6] = 2;
    a.data[7] = 4;
    a.data[8] = 8;

    ErrorCode er = decomp_PLU(a, L, U, P);
    printf("error: %d\n", er);

    multiply(L, U, r);
    show(a);
    show(U);
    show(L);
    show(P);
    show(r);

    free_registry();
    return 0;
}
