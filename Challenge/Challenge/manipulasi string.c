#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk membalik string
void reverseString(char str[]) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
// Fungsi untuk mengecek palindrome
int isPalindrome(char str[]) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        if(tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0; // Bukan palindrome
        }
    }
    return 1; // Palindrome
}
// Fungsi untuk menghitung jumlah kata
int countWords(char str[]) {
    int count = 0;
    int inWord = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if(!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    
    return count;
}
// Fungsi untuk mengubah string ke uppercase
void toUpperString(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
// Fungsi untuk mengubah string ke lowercase
void toLowerString(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
// Fungsi untuk menghapus spasi ekstra
void removeExtraSpaces(char str[]) {
    char result[100];
    int i, j = 0;
    int spaceFlag = 0;
    
    // Hapus spasi di awal
    while(str[0] == ' ') {
        for(i = 0; str[i] != '\0'; i++) {
            str[i] = str[i + 1];
        }
    }
    
    // Proses string
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            result[j++] = str[i];
            spaceFlag = 0;
        } else if(spaceFlag == 0) {
            result[j++] = ' ';
            spaceFlag = 1;
        }
    }
    
    // Hapus spasi di akhir jika ada
    if(j > 0 && result[j-1] == ' ') {
        j--;
    }
    
    result[j] = '\0';
    
    // Copy kembali ke str
    strcpy(str, result);
}
// Program utama
int main() {
    char input[100];
    char original[100];
    
    printf("Masukkan string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    // Simpan original
    strcpy(original, input);
    
    printf("\n=== HASIL MANIPULASI STRING ===\n");
    printf("Original         : '%s'\n", original);
    
    // Reverse
    strcpy(input, original);
    reverseString(input);
    printf("Reversed         : '%s'\n", input);
    
    // Palindrome check
    printf("Palindrome?      : %s\n", 
           isPalindrome(original) ? "Ya" : "Bukan");
    
    // Word count
    printf("Jumlah kata      : %d\n", countWords(original));
    
    // Uppercase
    strcpy(input, original);
    toUpperString(input);
    printf("Uppercase        : '%s'\n", input);
    
    // Lowercase
    strcpy(input, original);
    toLowerString(input);
    printf("Lowercase        : '%s'\n", input);
    
    // Remove extra spaces
    strcpy(input, "   Hello    World   ");
    removeExtraSpaces(input);
    printf("No extra spaces  : '%s'\n", input);
    
    return 0;
}

/*Contoh Output:
Masukkan string: Madam
========= HASIL MANIPULASI STRING =========
Original         : 'Madam'
Reversed         : 'madaM'
Palindrome?      : Ya
Jumlah kata      : 1
Uppercase        : 'MADAM'
Lowercase        : 'madam'
No extra spaces  : 'Hello World'
*/

// Penjelasan tambahan:
// - Program ini menyediakan berbagai fungsi untuk manipulasi string seperti
//   membalik string, mengecek palindrome, menghitung jumlah kata, mengubah
//   ke uppercase/lowercase, dan menghapus spasi ekstra.
// - Setiap fungsi diimplementasikan secara terpisah untuk modularitas.
// - Fungsi utama menguji semua fungsi tersebut dengan input
//   yang diberikan oleh pengguna.
// - Fungsi fgets digunakan untuk membaca string dengan aman.
// - Fungsi strcspn digunakan untuk menghapus newline yang ditambahkan oleh fgets.
// - Manipulasi karakter dilakukan menggunakan fungsi dari ctype.h seperti
//   toupper dan tolower untuk memastikan konsistensi karakter.
// - Validasi dan penanganan string dilakukan dengan hati-hati untuk
//   menghindari kesalahan seperti buffer overflow.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan
//   fitur-fitur manipulasi string lainnya sesuai kebutuhan pengguna.

// Tips:
// 1. Gunakan fungsi terpisah untuk setiap manipulasi string
// 2. Gunakan library ctype.h untuk manipulasi karakter
// 3. Hati-hati dengan batasan ukuran array saat mengolah string
// 4. Selalu hapus newline dari input string jika menggunakan fgets
// 5. Uji setiap fungsi secara terpisah sebelum menggabungkannya dalam program utama

