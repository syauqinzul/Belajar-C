//modifier & qualifier.c
#include <stdio.h>
int main() {
    // Modifier dan Qualifier pada Tipe Data di C

    // 1. Modifier: signed, unsigned, short, long
    unsigned int a = 4000000000U; // unsigned int
    long b = 1000000L;            // long int
    short c = 30000;              // short int

    printf("Unsigned int a: %u\n", a);
    printf("Long int b: %ld\n", b);
    printf("Short int c: %d\n", c);

    // 2. Qualifier: const, volatile, restrict
    const int d = 10;             // const qualifier
    volatile int e = 20;          // volatile qualifier

    printf("Const int d: %d\n", d);
    printf("Volatile int e: %d\n", e);

    // Note: restrict qualifier is used with pointers in C99 and later
    return 0;
}

// 1. SIGNED vs UNSIGNED
signed int x = -10;     // Bisa negatif
unsigned int y = 10;    // Hanya positif (0 to 4,294,967,295)

// 2. SHORT vs LONG
short int s = 100;      // Lebih kecil, lebih hemat memory
long int l = 1000000;   // Lebih besar, range lebih luas

// 3. CONST (tidak bisa diubah)
const float PI = 3.14159;
// PI = 3.14; // ERROR: assignment of read-only variable

// 4. VOLATILE (tidak di-cache oleh compiler)
volatile int sensor_value; // Untuk hardware/memory mapping

// 5. STATIC (lifetime selama program berjalan)
static int counter = 0;