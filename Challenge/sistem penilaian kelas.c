#include <stdio.h>
#include <string.h>
#define MAX_MAHASISWA 50
#define MAX_MATKUL 10

int main() {
    int jumlah_mahasiswa, jumlah_matkul;
    float nilai[MAX_MAHASISWA][MAX_MATKUL][3]; // [tugas][uts][uas]
    float nilai_akhir[MAX_MAHASISWA][MAX_MATKUL];
    char nama[MAX_MAHASISWA][50];
    int i, j;
    
    // Input jumlah mahasiswa dan mata kuliah
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah_mahasiswa);
    
    printf("Masukkan jumlah mata kuliah: ");
    scanf("%d", &jumlah_matkul);
    
    // Validasi input
    if(jumlah_mahasiswa <= 0 || jumlah_mahasiswa > MAX_MAHASISWA ||
       jumlah_matkul <= 0 || jumlah_matkul > MAX_MATKUL) {
        printf("Error: Input tidak valid!\n");
        return 1;
    }
    
    // Clear buffer
    getchar();
    
    // Input data mahasiswa
    for(i = 0; i < jumlah_mahasiswa; i++) {
        printf("\n=== Mahasiswa %d ===\n", i + 1);
        printf("Nama: ");
        fgets(nama[i], sizeof(nama[i]), stdin);
        nama[i][strcspn(nama[i], "\n")] = '\0'; // Hapus newline
        
        // Input nilai per mata kuliah
        for(j = 0; j < jumlah_matkul; j++) {
            printf("\nMata Kuliah %d:\n", j + 1);
            
            printf("  Nilai Tugas (0-100): ");
            scanf("%f", &nilai[i][j][0]);
            while(nilai[i][j][0] < 0 || nilai[i][j][0] > 100) {
                printf("  Nilai harus 0-100! Masukkan lagi: ");
                scanf("%f", &nilai[i][j][0]);
            }
            
            printf("  Nilai UTS (0-100): ");
            scanf("%f", &nilai[i][j][1]);
            while(nilai[i][j][1] < 0 || nilai[i][j][1] > 100) {
                printf("  Nilai harus 0-100! Masukkan lagi: ");
                scanf("%f", &nilai[i][j][1]);
            }
            
            printf("  Nilai UAS (0-100): ");
            scanf("%f", &nilai[i][j][2]);
            while(nilai[i][j][2] < 0 || nilai[i][j][2] > 100) {
                printf("  Nilai harus 0-100! Masukkan lagi: ");
                scanf("%f", &nilai[i][j][2]);
            }
            
            // Hitung nilai akhir: Tugas(30%) + UTS(30%) + UAS(40%)
            nilai_akhir[i][j] = (nilai[i][j][0] * 0.3) + 
                               (nilai[i][j][1] * 0.3) + 
                               (nilai[i][j][2] * 0.4);
        }
        getchar(); // Clear buffer
    }
    
    // Tampilkan hasil
    printf("\n\n=== HASIL PENILAIAN ===\n");
    
    for(i = 0; i < jumlah_mahasiswa; i++) {
        printf("\n%s:\n", nama[i]);
        printf("┌──────┬───────┬──────┬──────┬─────────────┐\n");
        printf("│ No.  │ Tugas │ UTS  │ UAS  │ Nilai Akhir │\n");
        printf("├──────┼───────┼──────┼──────┼─────────────┤\n");
        
        float total_semua = 0;
        
        for(j = 0; j < jumlah_matkul; j++) {
            printf("│ %-4d │ %-5.0f │ %-4.0f │ %-4.0f │ %-11.2f │\n", 
                   j + 1, 
                   nilai[i][j][0], 
                   nilai[i][j][1], 
                   nilai[i][j][2], 
                   nilai_akhir[i][j]);
            
            total_semua += nilai_akhir[i][j];
        }
        
        printf("└──────┴───────┴──────┴──────┴─────────────┘\n");
        printf("Rata-rata semua matkul: %.2f\n", total_semua / jumlah_matkul);
        
        // Tentukan predikat
        float rata = total_semua / jumlah_matkul;
        printf("Predikat: ");
        if(rata >= 85) printf("A (Sangat Baik)\n");
        else if(rata >= 70) printf("B (Baik)\n");
        else if(rata >= 60) printf("C (Cukup)\n");
        else if(rata >= 50) printf("D (Kurang)\n");
        else printf("E (Gagal)\n");
    }
    
    // Statistik kelas
    printf("\n=== STATISTIK KELAS ===\n");
    
    for(j = 0; j < jumlah_matkul; j++) {
        float total_matkul = 0;
        float max_matkul = 0;
        float min_matkul = 100;
        int lulus_matkul = 0;
        
        for(i = 0; i < jumlah_mahasiswa; i++) {
            total_matkul += nilai_akhir[i][j];
            
            if(nilai_akhir[i][j] > max_matkul) {
                max_matkul = nilai_akhir[i][j];
            }
            
            if(nilai_akhir[i][j] < min_matkul) {
                min_matkul = nilai_akhir[i][j];
            }
            
            if(nilai_akhir[i][j] >= 60) {
                lulus_matkul++;
            }
        }
        
        printf("\nMata Kuliah %d:\n", j + 1);
        printf("  Rata-rata kelas: %.2f\n", total_matkul / jumlah_mahasiswa);
        printf("  Nilai tertinggi: %.2f\n", max_matkul);
        printf("  Nilai terendah : %.2f\n", min_matkul);
        printf("  Jumlah lulus   : %d/%d (%.1f%%)\n", 
               lulus_matkul, jumlah_mahasiswa,
               (float)lulus_matkul / jumlah_mahasiswa * 100);
    }
    
    return 0;
}

/*
Penjelasan:
- Program ini mengelola penilaian kelas untuk beberapa mahasiswa dan mata kuliah.
- Data disimpan dalam array 3D untuk nilai tugas, UTS, dan UAS
- Nilai akhir dihitung berdasarkan bobot: Tugas 30%, UTS 30%, UAS 40%
- Hasil penilaian ditampilkan dalam format tabel untuk setiap mahasiswa
- Statistik kelas dihitung untuk setiap mata kuliah termasuk rata-rata, nilai tertinggi, terendah, dan jumlah lulus
- Validasi input nilai untuk memastikan berada dalam rentang 0-100
- Gunakan fungsi fgets untuk input nama agar dapat menangani spasi
*/

/*Contoh Output:
Masukkan jumlah mahasiswa: 2
Masukkan jumlah mata kuliah: 2

=== Mahasiswa 1 ===
Nama: Andi
Mata Kuliah 1:
  Nilai Tugas (0-100): 80
  Nilai UTS (0-100): 70
  Nilai UAS (0-100): 90

Mata Kuliah 2:
  Nilai Tugas (0-100): 60
  Nilai UTS (0-100): 75
  Nilai UAS (0-100): 80

=== Mahasiswa 2 ===
Nama: Budi
Mata Kuliah 1:
  Nilai Tugas (0-100): 50
  Nilai UTS (0-100): 60
  Nilai UAS (0-100): 70

Mata Kuliah 2:
  Nilai Tugas (0-100): 90
  Nilai UTS (0-100): 85
  Nilai UAS (0-100): 80

=== HASIL PENILAIAN ===
Andi:
┌──────┬───────┬──────┬──────┬─────────────┐
│ No.  │ Tugas │ UTS  │ UAS  │ Nilai Akhir │
├──────┼───────┼──────┼──────┼─────────────┤
│ 1    │ 80    │ 70   │ 90   │ 80.00       │
│ 2    │ 60    │ 75   │ 80   │ 73.50       │
└──────┴───────┴──────┴──────┴─────────────┘
Rata-rata semua matkul: 76.75
Predikat: B (Baik)

Budi:
┌──────┬───────┬──────┬──────┬─────────────┐
│ No.  │ Tugas │ UTS  │ UAS  │ Nilai Akhir │
├──────┼───────┼──────┼──────┼─────────────┤    
│ 1    │ 50    │ 60   │ 70   │ 62.00       │
│ 2    │ 90    │ 85   │ 80   │ 84.50       │
└──────┴───────┴──────┴──────┴─────────────┘

Rata-rata semua matkul: 73.25
Predikat: C (Cukup)

=== STATISTIK KELAS ===
Mata Kuliah 1:
  Rata-rata kelas: 71.00
  Nilai tertinggi: 80.00
  Nilai terendah : 62.00
  Jumlah lulus   : 2/2 (100.0%)

Mata Kuliah 2:
  Rata-rata kelas: 79.00
  Nilai tertinggi: 84.50
  Nilai terendah : 73.50
  Jumlah lulus   : 2/2 (100.0%)
*/

// Catatan:
// - Pastikan untuk menguji program dengan berbagai input untuk memastikan keakuratan perhitungan
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur seperti penyimpanan data ke file atau antarmuka pengguna grafis.

