# Estrutura de Dados — Quicksort e Particionamento

## 1. Conceito

Quicksort é um algoritmo de ordenação baseado na estratégia de **divisão e conquista**: o array é particionado em torno de um elemento de referência (**pivô**), de modo que todos os menores fiquem à esquerda e todos os maiores à direita. O processo é então repetido recursivamente para as duas partições.

## 2. Divisão e conquista

1. **Dividir**: escolher um pivô e particionar o array em duas metades.
2. **Conquistar**: ordenar recursivamente cada metade.
3. **Combinar**: não é necessário — ao final da recursão, o array já está ordenado in-place.

## 3. Escolha do pivô

Estratégias comuns:
- Primeiro elemento;
- Último elemento (usado no esquema de Lomuto);
- Elemento do meio;
- Elemento aleatório (reduz a chance do pior caso em entradas já ordenadas).

## 4. Particionamento (esquema de Lomuto)

1. Escolhe-se o último elemento como pivô.
2. Um índice `i` marca o limite da região "menor que o pivô".
3. Percorre-se o array com `j`; sempre que `array[j] < pivô`, o elemento é trocado para dentro da região dos menores.
4. Ao final, o pivô é trocado para sua posição correta (entre as duas regiões).

O pivô termina exatamente na posição em que ficaria se o array estivesse ordenado.

## 5. Chamadas recursivas

Após o particionamento, o Quicksort é chamado recursivamente para:
- o subarray à esquerda do pivô;
- o subarray à direita do pivô.

A recursão termina quando o subarray tem 0 ou 1 elemento.

## 6. Complexidade

| Caso | Complexidade | Situação |
|---|---|---|
| Melhor caso | O(n log n) | Pivô sempre divide o array ao meio |
| Caso médio | O(n log n) | Divisões razoavelmente equilibradas |
| Pior caso | O(n²) | Pivô sempre é o menor ou maior elemento (ex.: array já ordenado com pivô fixo) |

**Espaço:** O(log n) no caso médio, devido à pilha de recursão (ordenação in-place).

## Referências
Ver [bibliografia completa](../referencias/bibliografia.md#estrutura-de-dados).
