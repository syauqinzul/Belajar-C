// TIPE DATA DASAR DI C:

// 1. Tipe Data Integer (Bilangan Bulat)
int a = 10;             // 4 bytes (-2,147,483,648 to 2,147,483,647)
short b = 20;           // 2 bytes (-32,768 to 32,767)
long c = 1000000L;      // 4-8 bytes
long long d = 1000000000LL; // 8 bytes

// 2. Tipe Data Floating Point (Bilangan Desimal)
float e = 3.14f;        // 4 bytes (6-7 digit presisi)
double f = 3.14159265;  // 8 bytes (15-16 digit presisi)
long double g = 3.141592653589793L; // 10-16 bytes

// 3. Tipe Data Karakter
char h = 'A';           // 1 byte (-128 to 127)
unsigned char i = 200;  // 1 byte (0 to 255)

// 4. Tipe Data Boolean (di C99)
#include <stdbool.h>
bool j = true;          // 1 byte (true=1, false=0)

// 5. Tipe Data Tanpa Tanda (Unsigned)
unsigned int k = 4000000000U; // 0 to 4,294,967,295
unsigned short l = 60000;     // 0 to 65,535

// 6. Void (Tidak ada tipe)
void functionName();    // Digunakan untuk fungsi yang tidak return value