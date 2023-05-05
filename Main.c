#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int banyakArgumen, char *argumen[])
{
    if (banyakArgumen == 1)
    {
        // Menampilkan petunjuk cara penggunaan program
        printf("\nCara Penggunaan: \n");
        printf("Untuk Registrasi: ./Program reg\n");
        printf("Untuk Login: ./Program username(spasi)password\n\n");
        return EXIT_SUCCESS;
    }
    else if (strcmp(argumen[1], "reg") == 0)
    {
        // Bagian Registrasi
        printf("\n+==========================================+");
        printf("\n|               Registrasi                 |");
        printf("\n+==========================================+");
        printf("\nSilahkan masukkan username dan password");
        printf("\nFormatnya username(spasi)password");
        printf("\nMasukkan username dan password Anda: ");
        
        // Membaca input username dan password
        char namepass[50];
        
        scanf("%[^\n]s", namepass);
        getchar();
        
        // Membuka file Login.bin untuk menulis username dan password
        FILE *fptr;
        fptr = fopen("Login.bin", "wb");
        
        // Menulis username dan password ke dalam file jika input tidak kosong
        if (namepass != '\0')
        {
            fwrite(namepass, sizeof(char), sizeof(namepass) / sizeof(char), fptr);
        }

        fclose(fptr);
                      
        // Memisahkan string input menjadi username dan password
        char *string[3];
        char username[30], password[20];
        int ctrl = 0;

        string[0] = strtok(namepass, " ");
        while (string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, " ");
        }
        
        strcpy(username, string[0]);
        strcpy(password, string[1]);
        
        // Menampilkan username dan password yang telah diinput
        printf("Username: %s\nPassword: %s\n\n", username, password);
        printf("Registrasi berhasil!\n\n");
        printf("Untuk Login: ./Program username(spasi)password\n\n");
        return EXIT_SUCCESS;
    }
    else if (banyakArgumen == 3)
    {
        // Bagian login
        char usernameInput[30], passwordInput[20];
        strcpy(usernameInput, argumen[1]);
        strcpy(passwordInput, argumen[2]);
    
        // Membuka file Login.bin untuk membaca username dan password
        FILE *fptr;

        if ((fptr = fopen("Login.bin", "rb")) == NULL)
        {
        printf("Gagal membuka file!");
        return EXIT_FAILURE;
        }
    
        // Memisahkan string dan password yang ada di dile
        char namepass[50];
        fread(namepass, sizeof(char), sizeof(namepass) / sizeof(char), fptr);

        char *string[3];
        char username[30], password[20];
        int ctrl = 0;

        string[0] = strtok(namepass, " ");
        while (string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, " ");
        }
    
        // Menyalin nilai string ke variabel username dan password
        strcpy(username, string[0]);
        strcpy(password, string[1]);
    
        // Mengecek apakah usernameInput dan passwordInput sama dengan dalam file
        if ((strcmp(usernameInput, username) == 0) && (strcmp(passwordInput, password) == 0))
        {
            printf("\nSelamat, Anda berhasil login!\n");
        }
        else
        {
            printf("Anda gagal login!");
            printf("\nAnda gagal login!\n");
            printf("Username atau password yang anda ketik salah atau tidak terdaftar\n");
            printf("Tolong perhatikan kembali password dan username anda \nAtau silahkan registrasi terlebih dahulu untuk membuat akun\n");
            return EXIT_FAILURE;
        }
        // Menutup file Login.bin    
        fclose(fptr);
    }
    else
    {
        printf("Argumen yang dimasukkan tidak valid. Silakan cek kembali cara penggunaan program.\n");
        return EXIT_FAILURE;
    }
        
    int benar = 0;
    char jawaban;
    
    printf("\n+==========================================+");
    printf("\n|     SELAMAT DATANG DI PERMAINAN KAMI     |");
    printf("\n+==========================================+");
    // Pertanyaan 1
    printf("\n\nPERTANYAAN PERTAMA");
    printf("\nHewan apa yang menghasilkan madu?\n");
    printf("A. Lebah\n");
    printf("B. Semut\n");
    printf("C. Capung\n");
    printf("D. Lalat\n");
    
    printf("Masukkan jawaban: " );
    scanf("%s", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 2
    printf("\vPERTANYAAN KEDUA\n");
    printf("Apakah hewan yang memiliki duri seperti jarum di tubuhnya?\n");
    printf("A. Kalajengking\n");
    printf("B. Kadal\n");
    printf("C. Iguana\n");
    printf("D. Buaya\n");
    
    printf("Masukkan jawaban: " );
    scanf("%s", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 3
    printf("\vPERTANYAAN KETIGA\n");
    printf("Hewan besar yang sering berada di dalam air?\n");
    printf("A. Gajah\n");
    printf("B. Badak\n");
    printf("C. Kuda Nil\n");
    printf("D. Jerapah\n");
    
    printf("Masukkan jawaban: ");        
    scanf("%s", &jawaban);

    if (jawaban == 'C' || jawaban == 'c') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
        exit(1);
    }

    // Pertanyaan 4
    printf("\vPERTANYAAN KEEMPAT\n");
    printf("Mamalia terbesar di dunia adalah?\n");
    printf("A. Jerapah\n");
    printf("B. Singa\n");
    printf("C. Harimau\n");
    printf("D. Paus Biru\n");
    
    printf("Masukkan jawaban: " );        
    scanf("%s", &jawaban);

    if (jawaban == 'D' || jawaban == 'd') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 5
    printf("\vPERTANYAAN KELIMA\n");
    printf("Apa warna buah apel?\n");
    printf("A. Kuning\n");
    printf("B. Hijau\n");
    printf("C. Merah\n");
    printf("D. Biru\n");
    
    printf("Masukkan jawaban: " );        
    scanf("%s", &jawaban);

    if (jawaban == 'C' || jawaban == 'c') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 6
    printf("\vPERTANYAAN KEENAM\n");
    printf("Hewan apakah yang tercepat di darat?\n");
    printf("A. Kelinci\n");
    printf("B. Kuda\n");
    printf("C. Cheetah\n");
    printf("D. Jerapah\n");
            
    printf("Masukkan jawaban: " );
    scanf("%s", &jawaban);

    if (jawaban == 'C' || jawaban == 'c') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 7
    printf("\vPERTANYAAN KETUJUH\n");
    printf("Siapakah presiden ketujuh Indonesia?\n");
    printf("A. Susilo Bambang Yudhoyono\n");
    printf("B. Joko Widodo\n");
    printf("C. Megawati Soekarnoputri\n");
    printf("D. B. J. Habibi\n");
    printf("Masukkan jawaban: ");
    scanf("%s", &jawaban);
    if (jawaban == 'B' || jawaban == 'b') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 8
    printf("\vPERTANYAAN KEDELAPAN\n");
    printf("Siapa ketua umum PDIP?\n");
    printf("A. Susilo Bambang Yudhoyono\n");
    printf("B. Joko Widodo\n");
    printf("C. Megawati Soekarnoputri\n");
    printf("D. Puan Maharani\n");
    printf("Masukkan jawaban: ");
    scanf("%s", &jawaban);
    if (jawaban == 'C' || jawaban == 'c') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 9
    printf("\vPERTANYAAN KESEMBILAN\n");
    printf("Samudera Pasai adalah kerajaan Islam pertama, di manakah lokasinya??\n");
    printf("A. Aceh\n");
    printf("B. Jawa Timur\n");
    printf("C. Sumatera Selatan\n");
    printf("D. Sumatera Utara\n");
    printf("Masukkan jawaban: ");
    scanf("%s", &jawaban);
    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 10
    printf("\vPERTANYAAN TERAKHIR\n");
    printf("Tumbuhan apa yang dapat hidup di mana saja?\n");
    printf("A. Kelapa\n");
    printf("B. Anggrek\n");
    printf("C. Mangga\n");
    printf("D. Rambutan\n");
    printf("Masukkan jawaban: ");
    scanf("%s", &jawaban);
    if (jawaban == 'A' || jawaban == 'a') {
        printf("\nJawaban Anda benar!\n\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Hasil
    printf("SELAMAT!");
    printf("\nAnda berhasil menjawab %d dari 10 pertanyaan.\n", benar);
    
    return 0;
}
