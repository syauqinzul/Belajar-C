#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 10
#define MAX_LENGTH 50

// Struct untuk menyimpan data user
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int isActive;
} User;

// Array untuk menyimpan user
User users[MAX_USER];
int userCount = 0;

// Fungsi untuk enkripsi password
void encryptPassword(char password[]) {
    int i;
    for(i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] + 3; // Geser ASCII +3
    }
}

// Fungsi untuk dekripsi password
void decryptPassword(char password[]) {
    int i;
    for(i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] - 3; // Geser ASCII -3
    }
}

// Fungsi untuk registrasi user baru
void registerUser() {
    if(userCount >= MAX_USER) {
        printf("Maaf, kapasitas user penuh!\n");
        return;
    }
    
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char confirmPassword[MAX_LENGTH];
    
    printf("\n=== REGISTRASI USER BARU ===\n");
    
    // Input username
    printf("Username (maks %d karakter): ", MAX_LENGTH-1);
    scanf("%s", username);
    
    // Cek username sudah ada
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("Username sudah digunakan!\n");
            return;
        }
    }
    
    // Input password
    printf("Password: ");
    scanf("%s", password);
    
    printf("Konfirmasi Password: ");
    scanf("%s", confirmPassword);
    
    // Validasi password
    if(strcmp(password, confirmPassword) != 0) {
        printf("Password tidak cocok!\n");
        return;
    }
    
    // Simpan user baru
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    encryptPassword(users[userCount].password); // Enkripsi sebelum simpan
    users[userCount].isActive = 1;
    userCount++;
    
    printf("Registrasi berhasil!\n");
}

// Fungsi untuk login
void loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char encryptedPassword[MAX_LENGTH];
    
    printf("\n=== LOGIN ===\n");
    
    if(userCount == 0) {
        printf("Belum ada user terdaftar!\n");
        return;
    }
    
    printf("Username: ");
    scanf("%s", username);
    
    printf("Password: ");
    scanf("%s", password);
    
    // Cari user
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].username, username) == 0 && users[i].isActive) {
            // Decrypt password yang disimpan untuk dibandingkan
            strcpy(encryptedPassword, users[i].password);
            decryptPassword(encryptedPassword);
            
            if(strcmp(password, encryptedPassword) == 0) {
                printf("\n=================================\n");
                printf("LOGIN BERHASIL!\n");
                printf("Selamat datang, %s!\n", username);
                printf("=================================\n");
                return;
            }
        }
    }
    
    printf("Username atau password salah!\n");
}

// Fungsi untuk menampilkan semua user (admin only)
void viewAllUsers() {
    char adminPassword[MAX_LENGTH] = "admin123";
    char inputPassword[MAX_LENGTH];
    
    printf("\n=== ADMIN ACCESS ===\n");
    printf("Masukkan password admin: ");
    scanf("%s", inputPassword);
    
    if(strcmp(inputPassword, adminPassword) != 0) {
        printf("Akses ditolak!\n");
        return;
    }
    
    printf("\n=== DAFTAR SEMUA USER ===\n");
    printf("+----+-----------------+-----------------+----------+\n");
    printf("| No | Username        | Password        | Status   |\n");
    printf("+----+-----------------+-----------------+----------+\n");
    
    for(int i = 0; i < userCount; i++) {
        char decryptedPassword[MAX_LENGTH];
        strcpy(decryptedPassword, users[i].password);
        decryptPassword(decryptedPassword);
        
        printf("| %2d | %-15s | %-15s | %-8s |\n",
               i+1,
               users[i].username,
               decryptedPassword,
               users[i].isActive ? "Aktif" : "Nonaktif");
    }
    printf("+----+-----------------+-----------------+----------+\n");
    printf("Total user: %d\n", userCount);
}

// Fungsi utama
int main() {
    int choice;
    
    printf("=== SISTEM LOGIN SEDERHANA ===\n");
    
    do {
        printf("\nMENU UTAMA:\n");
        printf("1. Registrasi User\n");
        printf("2. Login\n");
        printf("3. Lihat Semua User (Admin)\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                viewAllUsers();
                break;
            case 4:
                printf("Terima kasih telah menggunakan sistem!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(choice != 4);
    
    return 0;
}