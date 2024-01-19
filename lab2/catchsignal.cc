#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void signalhandler(int signum) {
    printf("Otrzymano sygnal %s\n", strsignal(signum));
}

int main() {
    printf("PID: %d\n", getpid());
    for (int i=0; i<17; i++) {
        signal(i, signalhandler);
    }
    while (1) {
        printf("Czekam...\n");
        sleep(1);
    }
}