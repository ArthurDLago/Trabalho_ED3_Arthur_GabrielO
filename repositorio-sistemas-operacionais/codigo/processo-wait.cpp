#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Erro ao criar processo.\n";
        return 1;
    }

    if (pid == 0) {
        std::cout << "Filho executando...\n";
        sleep(1);
        std::cout << "Filho terminou.\n";
        return 42;
    }

    int status = 0;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        std::cout << "Pai: código de saída do filho = "
                  << WEXITSTATUS(status) << "\n";
    }

    return 0;
}
