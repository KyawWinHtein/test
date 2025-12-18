#include <stdio.h>
#include "matrix_op.h"

void printIntMatrix(int A[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%4d ", A[i][j]);
        printf("\n");
    }
}

void printFloatMatrix(float A[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%8.3f ", A[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[SIZE][SIZE] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int R[SIZE][SIZE];
    float Inv[SIZE][SIZE];

    /* ===== BEFORE ===== */
    printf("===== Matrix A (Before) =====\n");
    printIntMatrix(A);

    printf("\n===== Matrix B (Before) =====\n");
    printIntMatrix(B);

    /* ===== Addition ===== */
    printf("\n===== A + B =====\n");
    addMatrix(A, B, R);
    printIntMatrix(R);

    /* ===== Subtraction ===== */
    printf("\n===== A - B =====\n");
    subMatrix(A, B, R);
    printIntMatrix(R);

    /* ===== Element-wise Multiplication ===== */
    printf("\n===== A * B (Element-wise) =====\n");
    elemMulMatrix(A, B, R);
    printIntMatrix(R);

    /* ===== Matrix Multiplication ===== */
    printf("\n===== A x B =====\n");
    mulMatrix(A, B, R);
    printIntMatrix(R);

    /* ===== Transpose ===== */
    printf("\n===== Transpose of A =====\n");
    transposeMatrix(A, R);
    printIntMatrix(R);

    /* ===== Determinant ===== */
    printf("\n===== Determinant of A =====\n");
    printf("det(A) = %d\n", determinant(A));

    /* ===== Inverse ===== */
    printf("\n===== Inverse of A =====\n");
    if (inverseMatrix(A, Inv)) {
        printFloatMatrix(Inv);
    } else {
        printf("Matrix A is NOT invertible (det = 0)\n");
    }

    return 0;
}