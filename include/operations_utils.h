#ifndef OPERATIONS_UTILS_H
#define OPERATIONS_UTILS_H

#include "matrix.h"
#include "errores.h"

void show(const Matrix a);
void copy_matrix(const Matrix* a, Matrix* r);
void identity(Matrix a);
void fill(Matrix a, float n);
void random_fill(Matrix a, const float min, const float max);
ErrorCode swaprow(Matrix* a, int f1, int f2);


#endif // OPERATIONS_UTILS_H