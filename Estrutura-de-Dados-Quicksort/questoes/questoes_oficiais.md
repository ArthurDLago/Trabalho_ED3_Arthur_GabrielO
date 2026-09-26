# Questões oficiais — Quicksort

Os enunciados abaixo são paráfrases dos itens oficiais, acompanhadas de resolução detalhada. As provas e os gabaritos oficiais estão na [bibliografia](../referencias/bibliografia.md#fontes-das-questões).

---

## 1. ENADE 2005 — Questão 13: ordenação

**Perfil:** Bacharelado em Sistemas de Informação. O item avalia ordenação em geral; apenas uma das afirmações trata diretamente de Quicksort.

### Enunciado

A questão pede que se julguem quatro afirmações sobre algoritmos de ordenação:

I. O Insertion Sort teria complexidade $O(n \log n)$.

II. Um algoritmo seria estável quando preserva a ordem relativa dos elementos com valores iguais.

III. A escolha do pivô no Quicksort influenciaria seu desempenho.

IV. Bubble Sort e Insertion Sort fariam, em média, o mesmo número de comparações.

As alternativas combinam os itens considerados corretos:

- A) I e II;
- B) I e III;
- C) II e IV;
- D) I, III e IV;
- E) II, III e IV.

### Resolução comentada

**I. Falsa.** No Insertion Sort, o pior caso e o caso médio são $O(n^2)$; no melhor caso, com a entrada já ordenada, é $O(n)$. Não é um algoritmo de $O(n \log n)$.

**II. Verdadeira.** Estabilidade significa que dois elementos com a mesma chave mantêm entre si a ordem que tinham na entrada.

**III. Verdadeira.** O pivô determina os tamanhos das partições. Partições equilibradas levam a tempo médio $O(n \log n)$; partições repetidamente com tamanhos 0 e $n - 1$ levam ao pior caso $O(n^2)$.

**IV. Considerada verdadeira pelo gabarito oficial.** A afirmação deve ser lida em termos da ordem assintótica: as duas ordenações fazem $\Theta(n^2)$ comparações em média. Isso não significa que toda implementação execute exatamente a mesma quantidade; a contagem precisa depende das variantes e dos dados de entrada, que a questão não especifica.

**Gabarito oficial: E — II, III e IV.** A prova e a chave oficial do INEP estão ligadas na bibliografia.

---

## 2. ENADE 2021 — Questão 32: partição do Quicksort

### Enunciado

A questão fornece um algoritmo recursivo de ordenação e uma rotina de partição. Em cada chamada, a ordenação particiona o intervalo `lo..hi` e depois ordena recursivamente as partes antes e depois da posição devolvida.

Na partição, o último elemento do intervalo (`A[hi]`) é o pivô. Um índice `i` começa em `lo`; o índice `j` percorre o intervalo de `lo` até `hi`. Quando `A[j]` é menor que o pivô, `A[i]` e `A[j]` são trocados e `i` avança. Ao final, `A[i]` é trocado com o pivô, e `i` é devolvido.

Com base nessa implementação, a prova avalia:

I. se a pilha de recursão pode exigir espaço adicional $O(n)$;

II. se o algoritmo é recursivo e estável;

III. se o número médio de comparações é $O(n \log n)$;

IV. se escolher o primeiro elemento como pivô é sempre mais eficiente que escolher o último.

As alternativas são: A) I e III; B) II e IV; C) III e IV; D) I, II e III; E) I, II e IV.

### Resolução comentada

**I. Verdadeira no pior caso.** Considere uma entrada crescente `[1, 2, 3, 4]`. Como o último elemento é sempre o maior, a partição o deixa no final e produz subproblemas de tamanhos 3 e 0, depois 2 e 0, depois 1 e 0. A profundidade chega a $n$, portanto a pilha pode ocupar $O(n)$. Em partições equilibradas, a profundidade é $O(\log n)$; isso descreve o caso médio, não elimina o pior caso.

**II. Falsa.** As trocas do particionamento podem inverter elementos iguais. Por exemplo, considere quatro registros de mesma chave, inicialmente na ordem `a, b, c, d`. Como nenhum é menor que o pivô, a primeira partição troca o primeiro e o último. As chamadas recursivas deixam os registros na ordem `d, a, b, c`, diferente da entrada. O algoritmo é recursivo, mas não é estável.

**III. Verdadeira.** Para entradas sem padrão adverso, o custo médio das partições soma $O(n \log n)$. Isso é uma média: para entradas que geram partições desequilibradas, o número de comparações pode chegar a $O(n^2)$.

**IV. Falsa.** Nenhuma das duas posições é sempre superior. Com uma partição equivalente, usar o primeiro elemento como pivô também pode gerar partições extremas em dados ordenados; o resultado depende da entrada e da estratégia de escolha do pivô.

**Gabarito oficial: A — I e III.** O gabarito do INEP confirma a alternativa; a resolução acima explica por que a afirmação I é verdadeira como limite de pior caso, embora o consumo médio da pilha seja $O(\log n)$.
