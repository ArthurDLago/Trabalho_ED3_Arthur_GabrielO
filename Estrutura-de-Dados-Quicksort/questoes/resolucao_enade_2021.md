# Resolução de Questão: ENADE 2021 (Ciência da Computação)

## Enunciado da Questão
> **"Existe um grande número de implementações para algoritmos de ordenação. Um dos fatores a serem considerados, por exemplo, é o número máximo e médio de comparações..."**
> 
> *Nota: A questão apresenta o código clássico de partição do algoritmo **Quicksort** (geralmente estruturado com índices de início `lo` e fim `hi`, utilizando o primeiro ou o último elemento como pivô).*
> 
> Com relação ao algoritmo apresentado, avalie as afirmações a seguir:
> 
> * **I.** O algoritmo precisa de um espaço adicional $O(n)$ para a pilha de recursão.
> * **II.** O algoritmo apresentado é um algoritmo de ordenação recursivo e estável.
> * **III.** O algoritmo precisa, em média, de $O(n \log n)$ comparações para ordenar $n$ itens.
> * **IV.** O uso do primeiro elemento do vetor como "pivot" é mais eficiente que usar o último.

---

## Análise e Justificativa das Afirmativas

### Afirmativa I: Incorreta ($O(\log n)$ no caso médio / $O(n)$ no pior caso)
* **Explicação:** Embora o Quicksort seja considerado um algoritmo *in-place* (pois realiza a ordenação trocando elementos dentro do próprio vetor sem alocar estruturas auxiliares gigantescas de tamanho $O(n)$), ele consome espaço na memória devido à **pilha de chamadas recursivas**. 
* No **caso médio / melhor caso**, a árvore de recursão possui altura $O(\log n)$, exigindo $O(\log n)$ de espaço auxiliar. O consumo de $O(n)$ ocorre exclusivamente no **pior caso** (quando o vetor está ordenado ou reversamente ordenado e escolhemos mal o pivô). A afirmativa erra ao generalizar o pior caso como o comportamento padrão/necessário de espaço.

### Afirmativa II: Incorreta (Não é estável)
* **Explicação:** O Quicksort padrão utilizando particionamento tradicional (como Lomuto ou Hoare) **não é um algoritmo estável**. Uma ordenação é estável quando elementos com chaves iguais mantêm a mesma ordem relativa original após a ordenação. Durante as trocas de particionamento do Quicksort, elementos idênticos podem facilmente saltar uns sobre os outros, quebrando a estabilidade.

### Afirmativa III: Correta ($O(n \log n)$ no caso médio)
* **Explicação:** Esta é a propriedade fundamental do Quicksort. Em média, a partição divide o vetor em duas partes aproximadamente iguais a cada nível de recursão. O custo para particionar um vetor de tamanho $k$ é linear $O(k)$, e como a árvore de divisão possui profundidade média de $\log_2 n$, o número total de comparações no caso médio é da ordem de $O(n \log n)$.

### Afirmativa IV: Incorreta (A escolha do pivô depende da distribuição)
* **Explicação:** Utilizar o primeiro elemento (ou o último) como pivô fixo é, na verdade, uma abordagem **ineficiente** caso a entrada do algoritmo já esteja ordenada ou quase ordenada, pois resulta diretamente no pior caso de complexidade $O(n^2)$. Estratégias mais eficientes incluem a escolha de um pivô aleatório ou o uso da técnica da "mediana de três".

---

## Conclusão e Gabarito

Portanto, apenas a afirmativa **III** está correta. 

* **Gabarito oficial correspondente:** **Apenas a afirmativa III é verdadeira.**