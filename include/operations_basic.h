#ifndef OPERATIONS_BASIC_H
#define OPERATIONS_BASIC_H

#include "matrix.h"
#include "errores.h"

ErrorCode sum(const Matrix a, const Matrix b, Matrix r);
ErrorCode rest(const Matrix a, const Matrix b, Matrix r);
ErrorCode multiply(const Matrix a, const Matrix b, Matrix r);
ErrorCode transpose(const Matrix a, Matrix r);
void sum_number(Matrix a, float n);
void rest_number(Matrix a, float n);
void multiply_number(Matrix a, float n);
ErrorCode divide_number(Matrix a, float n);
void power_number(Matrix a, float n);


#endif // OPERATIONS_BASIC_H
