#include <stdioh>

int main() {
    printf("System program\n");
    getchar();
    int result = system("ls -al /var/log/");
    if (result == -1) {
        return 1;
    }
return 0;
}