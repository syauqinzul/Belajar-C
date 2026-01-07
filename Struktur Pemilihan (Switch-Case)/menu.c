#include <stdio.h>
int main() {
    char pilihan1, pilihan2;
    int harga1 = 0, harga2 = 0, total;

    printf("Menu:\n");
    printf("A. Nasi Goreng - Rp 15.000\n");
    printf("B. Mie Ayam    - Rp 12.000\n");
    printf("C. Es Teh      - Rp  5.000\n");
    printf("D. Kopi        - Rp  7.000\n");

    printf("Masukkan pilihan pertama (A/B/C/D): ");
    scanf(" %c", &pilihan1);
    printf("Masukkan pilihan kedua (A/B/C/D): ");
    scanf(" %c", &pilihan2);

    // Menentukan harga pilihan pertama
    switch(pilihan1) {
        case 'A': case 'a': harga1 = 15000; break;
        case 'B': case 'b': harga1 = 12000; break;
        case 'C': case 'c': harga1 = 5000; break;
        case 'D': case 'd': harga1 = 7000; break;
        default: printf("Pilihan pertama tidak valid.\n"); return 1;
    }

    // Menentukan harga pilihan kedua
    switch(pilihan2) {
        case 'A': case 'a': harga2 = 15000; break;
        case 'B': case 'b': harga2 = 12000; break;
        case 'C': case 'c': harga2 = 5000; break;
        case 'D': case 'd': harga2 = 7000; break;
        default: printf("Pilihan kedua tidak valid.\n"); return 1;
    }

    total = harga1 + harga2;
    printf("Total biaya yang harus dibayar: Rp %d\n", total);
    return 0;
}