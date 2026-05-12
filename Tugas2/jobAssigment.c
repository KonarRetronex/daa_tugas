#include <stdio.h>
#include <limits.h>

#define N 4

// Cost Matrix from the image
int costMatrix[N][N] = {
    {9, 2, 7, 8}, // Person a
    {6, 4, 3, 7}, // Person b
    {5, 8, 1, 4}, // Person c
    {7, 6, 9, 4}  // Person d
};

int minCost = INT_MAX;
int bestAssignment[N];

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to calculate cost for a specific permutation
void calculateCost(int jobs[]) {
    int currentCost = 0;
    for (int i = 0; i < N; i++) {
        currentCost += costMatrix[i][jobs[i]];
    }

    if (currentCost < minCost) {
        minCost = currentCost;
        for (int i = 0; i < N; i++) {
            bestAssignment[i] = jobs[i];
        }
    }
}

// Recursive function to generate all permutations of jobs
void generatePermutations(int jobs[], int start, int end) {
    if (start == end) {
        calculateCost(jobs);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&jobs[start], &jobs[i]);
            generatePermutations(jobs, start + 1, end);
            swap(&jobs[start], &jobs[i]); // backtrack
        }
    }
}

int main() {
    int jobs[N] = {0, 1, 2, 3}; // Represents Job1, Job2, Job3, Job4

    printf("Starting Exhaustive Search...\n\n");
    
    generatePermutations(jobs, 0, N - 1);

    // Display Result
    printf("--- Minimum Cost Found: %d ---\n", minCost);
    char persons[] = {'a', 'b', 'c', 'd'};
    for (int i = 0; i < N; i++) {
        printf("Person %c is assigned to Job %d (Cost: %d)\n", 
                persons[i], bestAssignment[i] + 1, costMatrix[i][bestAssignment[i]]);
    }

    return 0;
}