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
        printf("First Child PID is: %i\n", getpid());
        printf("First Parent PID is: %i\n", getppid());
        getchar();
}
else{
        pid_t child2 = fork();
        if (child2 < 0){
                return 1;
        }
        else if (child2 == 0){
                printf("Secont Child PID is: %i\n", getpid());
                printf("Second Child Parent PID is: %i\n", getppid());
                getchar();
        }
        else{
                getchar();
        }
}
return 0;
}