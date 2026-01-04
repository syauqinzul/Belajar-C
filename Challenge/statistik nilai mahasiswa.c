#include <stdio.h>
#define MAX 100

int main() {
    int nilai[MAX], n, i, j, temp;
    int total = 0, lulus = 0;
    float rata_rata;
    int max, min;
    
    // Input jumlah mahasiswa
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    
    // Validasi input
    if(n <= 0 || n > MAX) {
        printf("Error: Jumlah mahasiswa harus antara 1 dan %d\n", MAX);
        return 1; // Exit dengan error code
    }
    
    // Input nilai mahasiswa
    for(i = 0; i < n; i++) {
        printf("Masukkan nilai mahasiswa %d: ", i + 1);
        scanf("%d", &nilai[i]);
        
        // Validasi nilai antara 0-100
        while(nilai[i] < 0 || nilai[i] > 100) {
            printf("Nilai harus antara 0-100! Masukkan lagi: ");
            scanf("%d", &nilai[i]);
        }
    }
    
    // Inisialisasi max dan min dengan nilai pertama
    max = nilai[0];
    min = nilai[0];
    
    // Proses perhitungan
    for(i = 0; i < n; i++) {
        total += nilai[i];
        
        // Cek nilai maksimum
        if(nilai[i] > max) {
            max = nilai[i];
        }
        
        // Cek nilai minimum
        if(nilai[i] < min) {
            min = nilai[i];
        }
        
        // Hitung yang lulus (nilai >= 60)
        if(nilai[i] >= 60) {
            lulus++;
        }
    }
    
    // Hitung rata-rata
    rata_rata = (float)total / n;
    
    // Sorting (Bubble Sort) - descending
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(nilai[j] < nilai[j + 1]) {
                // Tukar nilai
                temp = nilai[j];
                nilai[j] = nilai[j + 1];
                nilai[j + 1] = temp;
            }
        }
    }
    
    // Tampilkan hasil
    printf("\n=== HASIL STATISTIK NILAI ===\n");
    printf("Jumlah mahasiswa    : %d\n", n);
    printf("Total nilai         : %d\n", total);
    printf("Rata-rata           : %.2f\n", rata_rata);
    printf("Nilai tertinggi     : %d\n", max);
    printf("Nilai terendah      : %d\n", min);
    printf("Jumlah yang lulus   : %d\n", lulus);
    printf("Jumlah tidak lulus  : %d\n", n - lulus);
    printf("Persentase kelulusan: %.2f%%\n", (float)lulus / n * 100);
    
    printf("\nUrutan nilai (terbesar ke terkecil):\n");
    for(i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
        if((i + 1) % 10 == 0) printf("\n"); // Newline setiap 10 nilai
    }
    printf("\n");
    
    // Penjelasan:
    // 1. Menggunakan define MAX untuk batas array
    // 2. Bubble Sort untuk sorting sederhana
    // 3. Cast ke float untuk presisi rata-rata
    // 4. Validasi input penting untuk program yang robust
    
    return 0;
}