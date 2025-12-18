#include "matrixop.h"

// ----------------------------------------------------
// I. 輔助/實用函式
// ----------------------------------------------------

void mat_print(const matrix_t M) {
    for (int i = 0; i < SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            printf("%8.3f ", M[i][j]);
        }
        printf(" |\n");
    }
}

// ----------------------------------------------------
// II. 基本操作
// ----------------------------------------------------

void mat_add(const matrix_t A, const matrix_t B, matrix_t C) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mat_subtract(const matrix_t A, const matrix_t B, matrix_t C) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// ----------------------------------------------------
// III. 線性操作
// ----------------------------------------------------

void mat_multiply(const matrix_t A, const matrix_t B, matrix_t C) {
    // 初始化結果矩陣 C
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0.0f;
        }
    }

    // 標準矩陣乘法邏輯 C[i][j] = sum(A[i][k] * B[k][j])
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mat_transpose(const matrix_t A, matrix_t C) {
    // 轉置操作：C[i][j] = A[j][i]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[j][i];
        }
    }
}

void mat_element_multiply(const matrix_t A, const matrix_t B, matrix_t C) {
    // 元素級乘法：C[i][j] = A[i][j] * B[i][j]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

// ----------------------------------------------------
// IV. 進階操作
// ----------------------------------------------------

/**
 * @brief 計算 2x2 子矩陣的行列式
 * @param a, b, c, d 矩陣元素
 * @return 行列式值
 */
static float det2x2(float a, float b, float c, float d) {
    return (a * d) - (b * c); [cite_start]// a*d - b*c [cite: 44]
}

float mat_determinant(const matrix_t A) {
    // 使用餘子式展開 (Cofactor Expansion) 沿著第一行展開
    float det = 0.0f;

    // A[0][0] * C(0,0)
    det += A[0][0] * det2x2(A[1][1], A[1][2], 
                           A[2][1], A[2][2]);
    
    // A[0][1] * C(0,1) (注意負號，因為 C(0,1) 的正負號是 (-1)^(0+1) = -1)
    det -= A[0][1] * det2x2(A[1][0], A[1][2], 
                           A[2][0], A[2][2]);
    
    // A[0][2] * C(0,2)
    det += A[0][2] * det2x2(A[1][0], A[1][1], 
                           A[2][0], A[2][1]);
    
    return det;
    [cite_start]// 公式確認 (Sarrus' Rule 形式): a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - (a13*a22*a31 + a11*a23*a32 + a12*a21*a33) [cite: 45] (註：原始文件公式有誤，此處使用正確版本)
}

void mat_adjoint(const matrix_t A, matrix_t C) {
    // 伴隨矩陣 (Adjoint Matrix) 是餘子式矩陣的轉置
    
    // 暫存餘子式矩陣 M
    matrix_t M;

    // 計算每個元素 (i, j) 的餘子式 M[i][j]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            
            // 找出不在第 i 行和第 j 列的元素，計算 2x2 子行列式
            // 行列式公式：det = M[i][j] * (-1)^(i+j)

            float a = A[(i + 1) % 3][(j + 1) % 3];
            float b = A[(i + 1) % 3][(j + 2) % 3];
            float c = A[(i + 2) % 3][(j + 1) % 3];
            float d = A[(i + 2) % 3][(j + 2) % 3];
            
            // 計算餘子式，不需要單獨處理 (-1)^(i+j) 
            // 因為計算伴隨矩陣時，這個正負號是內嵌在行列式計算的定義中的。

            // 餘子式 = (a*d - b*c) * (-1)^(i+j)
            float cofactor = det2x2(a, b, c, d);

            // 將結果存入伴隨矩陣 (注意：伴隨矩陣是餘子式矩陣的轉置！)
            // C[j][i] = 餘子式
            C[j][i] = cofactor; 
        }
    }
}

int mat_inverse(const matrix_t A, matrix_t C) {
    [cite_start]// 逆矩陣公式：A^(-1) = (1 / Det(A)) * adj(A) [cite: 66]

    float det_A = mat_determinant(A);

    // 檢查行列式是否接近零
    if (fabs(det_A) < EPSILON) {
        printf("錯誤：行列式為零 (%.3f)，逆矩陣不存在。\n", det_A);
        return 0; // 失敗
    }

    // 1. 計算伴隨矩陣 adj(A)
    matrix_t adj_A;
    mat_adjoint(A, adj_A);

    // 2. 計算 (1 / Det(A))
    float inv_det = 1.0f / det_A;

    // 3. 計算逆矩陣 C
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // C[i][j] = (1 / det_A) * adj_A[i][j]
            C[i][j] = adj_A[i][j] * inv_det;
        }
    }

    return 1; // 成功
}
