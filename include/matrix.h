#ifndef MATRIX_H
#define MATRIX_H

#define REGISTRY_CAPACITY 100

/**
 * @brief Structure representing a matrix.
 *
 * Contains the number of rows, columns, and a pointer to float data.
 */
typedef struct
{
    int row;     /**< Number of rows in the matrix. */
    int col;     /**< Number of columns in the matrix. */
    float *data; /**< Pointer to the matrix data in contiguous memory. */
} Matrix;

/**
 * @brief Registry for managing matrix memory.
 *
 * Stores pointers to matrix data for later memory release.
 */
typedef struct
{
    float *data[REGISTRY_CAPACITY]; /**< Array of pointers to matrix data. */
    int index;                      /**< Current index in the registry. */
} MatrixRegistry;

/**
 * @brief Creates a new matrix with specified dimensions and initial value.
 *
 * Allocates memory for the matrix and initializes it with the given value.
 * The matrix is registered for later release.
 *
 * @param rows Number of rows (must be >= 0).
 * @param cols Number of columns (must be >= 0).
 * @param val Initial value for all elements.
 * @return The created matrix, or a default matrix if error.
 */
Matrix create_matrix(const int rows, const int cols, const float val);

/**
 * @brief Frees memory of all registered matrices.
 *
 * Should be called at the end of the program to avoid memory leaks.
 */
void free_registry();

#endif // MATRIX_H