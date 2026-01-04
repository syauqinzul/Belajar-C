//ini contoh tipe data integer yang mudah untuk dipahami
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

// Contoh Output:
// Penjumlahan: 10 + 3 = 13
// Pengurangan: 10 - 3 = 7
// Perkalian: 10 * 3 = 30
// Pembagian: 10 / 3 = 3
// Modulus: 10 % 3 = 1

// Penjelasan tambahan:
// - Tipe data integer (int) digunakan untuk menyimpan bilangan bulat.
// - Operasi aritmatika dasar seperti penjumlahan, pengurangan,
//   perkalian, pembagian, dan modulus dapat dilakukan pada variabel
//   bertipe integer.
// - Hasil pembagian antara dua bilangan integer juga akan berupa
//   bilangan bulat (pembulatan ke bawah).
// - Modulus (%) memberikan sisa dari pembagian dua bilangan.
// - Fungsi printf digunakan untuk menampilkan hasil ke layar,
//   dengan format spesifier %d untuk menampilkan nilai integer.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan
//   fitur seperti input dari user atau operasi matematika lainnya.

