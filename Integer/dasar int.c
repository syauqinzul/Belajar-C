// dasar-dasar int.c
#include <stdio.h>
int main() {
    int a = 10; // deklarasi variabel integer
    int b = 3;
    int penjumlahan = a + b; // operasi penjumlahan
    int pengurangan = a - b; // operasi pengurangan
    int perkalian = a * b;   // operasi perkalian
    int pembagian = a / b;   // operasi pembagian
    int sisa = a % b;        // operasi modulus (sisa
                              // pembagian)
    // Menampilkan hasil
    printf("Penjumlahan: %d + %d = %d\n", a, b, penjumlahan);
    printf("Pengurangan: %d - %d = %d\n", a, b, pengurangan);
    printf("Perkalian: %d * %d = %d\n", a, b, perkalian);
    printf("Pembagian: %d / %d = %d\n", a, b, pembagian);
    printf("Modulus: %d %% %d = %d\n", a, b, sisa);
    return 0;
}

