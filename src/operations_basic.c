#include "operations_basic.h"
#include "matrix.h"

ErrorCode sum(const Matrix a, const Matrix b, Matrix r) {
    if (a.row != b.row || b.row != r.row || a.col != b.col || b.col != r.col) 
        return ERR_DIM_MISMATCH;

    int base;
    for (int i = 0; i < a.row; i++) {
        base = i * a.col;
        for (int j = 0; j < a.col; j++) {
            r.data[base + j] = a.data[base + j] + b.data[base + j];
        }
    }

    return ERR_NONE;
}

ErrorCode rest(const Matrix a, const Matrix b, Matrix r) {
    if (a.row != b.row || b.row != r.row || a.col != b.col || b.col != r.col) 
        return ERR_DIM_MISMATCH;

    int base;
    for (int i = 0; i < a.row; i++) {
        base = i * a.col;
        for (int j = 0; j < a.col; j++) {
            r.data[base + j] = a.data[base + j] - b.data[base + j];
        }
    }
    
    return ERR_NONE;
}

ErrorCode multiply(const Matrix a, const Matrix b, Matrix r) {
    if (a.col != b.row || r.row != a.row || r.col != b.col)
        return ERR_DIM_MISMATCH;

    int base_a, base_r;
    float element;
    for (int i = 0; i < a.row; i++) {
        base_a = i * a.col;
        base_r = i * r.col;
        for (int j = 0; j < b.col; j++) {
            element = 0;
            for (int k = 0; k < a.col; k++) {
                element += a.data[base_a + k] * b.data[k * b.col + j];
            }
            r.data[base_r + j] = element;
        }
    }
    
    return ERR_NONE;
}

ErrorCode transpose(const Matrix a, Matrix r) {
    if (a.row * a.col != r.row * r.col)
        return ERR_DIM_MISMATCH;

    r.row = a.col;
    r.col = a.row;
    int base;
    for (int j = 0; j < a.col; j++) {
        base = j * a.row;
        for (int i = 0; i < a.row; i++) {
            r.data[base + i] = a.data[j + i * a.col];
        }
    }

    return ERR_NONE;
}
