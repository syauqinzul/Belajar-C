#include <stdio.h>

int main() {
    float num1, num2, result; // Menampung bilangan dan hasil
    char operator; // Menampung operator aritmatika
    
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

// Contoh Output:
// Masukkan bilangan pertama: 5.5
// Masukkan operator (+, -, *, /): *
// Masukkan bilangan kedua: 2.0
// 5.50 * 2.00 = 11.00

// Penjelasan tambahan:
// - Program ini adalah kalkulator sederhana yang dapat melakukan operasi penjumlahan,
//   pengurangan, perkalian, dan pembagian pada dua bilangan floating point.
// - Tipe data float digunakan untuk menangani angka desimal.
// - Fungsi scanf dengan format %f digunakan untuk input float, dan %c untuk input
//   karakter operator.
// - Validasi dilakukan untuk memastikan pembagian dengan nol tidak terjadi,
//   yang akan menyebabkan error runtime.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   seperti operasi matematika lainnya atau validasi input yang lebih ketat.

// Tips:
// 1. Gunakan float untuk hasil desimal
// 2. Validasi input penting untuk pembagian
// 3. Spasi sebelum %c untuk menghindari newline
// 4. Format output dengan %.2f untuk 2 angka di belakang koma
// 5. Gunakan switch-case untuk struktur kontrol yang lebih bersih

/*Contoh Output (pembagian dengan nol):
Masukkan bilangan pertama: 10
Masukkan operator (+, -, *, /): /
Masukkan bilangan kedua: 0
Error: Pembagian dengan nol tidak diperbolehkan!
*/

/*Contoh Output:
Masukkan bilangan pertama: 10
Masukkan operator (+, -, *, /): /
Masukkan bilangan kedua: 2
10.00 / 2.00 = 5.00
*/

