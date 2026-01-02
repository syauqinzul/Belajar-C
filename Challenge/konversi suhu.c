/*
SOAL 1: Konversi Suhu
Buat program untuk mengkonversi suhu dari Celcius ke Fahrenheit dan Kelvin.
Rumus: 
- Fahrenheit = (Celcius × 9/5) + 32
- Kelvin = Celcius + 273.15

HINT: Gunakan float untuk presisi desimal
*/
#include <stdio.h>

int main() {
    float celcius, fahrenheit, kelvin;
    
    // Meminta input dari user
    printf("Masukkan suhu dalam Celcius: ");
    scanf("%f", &celcius);
    
    // Menghitung konversi suhu
    fahrenheit = (celcius * 9/5) + 32;
    kelvin = celcius + 273.15;
    
    // Menampilkan hasil konversi
    printf("Suhu dalam Fahrenheit: %.2f\n", fahrenheit);
    printf("Suhu dalam Kelvin: %.2f\n", kelvin);
    
    return 0;
}

/*
Contoh Output:
Masukkan suhu dalam Celcius: 25
Suhu dalam Fahrenheit: 77.00
Suhu dalam Kelvin: 298.15
*/  

// Penjelasan tambahan:
// - Program ini menggunakan tipe data float untuk menangani angka desimal.
// - Fungsi printf dengan format %.
// 2f digunakan untuk menampilkan hasil dengan 2 angka di belakang koma.
// - Input suhu dalam Celcius diambil menggunakan scanf.
// - Rumus konversi suhu diimplementasikan sesuai dengan standar fisika.
// - Pastikan untuk memasukkan nilai numerik saat diminta input suhu.
// - Perhatikan pembagian 9/5 yang harus dilakukan dalam float untuk menghindari
//   pembulatan integer.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan validasi input
//   atau opsi konversi lainnya.

// Tips:
// 1. Gunakan float/double untuk presisi desimal
// 2. Perhatikan urutan operasi matematika
// 3. Spasi sebelum %c untuk menghindari newline


