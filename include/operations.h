#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "matrix.h"
#include "errores.h"

int echelon_form(const Matrix a, Matrix r);
ErrorCode determinant(const Matrix a, Matrix r, float* det);
ErrorCode inverse(Matrix a, Matrix r);
ErrorCode LU(const Matrix a, Matrix L, Matrix U, Matrix P);

#endif // OPERATIONS_H