#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nim[20];
    float ipk;
    int umur;
    int valid = 0;
    
    printf("=== VALIDASI INPUT DATA MAHASISWA ===\n\n");
    
    // Validasi NIM (10 digit angka)
    do {
        printf("Masukkan NIM (10 digit angka): ");
        scanf("%s", nim);
        
        valid = 1;
        if(strlen(nim) != 10) {
            printf("Error: NIM harus 10 digit!\n");
            valid = 0;
            continue;
        }
        
        for(int i = 0; i < 10; i++) {
            if(!isdigit(nim[i])) {
                printf("Error: NIM hanya boleh berisi angka!\n");
                valid = 0;
                break;
            }
        }
    } while(!valid);
    
    // Validasi IPK (0.00 - 4.00)
    do {
        printf("Masukkan IPK (0.00 - 4.00): ");
        scanf("%f", &ipk);
        
        if(ipk < 0.00 || ipk > 4.00) {
            printf("Error: IPK harus antara 0.00 - 4.00!\n");
            valid = 0;
        } else {
            valid = 1;
        }
    } while(!valid);
    
    // Validasi Umur (17-30)
    do {
        printf("Masukkan umur (17-30): ");
        scanf("%d", &umur);
        
        if(umur < 17 || umur > 30) {
            printf("Error: Umur harus antara 17-30 tahun!\n");
            valid = 0;
        } else {
            valid = 1;
        }
    } while(!valid);
    
    // Tampilkan hasil
    printf("\n=== DATA YANG DIINPUT ===\n");
    printf("NIM  : %s\n", nim);
    printf("IPK  : %.2f\n", ipk);
    printf("Umur : %d tahun\n", umur);
    
    // Klasifikasi berdasarkan IPK
    printf("\n=== KLASIFIKASI ===\n");
    if(ipk >= 3.50) {
        printf("Predikat: Cum Laude\n");
    } else if(ipk >= 3.00) {
        printf("Predikat: Sangat Memuaskan\n");
    } else if(ipk >= 2.50) {
        printf("Predikat: Memuaskan\n");
    } else if(ipk >= 2.00) {
        printf("Predikat: Cukup\n");
    } else {
        printf("Predikat: Tidak Lulus\n");
    }
    
    return 0;
}

// Contoh Output:
// === VALIDASI INPUT DATA MAHASISWA ===
//
// Masukkan NIM (10 digit angka): 123456789
// Masukkan IPK (0.00 - 4.00): 4.5
// Error: IPK harus antara 0.00 - 4.00!
// Masukkan IPK (0.00 - 4.00): 3.75
// Masukkan umur (17-30): 16
// Error: Umur harus antara 17-30 tahun!
// Masukkan umur (17-30): 20
//
// === DATA YANG DIINPUT ===
// NIM  : 1234567890
// IPK  : 3.75
// Umur : 20 tahun
// === KLASIFIKASI ===
// Predikat: Cum Laude
// Penjelasan tambahan:
// - Program ini meminta user untuk memasukkan NIM, IPK, dan umur mahasiswa.  
// - Setiap input divalidasi sesuai kriteria yang ditentukan.  
// - Jika input tidak valid, program akan menampilkan pesan error dan meminta input ulang.
// - Setelah semua input valid, program menampilkan data yang diinput dan mengklasifikasikan
//   IPK berdasarkan predikat yang sesuai.  
// - Validasi input penting untuk memastikan data yang diproses oleh program
//   sesuai dengan yang diharapkan dan menghindari error di kemudian hari.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   seperti menyimpan data ke dalam file atau database.  

// Tips:
// 1. Gunakan loop untuk validasi input
// 2. Berikan pesan yang jelas kepada user saat input tidak valid
// 3. Pisahkan logika validasi ke dalam fungsi terpisah untuk modularitas
// 4. Pertimbangkan untuk menambahkan batasan jumlah percobaan input jika diperlukan
// 5. Gunakan tipe data yang sesuai untuk setiap input (string untuk NIM,
//    float untuk IPK, int untuk umur)
