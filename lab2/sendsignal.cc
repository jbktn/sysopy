#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    pid_t destination = atoi(argv[1]);
    int signalnumber = atoi(argv[2]);
    kill(destination, signalnumber);
    printf("Wysłano sygnał");
    return 0;
}