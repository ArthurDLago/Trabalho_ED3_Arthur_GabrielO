# Implementação do Quicksort

O código usa o particionamento de Lomuto e o último elemento do intervalo como pivô.

## Particionamento

1. `particionar()` define `valores[fim]` como pivô e inicia `limiteMenores` em `inicio`.
2. Percorre os elementos de `inicio` até `fim - 1`. Se um elemento for menor que o pivô, troca-o para a região à esquerda e avança o limite.
3. Troca o pivô com o primeiro elemento da região à direita e devolve sua posição final.

Depois da troca, os valores à esquerda são menores que o pivô; os valores à direita são maiores ou iguais. As duas regiões não precisam ter o mesmo tamanho.

## Recursão e complexidade

`quicksortIntervalo()` ordena as regiões antes e depois do pivô até que cada intervalo tenha no máximo um elemento. A função `quicksort()` recebe o vetor inteiro e trata vetores vazios e unitários sem calcular índices inválidos.

- Tempo melhor e médio: $O(n \log n)$.
- Tempo pior: $O(n^2)$, por exemplo, com entrada crescente e pivô sempre no último elemento.
- Pilha recursiva: $O(\log n)$ em média e $O(n)$ no pior caso.

O particionamento é in-place, mas a pilha de recursão ainda usa espaço auxiliar.

## Compilar e executar

Na pasta `codigo`, compile com:

```sh
g++ -std=c++17 quicksort.cpp -o quicksort
```

Execute com `./quicksort` em Linux/macOS ou `.\quicksort.exe` no PowerShell do Windows.

O programa também verifica, com `assert`, os casos vazio, unitário e com valores repetidos antes de mostrar o exemplo principal.








