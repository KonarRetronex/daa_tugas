#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void solvePartition(int arr[], int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[i];

    // If total sum is odd, partition is impossible
    if (totalSum % 2 != 0) {
        printf("No solution possible (Total sum %d is odd).\n", totalSum);
        return;
    }

    int target = totalSum / 2;
    bool found = false;

    // Optimization: We only need to check 2^(n-1) subsets
    // Using bitmask: i represents a subset selection
    long long numSubsets = pow(2, n - 1); 

    for (int i = 0; i < numSubsets; i++) {
        int currentSum = 0;
        
        // Check which elements are in the current subset
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                currentSum += arr[j];
            }
        }

        if (currentSum == target) {
            found = true;
            printf("Solution Found!\n");
            
            printf("Subset 1: { ");
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) printf("%d ", arr[j]);
            }
            printf("} Sum = %d\n", target);

            printf("Subset 2: { ");
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) printf("%d ", arr[j]);
            }
            printf("} Sum = %d\n", target);
            
            break; // Stop after finding the first valid partition
        }
    }

    if (!found) {
        printf("No valid partition found despite even sum.\n");
    }
}

int main() {
    // Example from your image: {3, 8, 4, 6, 1, 2}
    int data[] = {3, 8, 4, 6, 1, 2};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Array: {3, 8, 4, 6, 1, 2}\n");
    solvePartition(data, n);

    return 0;
}