#include <stdio.h>

int main() {
    int umur;
    
    printf("Masukkan umur: ");
    scanf("%d", &umur);
    
    // Algoritma klasifikasi umur
    printf("Kategori: ");
    
    if(umur < 0) {
        printf("Tidak valid\n");
    } else if(umur <= 5) {
        printf("Balita\n");
    } else if(umur <= 12) {
        printf("Anak-anak\n");
    } else if(umur <= 17) {
        printf("Remaja\n");
    } else if(umur <= 25) {
        printf("Pemuda\n");
    } else if(umur <= 35) {
        printf("Dewasa\n");
    } else if(umur <= 55) {
        printf("Paruh baya\n");
    } else {
        printf("Lansia\n");
    }
    
    return 0;
}

/*Contoh Output:
Masukkan umur: 20
Kategori: Pemuda
*/

