#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 4

// Character set (62 chars)
const char charset[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

const int CHARSET_SIZE = 62;

// Generate random password
void generate_password(char *password) {
    for (int i = 0; i < LENGTH; i++) {
        password[i] = charset[rand() % CHARSET_SIZE];
    }
    password[LENGTH] = '\0';
}

// Brute force
double brute_force(char *password) {
    clock_t start = clock();

    char guess[LENGTH + 1];
    guess[LENGTH] = '\0';

    for (int a = 0; a < CHARSET_SIZE; a++) {
        for (int b = 0; b < CHARSET_SIZE; b++) {
            for (int c = 0; c < CHARSET_SIZE; c++) {
                for (int d = 0; d < CHARSET_SIZE; d++) {

                    guess[0] = charset[a];
                    guess[1] = charset[b];
                    guess[2] = charset[c];
                    guess[3] = charset[d];

                    if (guess[0] == password[0] &&
                        guess[1] == password[1] &&
                        guess[2] == password[2] &&
                        guess[3] == password[3]) {

                        clock_t end = clock();
                        return (double)(end - start) / CLOCKS_PER_SEC;
                    }
                }
            }
        }
    }
    return 0;
}

// Run experiment
void run_experiment(int runs) {
    char password[LENGTH + 1];
    generate_password(password);

    printf("\nRuns: %d\n", runs);
    printf("Password: %s\n", password);

    double total = 0;

    for (int i = 1; i <= runs; i++) {
        double t = brute_force(password);
        total += t;

        // Print every 100 runs (avoid spam)
        if (i % 100 == 0) {
            printf("Run %d: %f seconds\n", i, t);
        }
    }

    printf("Average time: %f seconds\n", total / runs);
}

int main() {
    srand(time(NULL));

    run_experiment(1000);
    run_experiment(2000);
    run_experiment(3000);

    return 0;
}