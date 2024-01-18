#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void signalhandler(int signum) {
    printf("Otrzymano sygnal %s.\n", strsignal(signum));

}

int main() {
    printf("PID: %d\n", getpid());
    for (int i=0; i<17; i++){
        signal(i, signalhandler);
        }
    while (1) {
            printf("Czekam...\n");
            sleep(1);
    }
}
jpomorsk@student:~/lab2$ cat exec.cc
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Hello, I'm exec program!\n");
    getchar();
    execlp("./another", "another", (char *)NULL);

}