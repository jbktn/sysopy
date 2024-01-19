#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
printf("PID: %i\n", getpid());
getchar();
pid_t child = fork();
if (child < 0) {
        return 1;
}
else if(child == 0){
        printf("Child PID: %i\n", getpid());
        printf("Parent PID: %i\n", getppid());
        getchar();
        pid_t grantchild = fork();
        if (grantchild < 0) {
                return 1;
        } else if(grantchild == 0) {
                printf("Grandchild PID: %d\n", getpid());
                printf("Grandchild Parent PID: %d\n", getppid());
                getchar();
        } else {
                getchar();
        }
} else {
        getchar();
}
return 0;
}