#include <stdio.h>
#include <string.h>

#define JUMLAH_MAHASISWA 10
#define PANJANG_NIM 10
#define PANJANG_NAMA 50

// a. Deklarasi Array
struct Mahasiswa {
    char nim[PANJANG_NIM + 1];
    char nama[PANJANG_NAMA + 1];
    float nilai;
};

// Prototipe fungsi
int cariMahasiswa(struct Mahasiswa mhs[], int n, char nim_cari[]);
void urutkanMahasiswa(struct Mahasiswa mhs[], int n);
void tampilkanMahasiswa(struct Mahasiswa mhs[], int n);

int main() {
    struct Mahasiswa kelas[JUMLAH_MAHASISWA];
    int i;
    char nim_cari[PANJANG_NIM + 1];
    int index;
    
    // Input data mahasiswa
    printf("=== INPUT DATA MAHASISWA ===\n");
    for(i = 0; i < JUMLAH_MAHASISWA; i++) {
        printf("\nMahasiswa ke-%d:\n", i+1);
        
        printf("NIM   : ");
        scanf("%s", kelas[i].nim);
        
        printf("Nama  : ");
        scanf(" %[^\n]s", kelas[i].nama);  // Membaca string dengan spasi
        
        printf("Nilai : ");
        scanf("%f", &kelas[i].nilai);
        
        // Validasi nilai
        while(kelas[i].nilai < 0 || kelas[i].nilai > 100) {
            printf("Nilai harus 0-100! Ulangi: ");
            scanf("%f", &kelas[i].nilai);
        }
    }
    
    // b. Fungsi Pencarian
    printf("\n=== PENCARIAN MAHASISWA ===\n");
    printf("Masukkan NIM yang dicari: ");
    scanf("%s", nim_cari);
    
    index = cariMahasiswa(kelas, JUMLAH_MAHASISWA, nim_cari);
    
    if(index != -1) {
        printf("\nMahasiswa ditemukan:\n");
        printf("NIM   : %s\n", kelas[index].nim);
        printf("Nama  : %s\n", kelas[index].nama);
        printf("Nilai : %.2f\n", kelas[index].nilai);
    } else {
        printf("\nMahasiswa dengan NIM %s tidak ditemukan.\n", nim_cari);
    }
    
    // c. Fungsi Sorting
    printf("\n=== DATA SETELAH DIURUTKAN (DESCENDING) ===\n");
    urutkanMahasiswa(kelas, JUMLAH_MAHASISWA);
    tampilkanMahasiswa(kelas, JUMLAH_MAHASISWA);
    
    // Hitung statistik
    float total = 0, rata_rata;
    float nilai_tertinggi = kelas[0].nilai;
    float nilai_terendah = kelas[JUMLAH_MAHASISWA-1].nilai;
    
    for(i = 0; i < JUMLAH_MAHASISWA; i++) {
        total += kelas[i].nilai;
    }
    rata_rata = total / JUMLAH_MAHASISWA;
    
    printf("\n=== STATISTIK KELAS ===\n");
    printf("Nilai Tertinggi : %.2f\n", nilai_tertinggi);
    printf("Nilai Terendah  : %.2f\n", nilai_terendah);
    printf("Rata-rata Kelas : %.2f\n", rata_rata);
    
    return 0;
}

// b. Implementasi Fungsi Pencarian
int cariMahasiswa(struct Mahasiswa mhs[], int n, char nim_cari[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(mhs[i].nim, nim_cari) == 0) {
            return i;  // Mengembalikan index jika ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika tidak ditemukan
}

// c. Implementasi Fungsi Sorting (Bubble Sort)
void urutkanMahasiswa(struct Mahasiswa mhs[], int n) {
    int i, j;
    struct Mahasiswa temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(mhs[j].nilai < mhs[j+1].nilai) {
                // Tukar posisi
                temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}

// Fungsi untuk menampilkan data
void tampilkanMahasiswa(struct Mahasiswa mhs[], int n) {
    printf("\n==================================================================\n");
    printf("| No | %-10s | %-20s | %-6s |\n", "NIM", "Nama", "Nilai");
    printf("==================================================================\n");
    
    for(int i = 0; i < n; i++) {
        printf("| %2d | %-10s | %-20s | %6.2f |\n", 
               i+1, mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
    printf("==================================================================\n");
}