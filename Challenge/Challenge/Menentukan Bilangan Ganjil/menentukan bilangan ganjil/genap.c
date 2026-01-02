//Menentukan Bilangan Ganjil/Genap
#include <stdio.h>
int main() {
    int number;

    // Meminta input dari user
    printf("Masukkan sebuah bilangan bulat: ");
    scanf("%d", &number);

    // Menentukan apakah bilangan ganjil atau genap
    if (number % 2 == 0) {
        printf("%d adalah bilangan genap.\n", number);
    } else {
        printf("%d adalah bilangan ganjil.\n", number);
    }

    return 0;
}

