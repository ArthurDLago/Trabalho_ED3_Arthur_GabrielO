#include <iostream>
#include <thread>

void tarefa(int id) {
    std::cout << "Thread " << id << " executando.\n";
}

int main() {
    std::thread t1(tarefa, 1);
    std::thread t2(tarefa, 2);

    t1.join();
    t2.join();

    return 0;
}
