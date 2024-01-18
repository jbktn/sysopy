#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void statyczna() {
    srand(time(NULL));
    double tablica[1000000];
    for (int i = 0; i < 1000000; ++i) {
        tablica[i] = rand() % 100;
    }

    printf("Statyczna: Naciśnij Enter, aby kontynuować...");
    getchar();
}

void dynamiczna() {
    srand(time(NULL));
    double *tablica = (double*)malloc(1000000 * sizeof(double));
    for (int i = 0; i < 1000000; ++i) {
        tablica[i] = rand() % 100;
    }

    printf("Dynamiczna: Naciśnij Enter, aby kontynuować...");
    getchar();
    free(tablica);
}

int main() {
    statyczna();
    sleep(2);
    dynamiczna();

    return 0;
}
