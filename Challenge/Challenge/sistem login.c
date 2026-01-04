#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 10

struct User {
    char username[20];
    char password[50];
    int isActive; // 1 = active, 0 = inactive
};

void encryptPassword(char password[]) {
    // Caesar cipher: shift +3
    for(int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] + 3;
    }
}

void decryptPassword(char password[]) {
    // Caesar cipher: shift -3
    for(int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] - 3;
    }
}

int findUser(struct User users[], int userCount, char username[]) {
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return i; // Return index
        }
    }
    return -1; // Not found
}

void displayUsers(struct User users[], int userCount, int showPassword) {
    if(userCount == 0) {
        printf("\nTidak ada user terdaftar.\n");
        return;
    }
    
    printf("\n=== DAFTAR USER ===\n");
    printf("┌─────┬────────────────────┬────────────────────┬─────────┐\n");
    printf("│ No. │ Username           │ Password           │ Status  │\n");
    printf("├─────┼────────────────────┼────────────────────┼─────────┤\n");
    
    for(int i = 0; i < userCount; i++) {
        char tempPassword[50];
        strcpy(tempPassword, users[i].password);
        
        if(showPassword) {
            decryptPassword(tempPassword);
        } else {
            strcpy(tempPassword, "********");
        }
        
        printf("│ %-3d │ %-18s │ %-18s │ %-7s │\n",
               i + 1,
               users[i].username,
               tempPassword,
               users[i].isActive ? "Aktif" : "Nonaktif");
    }
    
    printf("└─────┴────────────────────┴────────────────────┴─────────┘\n");
}

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice;
    
    // Data dummy untuk testing
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    encryptPassword(users[0].password);
    users[0].isActive = 1;
    userCount++;
    
    do {
        printf("\n=== SISTEM LOGIN ===\n");
        printf("1. Registrasi User Baru\n");
        printf("2. Login\n");
        printf("3. Tampilkan Semua User (password hidden)\n");
        printf("4. Tampilkan Semua User (password decrypted)\n");
        printf("5. Nonaktifkan User\n");
        printf("6. Aktifkan User\n");
        printf("7. Hapus User\n");
        printf("8. Ubah Password\n");
        printf("9. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch(choice) {
            case 1: { // Registrasi
                if(userCount >= MAX_USERS) {
                    printf("Error: Maksimal %d user sudah tercapai!\n", MAX_USERS);
                    break;
                }
                
                printf("\n=== REGISTRASI USER BARU ===\n");
                
                char username[20];
                printf("Username (max 19 char): ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                // Cek apakah username sudah ada
                if(findUser(users, userCount, username) != -1) {
                    printf("Error: Username sudah digunakan!\n");
                    break;
                }
                
                char password[50];
                printf("Password (max 49 char): ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';
                
                // Konfirmasi password
                char confirmPassword[50];
                printf("Konfirmasi password: ");
                fgets(confirmPassword, sizeof(confirmPassword), stdin);
                confirmPassword[strcspn(confirmPassword, "\n")] = '\0';
                
                if(strcmp(password, confirmPassword) != 0) {
                    printf("Error: Password tidak cocok!\n");
                    break;
                }
                
                // Simpan user baru
                strcpy(users[userCount].username, username);
                strcpy(users[userCount].password, password);
                encryptPassword(users[userCount].password);
                users[userCount].isActive = 1;
                userCount++;
                
                printf("Registrasi berhasil! User '%s' telah ditambahkan.\n", username);
                break;
            }
                
            case 2: { // Login
                printf("\n=== LOGIN ===\n");
                
                if(userCount == 0) {
                    printf("Error: Belum ada user terdaftar!\n");
                    break;
                }
                
                char username[20];
                printf("Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                int userIndex = findUser(users, userCount, username);
                if(userIndex == -1) {
                    printf("Error: User tidak ditemukan!\n");
                    break;
                }
                
                if(!users[userIndex].isActive) {
                    printf("Error: User tidak aktif!\n");
                    break;
                }
                
                char password[50];
                printf("Password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';
                
                // Encrypt input password untuk dibandingkan
                encryptPassword(password);
                
                if(strcmp(users[userIndex].password, password) == 0) {
                    printf("\n=================================\n");
                    printf("LOGIN BERHASIL!\n");
                    printf("Selamat datang, %s!\n", username);
                    printf("=================================\n");
                    
                    // Menu setelah login sukses
                    int loginChoice;
                    do {
                        printf("\n=== MENU USER ===\n");
                        printf("1. Lihat Profil\n");
                        printf("2. Ubah Password\n");
                        printf("3. Logout\n");
                        printf("Pilihan: ");
                        scanf("%d", &loginChoice);
                        getchar();
                        
                        switch(loginChoice) {
                            case 1:
                                printf("\n=== PROFIL ANDA ===\n");
                                printf("Username: %s\n", users[userIndex].username);
                                
                                char decryptedPass[50];
                                strcpy(decryptedPass, users[userIndex].password);
                                decryptPassword(decryptedPass);
                                printf("Password: %s\n", decryptedPass);
                                printf("Status  : %s\n", 
                                       users[userIndex].isActive ? "Aktif" : "Nonaktif");
                                break;
                                
                            case 2: {
                                char newPass[50];
                                printf("Password baru: ");
                                fgets(newPass, sizeof(newPass), stdin);
                                newPass[strcspn(newPass, "\n")] = '\0';
                                
                                char confirmNewPass[50];
                                printf("Konfirmasi password baru: ");
                                fgets(confirmNewPass, sizeof(confirmNewPass), stdin);
                                confirmNewPass[strcspn(confirmNewPass, "\n")] = '\0';
                                
                                if(strcmp(newPass, confirmNewPass) == 0) {
                                    strcpy(users[userIndex].password, newPass);
                                    encryptPassword(users[userIndex].password);
                                    printf("Password berhasil diubah!\n");
                                } else {
                                    printf("Error: Password tidak cocok!\n");
                                }
                                break;
                            }
                                
                            case 3:
                                printf("Logout berhasil.\n");
                                break;
                                
                            default:
                                printf("Pilihan tidak valid!\n");
                        }
                    } while(loginChoice != 3);
                    
                } else {
                    printf("Error: Password salah!\n");
                }
                break;
            }
                
            case 3: // Tampilkan semua user (password hidden)
                displayUsers(users, userCount, 0);
                break;
                
            case 4: // Tampilkan semua user (password decrypted)
                displayUsers(users, userCount, 1);
                break;
                
            case 5: { // Nonaktifkan user
                printf("\n=== NONAKTIFKAN USER ===\n");
                
                if(userCount == 0) {
                    printf("Error: Belum ada user terdaftar!\n");
                    break;
                }
                
                displayUsers(users, userCount, 0);
                
                char username[20];
                printf("\nUsername yang akan dinonaktifkan: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                int userIndex = findUser(users, userCount, username);
                if(userIndex == -1) {
                    printf("Error: User tidak ditemukan!\n");
                    break;
                }
                
                users[userIndex].isActive = 0;
                printf("User '%s' telah dinonaktifkan.\n", username);
                break;
            }
                
            case 6: { // Aktifkan user
                printf("\n=== AKTIFKAN USER ===\n");
                
                if(userCount == 0) {
                    printf("Error: Belum ada user terdaftar!\n");
                    break;
                }
                
                displayUsers(users, userCount, 0);
                
                char username[20];
                printf("\nUsername yang akan diaktifkan: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                int userIndex = findUser(users, userCount, username);
                if(userIndex == -1) {
                    printf("Error: User tidak ditemukan!\n");
                    break;
                }
                
                users[userIndex].isActive = 1;
                printf("User '%s' telah diaktifkan.\n", username);
                break;
            }
                
            case 7: { // Hapus user
                printf("\n=== HAPUS USER ===\n");
                
                if(userCount == 0) {
                    printf("Error: Belum ada user terdaftar!\n");
                    break;
                }
                
                displayUsers(users, userCount, 0);
                
                char username[20];
                printf("\nUsername yang akan dihapus: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                int userIndex = findUser(users, userCount, username);
                if(userIndex == -1) {
                    printf("Error: User tidak ditemukan!\n");
                    break;
                }
                
                printf("Apakah yakin ingin menghapus user '%s'? (y/n): ", username);
                char confirm;
                scanf("%c", &confirm);
                getchar();
                
                if(confirm == 'y' || confirm == 'Y') {
                    // Geser elemen array
                    for(int i = userIndex; i < userCount - 1; i++) {
                        users[i] = users[i + 1];
                    }
                    userCount--;
                    printf("User '%s' berhasil dihapus.\n", username);
                } else {
                    printf("Penghapusan dibatalkan.\n");
                }
                break;
            }
                
            case 8: { // Ubah password
                printf("\n=== UBAH PASSWORD ===\n");
                
                if(userCount == 0) {
                    printf("Error: Belum ada user terdaftar!\n");
                    break;
                }
                
                displayUsers(users, userCount, 0);
                
                char username[20];
                printf("\nUsername: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                int userIndex = findUser(users, userCount, username);
                if(userIndex == -1) {
                    printf("Error: User tidak ditemukan!\n");
                    break;
                }
                
                // Verifikasi password lama
                char oldPass[50];
                printf("Password lama: ");
                fgets(oldPass, sizeof(oldPass), stdin);
                oldPass[strcspn(oldPass, "\n")] = '\0';
                encryptPassword(oldPass);
                
                if(strcmp(users[userIndex].password, oldPass) != 0) {
                    printf("Error: Password lama salah!\n");
                    break;
                }
                
                char newPass[50];
                printf("Password baru: ");
                fgets(newPass, sizeof(newPass), stdin);
                newPass[strcspn(newPass, "\n")] = '\0';
                
                char confirmNewPass[50];
                printf("Konfirmasi password baru: ");
                fgets(confirmNewPass, sizeof(confirmNewPass), stdin);
                confirmNewPass[strcspn(confirmNewPass, "\n")] = '\0';
                
                if(strcmp(newPass, confirmNewPass) == 0) {
                    strcpy(users[userIndex].password, newPass);
                    encryptPassword(users[userIndex].password);
                    printf("Password berhasil diubah!\n");
                } else {
                    printf("Error: Password baru tidak cocok!\n");
                }
                break;
            }
                
            case 9:
                printf("Terima kasih telah menggunakan sistem login!\n");
                break;
                
            default:
                printf("Error: Pilihan tidak valid!\n");
        }
        
    } while(choice != 9);
    
    return 0;
}


/*Contoh Output:
=== SISTEM LOGIN ===
1. Registrasi User Baru
2. Login
3. Tampilkan Semua User (password hidden)
4. Tampilkan Semua User (password decrypted)
5. Nonaktifkan User
6. Aktifkan User
7. Hapus User
8. Ubah Password
9. Keluar

Pilihan: 1
=== REGISTRASI USER BARU ===
Username (max 19 char): user1
Password (max 49 char): pass123

Konfirmasi password: pass123
Registrasi berhasil! User 'user1' telah ditambahkan.
=== SISTEM LOGIN ===
1. Registrasi User Baru
2. Login
3. Tampilkan Semua User (password hidden)
4. Tampilkan Semua User (password decrypted)
5. Nonaktifkan User
6. Aktifkan User
7. Hapus User
8. Ubah Password
9. Keluar

Pilihan: 3
=== DAFTAR USER === 
┌─────┬────────────────────┬────────────────────┬─────────┐
│ No. │ Username           │ Password           │ Status  │
├─────┼────────────────────┼────────────────────┼─────────┤
│ 1   │ admin              │ ********           │ Aktif   │
│ 2   │ user1              │ ********           │ Aktif   │
└─────┴────────────────────┴────────────────────┴─────────┘
*/
#include <stdio.h>
int main() {
    int nilai;

    // Meminta input dari user
    printf("Masukkan nilai (0-100): ");
    scanf("%d", &nilai);

    // Validasi input
    while (nilai < 0 || nilai > 100) {
        printf("Nilai tidak valid! Masukkan nilai antara 0 dan 100: ");
        scanf("%d", &nilai);
    }

    // Menampilkan nilai yang valid
    printf("Nilai yang dimasukkan adalah: %d\n", nilai);

    return 0;
}


/*Contoh Output:
Masukkan nilai (0-100): 150
Nilai tidak valid! Masukkan nilai antara 0 dan 100: -20
Nilai tidak valid! Masukkan nilai antara 0 dan 100: 85
Nilai yang dimasukkan adalah: 85
*/

// Penjelasan tambahan:
// - Program ini meminta user untuk memasukkan nilai antara 0 dan 100.
// - Jika nilai yang dimasukkan tidak valid (kurang dari 0 atau lebih dari
//   100), program akan terus meminta input hingga nilai yang valid diberikan.
// - Validasi dilakukan menggunakan loop while yang memeriksa kondisi nilai.
// - Setelah nilai yang valid dimasukkan, program menampilkan nilai tersebut.
// - Validasi input penting untuk memastikan data yang diproses oleh program
//   sesuai dengan yang diharapkan dan menghindari error di kemudian hari.
// - Program ini dapat dikembangkan lebih lanjut dengan menambahkan fitur
//   seperti menyimpan nilai ke dalam array atau menghitung statistik nilai.

// Tips:
// 1. Gunakan loop untuk validasi input
// 2. Berikan pesan yang jelas kepada user saat input tidak valid
// 3. Pastikan kondisi validasi sesuai dengan kebutuhan program
// 4. Pertimbangkan untuk menambahkan batasan jumlah percobaan input jika diperlukan
