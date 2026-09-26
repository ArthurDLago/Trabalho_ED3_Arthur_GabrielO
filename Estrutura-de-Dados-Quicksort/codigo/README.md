# Quicksort — Implementação e Particionamento

## Objetivo
Implementar o Quicksort de forma didática, isolando a função de particionamento para facilitar o entendimento.

## Funcionamento
- `particionar()` implementa o **esquema de Lomuto**: escolhe o último elemento do intervalo como pivô e reorganiza o vetor de modo que tudo à esquerda seja menor que o pivô e tudo à direita seja maior.
- `quicksort()` chama `particionar()` e então se chama recursivamente para os dois subvetores resultantes, até que cada partição tenha 0 ou 1 elemento.

## Escolha do pivô
Este exemplo usa o **último elemento** do intervalo como pivô (esquema de Lomuto), por ser a forma mais simples de implementar e explicar. Em entradas já ordenadas, essa escolha leva ao pior caso O(n²); um pivô aleatório ou pelo elemento do meio reduz esse risco na prática.

## Particionamento (passo a passo)
1. `pivo = v[fim]`.
2. `i` começa em `inicio - 1` e marca o fim da região de elementos menores que o pivô.
3. Para cada `j` de `inicio` a `fim - 1`: se `v[j] < pivo`, incrementa `i` e troca `v[i]` com `v[j]`.
4. Ao final, troca `v[i+1]` com `v[fim]` — o pivô assume sua posição definitiva.

## Complexidade
- Melhor/médio caso: **O(n log n)**
- Pior caso: **O(n²)** (ex.: vetor já ordenado, pivô sempre no extremo)

## Exemplo de execução
```
Antes:  8 3 7 4 9 1 5 2 6
Depois: 1 2 3 4 5 6 7 8 9
```

