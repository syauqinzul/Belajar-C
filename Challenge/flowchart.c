/*
SOAL 2: Kalkulator Sederhana
Buat flowchart dan program kalkulator yang bisa melakukan:
1. Penjumlahan
2. Pengurangan
3. Perkalian
4. Pembagian

Flowchart harus mencakup:
- Input 2 bilangan
- Pilihan operasi
- Validasi (untuk pembagian dengan 0)
- Output hasil
*/

#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;
    
    // Input bilangan pertama
    printf("Masukkan bilangan pertama: ");
    scanf("%f", &num1);
    
    // Input operator
    printf("Masukkan operator (+, -, *, /): ");
    scanf(" %c", &operator); // Spasi sebelum %c penting!
    
    // Input bilangan kedua
    printf("Masukkan bilangan kedua: ");
    scanf("%f", &num2);
    
    // Proses kalkulasi berdasarkan operator
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '-':
            result = num1 - num2;
            printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '*':
            result = num1 * num2;
            printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("\nError: Pembagian dengan nol tidak diperbolehkan!\n");
            }
            break;
            
        default:
            printf("\nError: Operator tidak valid!\n");
    }
    
    // Penjelasan:
    // 1. Menggunakan switch-case untuk multi kondisi
    // 2. Validasi pembagian dengan 0
    // 3. Spasi sebelum %c untuk menghindari newline
    
    return 0;
}

/*Contoh Output:
Masukkan bilangan pertama: 10
Masukkan operator (+, -, *, /): /
Masukkan bilangan kedua: 2
10.00 / 2.00 = 5.00
*/
/*Contoh Output (pembagian dengan nol):
Masukkan bilangan pertama: 10
Masukkan operator (+, -, *, /): /
Masukkan bilangan kedua: 0
Error: Pembagian dengan nol tidak diperbolehkan!
*/  

// Tips:
// 1. Gunakan float untuk hasil desimal
// 2. Validasi input penting untuk pembagian
// 3. Spasi sebelum %c untuk menghindari newline
// 4. Gunakan switch-case untuk struktur kontrol yang lebih bersih
// 5. Format output dengan %.2f untuk 2 angka di belakang koma

