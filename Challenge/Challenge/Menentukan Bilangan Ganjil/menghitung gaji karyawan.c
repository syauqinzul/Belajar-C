// Bagian A: Deklarasi variabel
float gaji_pokok, tunjangan, gaji_lembur, total_gaji, pajak, gaji_bersih;
int jam_lembur;

// Validasi jam lembur
if(jam_lembur < 0) {
    printf("Jam lembur tidak boleh negatif! Diatur ke 0.\n");
    jam_lembur = 0;
}

// Bagian B: Hitung tunjangan
tunjangan = gaji_pokok * 0.2;

// Hitung gaji lembur
if(jam_lembur > 40) {   
    gaji_lembur = 40 * 50000;
} else {
    gaji_lembur = jam_lembur * 50000;
}

// Bagian C: Hitung pajak
if(total_gaji > 5000000) {
    pajak = total_gaji * 0.05;
} else {
    pajak = 0;
}