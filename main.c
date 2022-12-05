#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void MenuUtama(int *pilihan);
void SubMenuSatu(int pilihan);

void ExitProgram();

void RumahTangga();
void Transportasi();
void MakananDanLayanan();

void timer(int secs);

int main() {
    const char *menuList[3] = {"Rumah Tangga", "Tranportasi", "Makanan dan Layanan"};
    int pilihan;

    MenuUtama(&pilihan);

    return 0;
}

/************************************************************************************************/

void MenuUtama(int *pilihan) {
    do {
        printf("\nSelamat Datang di aplikasi What You Can Do!\n");
        printf("\n1. Rumah Tangga\n2. Transportasi\n3. Makanan dan Layanan\n4. Keluar\nSilahkan pilih (angka) : ");
        scanf("%d", pilihan);

        if (*pilihan < 1 || *pilihan > 4) {
            printf("\nSilahkan masukkan angka yang sesuai dengan pilihan yang ada!\n");
            Sleep(1250);
            continue;   
        }

        SubMenuSatu(*pilihan);
    } while (*pilihan < 1 || *pilihan > 4);
}

void SubMenuSatu(int pilihan) {
    switch (pilihan) {
        case 1:
            RumahTangga();
            break;
        case 2:
            Transportasi();
            break;
        case 3:
            MakananDanLayanan();
            break;
    }
}

/************************************************************************************************/

void ExitProgram() {
    printf("\nDadah\n");
    exit(4);
}

/************************************************************************************************/

void RumahTangga() {
    printf("\nRumah Tangga\n");
    // exit(1);
}

void Transportasi() {
    printf("\nTransportasi\n");
    // exit(2);
}

void MakananDanLayanan() {
    printf("\nMakanan dan Layanan\n");
    // exit(3);
}

/************************************************************************************************/