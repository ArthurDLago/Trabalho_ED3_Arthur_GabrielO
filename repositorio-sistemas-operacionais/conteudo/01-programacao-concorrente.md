# 1. Introdução à programação concorrente

## 1.1 O que é concorrência?

Programação concorrente trata da existência de múltiplas atividades que podem avançar durante o mesmo intervalo de tempo.

Concorrência não significa necessariamente execução simultânea.

Em uma máquina com um único núcleo, duas tarefas podem alternar o uso da CPU. Em uma máquina multicore, tarefas diferentes podem realmente executar em paralelo.

## 1.2 Concorrência e paralelismo

**Concorrência:** várias tarefas estão em progresso e o sistema organiza sua execução.

**Paralelismo:** duas ou mais tarefas são executadas simultaneamente em recursos computacionais distintos.

### Exemplo

Imagine duas tarefas:

```text
A = processamento de dados
B = leitura de arquivo
```

Se A executa enquanto B espera uma operação de E/S, o processador pode alternar entre elas. Em um sistema multicore, A e B também podem ser executadas simultaneamente.

## 1.3 Por que utilizar concorrência?

- melhorar responsividade;
- aproveitar períodos de espera de E/S;
- explorar múltiplos núcleos;
- estruturar servidores e aplicações interativas;
- dividir problemas em tarefas independentes.

## 1.4 Desafios

A concorrência também introduz problemas:

- condições de corrida;
- acesso inconsistente a dados;
- deadlocks;
- starvation;
- dificuldade de reproduzir determinados erros;
- necessidade de sincronização.

Neste trabalho, o foco está nos fundamentos necessários para compreender processos e threads.

## 1.5 Conceito-chave

> Concorrência é uma propriedade da organização da execução; paralelismo é a execução simultânea de atividades.

Essa distinção é recorrente em questões conceituais.
