# Resumo — Quicksort e Particionamento

Este trabalho explica o algoritmo de ordenação Quicksort:

- Estratégia de **divisão e conquista**: escolhe-se um **pivô**, particiona-se o vetor em torno dele e repete-se o processo recursivamente.
- O **particionamento** (esquema de Lomuto) reorganiza o vetor para que tudo menor que o pivô fique à esquerda e tudo maior fique à direita, colocando o pivô em sua posição final.
- **Complexidade**: O(n log n) no melhor e no caso médio; O(n²) no pior caso, quando as partições ficam muito desbalanceadas (ex.: vetor já ordenado com pivô fixo no extremo).

Ver a explicação completa em [`conceitos.md`](conceitos.md), a implementação funcional em [`../codigo/quicksort/`](../codigo/quicksort) e a questão comentada em [`../questoes/`](../questoes).
