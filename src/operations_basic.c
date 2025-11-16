#include <stdint.h>
#include "operations_basic.h"
#include "matrix.h"

ErrorCode sum(const Matrix a, const Matrix b, Matrix r) {
    if (a.row != b.row || b.row != r.row || a.col != b.col || b.col != r.col) 
        return ERR_DIM_MISMATCH;

    int64_t base;
    for (int64_t i = 0; i < a.row; i++) {
        base = i * a.col;
        for (int64_t j = 0; j < a.col; j++) {
            r.data[base + j] = a.data[base + j] + b.data[base + j];
        }
    }

    return ERR_NONE;
}

ErrorCode rest(const Matrix a, const Matrix b, Matrix r) {
    if (a.row != b.row || b.row != r.row || a.col != b.col || b.col != r.col) 
        return ERR_DIM_MISMATCH;

    int64_t base;
    for (int64_t i = 0; i < a.row; i++) {
        base = i * a.col;
        for (int64_t j = 0; j < a.col; j++) {
            r.data[base + j] = a.data[base + j] - b.data[base + j];
        }
    }
    
    return ERR_NONE;
}

ErrorCode multiply(const Matrix a, const Matrix b, Matrix r) {
    if (a.col != b.row || r.row != a.row || r.col != b.col)
        return ERR_DIM_MISMATCH;

    int64_t base_a, base_r;
    float element;
    for (int64_t i = 0; i < a.row; i++) {
        base_a = i * a.col;
        base_r = i * r.col;
        for (int64_t j = 0; j < b.col; j++) {
            element = 0;
            for (int64_t k = 0; k < a.col; k++) {
                element += a.data[base_a + k] * b.data[k * b.col + j];
            }
            r.data[base_r + j] = element;
        }
    }
    
    return ERR_NONE;
}

ErrorCode transpose(const Matrix a, Matrix r) {
    if (a.row != r.col || a.col != r.row)
        return ERR_DIM_MISMATCH;

    int64_t base;
    for (int64_t j = 0; j < a.col; j++) {
        base = j * a.row;
        for (int64_t i = 0; i < a.row; i++) {
            r.data[base + i] = a.data[j + i * a.col];
        }
    }

    return ERR_NONE;
}

void sum_number(Matrix a, float n) {
    for (int64_t i = 0; i < a.row * a.col; i++) {
        a.data[i] += n;
    }
}

void rest_number(Matrix a, float n) {
    for (int64_t i = 0; i < a.row * a.col; i++) {
        a.data[i] -= n;
    }
}

void multiply_number(Matrix a, float n) {
    for (int64_t i = 0; i < a.row * a.col; i++) {
        a.data[i] *= n;
    }
}
