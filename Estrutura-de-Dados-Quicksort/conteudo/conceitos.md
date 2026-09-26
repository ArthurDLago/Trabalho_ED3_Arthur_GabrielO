# Quicksort e particionamento

## 1. Ideia

Quicksort ordena por **divisão e conquista**. Escolhe um pivô, particiona o vetor ao redor dele e ordena recursivamente as regiões resultantes. As partições não precisam ter o mesmo tamanho.

Na implementação deste projeto, o particionamento de Lomuto coloca à esquerda os valores menores que o pivô e, à direita, os valores maiores ou iguais a ele. O próprio pivô termina na posição que ocupará no vetor ordenado.

## 2. Particionamento de Lomuto

1. Escolher o último valor do intervalo como pivô.
2. Percorrer os demais valores e mover cada valor menor que o pivô para a região da esquerda.
3. Trocar o pivô com o primeiro valor da região da direita.

Como a comparação é estrita (`valor < pivô`), valores iguais ao pivô ficam do lado direito. Esse particionamento não é estável: elementos de mesma chave podem mudar sua ordem relativa.

## 3. Recursão e pivô

Depois de particionar, ordenar recursivamente os intervalos à esquerda e à direita do pivô. A recursão termina quando o intervalo tem zero ou um elemento.

O projeto escolhe sempre o último elemento como pivô. A escolha do primeiro ou do último pode produzir partições muito desequilibradas em entradas ordenadas; pivôs aleatórios ou medianas podem reduzir esse risco, mas não eliminam o pior caso teórico.

## 4. Complexidade

| Caso | Tempo | Comportamento |
|---|---|---|
| Melhor | $O(n \log n)$ | Partições equilibradas |
| Médio | $O(n \log n)$ | Entrada aleatória ou sem padrão que force partições ruins |
| Pior | $O(n^2)$ | Partições de tamanhos 0 e $n - 1$ repetidamente |

**Pilha de recursão:** $O(\log n)$ em média e $O(n)$ no pior caso. A ordenação é in-place quanto ao vetor, mas a pilha recursiva ocupa espaço auxiliar.

## Referências

Consulte a [bibliografia complementar](../referencias/bibliografia.md#bibliografia-complementar).
