#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int i, j;
    
    // Input matrix
    printf("Masukkan elemen matrix %dx%d:\n", ROWS, COLS);
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Output matrix
    printf("\nMatrix yang diinput:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Hitung jumlah diagonal utama
    int diagonal_sum = 0;
    for(i = 0; i < ROWS; i++) {
        diagonal_sum += matrix[i][i];
    }
    printf("\nJumlah diagonal utama: %d\n", diagonal_sum);
    
    // Transpose matrix
    printf("\nTranspose matrix:\n");
    for(i = 0; i < COLS; i++) {
        for(j = 0; j < ROWS; j++) {
            printf("%d\t", matrix[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}