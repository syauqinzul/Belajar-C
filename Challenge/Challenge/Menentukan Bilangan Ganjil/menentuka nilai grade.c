//menentukan nilai grade.c
//menggunakan struktur if-else untuk menentukan nilai grade berdasarkan skor yang dimasukkan oleh user
#include <stdio.h>
int main() {
    int score;
    char grade;

    // Meminta input dari user
    printf("Masukkan nilai skor (0-100): ");
    scanf("%d", &score);

    // Menentukan nilai grade berdasarkan skor
    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 80 && score < 90) {
        grade = 'B';
    } else if (score >= 70 && score < 80) {
        grade = 'C';
    } else if (score >= 60 && score < 70) {
        grade = 'D';
    } else if (score >= 0 && score < 60) {
        grade = 'F';
    } else {
        printf("Nilai skor tidak valid.\n");
        return 1; // Keluar dengan kode error
    }

    // Menampilkan hasil
    printf("Nilai grade Anda adalah: %c\n", grade);

    return 0;
}

//versi lain
//menggunakan float untuk nilai dan menampilkan pesan lulus/tidak lulus
// #include <stdio.h>

// int main() {
//     float nilai;
    
//     printf("Masukkan nilai (0-100): ");
//     scanf("%f", &nilai);
    
//     if (nilai >= 85 && nilai <= 100) {
//         printf("Grade: A\n");
//     } else if (nilai >= 70 && nilai < 85) {
//         printf("Grade: B\n");
//     } else if (nilai >= 60 && nilai < 70) {
//         printf("Grade: C\n");
//     } else if (nilai >= 50 && nilai < 60) {
//         printf("Grade: D\n");
//     } else if (nilai >= 0 && nilai < 50) {
//         printf("Grade: E (Tidak Lulus)\n");
//     } else {
//         printf("Nilai tidak valid!\n");
//     }
    
//     return 0;
// }