#include <stdio.h>

int main() {
    // a. Deklarasi Array
    char nama[5][50];           // Array 2D untuk nama
    float tugas[5], uts[5], uas[5], nilai_akhir[5];
    char grade[5];
    int i;
    
    // b. Input Data
    printf("=== INPUT DATA MAHASISWA ===\n");
    for(i = 0; i < 5; i++) {
        printf("\nMahasiswa ke-%d:\n", i+1);
        printf("Nama  : ");
        scanf(" %[^\n]s", nama[i]);  // baca string dengan spasi
        printf("Tugas : ");
        scanf("%f", &tugas[i]);
        printf("UTS   : ");
        scanf("%f", &uts[i]);
        printf("UAS   : ");
        scanf("%f", &uas[i]);
    }
    
    // c. Proses & Output
    printf("\n\n=== HASIL NILAI MAHASISWA ===\n");
    printf("=================================================================\n");
    printf("| No | Nama Mahasiswa | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
    printf("=================================================================\n");
    
    for(i = 0; i < 5; i++) {
        // Hitung nilai akhir
        nilai_akhir[i] = (tugas[i]*0.3) + (uts[i]*0.3) + (uas[i]*0.4);
        
        // Tentukan grade
        if(nilai_akhir[i] >= 85) {
            grade[i] = 'A';
        } else if(nilai_akhir[i] >= 70) {
            grade[i] = 'B';
        } else if(nilai_akhir[i] >= 60) {
            grade[i] = 'C';
        } else if(nilai_akhir[i] >= 50) {
            grade[i] = 'D';
        } else {
            grade[i] = 'E';
        }
        
        // Tampilkan dalam tabel
        printf("| %2d | %-14s | %5.1f | %3.1f | %3.1f | %11.2f |   %c   |\n",
               i+1, nama[i], tugas[i], uts[i], uas[i], nilai_akhir[i], grade[i]);
    }
    printf("=================================================================\n");
    
    // Hitung statistik
    float rata_rata = 0;
    int count_A = 0, count_B = 0, count_C = 0, count_D = 0, count_E = 0;
    
    for(i = 0; i < 5; i++) {
        rata_rata += nilai_akhir[i];
        
        switch(grade[i]) {
            case 'A': count_A++; break;
            case 'B': count_B++; break;
            case 'C': count_C++; break;
            case 'D': count_D++; break;
            case 'E': count_E++; break;
        }
    }
    rata_rata /= 5;
    
    printf("\n=== STATISTIK KELAS ===\n");
    printf("Rata-rata nilai akhir: %.2f\n", rata_rata);
    printf("Distribusi Grade:\n");
    printf("A: %d mahasiswa\n", count_A);
    printf("B: %d mahasiswa\n", count_B);
    printf("C: %d mahasiswa\n", count_C);
    printf("D: %d mahasiswa\n", count_D);
    printf("E: %d mahasiswa\n", count_E);
    
    return 0;
}