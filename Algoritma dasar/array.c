#include <stdio.h>
#define MAX 100

int main() {
    int data[MAX];
    int n, i;
    int maks, min, total = 0;
    
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);
    
    // Validasi jumlah data
    if(n <= 0 || n > MAX) {
        printf("Jumlah data tidak valid!\n");
        return 1;
    }
    
    // Input data
    printf("Masukkan %d bilangan:\n", n);
    for(i = 0; i < n; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }
    
    // Inisialisasi maks dan min dengan data pertama
    maks = data[0];
    min = data[0];
    
    // Algoritma pencarian maksimum dan minimum
    for(i = 0; i < n; i++) {
        total += data[i];
        
        if(data[i] > maks) {
            maks = data[i];
        }
        
        if(data[i] < min) {
            min = data[i];
        }
    }
    
    // Output hasil
    printf("\n=== ANALISIS DATA ===\n");
    printf("Data: ");
    for(i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\nJumlah data    : %d\n", n);
    printf("Total          : %d\n", total);
    printf("Rata-rata      : %.2f\n", (float)total / n);
    printf("Nilai maksimum : %d\n", maks);
    printf("Nilai minimum  : %d\n", min);
    
    return 0;
}

/*Contoh Output:
Masukkan jumlah data: 5
Masukkan 5 bilangan:
Data ke-1: 10
Data ke-2: 50
Data ke-3: 30
Data ke-4: 20
Data ke-5: 40

=== ANALISIS DATA ===
Data: 10 50 30 20 40
Jumlah data    : 5
Total          : 150
Rata-rata      : 30.00
Nilai maksimum : 50
Nilai minimum  : 10
*/

