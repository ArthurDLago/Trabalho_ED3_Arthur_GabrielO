# 2. Criação e gerência de processos

## 2.1 Programa × processo

Um **programa** é uma coleção de instruções armazenada de forma estática.

Um **processo** é uma instância desse programa em execução, acompanhada do estado e dos recursos necessários para sua execução.

## 2.2 Informações associadas ao processo

O sistema operacional mantém informações como:

- estado do processo;
- identificador;
- contador de programa;
- registradores;
- informações de escalonamento;
- informações de memória;
- recursos e arquivos associados.

Uma estrutura de controle do processo é frequentemente chamada de **PCB (Process Control Block)**.

## 2.3 Estados de processo

Uma representação simplificada é:

```text
             admitido
Novo --------------------> Pronto
                              |
                              | escalonado
                              v
                         Executando
                         /        \
                 espera E/S       termina
                       |             |
                       v             v
                  Bloqueado       Encerrado
                       |
                       | evento concluído
                       v
                    Pronto
```

Os nomes e detalhes dos estados podem variar entre modelos e sistemas.

## 2.4 Criação com fork()

Em sistemas POSIX, `fork()` cria um novo processo.

A ideia simplificada é:

```text
antes:
    P

depois de fork():
    P
    |
    F
```

Pai e filho continuam a partir da instrução seguinte.

O valor retornado por `fork()` permite distinguir os fluxos:

- `0` no processo filho;
- valor positivo, correspondente ao PID do filho, no pai;
- `-1` em caso de erro.

## 2.5 fork() em um laço

Considere:

```cpp
for (int i = 0; i < 3; ++i) {
    fork();
}
```

Se todas as chamadas forem bem-sucedidas e todos os processos continuarem executando o laço, a quantidade final será:

```text
1 → 2 → 4 → 8
```

A regra é:

**cada chamada `fork()` duplica a quantidade de processos existentes naquele ponto**, quando todos os processos chegam à chamada.

## 2.6 Espera pelo processo filho

`wait()` e `waitpid()` permitem que um processo pai aguarde um filho.

Isso é importante para:

- sincronização entre pai e filho;
- obtenção do status de término;
- evitar determinados processos filhos permanecerem como zumbis.

## 2.7 Terminação

Quando um processo termina, recursos associados devem ser tratados pelo sistema operacional.

O gerenciamento inadequado de processos pode provocar:

- consumo desnecessário de recursos;
- processos zumbis;
- acúmulo de processos;
- degradação do sistema.

## 2.8 Troca de contexto

Para alternar a CPU entre unidades de execução, o sistema precisa preservar o estado da execução interrompida e restaurar o estado da próxima.

Esse trabalho possui custo. Por isso, concorrência não significa que alternar entre tarefas seja gratuito.

## 2.9 Ponto de prova

Ao analisar `fork()`, não conte apenas as chamadas escritas no código. Pergunte:

1. Quantos processos existem antes da chamada?
2. Quais processos chegam à próxima chamada?
3. Todos os `fork()` são executados por todos?
4. Existe alguma condição que impede uma duplicação?
