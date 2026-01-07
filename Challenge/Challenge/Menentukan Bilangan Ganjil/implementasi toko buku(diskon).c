// Bagian A: Deklarasi variabel
int jumlah_buku;
float harga_per_buku, subtotal, diskon_jumlah, diskon_tambahan, total_diskon, total_bayar;

// Validasi input
if(jumlah_buku <= 0) {
    printf("Jumlah buku harus lebih dari 0!\n");
    return 1; // Keluar program dengan kode error
}

// Bagian B: Hitung diskon berdasarkan jumlah buku
if(jumlah_buku >= 1 && jumlah_buku <= 5) {
    diskon_jumlah = 0;
} else if(jumlah_buku >= 6 && jumlah_buku <= 10) {
    diskon_jumlah = subtotal * 0.05;
} else if(jumlah_buku >= 11 && jumlah_buku <= 20) {
    diskon_jumlah = subtotal * 0.10;
} else if(jumlah_buku >= 21 && jumlah_buku <= 50) {
    diskon_jumlah = subtotal * 0.15;
} else if(jumlah_buku > 50) {
    diskon_jumlah = subtotal * 0.20;
}

// Bagian C: Hitung diskon tambahan untuk pembelian besar
if(subtotal > 1000000) {
    diskon_tambahan = subtotal * 0.05;
} else {
    diskon_tambahan = 0;
}