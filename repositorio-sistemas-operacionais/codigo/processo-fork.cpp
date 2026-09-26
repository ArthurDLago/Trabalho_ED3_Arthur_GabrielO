#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Erro ao criar processo.\n";
        return 1;
    }

    if (pid == 0) {
        std::cout << "Filho: PID = " << getpid() << "\n";
    } else {
        std::cout << "Pai: PID = " << getpid()
                  << ", filho = " << pid << "\n";
    }

    return 0;
}
