#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

/* ===== Basic Operations ===== */
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void subMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void elemMulMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);

/* ===== Linear Operations ===== */
void mulMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void transposeMatrix(int A[SIZE][SIZE], int R[SIZE][SIZE]);

/* ===== Advanced Operations ===== */
int  determinant(int A[SIZE][SIZE]);
void adjointMatrix(int A[SIZE][SIZE], int R[SIZE][SIZE]);
int  inverseMatrix(int A[SIZE][SIZE], float R[SIZE][SIZE]);

#endif