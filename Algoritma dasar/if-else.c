//penjelasan tentang if else
#include <stdio.h>
int main() {
    int nilai;
    
    // Meminta input dari user
    printf("Masukkan nilai (0-100): ");
    scanf("%d", &nilai);
    
    // Algoritma percabangan if-else
    if(nilai < 0 || nilai > 100) {
        printf("Nilai tidak valid!\n");
    } else if(nilai >= 85) {
        printf("Grade: A\n");
    } else if(nilai >= 70) {
        printf("Grade: B\n");
    } else if(nilai >= 55) {
        printf("Grade: C\n");
    } else if(nilai >= 40) {
        printf("Grade: D\n");
    } else {
        printf("Grade: E\n");
    }
    
    return 0;
}
/*Contoh Output:
Masukkan nilai (0-100): 78
Grade: B

*/
// Penjelasan tambahan:
// - Program ini meminta user untuk memasukkan nilai antara 0 dan 100.
// - Menggunakan struktur if-else untuk menentukan grade berdasarkan nilai yang dimasukkan.
// - Setiap kondisi if-else memeriksa rentang nilai tertentu dan mencetak grade
//   yang sesuai.
// - Jika nilai di luar rentang 0-100, program akan menampilkan pesan "Nilai tidak valid!".
// - Struktur if-else memungkinkan program untuk menangani berbagai kondisi
//   dengan cara yang terorganisir dan mudah dibaca.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   seperti menyimpan nilai ke dalam array atau menghitung statistik nilai.
