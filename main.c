#include <stdio.h>
#include "matrixop.h"

int main() {
    double A[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    double B[3][3] = {
        {7, 8, 9},
        {2, 3, 4},
        {1, 0, 1}
    };

    double C[3][3], invA[3][3];

    printf("Matrix A:\n");
    print_matrix(A);

    printf("\nMatrix B:\n");
    print_matrix(B);

    mat_mul(A, B, C);
    printf("\nA * B:\n");
    print_matrix(C);

    if (inverse(A, invA)) {
        printf("\nInverse of A:\n");
        print_matrix(invA);
    } else {
        printf("\nMatrix A has no inverse.\n");
    }

    return 0;
}

