#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "operations_utils.h"

static MatrixRegistry registry = {.index = 0};

void add_registry(float* data) {
    registry.data[registry.index] = data;
    registry.index += 1; 
}

Matrix create_matrix(const int rows, const int cols, const float val) {
    // if (registry.index < REGISTRY_CAPACITY - 1) return ;
    float* data = (float*)calloc(rows*cols, sizeof(float));
    // if (data == NULL) return NULL;

    Matrix m = {
        .row = rows, 
        .col = cols, 
        .data = data
    };
    
    add_registry(data);
    fill(m, val);
    
    return m;
}

void free_registry() {
    for (int i = 0; i < registry.index; i++){
        free(registry.data[i]);
    }
}
