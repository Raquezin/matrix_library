#ifndef OPERATIONS_BASIC_H
#define OPERATIONS_BASIC_H

#include "matrix.h"
#include "errores.h"

/**
 * @brief Adds two matrices element-wise.
 *
 * Matrices must have the same dimensions.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @param r Result matrix (must have the same dimensions as a and b).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions do not match.
 */
ErrorCode sum(const Matrix a, const Matrix b, Matrix r);

/**
 * @brief Subtracts two matrices element-wise.
 *
 * Matrices must have the same dimensions.
 *
 * @param a First matrix (minuend).
 * @param b Second matrix (subtrahend).
 * @param r Result matrix (must have the same dimensions as a and b).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions do not match.
 */
ErrorCode rest(const Matrix a, const Matrix b, Matrix r);

/**
 * @brief Multiplies two matrices.
 *
 * The number of columns in a must match the number of rows in b.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @param r Result matrix (rows of a, columns of b).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions are incompatible.
 */
ErrorCode multiply(const Matrix a, const Matrix b, Matrix r);

/**
 * @brief Transposes a matrix.
 *
 * Swaps rows and columns.
 *
 * @param a Matrix to transpose.
 * @param r Result matrix (columns of a, rows of a).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if r dimensions are incorrect.
 */
ErrorCode transpose(const Matrix a, Matrix r);
void sum_number(Matrix a, float n);
void rest_number(Matrix a, float n);
void multiply_number(Matrix a, float n);
ErrorCode divide_number(Matrix a, float n);
void power_number(Matrix a, float n);

/**
 * @brief Adds a scalar to all elements of the matrix.
 *
 * Modifies the matrix in-place.
 *
 * @param a Matrix to modify.
 * @param n Scalar to add.
 */
void sum_number(Matrix* a, float n);

/**
 * @brief Subtracts a scalar from all elements of the matrix.
 *
 * Modifies the matrix in-place.
 *
 * @param a Matrix to modify.
 * @param n Scalar to subtract.
 */
void rest_number(Matrix* a, float n);

/**
 * @brief Multiplies all elements of the matrix by a scalar.
 *
 * Modifies the matrix in-place.
 *
 * @param a Matrix to modify.
 * @param n Scalar to multiply by.
 */
void multiply_number(Matrix* a, float n);

/**
 * @brief Divides all elements of the matrix by a scalar.
 *
 * Modifies the matrix in-place.
 *
 * @param a Matrix to modify.
 * @param n Scalar to divide by (must not be zero).
 * @return ERR_NONE on success, ERR_DIV_BY_ZERO if n is zero.
 */
ErrorCode divide_number(Matrix* a, float n);

/**
 * @brief Raises each element of the matrix to a power.
 *
 *  Modifies the matrix in-place.
 *
 * @param a Matrix to modify.
 * @param n Power to apply.
 */
void power_number(Matrix* a, float n);


#endif // OPERATIONS_BASIC_H