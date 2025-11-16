# Matrix Library

A C library for matrix operations, including basic, advanced, and utility functions.

## Structures

- **Matrix**: Represents a matrix with rows, columns, and float data.
- **MatrixRegistry**: Manages matrix memory for release.

## Main Functions

### Creation and Management

- `Matrix create_matrix(int rows, int cols, float val)`: Creates an initialized matrix.
- `void free_registry()`: Frees memory of all matrices.

### Basic Operations

- `ErrorCode sum(Matrix a, Matrix b, Matrix r)`: Adds matrices.
- `ErrorCode multiply(Matrix a, Matrix b, Matrix r)`: Matrix multiplication.
- `ErrorCode transpose(Matrix a, Matrix r)`: Transposition.
- Scalar operations: `sum_number`, `multiply_number`, etc.

### Utilities

- `void show(Matrix a)`: Prints the matrix.
- `ErrorCode copy_matrix(Matrix* a, Matrix* r)`: Copies matrices.
- `void fill(Matrix a, float n)`: Fills with constant value.

### Advanced Operations

- `ErrorCode determinant(Matrix a, Matrix r, float* det)`: Computes determinant.
- `ErrorCode inverse(Matrix a, Matrix r)`: Computes inverse.
- `ErrorCode decomp_PLU(Matrix a, Matrix L, Matrix U, Matrix P)`: PLU decomposition.
- `ErrorCode solve_PLU(...)`: Solves linear systems.

## Compilation

Use the Makefile:

```bash
make
```

This compiles the library and the `matrix_app` executable.

## Usage

Include the headers in your code:

```c
#include "matrix.h"
#include "operations_basic.h"
// etc.

int main() {
    Matrix a = create_matrix(2, 2, 1.0);
    show(a);
    free_registry();
    return 0;
}
```

## Errors

Error codes are defined in `errores.h`. Check the return of functions that return `ErrorCode`.

## Dependencies

- Standard C (stdlib, stdio, etc.).
- For randomness: uses `srand` and `rand`.

## Contribution

Add functions in the corresponding files and update headers with Doxygen documentation.
