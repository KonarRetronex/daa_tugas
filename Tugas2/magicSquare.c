#include <stdio.h>
#include <stdbool.h>

#define N 3
#define SIZE (N * N)

// The Magic Constant for N=3 is 15
int magicConstant = N * (N * N + 1) / 2;

void printSquare(int arr[]) {
    printf("-----------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % N == 0) printf("\n");
    }
}

bool isMagic(int arr[]) {
    // Check Rows
    for (int i = 0; i < N; i++) {
        if (arr[i*3] + arr[i*3+1] + arr[i*3+2] != magicConstant) return false;
    }
    // Check Columns
    for (int i = 0; i < N; i++) {
        if (arr[i] + arr[i+3] + arr[i+6] != magicConstant) return false;
    }
    // Check Diagonals
    if (arr[0] + arr[4] + arr[8] != magicConstant) return false;
    if (arr[2] + arr[4] + arr[6] != magicConstant) return false;

    return true;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate(int arr[], int k) {
    if (k == SIZE) {
        if (isMagic(arr)) {
            printSquare(arr);
        }
        return;
    }

    for (int i = k; i < SIZE; i++) {
        swap(&arr[k], &arr[i]);
        generate(arr, k + 1);
        swap(&arr[k], &arr[i]); // backtrack
    }
}

int main() {
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) numbers[i] = i + 1;

    printf("Searching for 3x3 Magic Squares...\n");
    generate(numbers, 0);

    return 0;
}