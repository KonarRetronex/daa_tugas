#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 4
#define ASCII_START 32
#define ASCII_END 126

void generate_password(char *password) {
    for (int i = 0; i < LENGTH; i++) {
        password[i] = (rand() % (ASCII_END - ASCII_START + 1)) + ASCII_START;
    }
    password[LENGTH] = '\0';
}

double brute_force(char *password) {
    clock_t start = clock();

    char guess[LENGTH + 1];
    guess[LENGTH] = '\0';

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

void run_experiment(int runs) {
    char password[LENGTH + 1];
    generate_password(password);

    printf("\nRuns: %d\n", runs);
    printf("Password: %s\n", password);

    double total = 0;

    for (int i = 1; i <= runs; i++) {
        double t = brute_force(password);
        total += t;

        if (i % 100 == 0) {
            printf("Run %d: %f seconds\n", i, t);
        }
    }

    printf("Average time: %f\n", total / runs);
}

int main() {
    srand(time(NULL));

    run_experiment(1000);
    run_experiment(2000);
    run_experiment(3000);

    return 0;
}