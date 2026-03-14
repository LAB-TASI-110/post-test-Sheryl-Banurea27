#include <stdio.h>
#include <string.h>

int main(void) {
    char kota_simpan[100][10];
    float berat_butet_simpan[100];
    int jumlah_data = 0;
    
    char kota_input[10];
    float berat_input;

    printf("=== SISTEM INPUT DEL-EXPRESS ===\n");
    printf("Masukkan data terus menerus. Ketik 'END' pada Kode Kota untuk memproses struk.\n\n");

    while (jumlah_data < 100) {
        printf("Masukkan Kode Kota ke-%d (MDN/BLG/JKT/SBY): ", jumlah_data + 1);
        scanf("%s", kota_input);

        if (strcmp(kota_input, "END") == 0) {
            printf("\nInput selesai. Memproses %d data pengiriman...\n", jumlah_data);
            break;
        }

        if (strcmp(kota_input, "MDN") == 0 || strcmp(kota_input, "BLG") == 0 || 
            strcmp(kota_input, "JKT") == 0 || strcmp(kota_input, "SBY") == 0) {
            
            printf("Masukkan Berat Paket Butet (kg): ");
            scanf("%f", &berat_input);

            strcpy(kota_simpan[jumlah_data], kota_input);
            berat_butet_simpan[jumlah_data] = berat_input;
            jumlah_data++;
            
            printf("Data berhasil dicatat!\n\n");
        } else {
            printf("\n[ERROR] Kode kota '%s' tidak valid. Silakan coba lagi.\n\n", kota_input);
        }
    }

    for (int i = 0; i < jumlah_data; i++) {
        float berat_butet = berat_butet_simpan[i];
        float berat_ucok = berat_butet * 1.5;
        float total_berat = berat_butet + berat_ucok;
        
        float harga_per_kg = 0;
        int status_luar_pulau = 0;

        if (strcmp(kota_simpan[i], "MDN") == 0) {
            harga_per_kg = 8000;
        } else if (strcmp(kota_simpan[i], "BLG") == 0) {
            harga_per_kg = 5000;
        } else if (strcmp(kota_simpan[i], "JKT") == 0) {
            harga_per_kg = 12000;
            status_luar_pulau = 1;
        } else if (strcmp(kota_simpan[i], "SBY") == 0) {
            harga_per_kg = 13000;
            status_luar_pulau = 1;
        }

        float total_ongkir = total_berat * harga_per_kg;
        float diskon = 0;

        if (total_berat > 10.0) {
            diskon = total_ongkir * 0.10;
        }

        float hasil_akhir = total_ongkir - diskon;

        printf("\n========================================\n");
        printf("    STRUK PEMBAYARAN DEL-EXPRESS #%d    \n", i + 1);
        printf("========================================\n");
        printf("Kota Tujuan       : %s\n", kota_simpan[i]);
        printf("Berat Paket Butet : %.2f KG\n", berat_butet);
        printf("Berat Paket Ucok  : %.2f KG\n", berat_ucok);
        printf("Total Berat       : %.2f KG\n", total_berat);
        printf("Total Ongkos Kirim: Rp %.2f\n", hasil_akhir);
        printf("Informasi Promo   : ");

        if (total_berat > 10.0 && status_luar_pulau == 1) {
            printf("Diskon Ongkir 10%% & Asuransi Gratis\n");
        } else if (total_berat > 10.0) {
            printf("Diskon Ongkir 10%%\n");
        } else if (status_luar_pulau == 1) {
            printf("Asuransi Gratis\n");
        } else {
            printf("Tidak Ada\n");
        }
        printf("========================================\n");
    }

    return 0;
}