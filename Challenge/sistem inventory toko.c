#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BARANG 100

struct Barang {
    int kode;
    char nama[50];
    float harga;
    int stok;
};

// Fungsi untuk clear screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk pause
void pause() {
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
    getchar(); // Dua kali untuk menangkap newline
}

int main() {
    struct Barang inventory[MAX_BARANG];
    int jumlah_barang = 0;
    int pilihan;
    int i;
    
    // Inisialisasi beberapa data dummy
    inventory[0].kode = 1001;
    strcpy(inventory[0].nama, "Buku Tulis");
    inventory[0].harga = 5000;
    inventory[0].stok = 50;
    
    inventory[1].kode = 1002;
    strcpy(inventory[1].nama, "Pulpen");
    inventory[1].harga = 3000;
    inventory[1].stok = 100;
    
    inventory[2].kode = 1003;
    strcpy(inventory[2].nama, "Penggaris");
    inventory[2].harga = 7000;
    inventory[2].stok = 30;
    
    jumlah_barang = 3;
    
    do {
        clearScreen();
        printf("╔══════════════════════════════════════╗\n");
        printf("║      SISTEM INVENTORY TOKO           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║ 1. Tambah Barang                     ║\n");
        printf("║ 2. Tampilkan Semua Barang            ║\n");
        printf("║ 3. Cari Barang (berdasarkan kode)    ║\n");
        printf("║ 4. Cari Barang (berdasarkan nama)    ║\n");
        printf("║ 5. Update Stok Barang                ║\n");
        printf("║ 6. Hapus Barang                      ║\n");
        printf("║ 7. Hitung Total Nilai Inventory      ║\n");
        printf("║ 8. Urutkan Barang (berdasarkan stok) ║\n");
        printf("║ 9. Simpan ke File                    ║\n");
        printf("║ 10. Load dari File                   ║\n");
        printf("║ 0. Keluar                            ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: // Tambah Barang
                clearScreen();
                printf("=== TAMBAH BARANG ===\n");
                
                if(jumlah_barang >= MAX_BARANG) {
                    printf("Inventory penuh! Maksimal %d barang.\n", MAX_BARANG);
                    pause();
                    break;
                }
                
                // Input data barang
                printf("Kode barang  : ");
                scanf("%d", &inventory[jumlah_barang].kode);
                
                // Cek duplikasi kode
                for(i = 0; i < jumlah_barang; i++) {
                    if(inventory[i].kode == inventory[jumlah_barang].kode) {
                        printf("Error: Kode sudah digunakan!\n");
                        pause();
                        break;
                    }
                }
                if(i < jumlah_barang) break; // Jika ada duplikat
                
                printf("Nama barang  : ");
                getchar(); // Clear buffer
                fgets(inventory[jumlah_barang].nama, 
                      sizeof(inventory[jumlah_barang].nama), stdin);
                inventory[jumlah_barang].nama[strcspn(
                    inventory[jumlah_barang].nama, "\n")] = '\0';
                
                printf("Harga barang : Rp ");
                scanf("%f", &inventory[jumlah_barang].harga);
                
                printf("Stok barang  : ");
                scanf("%d", &inventory[jumlah_barang].stok);
                
                printf("\nBarang berhasil ditambahkan!\n");
                jumlah_barang++;
                pause();
                break;
                
            case 2: // Tampilkan Semua Barang
                clearScreen();
                printf("=== DAFTAR BARANG ===\n");
                printf("┌──────┬────────────────────────────┬──────────────┬───────┬──────────────┐\n");
                printf("│ Kode │ Nama Barang                │ Harga        │ Stok  │ Total Value  │\n");
                printf("├──────┼────────────────────────────┼──────────────┼───────┼──────────────┤\n");
                
                if(jumlah_barang == 0) {
                    printf("│                                  TIDAK ADA DATA                                  │\n");
                } else {
                    float total_inventory = 0;
                    
                    for(i = 0; i < jumlah_barang; i++) {
                        float total_value = inventory[i].harga * inventory[i].stok;
                        total_inventory += total_value;
                        
                        printf("│ %-4d │ %-26s │ Rp %-9.0f │ %-5d │ Rp %-10.0f │\n",
                               inventory[i].kode,
                               inventory[i].nama,
                               inventory[i].harga,
                               inventory[i].stok,
                               total_value);
                    }
                    
                    printf("├──────┴────────────────────────────┴──────────────┴───────┴──────────────┤\n");
                    printf("│ Total Nilai Inventory: Rp %-36.0f │\n", total_inventory);
                }
                printf("└────────────────────────────────────────────────────────────────────────────┘\n");
                pause();
                break;
                
            case 3: // Cari berdasarkan kode
                clearScreen();
                printf("=== CARI BARANG (KODE) ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                int cari_kode;
                printf("Masukkan kode barang: ");
                scanf("%d", &cari_kode);
                
                int ditemukan = 0;
                for(i = 0; i < jumlah_barang; i++) {
                    if(inventory[i].kode == cari_kode) {
                        printf("\nBarang ditemukan:\n");
                        printf("Kode   : %d\n", inventory[i].kode);
                        printf("Nama   : %s\n", inventory[i].nama);
                        printf("Harga  : Rp %.0f\n", inventory[i].harga);
                        printf("Stok   : %d\n", inventory[i].stok);
                        printf("Nilai  : Rp %.0f\n", inventory[i].harga * inventory[i].stok);
                        ditemukan = 1;
                        break;
                    }
                }
                
                if(!ditemukan) {
                    printf("Barang dengan kode %d tidak ditemukan!\n", cari_kode);
                }
                pause();
                break;
                
            case 4: // Cari berdasarkan nama
                clearScreen();
                printf("=== CARI BARANG (NAMA) ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                char cari_nama[50];
                printf("Masukkan nama barang: ");
                getchar();
                fgets(cari_nama, sizeof(cari_nama), stdin);
                cari_nama[strcspn(cari_nama, "\n")] = '\0';
                
                printf("\nHasil pencarian untuk '%s':\n", cari_nama);
                printf("┌──────┬────────────────────────────┬──────────────┬───────┐\n");
                printf("│ Kode │ Nama Barang                │ Harga        │ Stok  │\n");
                printf("├──────┼────────────────────────────┼──────────────┼───────┤\n");
                
                int hasil_ditemukan = 0;
                for(i = 0; i < jumlah_barang; i++) {
                    if(strstr(inventory[i].nama, cari_nama) != NULL) {
                        printf("│ %-4d │ %-26s │ Rp %-9.0f │ %-5d │\n",
                               inventory[i].kode,
                               inventory[i].nama,
                               inventory[i].harga,
                               inventory[i].stok);
                        hasil_ditemukan++;
                    }
                }
                
                if(hasil_ditemukan == 0) {
                    printf("│              TIDAK ADA BARANG YANG COCOK               │\n");
                }
                printf("└──────┴────────────────────────────┴──────────────┴───────┘\n");
                printf("Ditemukan: %d barang\n", hasil_ditemukan);
                pause();
                break;
                
            case 5: // Update Stok
                clearScreen();
                printf("=== UPDATE STOK BARANG ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                int update_kode, jumlah_update;
                printf("Masukkan kode barang: ");
                scanf("%d", &update_kode);
                
                int index_update = -1;
                for(i = 0; i < jumlah_barang; i++) {
                    if(inventory[i].kode == update_kode) {
                        index_update = i;
                        break;
                    }
                }
                
                if(index_update == -1) {
                    printf("Barang tidak ditemukan!\n");
                    pause();
                    break;
                }
                
                printf("\nBarang: %s\n", inventory[index_update].nama);
                printf("Stok saat ini: %d\n", inventory[index_update].stok);
                printf("\nMasukkan jumlah perubahan (+ untuk tambah, - untuk kurangi): ");
                scanf("%d", &jumlah_update);
                
                int stok_baru = inventory[index_update].stok + jumlah_update;
                
                if(stok_baru < 0) {
                    printf("Error: Stok tidak boleh negatif!\n");
                } else {
                    inventory[index_update].stok = stok_baru;
                    printf("Stok berhasil diupdate menjadi: %d\n", stok_baru);
                }
                pause();
                break;
                
            case 6: // Hapus Barang
                clearScreen();
                printf("=== HAPUS BARANG ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                int hapus_kode;
                printf("Masukkan kode barang yang akan dihapus: ");
                scanf("%d", &hapus_kode);
                
                int index_hapus = -1;
                for(i = 0; i < jumlah_barang; i++) {
                    if(inventory[i].kode == hapus_kode) {
                        index_hapus = i;
                        break;
                    }
                }
                
                if(index_hapus == -1) {
                    printf("Barang tidak ditemukan!\n");
                    pause();
                    break;
                }
                
                printf("\nBarang yang akan dihapus:\n");
                printf("Kode   : %d\n", inventory[index_hapus].kode);
                printf("Nama   : %s\n", inventory[index_hapus].nama);
                printf("Harga  : Rp %.0f\n", inventory[index_hapus].harga);
                printf("Stok   : %d\n", inventory[index_hapus].stok);
                
                printf("\nApakah yakin ingin menghapus? (1=Ya, 0=Tidak): ");
                int konfirmasi;
                scanf("%d", &konfirmasi);
                
                if(konfirmasi == 1) {
                    // Geser elemen ke kiri
                    for(i = index_hapus; i < jumlah_barang - 1; i++) {
                        inventory[i] = inventory[i + 1];
                    }
                    jumlah_barang--;
                    printf("Barang berhasil dihapus!\n");
                } else {
                    printf("Penghapusan dibatalkan.\n");
                }
                pause();
                break;
                
            case 7: // Hitung Total Nilai Inventory
                clearScreen();
                printf("=== TOTAL NILAI INVENTORY ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                float total_nilai = 0;
                for(i = 0; i < jumlah_barang; i++) {
                    total_nilai += inventory[i].harga * inventory[i].stok;
                }
                
                printf("Jumlah barang       : %d\n", jumlah_barang);
                printf("Total nilai inventory: Rp %.0f\n", total_nilai);
                printf("Rata-rata nilai per barang: Rp %.0f\n", 
                       total_nilai / jumlah_barang);
                pause();
                break;
                
            case 8: // Urutkan berdasarkan stok
                clearScreen();
                printf("=== URUTKAN BARANG (BERDASARKAN STOK) ===\n");
                
                if(jumlah_barang == 0) {
                    printf("Inventory kosong!\n");
                    pause();
                    break;
                }
                
                // Bubble sort berdasarkan stok (descending)
                for(i = 0; i < jumlah_barang - 1; i++) {
                    for(j = 0; j < jumlah_barang - i - 1; j++) {
                        if(inventory[j].stok < inventory[j + 1].stok) {
                            // Tukar posisi
                            struct Barang temp = inventory[j];
                            inventory[j] = inventory[j + 1];
                            inventory[j + 1] = temp;
                        }
                    }
                }
                
                printf("Barang berhasil diurutkan berdasarkan stok (terbanyak).\n");
                pause();
                break;
                
            case 9: // Simpan ke file
                clearScreen();
                printf("=== SIMPAN KE FILE ===\n");
                
                FILE *file = fopen("inventory.txt", "w");
                if(file == NULL) {
                    printf("Error: Gagal membuka file!\n");
                    pause();
                    break;
                }
                
                // Simpan jumlah barang terlebih dahulu
                fprintf(file, "%d\n", jumlah_barang);
                
                // Simpan setiap barang
                for(i = 0; i < jumlah_barang; i++) {
                    fprintf(file, "%d\n", inventory[i].kode);
                    fprintf(file, "%s\n", inventory[i].nama);
                    fprintf(file, "%.2f\n", inventory[i].harga);
                    fprintf(file, "%d\n", inventory[i].stok);
                }
                
                fclose(file);
                printf("Data berhasil disimpan ke inventory.txt\n");
                printf("Total %d barang tersimpan.\n", jumlah_barang);
                pause();
                break;
                
            case 10: // Load dari file
                clearScreen();
                printf("=== LOAD DARI FILE ===\n");
                
                FILE *file_load = fopen("inventory.txt", "r");
                if(file_load == NULL) {
                    printf("Error: File tidak ditemukan!\n");
                    pause();
                    break;
                }
                
                // Baca jumlah barang
                fscanf(file_load, "%d\n", &jumlah_barang);
                
                // Baca setiap barang
                for(i = 0; i < jumlah_barang; i++) {
                    fscanf(file_load, "%d\n", &inventory[i].kode);
                    
                    // Baca nama dengan fgets karena bisa ada spasi
                    fgets(inventory[i].nama, sizeof(inventory[i].nama), file_load);
                    inventory[i].nama[strcspn(inventory[i].nama, "\n")] = '\0';
                    
                    fscanf(file_load, "%f\n", &inventory[i].harga);
                    fscanf(file_load, "%d\n", &inventory[i].stok);
                }
                
                fclose(file_load);
                printf("Data berhasil dimuat dari inventory.txt\n");
                printf("Total %d barang dimuat.\n", jumlah_barang);
                pause();
                break;
                
            case 0:
                printf("Terima kasih telah menggunakan sistem inventory!\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
                pause();
        }
        
    } while(pilihan != 0);
    
    return 0;
}

// Penjelasan:
// - Program ini mengelola sistem inventory toko dengan berbagai fitur seperti tambah,
//   tampilkan, cari, update, hapus, hitung total nilai, urutkan, simpan, dan load data.
// - Data barang disimpan dalam array struktur untuk kemudahan pengelolaan.
// - Fungsi clearScreen dan pause digunakan untuk meningkatkan pengalaman pengguna.
// - Validasi input dilakukan pada beberapa bagian untuk memastikan data yang dimasukkan benar.
// - Data dapat disimpan ke file teks dan dimuat kembali untuk persistensi data.

/*Contoh Output:
╔══════════════════════════════════════╗
║      SISTEM INVENTORY TOKO           ║
╠══════════════════════════════════════╣
║ 1. Tambah Barang                     ║
║ 2. Tampilkan Semua Barang            ║
║ 3. Cari Barang (berdasarkan kode)    ║
║ 4. Cari Barang (berdasarkan nama)    ║
║ 5. Update Stok Barang                ║
║ 6. Hapus Barang                      ║
║ 7. Hitung Total Nilai Inventory      ║  
║ 8. Urutkan Barang (berdasarkan stok) ║
║ 9. Simpan ke File                    ║    
║ 10. Load dari File                   ║
║ 0. Keluar                            ║
╚══════════════════════════════════════╝

Pilihan: 
*/  
// Tips:
// 1. Gunakan struktur untuk data kompleks
// 2. Validasi input untuk mencegah error
// 3. Gunakan fungsi untuk modularitas kode
// 4. Simpan dan load data dari file untuk persistensi    
// 5. Clear screen dan pause untuk pengalaman pengguna yang lebih baik

