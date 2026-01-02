#include <stdio.h>
#define SIZE 5

int main() {
    int arr[SIZE];
    int i;
    
    // 1. Input data ke array
    printf("Masukkan %d bilangan:\n", SIZE);
    for(i = 0; i < SIZE; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // 2. Output data dari array
    printf("\nIsi array: ");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 3. Hitung total
    int total = 0;
    for(i = 0; i < SIZE; i++) {
        total += arr[i];
    }
    printf("Total: %d\n", total);
    
    // 4. Cari nilai maksimum
    int max = arr[0];
    for(i = 1; i < SIZE; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Nilai maksimum: %d\n", max);
    
    // 5. Cari nilai minimum
    int min = arr[0];
    for(i = 1; i < SIZE; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Nilai minimum: %d\n", min);
    
    // 6. Rata-rata
    float rata = (float)total / SIZE;
    printf("Rata-rata: %.2f\n", rata);
    
    return 0;
}