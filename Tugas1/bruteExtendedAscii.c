#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 4
#define ASCII_START 0
#define ASCII_END 255

// Generate password (0–255)
void generate_password(unsigned char *password) {
    for (int i = 0; i < LENGTH; i++) {
        password[i] = rand() % 256;
    }
}

// Print password as HEX (important!)
void print_password(unsigned char *password) {
    printf("Password (HEX): ");
    for (int i = 0; i < LENGTH; i++) {
        printf("%02X ", password[i]);
    }
    printf("\n");
}

// Brute force
double brute_force(unsigned char *password) {
    clock_t start = clock();

    unsigned char guess[LENGTH];

    for (int a = ASCII_START; a <= ASCII_END; a++) {
        for (int b = ASCII_START; b <= ASCII_END; b++) {
            for (int c = ASCII_START; c <= ASCII_END; c++) {
                for (int d = ASCII_START; d <= ASCII_END; d++) {

                    guess[0] = a;
                    guess[1] = b;
                    guess[2] = c;
                    guess[3] = d;

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
    unsigned char password[LENGTH];
    generate_password(password);

    printf("\n============================\n");
    printf("Runs: %d\n", runs);
    print_password(password);
    printf("============================\n");

    double total = 0;

    for (int i = 1; i <= runs; i++) {
        double t = brute_force(password);
        total += t;

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