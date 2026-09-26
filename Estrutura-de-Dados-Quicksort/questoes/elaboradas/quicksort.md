# Questão elaborada — Estrutura de Dados

> **Questão elaborada para este trabalho.**

## Enunciado

Considere o vetor `[5, 2, 8, 1, 6]` e o algoritmo Quicksort com particionamento de Lomuto, no qual o pivô é sempre o **último elemento** do intervalo. Após a **primeira** chamada de `particionar()` sobre o vetor inteiro, qual é o conteúdo do vetor e a posição final (índice) do pivô?

(a) `[5, 2, 1, 6, 8]`, pivô no índice 3
(b) `[1, 2, 5, 6, 8]`, pivô no índice 3
(c) `[5, 2, 1, 8, 6]`, pivô no índice 4
(d) `[2, 1, 5, 6, 8]`, pivô no índice 2
(e) `[5, 2, 8, 1, 6]`, pivô no índice 4

## Gabarito
**(a) `[5, 2, 1, 6, 8]`, pivô no índice 3**

## Resolução comentada
Pivô = `6` (último elemento, índice 4). `i = -1`.

| j | v[j] | v[j] < pivô (6)? | Ação | Vetor após a ação |
|---|---|---|---|---|
| 0 | 5 | sim | i=0, troca v[0]↔v[0] | `[5,2,8,1,6]` |
| 1 | 2 | sim | i=1, troca v[1]↔v[1] | `[5,2,8,1,6]` |
| 2 | 8 | não | nada | `[5,2,8,1,6]` |
| 3 | 1 | sim | i=2, troca v[2]↔v[3] | `[5,2,1,8,6]` |

Ao final do laço, troca-se `v[i+1]` (índice 3) com `v[fim]` (índice 4, o pivô): troca `8` ↔ `6` → `[5, 2, 1, 6, 8]`.

O pivô `6` fica no **índice 3**, com todos os elementos menores (`5, 2, 1`) à esquerda e o único maior (`8`) à direita — exatamente a posição que `6` ocuparia no vetor ordenado.

## Conceito cobrado
Particionamento de Lomuto; rastreamento manual do algoritmo Quicksort.
