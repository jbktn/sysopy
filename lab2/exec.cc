#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Exec\n");
    getchar();
    execlp("./another", "another", (char *)NULL);
}