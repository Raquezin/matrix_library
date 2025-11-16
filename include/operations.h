#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "matrix.h"
#include "errores.h"

/**
 * @brief Computes the echelon form of a matrix.
 *
 * Modifies matrix r to obtain the echelon form of a.
 *
 * @param a Original matrix.
 * @param r Result matrix (echelon form).
 * @return Number of row swaps performed.
 */
int echelon_form(const Matrix a, Matrix r);

/**
 * @brief Computes the determinant of a square matrix.
 *
 * Uses echelon form for calculation.
 *
 * @param a Square matrix.
 * @param r Auxiliary matrix for calculations.
 * @param det Pointer where the determinant will be stored.
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if not square.
 */
ErrorCode determinant(const Matrix a, Matrix r, float* det);

/**
 * @brief Computes the inverse of a square matrix.
 *
 * The matrix must be invertible.
 *
 * @param a Matrix to invert.
 * @param r Result matrix (inverse).
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if not square, ERR_DET_0 if not invertible.
 */
ErrorCode inverse(Matrix a, Matrix r);

/**
 * @brief Performs PLU decomposition of a matrix.
 *
 * PA = LU, where P is permutation, L lower, U upper.
 *
 * @param a Original matrix.
 * @param L Result L matrix.
 * @param U Result U matrix.
 * @param P Result P matrix.
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions incorrect.
 */
ErrorCode decomp_PLU(const Matrix a, Matrix L, Matrix U, Matrix P);

/**
 * @brief Solves a linear system using PLU decomposition.
 *
 * Solves Ax = b given PLU.
 *
 * @param a Original matrix.
 * @param L L matrix from PLU.
 * @param U U matrix from PLU.
 * @param P P matrix from PLU.
 * @param b Vector of independent terms.
 * @param x Solution vector.
 * @return ERR_NONE on success, ERR_DIM_MISMATCH if dimensions incorrect, ERR_NO_SOL or ERR_INF_SOL if issues.
 */
ErrorCode solve_PLU(const Matrix a, const Matrix L, const Matrix U,
                    const Matrix P, const Matrix b, Matrix x);

#endif // OPERATIONS_H