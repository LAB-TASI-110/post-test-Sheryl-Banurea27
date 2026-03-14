#include <stdio.h>

int main() {
    int n, total = 0;
    char kategori;

    printf("Masukkan Jumlah Total Data (N): ");
    scanf("%d", &n);

    int stok[n];
    printf("Masukkan Deret Stok (Pisahkan dengan Spasi): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stok[i]);
    }

    printf("Pilih Kode Kategori (A = Pakaian Sekolah, B = Sembako): ");
    scanf(" %c", &kategori);

    if (kategori == 'A' || kategori == 'a') {
        for (int i = 0; i < n; i += 2) {
            total += stok[i];
        }
    } else if (kategori == 'B' || kategori == 'b') {
        for (int i = 1; i < n; i += 2) {
            total += stok[i];
        }
    }

    printf("Total Stok untuk Kategori %c adalah: %d\n", kategori, total);

    return 0;
}