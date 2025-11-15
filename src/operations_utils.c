#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operations_utils.h"
#include "matrix.h"
#include "errores.h"

ErrorCode identity(Matrix a) {
    if (a.row != a.col)
        return ERR_DIM_MISMATCH;
    for (int i = 0; i < a.row; i++) {
        a.data[i * a.col + i] = 1;
    }
    return ERR_NONE;
}

void fill(Matrix a, const float n) {
    for (int i = 0; i < a.row * a.col; i++) {
        a.data[i] = n;
    }
}

void random_fill(Matrix a, const float min, const float max) {
    for (int i = 0; i < a.row * a.col; i++) {
        float scale = rand() / (float) RAND_MAX;
        a.data[i] = min + scale * (max - min);
    }
}

ErrorCode copy_matrix(const Matrix *a, Matrix *r) {
    if (a->row != r->row || a->col != r->col)
        return ERR_DIM_MISMATCH;
    memcpy(r->data, a->data, (a->row * a->col * sizeof(float)));
    return ERR_NONE;
}

ErrorCode swaprow(Matrix* a, int f1, int f2) {
    if (f1 == f2) return ERR_NONE;
    if (f1 >= a->row || f2 >= a->row || f1 < 0 || f2 < 0) return ERR_DIM_MISMATCH;

    size_t row_size_bytes = a->col * sizeof(float);

    float* row1_ptr = &a->data[f1 * a->col]; // Puntero al inicio de la primera fila.
    float* row2_ptr = &a->data[f2 * a->col]; // Puntero al inicio de la segunda fila.
    float tmp[a->col];

    memcpy(tmp, row1_ptr, row_size_bytes);
    memcpy(row1_ptr, row2_ptr, row_size_bytes);
    memcpy(row2_ptr, tmp, row_size_bytes);

    return ERR_NONE;
}

void show(const Matrix a) {
    int base;
    for (int i = 0; i < a.row; i++) {
        base = i * a.col;
        for (int j = 0; j < a.col; j++) {
            printf("%5.2f ", a.data[base + j]);
        }
        printf("\n");
    }
    printf("------------------------\n");
}
