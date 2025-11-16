#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "matrix.h"
#include "operations.h"
#include "operations_basic.h"
#include "operations_utils.h"

int echelon_form(const Matrix a, Matrix r) {
    if (a.row != r.row || a.col != r.col)
        return ERR_DIM_MISMATCH;

    copy_matrix(&a, &r);

    float factor;
    int64_t base_a, base_k ;
    int swap_count = 0;

    for (int64_t i = 0; i < a.row; i++) {
        base_a = i * a.col;
        if (r.data[base_a + i] == 0) { // pivote = 0, cambiar filas.
            for (int64_t t = i + 1; t < a.row; t++) {
                if (r.data[t * a.col + i] != 0) {
                    printf("cambio fila %ld por %ld\n", i + 1, t + 1);
                    swap_count += 1;
                    swaprow(&r, i, t);
                    break;
                }
            }
        }
        // si sigue siendo 0, no podemos seguir.
        if (r.data[base_a + i] == 0)
            continue;
            
        for (int64_t k = i + 1; k < a.row; k++) {
            base_k = k * a.col;
            if (r.data[base_k + i] == 0)
                continue;

            factor = -1 * ((float)r.data[base_k + i] / r.data[base_a + i]);
            for (int64_t j = i; j < a.col; j++) {
                r.data[base_k + j] = r.data[base_k + j] + r.data[base_a + j] * factor;
            }
        }
    }
    return swap_count;
}

ErrorCode determinant(const Matrix a, Matrix r, float* det) {
    if (a.row != a.col || a.row != r.row || a.col != r.col)
        return ERR_DIM_MISMATCH;
    int swap_count = echelon_form(a, r);

    *det = 1;
    for (int64_t i = 0; i < r.row; i++) {
        *det *= r.data[i * a.col + i];
    }
    if (swap_count % 2 != 0)
        *det = -*det;

    return ERR_NONE;
}

// devolver a como a y no la identidad.
ErrorCode inverse(Matrix a, Matrix r){
    if (a.row != a.col || a.row != r.row || a.col != r.col)
        return ERR_DIM_MISMATCH;
    
    float d;
    determinant(a, r, &d);
    
    if (fabs(d) < 1e-9)
        return ERR_DET_0;

    fill(r, 0);
    identity(r);

    // Matrix a_copy; ver copiar matriz para la inversa.
    // copy_matrix(&a, &a_copy);

    float factor;
    int64_t base_a, base_k;

    for (int64_t i = 0; i < a.row; i++) {
        base_a = i * a.col;
        if (a.data[base_a + i] == 0) { // pivote = 0, cambiar filas.
            for (int64_t t = i + 1; t < a.row; t++) {
                if (a.data[t * a.col + i] != 0) {
                    printf("cambio fila %ld por %ld\n", i + 1, t + 1);
                    swaprow(&a, i, t);
                    swaprow(&r, i, t);
                    break;
                }
            }
        }
        if (a.data[base_a + i] != 1) {
            factor = a.data[base_a + i];
            for (int64_t j = 0; j < a.col; j++) {
                a.data[base_a + j] = a.data[base_a + j] / factor;
                r.data[base_a + j] = r.data[base_a + j] / factor;
            }
        }
        for (int64_t k = i + 1; k < a.row; k++) {
            base_k = k * a.col; 
            if (a.data[base_k + i] == 0)
                continue;

            factor = -1 * ((float)a.data[base_k + i] / a.data[base_a + i]);

            for (int64_t j = 0; j < a.col; j++) {
                a.data[base_k + j] = a.data[base_k + j] + a.data[base_a + j] * factor;
                r.data[base_k + j] = r.data[base_k + j] + r.data[base_a + j] * factor;
            }
        }
    }

    for (int64_t i = a.row - 1; i > 0; i--) {
        base_a = i * a.col;
        for (int64_t k = i - 1; k >= 0; k--) {
            base_k = k * a.col;
            if (a.data[base_k + i] == 0)
                continue;

            factor = -1 * ((float)a.data[base_k + i] / a.data[base_a + i]);
            for (int64_t j = 0; j < a.col; j++) {
                a.data[base_k + j] = a.data[base_k + j] + a.data[base_a + j] * factor;
                r.data[base_k + j] = r.data[base_k + j] + r.data[base_a + j] * factor;
            }
        }
    }
    return ERR_NONE;
}

ErrorCode decomp_PLU(const Matrix a, Matrix L, Matrix U, Matrix P) {
    /*
    You have PA = LU
    Ax = b
    */
    if (a.row != a.col || L.row != a.row || L.col != a.col || U.row != a.row 
        || U.col != a.col || P.row != a.row || P.col != a.col)
        return ERR_DIM_MISMATCH;

    copy_matrix(&a, &U);
    fill(L, 0);
    identity(P);

    float factor;
    int64_t base_a, base_k;
    int swap_count = 0;

    for (int64_t i = 0; i < a.row; i++) {
        base_a = i * a.col;
        if (U.data[base_a + i] == 0) { // pivote = 0, cambiar filas.
            for (int64_t t = i + 1; t < a.row; t++) {
                if (U.data[t * a.col + i] != 0) {
                    printf("cambio fila %ld por %ld\n", i + 1, t + 1);
                    swap_count += 1;
                    swaprow(&U, i, t);
                    swaprow(&L, i, t);
                    swaprow(&P, i, t);
                    break;
                }
            }
        }
        // si sigue siendo 0, no podemos seguir.
        if (U.data[base_a + i] == 0)
            continue;

        for (int64_t k = i + 1; k < a.row; k++) {
            base_k = k * a.col;
            if (U.data[base_k + i] == 0)
                continue;

            factor = ((float)U.data[base_k + i] / U.data[base_a + i]);
            L.data[base_k + i] = factor;
            for (int64_t j = i; j < a.col; j++) {
                U.data[base_k + j] = U.data[base_k + j] + U.data[base_a + j] * -1 * factor;
            }
        }
    }

    identity(L);
    return ERR_NONE;
}

ErrorCode solve_PLU(const Matrix a, const Matrix L, const Matrix U,
                    const Matrix P, const Matrix b, Matrix x) {
    if (a.row != a.col || L.row != a.row || L.col != a.col 
        || U.row != a.row || U.col != a.col 
        || P.row != a.row || P.col != a.col
        || b.row != a.row || b.col != 1 
        || a.row != x.row || x.col != 1)
        return ERR_DIM_MISMATCH;

    float y[a.row];
    multiply(P, b, x);

    int64_t base;
    for (int64_t i = 0; i < a.row; i++) { // Ly = Pb
        y[i] = x.data[i];
        base = i * a.col;
        for (int64_t j = 0; j < i; j++) {
            y[i] -= L.data[base + j]*y[j];
        }
    } 

    for (int64_t i = a.row - 1; i >= 0; i--) { // Ux = y
        x.data[i] = y[i];
        base = i * a.col;
        for (int64_t j = a.col - 1; j >= i + 1; j--) {
            x.data[i] -= U.data[base + j]*x.data[j];
        }
        if (fabs(U.data[base + i]) < 1e-9) { 
            if (fabs(x.data[i]) < 1e-9) { // Caso 0 = 0
                    return ERR_INF_SOL;
            } else { // Caso 0 = (no cero)
                return ERR_NO_SOL;
            }
        }
        x.data[i] /= U.data[base + i];
    } 
    return ERR_NONE;
}
