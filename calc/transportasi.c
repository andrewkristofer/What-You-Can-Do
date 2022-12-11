#include <stdio.h>

void inputKategori(int pilihan, int kategori[]);
void templateInputKategori(char* str, int kategori[], int *pilihan);

void menuSebelumInputTransportasi(int *pilihan, int kategori[]);
void menuSetelahInputTransportasi(int *pilihan, int kategori[]);

void perhitungan(int kategori[]);
void kesimpulan(float total_co2);

int main () {
    /* Penjelasan array kategori:
     * Array kategori memiliki besar sebanyak 6 elemen berguna untuk 
     * menyimpan input setiap kategori emisi rumah tangga; 
     *      - Index ke-0 untuk input kategori listrik,
     *      - Index ke-1 untuk input kategori minyak tanah,
     *      - Index ke-2 untuk input kategori kantong sampah,
     *      - Index ke-3 untuk input kategori kayu bakar,
     *      - Index ke-4 untuk input kategori LPG
     */
    int pilihan, kategori[6] = {0};
    
    menuSebelumInputTransportasi(&pilihan, kategori);
}

void menuSebelumInputTransportasi(int *pilihan, int kategori[]) {
    printf(
	"=======================================================\n"
	"\t\tEmisi Karbon Transportasi\n"
	"=======================================================\n\n"
	);

    printf(
        "1. Bensin motor \t(Rp)\n"
        "2. Bensin motor \t(Rp)\n"
        "3. Kereta \t\t(Rp)\n"
        "4. Transjakarta \t(Rp)\n"
        "5. Ojek Offline/Online (Rp)\n"
        "6. Kendaraan berlistrik (KW)\n"
        "\n\nPilih nomor data yang ingin dimasukkan (1 - 6): "
    );

    scanf("%d", pilihan);
    inputKategori(*pilihan, kategori);
}

void templateInputKategori(char* str, int kategori[], int *pilihan) {
    int index = *pilihan - 1;

	printf("\n*0 untuk kembali.\n");
    printf("%s Anda dalam satu minggu: ", str);
    scanf("%d", &kategori[index]);

    if (kategori[index] == 0) {
    	system("cls");
	    menuSebelumInputTransportasi(pilihan, kategori);
	}
    else
        menuSetelahInputTransportasi(pilihan, kategori);
}

void inputKategori(int pilihan, int kategori[]) {
    switch(pilihan) {
        case 1:
            templateInputKategori("Harga bensin motor (Rp)", kategori, &pilihan);
            break;
        case 2:
            templateInputKategori("Harga bensin mobil (Rp)", kategori, &pilihan);
            break;
        case 3:
            templateInputKategori("Tarif kereta (Rp)", kategori, &pilihan);
            break;
        case 4:
            templateInputKategori("Tarif Transjakarta (Rp)", kategori, &pilihan);
            break;
        case 5:
            templateInputKategori("Tarif ojek (Rp)", kategori, &pilihan);
            break;
        case 6:
            templateInputKategori("Isi ulang kendaraan berlistrik", kategori, &pilihan);
            break;
        case 7:
            perhitungan(kategori);
            break;
    }
}

void menuSetelahInputTransportasi(int *pilihan, int kategori[]) {
	system("cls");
    printf(
		"=======================================================\n"
		"\t\tEmisi Karbon Transportasi\n"
		"=======================================================\n\n"
	);
    
    printf("1. Bensin motor\t: Rp%d\n", kategori[0]);
    printf("2. Bensin mobil\t: %d Rp\n", kategori[1]);
    printf("3. Tarif kereta\t: %d Rp\n", kategori[2]);
    printf("4. Tarif Transjakarta\t: %d Rp\n", kategori[2]);
    printf("5. Tarif ojek\t: %d Rp\n", kategori[2]);
    printf("6. Kendaraan listrik\t: %d KW\n", kategori[3]);
    printf("\n7. Melakukan perhitungan\n");
    
    printf("\nPilih nomor data yang ingin dimasukkan atau diganti (1 - 7): ");

    scanf("%d", pilihan);
    inputKategori(*pilihan, kategori);
}

void perhitungan(int kategori[]) {
    /* Penjelasan array co2:
     * Array co2 memiliki besar sebanyak 6 elemen berguna untuk 
     * menyimpan hasil pertitungan setiap kategori emisi oleh transportasi; 
     *      - Index ke-0 untuk hasil co2 bensin motor,
     *      - Index ke-1 untuk hasil co2 bensin mobil,
     *      - Index ke-2 untuk hasil co2 tarif kendaraan publik,
     *      - Index ke-3 untuk hasil co2 KW isi ulang kendaraan listrik,
     */
    float co2[6] = {0};
    float total_co2, rataRataPribadi = 2.37;

    /* == Perhitungan kalkulasi co2 oleh bensin ==
     *     Berdasarkan sumber dari https://climatekids.nasa.gov/review/carbon/gasoline.html, didapat bahwa
     * 1 gallons menghasilkan 20 pounds CO2. Setelah dilakukan konversi ke liter dan kilogram, didapat bahwa
     * 1 liter bensin menghasilkan 2.37 kg CO2. Jangkauan harga bensin di Indonesia beragam mulai dari Rp10.000
     * sampai Rp16.000, bila diambil rata-rata maka didapat harga bensin per liter = Rp13.000.
     *     Maka perhitungan dilakukan dengan cara membagi harga yang di-input user dengan 13000 dan 
     * mengalikan hasilnya dengan 2.37 agar didapat jumlah kg emisi karbonnya.  
    */
    
    // 1. Perhitungan bensin motor
    co2[0] = kategori[0] / 13000 * rataRataPribadi;

    printf("Emisi karbon oleh Motor\t: %.2f kg CO2\n\n", co2[0]);

    //2. Perhitungan bensin mobil
    co2[1] = kategori[1] / 13000 * rataRataPribadi;

    printf ("Emisi karbon oleh Mobil\t: %.2f kg CO2\n", co2[1]);

    /* == Perhitungan kereta ==
     *     Berdasarkan sumber dari https://www.sncf-connect.com/en-ch/help/calculation-co2-emissions-your-train-journey,
     * didapat bahwa untuk kereta bisa diambil rata-rata untuk satu kilometer perjalanan, akan
     * dihasilkan 17.5 g CO2 = 0.0175 kg CO2.
     *     Tarif kereta bisa diambil untuk jarak < 24 km = Rp3.000, 24 km < jarak < 32 km = Rp4.000.
     * 32 km < jarak < 44 km = Rp5.000, dan Jarak > 44 km =  Rp13.000. Maka dari itu bisa diambil rata-rata
     * bahwa untuk 1 km perjalanan dikenai tarif = Rp5.000.
     *     Maka, kalkulasi emisi karbon bisa dilakukan dengan membagi tarif yang di-input user dengan 5000,
     * kemudian hasilnya dikalikan dengan 0.0175 agar didapat jumlah kg CO2.
     */
    co2[2] = kategori[2] / 5000 * 0.0175;    

    printf ("Emisi karbon oleh Kereta\t: %.2f kg CO2\n", co2[2]); 
    
    /* == Perhitungan Transjakarta ==
     *     Berdasarkan sumber dari https://www.sncf-connect.com/en-ch/help/calculation-co2-emissions-your-train-journey,
     * didapat bahwa untuk Transjakarta bisa diambil rata-rata untuk satu kilometer perjalanan, akan
     * dihasilkan 89.4 g CO2 = 0.0894 kg CO2.
     *     Tarif Transjakarta bisa diambil rata-rata Rp4.000 per kilometer. Maka, kalkulasi emisi karbon 
     * bisa dilakukan dengan membagi tarif yang di-input user dengan 4000, kemudian hasilnya dikalikan 
     * dengan 0.0894 agar didapat jumlah kg CO2.
     */
    co2[3] = kategori[3] / 5000 * 0.0894;

    printf ("Emisi karbon oleh Transjakarta : %.2f Kg CO2\n", co2[3]);

    /* == Perhitungan Ojek ==
     *     Tarif Ojek Online dicek menggunakan aplikasi Go-Jek untuk 6 km terdapat tarif Rp26.000 
     * maka didapat tarif Rp4.333 per kilometer. Kalkulasi bisa dilakukan dengan membagi input user 
     * dengan 4333 dan mengalikan hasilnya dengan 2.37 agar didapat jumlah kg CO2.
     */
    co2[4] = kategori[4] / 4333 * rataRataPribadi;

    printf ("Emisi karbon oleh Ojek\t: %.2f Kg CO2\n", co2[4]);
    
    /* == Perhitungan Ojek ==
     *     Tarif Ojek Online dicek menggunakan aplikasi Go-Jek untuk 6 km terdapat tarif Rp26.000 
     * maka didapat tarif Rp4.333 per kilometer. Kalkulasi bisa dilakukan dengan membagi input user 
     * dengan 4333 dan mengalikan hasilnya dengan 2.37 agar didapat jumlah kg CO2.
     */
    co2[5] = kategori[5] / 4333 * rataRataPribadi;

    printf ("Emisi karbon oleh Ojek\t: %.2f Kg CO2\n", co2[4]);

    // Rata-rata total perhitungan co2
    total_co2 = (co2[0] + co2[1] + co2[2] + co2[3] + co2[4] + co2[5]) / 6;

    kesimpulan(total_co2);
}

void kesimpulan(float total_co2) {
    const float batas = 730000.0;

    printf("\nMaka emisi rata-rata yang anda hasilkan selama seminggu adalah : %.2f\n\n", total_co2);

	printf("=======================================================\n");
    if (total_co2 > batas)
        printf("\tMaka emisi CO2 anda termasuk TINGGI\n ");
    else if (total_co2 < batas)
        printf("\tMaka emisi CO2 anda termasuk RENDAH\n");
    else
        printf("\tMaka emisi CO2 anda termasuk NORMAL\n");
    printf("=======================================================\n\n");
}
