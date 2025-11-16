#ifndef OPERATIONS_UTILS_H
#define OPERATIONS_UTILS_H

#include "matrix.h"
#include "errores.h"

/**
 * @brief Prints the matrix to the console.
 *
 * Displays elements with 2 decimal places.
 *
 * @param a Matrix to print.
 */
void show(const Matrix a);

/**
 * @brief Copies the content of one matrix to another.
 *
 * Matrices must have the same dimensions.
 *
 * @param a Source matrix.
 * @param r Destination matrix.
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions do not match.
 */
ErrorCode copy_matrix(const Matrix* a, Matrix* r);

/**
 * @brief Converts the matrix to an identity matrix.
 *
 * The matrix must be square.
 *
 * @param a Matrix to convert.
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if not square.
 */
ErrorCode identity(Matrix a);

/**
 * @brief Fills the matrix with a constant value.
 *
 * @param a Matrix to fill.
 * @param n Value to assign to all elements.
 */
void fill(Matrix a, float n);

/**
 * @brief Fills the matrix with random values in a range.
 *
 * @param a Matrix to fill.
 * @param min Minimum value.
 * @param max Maximum value.
 */
void random_fill(Matrix a, const float min, const float max);

/**
 * @brief Swaps two rows of the matrix.
 *
 * @param a Matrix to modify.
 * @param f1 Index of the first row (0-based).
 * @param f2 Index of the second row (0-based).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if indices out of range.
 */
ErrorCode swaprow(Matrix* a, int f1, int f2);

/**
 * @brief Checks if two matrices are equal.
 *
 * Compares element by element.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return 1 if equal, 0 otherwise.
 */
int equals(const Matrix a, const Matrix b);

#endif // OPERATIONS_UTILS_H