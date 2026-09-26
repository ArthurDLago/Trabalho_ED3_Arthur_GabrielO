# Resolução de Questão: ENADE 2005 (Ciência da Computação)

## Enunciado da Questão (Referente ao Quicksort)

> **Questão 13 (ENADE 2005)** - Julgue os itens a seguir relativos a algoritmos de ordenação, considerando em especial a afirmativa relacionada ao **Quicksort**:
>
> * **III) No algoritmo quicksort, a escolha do elemento pivô influencia o desempenho do algoritmo.**

---

## Análise e Justificativa da Afirmativa

### Afirmativa III: Correta

* **Explicação do Conceito:** O *Quicksort* é um algoritmo de ordenação por divisão e conquista cujo desempenho de tempo depende criticamente da forma como o vetor é particionado em cada etapa recursiva. 
* O particionamento é guiado pela escolha do **elemento pivô**. 
  * Se o pivô escolhido for sempre o elemento mediano (ou próximo disso), o vetor é dividido em metades quase iguais, resultando na excelente complexidade de tempo de caso médio/melhor caso de $O(n \log n)$.
  * Por outro lado, se a escolha do pivô for desfavorável (por exemplo, selecionar sistematicamente o menor ou o maior elemento de um vetor que já se encontra ordenado ou inversamente ordenado), o particionamento gera subproblemas de tamanhos $1$ e $n-1$. Isso degrada o desempenho do algoritmo para o seu **pior caso**, cuja complexidade de tempo salta para $O(n^2)$.
* **Conclusão:** Portanto, a escolha do pivô afeta diretamente a eficiência operacional e a profundidade da árvore de recursão do Quicksort.

---

## Conclusão e Gabarito

* **Status da Afirmativa:** Verdadeira (Correta).
* **Impacto Prático:** Devido a essa forte dependência, técnicas avançadas como a *mediana de três* ou a *escolha aleatória de pivô* são amplamente adotadas para evitar o pior caso em cenários reais.