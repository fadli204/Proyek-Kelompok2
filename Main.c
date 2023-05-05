#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int banyakArgumen, char *argumen[])
{
    if (!(banyakArgumen > 1))
    {
        char namepass[50];
        FILE *fptr;
        printf("\nSilahkan masukkan username dan password");
        printf("\nFormatnya username(spasi)password");
        printf("\nMasukkan username dan password Anda: ");
        scanf("%[^\n]s", namepass);
        getchar();
        fptr = fopen("Login.bin", "wb");
        if (namepass != '\0')
        {
            fwrite(namepass, sizeof(char), sizeof(namepass) / sizeof(char), fptr);
        }

        fclose(fptr);

        char *string[3];
        char username[30], password[20];
        int ctrl = 0;

        string[0] = strtok(namepass, " ");
        while (string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, " ");
        }
        printf("Cara penggunaan: ./FileAplikasiProgramUtama username password");     
    }
    else if (!(banyakArgumen == 3))
    {
        printf("Gagal login!");
        printf("\nCara Penggunaan: ./FileAplikasiProgramUtama username password");
    }
    char usernameInput[30], passwordInput[20];
    strcpy(usernameInput, argumen[1]);
    strcpy(passwordInput, argumen[2]);

    FILE *fptr;

    if ((fptr = fopen("Login.bin", "rb")) == NULL)
    {
        printf("Gagal membuka file!");
        return EXIT_FAILURE;
    }

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

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    if ((strcmp(usernameInput, username) == 0) && (strcmp(passwordInput, password) == 0))
    {
        printf("Selamat, Anda berhasil login!");
    }
    else
    {
        printf("Anda gagal login!");
    }
    char serangga[20];
    char duri[20];
    char air[20];
    char mamalia[20];
    char buah[20];
    char hewan[20];
    char tumbuhan[20];
    int benar = 0;

    // Pertanyaan 1
    printf("Apa yang menghasilkan madu? ");
    scanf("%s",serangga);
    if (strcmp(serangga, "lebah") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 1
    printf("Apa yang menghasilkan madu?\n");
    printf("A. Lebah\n");
    printf("B. Semut\n");
    printf("C. Capung\n");
    printf("D. Lalat\n");
    scanf("%d", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 2
    printf("Hewan yang memiliki duri seperti jarum di tubuhnya? ");
    scanf("%s", duri);
    if (strcmp(duri, "kalajengking") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 3
    printf("Hewan besar yang sering berada di dalam air? ");
    scanf("%s", air);
    if (strcmp(air, "gajah") == 0 || strcmp(air, "badak") == 0 || strcmp(air, "kuda nil") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 4
    printf("Mamalia terbesar di dunia? ");
    scanf("%s", mamalia);
    if (strcmp(mamalia, "paus biru") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
        printf("Jawaban Anda salah.\n");
    }
    
    // Pertanyaan 5
    printf("Apa warna buah apel? ");
    scanf("%s", buah);
    if (strcmp(buah, "merah") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
        printf("Jawaban Anda salah.\n");
    }
    
    //Pertanyaan 6
    printf("Hewan tercepat di darat? ");
    scanf("%s", hewan);
    if (strcmp(hewan, "kelinci") == 0 || strcmp(hewan, "kuda") == 0 || strcmp(hewan, "sepatu roda") == 0) {
        printf("Jawaban Anda salah. Hewan yang dicari lebih cepat dari itu!\n");
    } 
    else if (strcmp(hewan, "cheetah") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } 
    else {
    printf("Jawaban Anda salah.\n");
    }
    
    // Pertanyaan 7
    printf("Apa nama tumbuhan yang dapat hidup dimana saja? ");
    scanf("%s", tumbuhan);
    if (strcmp(tumbuhan, "kelapa") == 0) {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }


    // Hasil
    printf("Anda berhasil menjawab %d dari 4 pertanyaan.\n", benar);
    
    return 0;
}
