#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char tanggal[20], nama_barang[50], metode[10];
    float harga, total_pemasukan = 0;
    char buffer[50];

    printf("=== SISTEM KAFETARIA IT DEL ===\n");
    printf("Masukkan Tanggal (DD-MM-YYYY): ");
    scanf("%s", tanggal);

    printf("\n--- Input Transaksi (Ketik 'END' pada nama barang untuk selesai) ---\n");

    while (1) {
        printf("\nNama Barang: ");
        scanf(" %[^\n]", buffer);

        if (strcmp(buffer, "END") == 0) {
            break;
        }

        strcpy(nama_barang, buffer);

        printf("Harga: ");
        scanf("%f", &harga);

        printf("Metode Pembayaran (cash/tf): ");
        scanf("%s", metode);

        total_pemasukan += harga;

        printf(">> Tercatat: %s | %s | Rp.%.2f\n", nama_barang, metode, harga);
    }

    printf("\n================================\n");
    printf("LAPORAN TRANSAKSI KAFETARIA\n");
    printf("Tanggal: %s\n", tanggal);
    printf("Total Pemasukan: Rp. %.2f\n", total_pemasukan);
    printf("================================\n");

    return 0;
}