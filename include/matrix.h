#ifndef MATRIX_H
#define MATRIX_H

#define REGISTRY_CAPACITY 100

typedef struct {
    int row;
    int col;
    float* data;
} Matrix;

typedef struct {
    float* data[REGISTRY_CAPACITY];
    int index;
} MatrixRegistry;


Matrix create_matrix(const int rows, const int cols, const float val);
void free_registry();

#endif // MATRIX_H