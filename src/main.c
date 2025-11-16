#include <stdio.h>
#include <string.h>

#include "matrix.h"
#include "operations.h"
#include "operations_basic.h"
#include "operations_utils.h"

#define M_AT(m, r, c) (m->data[(r) * m->col + (c)])

int main() {
    Matrix a = create_matrix(3,3,3);
    multiply_number(a,  30);
    show(a);


    free_registry();
    return 0;
}
