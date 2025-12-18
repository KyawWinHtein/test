#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

/* Basic operations */
void mat_add(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_sub(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);

/* Linear operations */
void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_transpose(double A[SIZE][SIZE], double T[SIZE][SIZE]);

/* Advanced operations */
double det2(double A[2][2]);
double det3(double A[SIZE][SIZE]);
void adjoint(double A[SIZE][SIZE], double adj[SIZE][SIZE]);

/* Inverse */
int inverse(double A[SIZE][SIZE], double inv[SIZE][SIZE]);

/* Utility */
void print_matrix(double A[SIZE][SIZE]);

#endif

