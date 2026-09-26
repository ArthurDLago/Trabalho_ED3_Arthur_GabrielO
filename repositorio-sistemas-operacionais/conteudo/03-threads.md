# 3. Criação e gerência de threads

## 3.1 Definição

Uma thread é um fluxo de execução dentro de um processo.

Um processo pode possuir uma ou várias threads.

## 3.2 Recursos compartilhados

Threads de um mesmo processo normalmente compartilham:

- código;
- heap;
- espaço de endereçamento;
- arquivos e outros recursos do processo.

Cada thread possui seu próprio contexto de execução, incluindo:

- contador de programa;
- registradores;
- pilha;
- estado de execução.

## 3.3 Por que usar threads?

Threads são úteis quando uma aplicação precisa:

- realizar tarefas independentes;
- manter uma interface responsiva;
- processar várias requisições;
- aproveitar múltiplos núcleos;
- executar operações de E/S de forma concorrente.

## 3.4 std::thread em C++

Exemplo:

```cpp
#include <iostream>
#include <thread>

void tarefa() {
    std::cout << "Executando tarefa\n";
}

int main() {
    std::thread t(tarefa);
    t.join();

    return 0;
}
```

`join()` faz a thread chamadora aguardar a conclusão de `t`.

## 3.5 Threads e dados compartilhados

Considere:

```cpp
int contador = 0;

void incrementar() {
    ++contador;
}
```

Se várias threads executarem `incrementar()` simultaneamente, o acesso ao contador precisa ser analisado.

Uma operação aparentemente simples como:

```text
contador = contador + 1
```

envolve leitura, cálculo e escrita. Essas etapas podem ser intercaladas com operações de outra thread.

## 3.6 Mutex

Um mutex pode proteger uma região crítica:

```cpp
std::lock_guard<std::mutex> lock(m);
++contador;
```

O `lock_guard` utiliza RAII para garantir a liberação do mutex ao sair do escopo.

## 3.7 Condição de corrida

Uma race condition ocorre quando o resultado depende da ordem relativa de operações concorrentes sobre dados ou recursos compartilhados.

Nem toda execução concorrente possui uma race condition. Ela surge quando existe uma interação não devidamente sincronizada que permite resultados incorretos ou indeterminados.

## 3.8 Processo × thread

A principal ideia é:

```text
Processos → maior isolamento entre espaços de memória.

Threads → maior compartilhamento dentro do mesmo processo.
```

O compartilhamento facilita comunicação, mas aumenta a necessidade de sincronização.

## 3.9 Cuidado importante

Não conclua que threads são sempre melhores que processos.

A escolha depende de:

- isolamento necessário;
- custo de comunicação;
- segurança;
- necessidade de compartilhamento;
- características do sistema;
- natureza da aplicação.
