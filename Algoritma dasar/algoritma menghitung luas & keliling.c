#include <stdio.h>

// Algoritma: Hitung luas dan keliling persegi panjang
int main() {
    // Langkah 1: Deklarasi variabel
    float panjang, lebar, luas, keliling;
    
    // Langkah 2: Input data
    printf("Masukkan panjang: ");
    scanf("%f", &panjang);
    printf("Masukkan lebar: ");
    scanf("%f", &lebar);
    
    // Langkah 3: Proses perhitungan
    luas = panjang * lebar;          // Rumus luas
    keliling = 2 * (panjang + lebar); // Rumus keliling
    
    // Langkah 4: Output hasil
    printf("\n=== HASIL PERHITUNGAN ===\n");
    printf("Panjang   : %.2f cm\n", panjang);
    printf("Lebar     : %.2f cm\n", lebar);
    printf("Luas      : %.2f cm²\n", luas);
    printf("Keliling  : %.2f cm\n", keliling);
    
    return 0;
}

/*Contoh Output:
Masukkan panjang: 10
Masukkan lebar: 5
=== HASIL PERHITUNGAN ===
Panjang   : 10.00 cm
Lebar     : 5.00 cm
Luas      : 50.00 cm²
Keliling  : 30.00 cm
*/
// Penjelasan tambahan:
// - Program ini menghitung luas dan keliling persegi panjang berdasarkan
//   input panjang dan lebar dari user.
// - Variabel bertipe float digunakan untuk menyimpan nilai desimal.
// - Rumus luas adalah panjang * lebar, sedangkan rumus keliling adalah
//   2 * (panjang + lebar).
// - Hasil perhitungan ditampilkan dengan format dua angka di belakang koma.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan validasi
//   input atau fitur untuk menghitung bentuk geometris lainnya.

// Tips:
// 1. Gunakan tipe data float untuk nilai desimal
// 2. Selalu tampilkan hasil dengan format yang rapi
// 3. Pisahkan logika input, proses, dan output untuk kode yang lebih bersih
// 4. Pertimbangkan validasi input untuk program yang lebih robust
// 5. Kembangkan program dengan menambahkan fitur baru sesuai kebutuhan pengguna


