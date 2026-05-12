#include <stdio.h>
#include <limits.h>

int main() {
    // Data dari soal
    int spbu[] = {10, 25, 30, 40, 50, 75, 80};
    int n = sizeof(spbu) / sizeof(spbu[0]);
    int target_distance = 100;
    int max_range = 30;

    // Variabel untuk menyimpan hasil terbaik
    int min_stops = INT_MAX; 
    int best_combination = -1;

    // Total kombinasi = 2 pangkat n. 
    // 1 << 7 sama dengan 128 (dari 0 sampai 127).
    int total_combinations = 1 << n;

    // Evaluasi semua kombinasi secara Brute Force
    for (int i = 0; i < total_combinations; i++) {
        int valid = 1;
        int current_pos = 0;
        int stops_count = 0;

        // Mengecek setiap bit dari angka 'i' untuk melihat SPBU mana yang dipilih
        for (int j = 0; j < n; j++) {
            
            // Jika bit ke-j bernilai 1 (berarti SPBU ke-j dipilih untuk berhenti)
            if (i & (1 << j)) {
                int distance_to_next = spbu[j] - current_pos;

                // Jika jarak ke SPBU pilihan ini lebih dari kapasitas tangki -> MOGOK
                if (distance_to_next > max_range) {
                    valid = 0;
                    break;
                }

                current_pos = spbu[j];
                stops_count++;
            }
        }

        // Jika rute antar SPBU aman, cek perjalanan terakhir dari SPBU terakhir ke titik 100km
        if (valid) {
            int distance_to_target = target_distance - current_pos;
            if (distance_to_target > max_range) {
                valid = 0; // Mogok sebelum sampai tujuan akhir
            }
        }

        // Jika rute ini Valid dan jumlah pemberhentiannya lebih sedikit dari catatan kita
        if (valid) {
            if (stops_count < min_stops) {
                min_stops = stops_count;
                best_combination = i; // Simpan kombinasi terbaik ini
            }
        }
    }

    // Mencetak Hasil Akhir
    printf("--- Penyelesaian Brute Force ---\n");
    if (min_stops == INT_MAX) {
        printf("Tidak ada rute yang memungkinkan untuk sampai tujuan.\n");
    } else {
        printf("Jumlah pemberhentian minimum: %d kali\n", min_stops);
        printf("Berhenti di SPBU pada kilometer: ");
        
        // Membaca ulang kombinasi terbaik untuk mengekstrak angka kilometernya
        for (int j = 0; j < n; j++) {
            if (best_combination & (1 << j)) {
                printf("%d ", spbu[j]);
            }
        }
        printf("\n");
    }

    return 0;
}