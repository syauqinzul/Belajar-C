//floating.c
#include <stdio.h>

// simpel float operations
// Program untuk melakukan operasi aritmatika dasar pada dua angka floating point
int main() {
    float a, b, sum, difference, product, quotient;
    
    // Input two floating point numbers
    printf("Enter first floating point number: ");
    scanf("%f", &a);
    
    printf("Enter second floating point number: ");
    scanf("%f", &b);
    
    // Perform basic arithmetic operations
    sum = a + b;
    difference = a - b;
    product = a * b;
    
    if(b != 0) {
        quotient = a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 1; // Exit with error code
    }
    
    // Display results
    printf("\nResults:\n");
    printf("Sum: %.2f\n", sum);
    printf("Difference: %.2f\n", difference);
    printf("Product: %.2f\n", product);
    printf("Quotient: %.2f\n", quotient);
    
    return 0;
}

/*
output nya: DALAM BAHASA INDONESIA
Masukkan angka floating point pertama: 5.5
Masukkan angka floating point kedua: 2.0
Hasil:
Jumlah: 7.50
Selisih: 3.50
Perkalian: 11.00
Pembagian: 2.75
*/

// Penjelasan tambahan:
// - Program ini menggunakan tipe data float untuk menangani angka desimal.
// - Fungsi scanf dengan format %f digunakan untuk input float.
// - Fungsi printf dengan format %.
//2f digunakan untuk menampilkan hasil dengan 2 angka di belakang koma.
// - Validasi pembagian dengan nol dilakukan untuk menghindari error runtime.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan operasi matematika lainnya
//   atau validasi input yang lebih ketat.

// Tips:
// 1. Gunakan float/double untuk presisi desimal
// 2. Perhatikan pembagian dengan nol
// 3. Spasi sebelum %c untuk menghindari newline
// 4. Format output dengan %.2f untuk 2 angka di belakang koma





