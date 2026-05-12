#include <stdio.h>

int maxSubArrayBruteForce(int arr[], int n) {
    // Diinisiasi dengan 0 sesuai syarat soal 
    // "Nilai maksimum adalah 0 jika semua elemen negatif"
    int maxSum = 0; 

    for (int i = 0; i < n; i++) {
        int currentSum = 0;

        for (int j = i; j < n; j++) {
            currentSum += arr[j];

            // Perbarui maxSum jika currentSum lebih besar
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main() {
    // Uji coba menggunakan larik instansiasi dari soal
    int larik[] = {-2, 11, -4, 13, -5, 2, -1, 3};
    
    // Menghitung jumlah elemen di dalam larik
    int n = sizeof(larik) / sizeof(larik[0]);

    int max_sum = maxSubArrayBruteForce(larik, n);

    printf("Nilai maksimum sub-sequence: %d\n", max_sum);

    return 0;
}

//ini abis hard