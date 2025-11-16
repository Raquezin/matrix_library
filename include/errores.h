#ifndef ERRORES_H
#define ERRORES_H

typedef enum {
    ERR_DIM_MISMATCH = -1,
    ERR_NONE,
    ERR_DET_0,
    ERR_INF_SOL,
    ERR_NO_SOL,
    ERR_NOT_INVERTIBLE,
    ERR_DIV_BY_ZERO
} ErrorCode;

#endif // ERRORES_H