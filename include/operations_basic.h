#ifndef OPERATIONS_BASIC_H
#define OPERATIONS_BASIC_H

#include "matrix.h"
#include "errores.h"

ErrorCode sum(const Matrix a, const Matrix b, Matrix r);
ErrorCode rest(const Matrix a, const Matrix b, Matrix r);
ErrorCode multiply(const Matrix a, const Matrix b, Matrix r);
ErrorCode transpose(const Matrix a, Matrix* b);


#endif // OPERATIONS_BASIC_H