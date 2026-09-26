# Análise de código — Estrutura de Dados

## Código

```cpp
int particionar(std::vector<int> &v, int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (v[j] < pivo)
        {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[fim]);
    return i + 1;
}
```

## Pergunta
Se este código for chamado com o vetor `[1, 2, 3, 4, 5]` (já ordenado) e `inicio=0, fim=4`, quantas trocas (`swap`) efetivamente alteram o vetor, e qual é o impacto disso na complexidade do Quicksort completo?

## Resposta
Nenhuma troca realizada pelo laço altera o vetor (todas são `swap(v[i], v[i])`, ou seja, trocam um elemento consigo mesmo), e a troca final também é `swap(v[4], v[4])`. O particionamento retorna `posPivo = 4` — a maior posição possível, ou seja, uma partição totalmente desbalanceada (0 elementos à direita, 4 à esquerda). Se essa entrada se repetir a cada chamada recursiva (como ocorre com um vetor já ordenado e pivô = último elemento), o Quicksort degenera para o **pior caso, O(n²)**.

## Análise
Como o pivô é sempre o último elemento e o vetor já está ordenado, todo elemento antes do pivô é sempre menor que ele — logo `i` avança a cada iteração e a partição resultante tem `fim - inicio` elementos de um lado e nenhum do outro. Isso significa que, a cada chamada recursiva, apenas 1 elemento (o pivô) é removido do problema, resultando em `n` níveis de recursão em vez de `log n` — daí a complexidade quadrática no pior caso.

## Conceito
Impacto da escolha do pivô no desbalanceamento das partições; pior caso do Quicksort.
