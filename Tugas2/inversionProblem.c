#include <stdio.h>

// Fungsi untuk menghitung jumlah inversi secara Brute Force
int hitungInversi(int arr[], int n) {
    int total_inversi = 0;
    
    // Loop luar: memilih angka patokan (indeks i)
    for (int i = 0; i < n - 1; i++) {
        
        // Loop dalam: membandingkan dengan angka di sebelah kanannya (indeks j)
        for (int j = i + 1; j < n; j++) {
            
            // Jika angka di kiri lebih besar dari angka di kanan, itu adalah inversi
            if (arr[i] > arr[j]) {
                printf("Ditemukan Inversi: (%d, %d)\n", arr[i], arr[j]);
                total_inversi++;
            }
        }
    }
    
    return total_inversi;
}

int main() {
    // Data dari soal slide
    int rankingX[] = {1, 3, 4, 2, 5};
    int rankingY[] = {1, 2, 4, 3, 5};
    
    int nX = sizeof(rankingX) / sizeof(rankingX[0]);
    int nY = sizeof(rankingY) / sizeof(rankingY[0]);
    
    printf("--- Mengecek Ranking X ---\n");
    int inversiX = hitungInversi(rankingX, nX);
    printf("Total Inversi X: %d\n\n", inversiX);
    
    printf("--- Mengecek Ranking Y ---\n");
    int inversiY = hitungInversi(rankingY, nY);
    printf("Total Inversi Y: %d\n\n", inversiY);
    
    // Kesimpulan program
    if (inversiY < inversiX) {
        printf("Kesimpulan: Kesukaan dengan Y lebih mirip karena inversi lebih sedikit.\n");
    }
    
    return 0;
}