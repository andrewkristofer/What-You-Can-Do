#include <stdio.h>

void kasus(int pilihan, int nomoroperator[]);
void promptCase(char* str, int *nop, int *pilihan, int nomor[]);

void RumahTangga(int *pilihan, int nomoroperator[]);
void RumahTangga2(int *pilihan, int nomoroperator[]);

void ngitung(int nomoroperator[]);
void summarize(float summarize_co2);


int main () {
    int pilihan, nomoroperator[5] = {0};
    RumahTangga(&pilihan, nomoroperator);
}

void RumahTangga(int *pilihan, int nomoroperator[]) {
    printf("\nRumah Tangga\n");
    printf("Pilih input yang ingin dimasukkan terlebih dahulu\n"
    "1. Listrik (Satuan harga)\n"
    "2. Minyak tanah (Satuan harga)\n"
    "3. Sampah (Satuan kantong)\n"
    "4. Kayu Bakar (Dalam satuan Kg)\n"
    "5. Gas LPG (Satuan Kg)\n" );

    scanf("%d", pilihan);
    kasus(*pilihan, nomoroperator);
}

void promptCase(char* str, int *nop, int *pilihan, int nomor[]) {
    printf("%s\nTekan 0 untuk kembali\n", str);
        
        scanf("%d", nop);

        if (nop == 0) RumahTangga(pilihan, nomor);
        else RumahTangga2(pilihan, nomor);
}

void kasus(int pilihan, int nomoroperator[]) {
    switch(pilihan) {  
        case 1:
            promptCase("Masukkan Harga Listrik Anda dalam satu minggu\n", &nomoroperator[0], &pilihan, nomoroperator);
            break;
        case 2:
            promptCase("Masukkan Harga Minyak Tanah Anda dalam satu minggu\n", &nomoroperator[1], &pilihan, nomoroperator);
            break;
        case 3:
            promptCase("Masukkan Berapa kantong sampah Anda dalam satu minggu\n", &nomoroperator[2], &pilihan, nomoroperator);
            break;
        case 4:
            promptCase("Masukkan berapa Kg Anda menggunakan Kayu Bakar dalam satu minggu\n", &nomoroperator[3], &pilihan, nomoroperator);
            break;
        case 5:
            promptCase("Masukkan berapa Kg Anda menggunakan LPG dalam satu minggu\n", &nomoroperator[4], &pilihan, nomoroperator);
            break;
        case 6:
            ngitung(nomoroperator);
            break;
    }
}

void RumahTangga2(int *pilihan, int nomoroperator[]) {
    printf("\nRumah Tangga\n");
    
    // ini disini ada function yg gunanya ngitung dari inputan yg kita masukan cuy.
    //PR ini dia ngesave salah satu aja gmn, masak dibuat 5 function per pilihan pak?
    printf("1. Listrik (Satuan harga) : Rp%d\n", nomoroperator[0]);
    printf("2. Minyak tanah (liter) : %d liter\n", nomoroperator[1]);
    printf("3. Sampah (Satuan kantong) : %d kantong\n", nomoroperator[2]);
    printf("4. Kayu Bakar (Dalam satuan Kg) : %d Kg\n", nomoroperator[3]);
    printf("5. LPG (Dalam satuan kg) : %d Kg\n", nomoroperator[4]);
    printf("\n=== TEKAN 6 UNTUK MELAKUKAN PERHITUNGAN EMISI! ===\n");

    scanf("%d", pilihan);
    kasus(*pilihan, nomoroperator);
}

void ngitung(int nomoroperator[]) {
    //int harga, liter, kg_kayu, kg_LPG;
    const float 
    FE_listrik = 0.794, 
    FE_minyak = 71.9, 
    NCV_minyak = 43.8, 
    FE_kayubakar = 112, 
    NCV_kayubakar = 15, 
    FE_LPG = 63.1,
    NCV_LPG = 47.3;
    
    float kwh, co2_listrik, co2_minyak, co2_sampah, co2_kayubakar, co2_LPG;
    float summarize_co2;
    
    //1. Perhitungan listriknya
    //harga = nomoroperator[0]; //emisi co2 untuk penggunaan banyaknya listrik
    kwh = nomoroperator[0] / 605; //605 ki harga per kwh
    
    co2_listrik = nomoroperator[0] * kwh * FE_listrik; 
    printf("\nMaka Kwh yang dihasilkan : %.3f\n", kwh);
    printf("Maka banyaknya CO2 yang dihasilkan : %.3f Kg CO2\n\n", co2_listrik);

    //2. Perhitungan emisi gas co2 terhadap konsumsi minyak tanah
    //liter = nomoroperator[1]; //emisi co2 untuk minyak tanah
    co2_minyak = nomoroperator[1] * FE_minyak * NCV_minyak;
    
    printf ("Maka Emisi karbon yang dihasilkan minyak tanah adalah : %.3f Kg CO2\n\n", co2_minyak);

    // 3. Perhitungan satu kantong sampah 
    // kantong = nomoroperator[2]; //satu kantong sampah itungannya 0,32 kg
    co2_sampah = nomoroperator[2] * 0.32 * 0.21; // (kantong * 0.32) / (1000 * co2_sampah);             
    
    // per kilogram menghasilkan (ini sampah kering) 0,09 kg CH4
    printf ("Maka Emisi karbon yang dihasilkan sampah adalah : %.3f Kg CO2\n\n", co2_sampah); 
    // perkilogram menghasilkan (ini sampah basah) 0,44 kg CH4
    // ambil kesimpiulan 0.21 kg CH4 aja lah yaw
    
    // 4. Perhitungan per satu kg kayu bakar
    // kg_kayu = nomoroperator[3];
    co2_kayubakar = nomoroperator[3] * FE_kayubakar * NCV_kayubakar;
    printf ("Maka Emisi karbon yang dihasilkan kayu bakar adalah : %.3f Kg CO2\n\n", co2_kayubakar);

    // 5. Perhitungan gas LPG
    // kg_LPG = nomoroperator[4];
    
    co2_LPG = nomoroperator[4] * FE_LPG * NCV_LPG;
    printf ("Maka Emisi karbon yang dihasilkan LPG adalah : %.3f Kg CO2\n\n", co2_LPG);

    summarize_co2 = ( co2_listrik + co2_minyak + co2_sampah + co2_kayubakar + co2_LPG) / 5;
    summarize (summarize_co2);
}

void summarize(float summarize_co2) {
    printf("Maka emisi rata rata yang anda hasilkan selama seminggu adalah : %.2f\n", summarize_co2);

    if (summarize_co2 > 73000 * 1.0){
        printf("Maka emisi CO2 anda termasuk TINGGI\n ");
    }
    else if (summarize_co2 < 73000 * 1.0){
        printf("Maka emisi CO2 anda termasuk RENDAH!\n");
    }
    else {
        printf ("Maka emisi CO2 anda termasuk rata-rata\n");
    }
}
