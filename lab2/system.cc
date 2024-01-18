#include <stdioh>

int main() {
    std::cout << "Hello, I'm a system program!" << std::endl;
    getchar();
    int result = system("ls -al /var/log/");
    if (result == -1) {
        return 1;
    }
return 0;
}