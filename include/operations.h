#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "matrix.h"
#include "errores.h"

int echelon_form(const Matrix a, Matrix r);
ErrorCode determinant(const Matrix a, Matrix r, float* det);
ErrorCode inverse(Matrix a, Matrix r);
ErrorCode decomp_PLU(const Matrix a, Matrix L, Matrix U, Matrix P);
ErrorCode solve_PLU(const Matrix a, const Matrix L, const Matrix U,
                    const Matrix P, const Matrix b, Matrix x);

#endif // OPERATIONS_H