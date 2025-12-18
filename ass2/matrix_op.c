#include "matrix_op.h"

/* ===== Basic Operations ===== */

// Matrix Addition
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            R[i][j] = A[i][j] + B[i][j];
}

// Matrix Subtraction
void subMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            R[i][j] = A[i][j] - B[i][j];
}

// Element-wise Multiplication
void elemMulMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            R[i][j] = A[i][j] * B[i][j];
}

/* ===== Linear Operations ===== */

// Matrix Multiplication
void mulMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE])
{
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            R[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose Matrix
void transposeMatrix(int A[SIZE][SIZE], int R[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            R[j][i] = A[i][j];
}

/* ===== Advanced Operations ===== */

// Determinant of 3x3 Matrix
int determinant(int A[SIZE][SIZE])
{
    int det;

    det =  A[0][0]*A[1][1]*A[2][2]
         + A[0][1]*A[1][2]*A[2][0]
         + A[0][2]*A[1][0]*A[2][1]
         - A[0][2]*A[1][1]*A[2][0]
         - A[0][0]*A[1][2]*A[2][1]
         - A[0][1]*A[1][0]*A[2][2];

    return det;
}

// Adjoint Matrix
void adjointMatrix(int A[SIZE][SIZE], int R[SIZE][SIZE])
{
    R[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    R[0][1] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    R[0][2] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    R[1][0] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    R[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    R[1][2] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    R[2][0] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    R[2][1] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    R[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

// Inverse Matrix
int inverseMatrix(int A[SIZE][SIZE], float R[SIZE][SIZE])
{
    int det = determinant(A);
    int adj[SIZE][SIZE];
    int i, j;

    if (det == 0)
        return 0;   // Not invertible

    adjointMatrix(A, adj);

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            R[i][j] = adj[i][j] / (float)det;

    return 1;   // Success
}
