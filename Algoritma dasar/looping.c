#include <stdio.h>

int main() {
    int n, i;
    int total = 0;
    
    printf("Masukkan jumlah bilangan: ");
    scanf("%d", &n);
    
    // Algoritma perulangan for
    for(i = 1; i <= n; i++) {
        int bilangan;
        printf("Masukkan bilangan ke-%d: ", i);
        scanf("%d", &bilangan);
        total += bilangan; // total = total + bilangan
    }
    
    printf("\nJumlah bilangan yang dimasukkan: %d\n", n);
    printf("Total penjumlahan: %d\n", total);
    printf("Rata-rata: %.2f\n", (float)total / n);
    
    return 0;
}

/*Contoh Output:
Masukkan jumlah bilangan: 3
Masukkan bilangan ke-1: 10
Masukkan bilangan ke-2: 20
Masukkan bilangan ke-3: 30
Jumlah bilangan yang dimasukkan: 3
Total penjumlahan: 60
Rata-rata: 20.00
*/

