#include <stdio.h>

void inputKategori(int pilihan, int kategori[]);
void templateInputKategori(char* str, int kategori[], int *pilihan);

void menuSebelumInputRumahTangga(int *pilihan, int kategori[]);
void menuSetelahInputRumahTangga(int *pilihan, int kategori[]);

void perhitungan(int kategori[]);
void kesimpulan(float total_co2);


int main () {
    /* Penjelasan array kategori:
     * Array kategori memiliki besar sebanyak 5 elemen berguna untuk 
     * menyimpan input setiap kategori emisi rumah tangga; 
     *      - Index ke-0 untuk input kategori listrik,
     *      - Index ke-1 untuk input kategori minyak tanah,
     *      - Index ke-2 untuk input kategori kantong sampah,
     *      - Index ke-3 untuk input kategori kayu bakar,
     *      - Index ke-4 untuk input kategori LPG
    **/
    int pilihan, kategori[5] = {0};
    menuSebelumInputRumahTangga(&pilihan, kategori);
}

void menuSebelumInputRumahTangga(int *pilihan, int kategori[]) {
    printf("\nRumah Tangga\n");
    printf(
        "Pilih input yang ingin dimasukkan terlebih dahulu\n"
        "1. Listrik (Satuan harga)\n"
        "2. Minyak tanah (Satuan harga)\n"
        "3. Sampah (Satuan kantong)\n"
        "4. Kayu Bakar (Dalam satuan Kg)\n"
        "5. Gas LPG (Satuan Kg)\n"
    );

    scanf("%d", pilihan);
    inputKategori(*pilihan, kategori);
}

void templateInputKategori(char* str, int kategori[], int *pilihan) {
    int index = *pilihan - 1;

    printf("%s\nTekan 0 untuk kembali\n", str);
    
    scanf("%d", &kategori[index]);

    if (kategori[index] == 0) 
        menuSebelumInputRumahTangga(pilihan, kategori);
    else 
        menuSetelahInputRumahTangga(pilihan, kategori);
}

void inputKategori(int pilihan, int kategori[]) {
    switch(pilihan) {  
        case 1:
            templateInputKategori("Masukkan Harga Listrik Anda dalam satu minggu\n", kategori, &pilihan);
            break;
        case 2:
            templateInputKategori("Masukkan Harga Minyak Tanah Anda dalam satu minggu\n", kategori, &pilihan);
            break;
        case 3:
            templateInputKategori("Masukkan Berapa kantong sampah Anda dalam satu minggu\n", kategori, &pilihan);
            break;
        case 4:
            templateInputKategori("Masukkan berapa Kg Anda menggunakan Kayu Bakar dalam satu minggu\n", kategori, &pilihan);
            break;
        case 5:
            templateInputKategori("Masukkan berapa Kg Anda menggunakan LPG dalam satu minggu\n", kategori, &pilihan);
            break;
        case 6:
            perhitungan(kategori);
            break;
    }
}

void menuSetelahInputRumahTangga(int *pilihan, int kategori[]) {
    printf("\nRumah Tangga\n");
    
    // ini disini ada function yg gunanya perhitungan dari inputan yg kita masukan cuy.
    // PR ini dia ngesave salah satu aja gmn, masak dibuat 5 function per pilihan pak?
    printf("1. Listrik (Satuan harga) : Rp%d\n", kategori[0]);
    printf("2. Minyak tanah (liter) : %d liter\n", kategori[1]);
    printf("3. Sampah (Satuan kantong) : %d kantong\n", kategori[2]);
    printf("4. Kayu Bakar (Dalam satuan Kg) : %d Kg\n", kategori[3]);
    printf("5. LPG (Dalam satuan kg) : %d Kg\n", kategori[4]);
    printf("\n=== TEKAN 6 UNTUK MELAKUKAN PERHITUNGAN EMISI! ===\n");

    scanf("%d", pilihan);
    inputKategori(*pilihan, kategori);
}

void perhitungan(int kategori[]) {
    /* Penjelasan array co2:
     * Array co2 memiliki besar sebanyak 5 elemen berguna untuk 
     * menyimpan hasil pertitungan setiap kategori emisi rumah tangga; 
     *      - Index ke-0 untuk hasil co2 listrik,
     *      - Index ke-1 untuk hasil co2 minyak tanah,
     *      - Index ke-2 untuk hasil co2 kantong sampah,
     *      - Index ke-3 untuk hasil co2 kayu bakar,
     *      - Index ke-4 untuk hasil co2 LPG
    **/
    float kwh, co2[5] = {0};
    float total_co2;
    
    // 1. Perhitungan listriknya
    // 605 ki harga per kwh
    kwh = kategori[0] / 605;
    co2[0] = kategori[0] * kwh * 0.794;

    printf("\nMaka Kwh yang dihasilkan : %.3f\n", kwh);
    printf("Maka banyaknya CO2 yang dihasilkan : %.3f Kg CO2\n\n", co2[0]);

    //2. Perhitungan emisi gas co2 terhadap konsumsi minyak tanah
    co2[1] = kategori[1] * 71.9 * 43.8;

    printf ("Maka Emisi karbon yang dihasilkan minyak tanah adalah : %.3f Kg CO2\n\n", co2[1]);

    /* 3. Perhitungan satu kantong sampah
     *      1x kantong sampah  = 0,32 kg
     *      1 kg sampah kering = 0,09 kg CH4
     *      1 kg sampah basah  = 0,44 kg CH4
     * Maka bisa diambil rata-rta untuk 1x kantong sampah = 0.21 kg CH4
    **/
    co2[2] = kategori[2] * 0.32 * 0.21;    

    printf ("Maka Emisi karbon yang dihasilkan sampah adalah : %.3f Kg CO2\n\n", co2[2]); 
    
    // 4. Perhitungan per satu kg kayu bakar
    co2[3] = kategori[3] * 112 * 15;

    printf ("Maka Emisi karbon yang dihasilkan kayu bakar adalah : %.3f Kg CO2\n\n", co2[3]);

    // 5. Perhitungan gas LPG
    co2[4] = kategori[4] * 63.1 * 47.3;

    printf ("Maka Emisi karbon yang dihasilkan LPG adalah : %.3f Kg CO2\n\n", co2[4]);

    // Rata-rata total perhitungan co2
    total_co2 = (co2[0] + co2[1] + co2[2] + co2[3] + co2[4]) / 5;

    kesimpulan(total_co2);
}

void kesimpulan(float total_co2) {
    const float batas = 73000.0;

    printf("Maka emisi rata rata yang anda hasilkan selama seminggu adalah : %.2f\n", total_co2);

    if (total_co2 > batas)
        printf("Maka emisi CO2 anda termasuk TINGGI\n ");
    else if (total_co2 < batas)
        printf("Maka emisi CO2 anda termasuk RENDAH\n");
    else
        printf("Maka emisi CO2 anda termasuk NORMAL\n");
}
