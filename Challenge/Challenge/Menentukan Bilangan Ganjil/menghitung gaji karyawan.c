#include <stdio.h>

int main() {
    // Bagian A: Deklarasi variabel (5 poin)
    ________________ gaji_pokok, tunjangan, gaji_lembur, total_gaji, pajak, gaji_bersih;
    ________________ jam_lembur;
    
    // Inisialisasi konstanta
    gaji_pokok = 3000000;
    
    // Input jam lembur
    printf("Masukkan jam lembur: ");
    scanf("%d", &jam_lembur);
    
    // Validasi jam lembur (5 poin)
    ________________________________________________________
    ________________________________________________________
    
    // Bagian B: Hitung tunjangan (5 poin)
    tunjangan = ___________________________________________;
    
    // Hitung gaji lembur (5 poin)
    if(jam_lembur > 40) {
        gaji_lembur = _______________;
    } else {
        gaji_lembur = _______________;
    }
    
    // Hitung total gaji
    total_gaji = gaji_pokok + tunjangan + gaji_lembur;
    
    // Bagian C: Hitung pajak (5 poin)
    if(_______________) {
        pajak = _______________;
    } else {
        pajak = _______________;
    }
    
    // Hitung gaji bersih
    gaji_bersih = total_gaji - pajak;
    
    // Output hasil
    printf("\n=== SLIP GAJI ===\n");
    printf("Gaji Pokok   : Rp %.0f\n", gaji_pokok);
    printf("Tunjangan    : Rp %.0f\n", tunjangan);
    printf("Lembur       : Rp %.0f\n", gaji_lembur);
    printf("Total Gaji   : Rp %.0f\n", total_gaji);
    printf("Pajak        : Rp %.0f\n", pajak);
    printf("Gaji Bersih  : Rp %.0f\n", gaji_bersih);
    
    return 0;
}