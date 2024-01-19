#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
printf("The PID is: %i\n", getpid());
getchar();
pid_t child = fork();
if (child < 0) {
        return 1;
} else if (child == 0) {
        printf("Child PID is: %i\n", getpid());
        printf("Parent PID is: %i\n", getppid());
        getchar();
} else {
        getchar();
}
return 0;
}