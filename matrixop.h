#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#include <stdio.h>
#include <math.h> // 用於逆矩陣中的 fabs

[cite_start]// 專案定義：矩陣的固定維度為 3x3 [cite: 8]
#define SIZE 3

// 浮點數精度容忍度，用於比較行列式是否為零
#define EPSILON 1e-6 

// 定義矩陣的資料類型 (使用 float)
typedef float matrix_t[SIZE][SIZE];

// ----------------------------------------------------
// I. 輔助/實用函式 (Utility)
// ----------------------------------------------------

/**
 * @brief 輸出矩陣到標準輸出
 * @param M 欲輸出的矩陣
 */
void mat_print(const matrix_t M);

// ----------------------------------------------------
// II. [cite_start]基本操作 (Basic Operations) [cite: 6]
// ----------------------------------------------------

/**
 * [cite_start]@brief 將矩陣 B 加到矩陣 A，結果存入矩陣 C (C = A + B) [cite: 7]
 */
void mat_add(const matrix_t A, const matrix_t B, matrix_t C);

/**
 * [cite_start]@brief 將矩陣 B 從矩陣 A 減去，結果存入矩陣 C (C = A - B) [cite: 13]
 */
void mat_subtract(const matrix_t A, const matrix_t B, matrix_t C);

// ----------------------------------------------------
// III. [cite_start]線性操作 (Linear Operations) [cite: 11]
// ----------------------------------------------------

/**
 * [cite_start]@brief 進行矩陣乘法 A * B，結果存入矩陣 C [cite: 12]
 */
void mat_multiply(const matrix_t A, const matrix_t B, matrix_t C);

/**
 * [cite_start]@brief 計算矩陣 A 的轉置矩陣，結果存入矩陣 C (C = A^T) [cite: 14]
 */
void mat_transpose(const matrix_t A, matrix_t C);

/**
 * [cite_start]@brief 進行元素級乘法 A o B (Hadamard product)，結果存入矩陣 C [cite: 15]
 */
void mat_element_multiply(const matrix_t A, const matrix_t B, matrix_t C);

// ----------------------------------------------------
// IV. [cite_start]進階操作 (Advanced Operations) [cite: 16]
// ----------------------------------------------------

/**
 * [cite_start]@brief 計算矩陣 A 的行列式 (Determinant) [cite: 17]
 * @return 矩陣 A 的行列式值
 */
float mat_determinant(const matrix_t A);

/**
 * [cite_start]@brief 計算矩陣 A 的伴隨矩陣 (Adjoint Matrix)，結果存入矩陣 C [cite: 18]
 */
void mat_adjoint(const matrix_t A, matrix_t C);

/**
 * [cite_start]@brief 計算矩陣 A 的逆矩陣 (Inverse Matrix)，結果存入矩陣 C [cite: 19, 20]
 * @return 1 表示成功，0 表示失敗 (行列式為零)
 */
int mat_inverse(const matrix_t A, matrix_t C);

#endif // MATRIX_OP_H
