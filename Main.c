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

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    printf("Username: %s\nPassword: %s", username, password);
        
    } else if (!(banyakArgumen == 3))
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
    return 0;
}
