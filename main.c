#include "matrixop.h"
#include <stdlib.h> // for EXIT_SUCCESS

int main() {
    // 示例矩陣 A 和 B
    matrix_t A = {
        {1.0f, 2.0f, 3.0f},
        {0.0f, 1.0f, 4.0f},
        {5.0f, 6.0f, 0.0f}
    };

    matrix_t B = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 2.0f, 0.0f},
        {1.0f, 0.0f, 3.0f}
    };

    matrix_t Result;
    
    printf("==========================================\n");
    printf("        3x3 矩陣運算函式庫測試\n");
    printf("==========================================\n");
    
    printf("矩陣 A:\n");
    mat_print(A);
    printf("\n矩陣 B:\n");
    mat_print(B);
    printf("\n------------------------------------------\n");

    // 1. 加法 (Addition)
    mat_add(A, B, Result);
    printf("1. A + B (加法):\n");
    mat_print(Result);
    printf("\n");

    // 2. 減法 (Subtraction)
    mat_subtract(A, B, Result);
    printf("2. A - B (減法):\n");
    mat_print(Result);
    printf("\n");

    // 3. 轉置 (Transpose)
    mat_transpose(A, Result);
    printf("3. A^T (轉置):\n");
    mat_print(Result);
    printf("\n");

    // 4. 矩陣乘法 (Matrix Multiplication)
    mat_multiply(A, B, Result);
    printf("4. A * B (矩陣乘法):\n");
    mat_print(Result);
    printf("\n");

    // 5. 元素級乘法 (Element-wise Multiplication)
    mat_element_multiply(A, B, Result);
    printf("5. A o B (元素級乘法):\n");
    mat_print(Result);
    printf("\n");

    // 6. 行列式 (Determinant)
    float det = mat_determinant(A);
    printf("6. Det(A) (行列式): %.3f\n", det);
    printf("\n------------------------------------------\n");

    // 7. 伴隨矩陣 (Adjoint Matrix)
    mat_adjoint(A, Result);
    printf("7. adj(A) (伴隨矩陣):\n");
    mat_print(Result);
    printf("\n");

    // 8. 逆矩陣 (Inverse Matrix)
    printf("8. A^-1 (逆矩陣):\n");
    if (mat_inverse(A, Result)) {
        mat_print(Result);
        
        // 驗證：A * A^-1 應接近單位矩陣 I
        matrix_t IdentityCheck;
        mat_multiply(A, Result, IdentityCheck);
        printf("\n驗證: A * A^-1 (應為單位矩陣 I):\n");
        mat_print(IdentityCheck);
    }
    printf("\n------------------------------------------\n");


    // 測試不可逆矩陣 (行列式為 0)
    matrix_t Singular = {
        {1.0f, 2.0f, 3.0f},
        {1.0f, 2.0f, 3.0f}, // 第二行等於第一行
        {4.0f, 5.0f, 6.0f}
    };
    printf("測試不可逆矩陣 (Singular Matrix):\n");
    printf("Det(Singular): %.3f\n", mat_determinant(Singular));
    mat_inverse(Singular, Result);


    return EXIT_SUCCESS;
}
