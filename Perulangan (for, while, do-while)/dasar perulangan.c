// dasar - dasar perulangan.c
#include <stdio.h>
int main() {
    int nilai;

    // Meminta input dari user
    printf("Masukkan nilai (0-100): ");
    scanf("%d", &nilai);

    // Validasi input
    while (nilai < 0 || nilai > 100) {
        printf("Nilai tidak valid! Masukkan nilai antara 0 dan 100: ");
        scanf("%d", &nilai);
    }

    // Menampilkan nilai yang valid
    printf("Nilai yang dimasukkan adalah: %d\n", nilai);

    return 0;
}

/*Contoh Output:
Masukkan nilai (0-100): 150 
Nilai tidak valid! Masukkan nilai antara 0 dan 100: -20
Nilai tidak valid! Masukkan nilai antara 0 dan 100: 85
Nilai yang dimasukkan adalah: 85
*/

// Penjelasan tambahan:
// - Program ini meminta user untuk memasukkan nilai antara 0 dan 100.
// - Jika nilai yang dimasukkan tidak valid (kurang dari 0 atau lebih dari 100), program akan terus meminta input hingga nilai yang valid diberikan.
// - Validasi dilakukan menggunakan loop
//   while yang memeriksa kondisi nilai.
// - Setelah nilai yang valid dimasukkan, program menampilkan nilai tersebut.
// - Validasi input penting untuk memastikan data yang diproses oleh program
//   sesuai dengan yang diharapkan dan menghindari error di kemudian hari.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   seperti menyimpan nilai ke dalam array atau menghitung statistik nilai.

// Tips:
// 1. Gunakan loop untuk validasi input
// 2. Berikan pesan yang jelas kepada user saat input tidak valid
// 3. Pastikan kondisi validasi sesuai dengan kebutuhan program
// 4. Pertimbangkan untuk menambahkan batasan jumlah percobaan input jika diperlukan

