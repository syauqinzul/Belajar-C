//string.c yang simpel untuk pemula dan mudah dipahami
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int validasiNama(char nama[]) {
    // Nama hanya boleh berisi huruf dan spasi
    for(int i = 0; nama[i] != '\0'; i++) {  // Loop sampai akhir string
        if(!isalpha(nama[i]) && nama[i] != ' ') {  // Cek jika bukan huruf atau spasi
            return 0; // Tidak valid
        }
    }
    return 1; // Valid
}// Fungsi untuk validasi NIM
int validasiNIM(char nim[]) {  // NIM harus 10 digit angka
    // NIM harus 10 digit angka
    if(strlen(nim) != 10) {
        return 0;
    }
    
    for(int i = 0; nim[i] != '\0'; i++) {
        if(!isdigit(nim[i])) {
            return 0;
        }
    }
    return 1;
}// Fungsi untuk validasi email
int validasiEmail(char email[]) {
    // Email harus mengandung @ dan .
    int ada_at = 0;
    int ada_titik = 0;
    
    for(int i = 0; email[i] != '\0'; i++) {
        if(email[i] == '@') ada_at = 1;
        if(email[i] == '.') ada_titik = 1;
    }
    
    return (ada_at && ada_titik);
}

// Program utama
int main() {
    char nama[100], nim[20], email[100];
    
    // Input dan validasi NAMA
    do {
        printf("Masukkan nama (hanya huruf dan spasi): ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = '\0';
        
        if(!validasiNama(nama)) {
            printf("Error: Nama hanya boleh berisi huruf dan spasi!\n\n");
        }
    } while(!validasiNama(nama));
    
    // Input dan validasi NIM
    do {
        printf("Masukkan NIM (10 digit angka): ");
        fgets(nim, sizeof(nim), stdin);
        nim[strcspn(nim, "\n")] = '\0';
        
        if(!validasiNIM(nim)) {
            printf("Error: NIM harus 10 digit angka!\n\n");
        }
    } while(!validasiNIM(nim));
    
    // Input dan validasi EMAIL
    do {
        printf("Masukkan email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';
        
        if(!validasiEmail(email)) {
            printf("Error: Email harus mengandung @ dan titik!\n\n");
        }
    } while(!validasiEmail(email));
    
    // Tampilkan hasil
    printf("\n=== DATA VALID ===\n");
    printf("Nama  : %s\n", nama);
    printf("NIM   : %s\n", nim);
    printf("Email : %s\n", email);
    
    return 0;
}

// Contoh Output:
// Masukkan nama (hanya huruf dan spasi): Advan Pratama
// Masukkan NIM (10 digit angka): 1234567890
// Masukkan email:
//

// === DATA VALID ===
// Nama  : Advan Pratama
// NIM   : 1234567890
// Email :
//
// Penjelasan:
// - Fungsi validasiNama memastikan hanya huruf dan spasi yang diterima.
// - Fungsi validasiNIM memastikan NIM terdiri dari 10 digit angka.
// - Fungsi validasiEmail memastikan email mengandung karakter '@' dan '.'.
// - Loop do-while digunakan untuk meminta input ulang hingga valid.
// - Fungsi fgets digunakan untuk membaca string input dari user.
// - Setelah semua input valid, data ditampilkan ke layar.
// - Validasi input penting untuk memastikan data yang diproses oleh program
//   sesuai dengan yang diharapkan dan menghindari error di kemudian hari.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   sesuai kebutuhan pengguna.


