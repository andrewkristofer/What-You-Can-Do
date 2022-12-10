#include <stdio.h>

void inputKategori(int pilihan, int kategori[]);
void templateInputKategori(char* str, int kategori[], int *pilihan);

void MenuAwalRumahTangga(int *pilihan, int kategori[]);
void RumahTangga2(int *pilihan, int kategori[]);

void ngitung(int kategori[]);
void summarize(float summarize_co2);


int main () {
    int pilihan, kategori[5] = {0};
    MenuAwalRumahTangga(&pilihan, kategori);
}

void MenuAwalRumahTangga(int *pilihan, int kategori[]) {
    printf("\nRumah Tangga\n");
    printf("Pilih input yang ingin dimasukkan terlebih dahulu\n"
    "1. Listrik (Satuan harga)\n"
    "2. Minyak tanah (Satuan harga)\n"
    "3. Sampah (Satuan kantong)\n"
    "4. Kayu Bakar (Dalam satuan Kg)\n"
    "5. Gas LPG (Satuan Kg)\n" );

    scanf("%d", pilihan);
    inputKategori(*pilihan, kategori);
}

void templateInputKategori(char* str, int kategori[], int *pilihan) {
    int index = *pilihan - 1;

    printf("%s\nTekan 0 untuk kembali\n", str);
    
    scanf("%d", &kategori[index]);

    if (kategori[index] == 0) 
        MenuAwalRumahTangga(pilihan, kategori);
    else 
        RumahTangga2(pilihan, kategori);
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
            ngitung(kategori);
            break;
    }
}

void RumahTangga2(int *pilihan, int kategori[]) {
    printf("\nRumah Tangga\n");
    
    // ini disini ada function yg gunanya ngitung dari inputan yg kita masukan cuy.
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

void ngitung(int kategori[]) {
    float kwh, co2[5] = {0};
    float summarize_co2;
    
    //1. Perhitungan listriknya
    //emisi co2 untuk penggunaan banyaknya listrik
    kwh = kategori[0] / 605; //605 ki harga per kwh
    
    co2[0] = kategori[0] * kwh * 0.794; 
    printf("\nMaka Kwh yang dihasilkan : %.3f\n", kwh);
    printf("Maka banyaknya CO2 yang dihasilkan : %.3f Kg CO2\n\n", co2[0]);

    //2. Perhitungan emisi gas co2 terhadap konsumsi minyak tanah
    //emisi co2 untuk minyak tanah
    co2[1] = kategori[1] * 71.9 * 43.8;
    printf ("Maka Emisi karbon yang dihasilkan minyak tanah adalah : %.3f Kg CO2\n\n", co2[1]);

    // 3. Perhitungan satu kantong sampah 
    //satu kantong sampah itungannya 0,32 kg
    co2[2] = kategori[2] * 0.32 * 0.21;         
    
    // per kilogram menghasilkan (ini sampah kering) 0,09 kg CH4
    printf ("Maka Emisi karbon yang dihasilkan sampah adalah : %.3f Kg CO2\n\n", co2[2]); 
    // perkilogram menghasilkan (ini sampah basah) 0,44 kg CH4
    // ambil kesimpiulan 0.21 kg CH4 aja lah yaw
    
    // 4. Perhitungan per satu kg kayu bakar
    co2[3] = kategori[3] * 112 * 15;
    printf ("Maka Emisi karbon yang dihasilkan kayu bakar adalah : %.3f Kg CO2\n\n", co2[3]);

    // 5. Perhitungan gas LPG
    co2[4] = kategori[4] * 63.1 * 47.3;
    printf ("Maka Emisi karbon yang dihasilkan LPG adalah : %.3f Kg CO2\n\n", co2[4]);

    summarize_co2 = (co2[0] + co2[1] + co2[2] + co2[3] + co2[4]) / 5;
    summarize (summarize_co2);
}

void summarize(float summarize_co2) {
    float summarize_f = 73000 * 1.0;

    printf("Maka emisi rata rata yang anda hasilkan selama seminggu adalah : %.2f\n", summarize_co2);

    if (summarize_co2 > summarize_f)
        printf("Maka emisi CO2 anda termasuk TINGGI\n ");
    else if (summarize_co2 < summarize_f)
        printf("Maka emisi CO2 anda termasuk RENDAH!\n");
    else
        printf("Maka emisi CO2 anda termasuk rata-rata\n");
}
