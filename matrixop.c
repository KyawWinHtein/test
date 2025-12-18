#include <stdio.h>
#include "matrixop.h"

/* Basic operations */
void mat_add(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void mat_sub(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] * B[i][j];
}

/* Matrix multiplication */
void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* Transpose */
void mat_transpose(double A[SIZE][SIZE], double T[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            T[i][j] = A[j][i];
}

/* Determinant 2x2 */
double det2(double A[2][2]) {
    return A[0][0]*A[1][1] - A[0][1]*A[1][0];
}

/* Determinant 3x3 */
double det3(double A[SIZE][SIZE]) {
    return  A[0][0]*A[1][1]*A[2][2]
          + A[0][1]*A[1][2]*A[2][0]
          + A[0][2]*A[1][0]*A[2][1]
          - A[0][2]*A[1][1]*A[2][0]
          - A[0][0]*A[1][2]*A[2][1]
          - A[0][1]*A[1][0]*A[2][2];
}

/* Adjoint matrix */
void adjoint(double A[SIZE][SIZE], double adj[SIZE][SIZE]) {
    double temp[2][2];

    temp[0][0] = A[1][1]; temp[0][1] = A[1][2];
    temp[1][0] = A[2][1]; temp[1][1] = A[2][2];
    adj[0][0] =  det2(temp);

    temp[0][0] = A[1][0]; temp[0][1] = A[1][2];
    temp[1][0] = A[2][0]; temp[1][1] = A[2][2];
    adj[0][1] = -det2(temp);

    temp[0][0] = A[1][0]; temp[0][1] = A[1][1];
    temp[1][0] = A[2][0]; temp[1][1] = A[2][1];
    adj[0][2] =  det2(temp);

    temp[0][0] = A[0][1]; temp[0][1] = A[0][2];
    temp[1][0] = A[2][1]; temp[1][1] = A[2][2];
    adj[1][0] = -det2(temp);

    temp[0][0] = A[0][0]; temp[0][1] = A[0][2];
    temp[1][0] = A[2][0]; temp[1][1] = A[2][2];
    adj[1][1] =  det2(temp);

    temp[0][0] = A[0][0]; temp[0][1] = A[0][1];
    temp[1][0] = A[2][0]; temp[1][1] = A[2][1];
    adj[1][2] = -det2(temp);

    temp[0][0] = A[0][1]; temp[0][1] = A[0][2];
    temp[1][0] = A[1][1]; temp[1][1] = A[1][2];
    adj[2][0] =  det2(temp);

    temp[0][0] = A[0][0]; temp[0][1] = A[0][2];
    temp[1][0] = A[1][0]; temp[1][1] = A[1][2];
    adj[2][1] = -det2(temp);

    temp[0][0] = A[0][0]; temp[0][1] = A[0][1];
    temp[1][0] = A[1][0]; temp[1][1] = A[1][1];
    adj[2][2] =  det2(temp);
}

/* Inverse matrix */
int inverse(double A[SIZE][SIZE], double inv[SIZE][SIZE]) {
    double det = det3(A);
    int i, j;
    double adj[SIZE][SIZE];

    if (det == 0)
        return 0;

    adjoint(A, adj);

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            inv[i][j] = adj[i][j] / det;

    return 1;
}

/* Print matrix */
void print_matrix(double A[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%8.3f ", A[i][j]);
        printf("\n");
    }
}

