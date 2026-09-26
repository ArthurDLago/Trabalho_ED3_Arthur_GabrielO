#include <iostream>
#include <mutex>
#include <thread>

int contador = 0;
std::mutex mutex_contador;

void incrementar() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mutex_contador);
        ++contador;
    }
}

int main() {
    std::thread t1(incrementar);
    std::thread t2(incrementar);

    t1.join();
    t2.join();

    std::cout << "Contador: " << contador << "\n";
    return 0;
}
