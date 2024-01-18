#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
printf("The PID is: %i\n", getpid());
getchar();
pid_t child = fork();
if (child < 0){
        return 1;
}
else if(child == 0){
        printf("Child PID is: %i\n", getpid());
        printf("Parent PID (PPID) is: %i\n", getppid());
        getchar();
        pid_t grantchild = fork();
        if (grantchild < 0){
                return 1;
        }
        else if(grantchild == 0){
                printf("Grandchild PID: %d\n", getpid());
                printf("Grandchild Parent PID (PPID): %d\n", getppid());
                getchar();
        }
        else{
                getchar();
        }
}
else{
        getchar();
}
return 0;
}