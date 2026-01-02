#include <stdio.h>

int main() {
    // 1. Deklarasi array tanpa inisialisasi
    int arr1[5]; // Array 5 elemen integer
    
    // 2. Deklarasi dengan inisialisasi
    int arr2[5] = {1, 2, 3, 4, 5};
    
    // 3. Deklarasi tanpa spesifikasi size
    int arr3[] = {10, 20, 30}; // Size otomatis = 3
    
    // 4. Inisialisasi sebagian
    int arr4[5] = {1, 2}; // arr4[0]=1, arr4[1]=2, lainnya=0
    
    // 5. Array multidimensi
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // 6. Array karakter (string)
    char nama[] = "Budi";
    char huruf[5] = {'A', 'B', 'C', 'D', 'E'};
    
    return 0;
}