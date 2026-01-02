//dasar-dasar-float.c
#include <stdio.h>
// Program dasar untuk memahami tipe data float di C yang mudah untuk pemula
int main() {
    // Deklarasi variabel float
    float pi = 3.14f; // 'f' menandakan ini adalah float literal
    float radius, area, circumference;
    
    // Input jari-jari lingkaran dari user
    printf("Masukkan jari-jari lingkaran: ");
    scanf("%f", &radius);
    
    // Menghitung luas dan keliling lingkaran
    area = pi * radius * radius; // Luas = πr²
    circumference = 2 * pi * radius; // Keliling = 2πr
    
    // Menampilkan hasil
    printf("\nLuas lingkaran dengan jari-jari %.2f adalah: %.2f\n", radius, area);
    printf("Keliling lingkaran dengan jari-jari %.2f adalah: %.2f\n", radius, circumference);
    
    return 0;
}

/*
Contoh Output:
Masukkan jari-jari lingkaran: 5.5
Luas lingkaran dengan jari-jari 5.50 adalah: 95.03
Keliling lingkaran dengan jari-jari 5.50 adalah: 34.56
*/  

// Penjelasan tambahan:
// - Program ini menggunakan tipe data float untuk menangani angka desimal.
// - Fungsi scanf dengan format %f digunakan untuk input float.
// - Fungsi printf dengan format %.
//2f digunakan untuk menampilkan hasil dengan 2 angka di belakang koma.
// - Rumus luas dan keliling lingkaran diimplementasikan sesuai dengan standar matematika
// - Pastikan untuk memasukkan nilai numerik saat diminta input jari-jari.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan validasi input
//   atau fitur lainnya seperti menghitung diameter.

// Tips:
// 1. Gunakan float/double untuk presisi desimal
// 2. Perhatikan urutan operasi matematika
// 3. Spasi sebelum %c untuk menghindari newline
// 4. Gunakan konstanta untuk nilai tetap seperti π
// 5. Format output dengan %.2f untuk 2 angka di belakang koma
