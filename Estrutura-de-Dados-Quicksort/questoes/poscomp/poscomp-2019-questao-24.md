# POSCOMP — 2019

## Questão
Número: 24 (área: Algoritmos e Estrutura de Dados)

## Conteúdo
Recursividade — propriedade que caracteriza um procedimento recursivo, exemplificada com o Quicksort.

## Enunciado
Um procedimento recursivo é aquele que contém em sua descrição:

(A) Uma prova de indução matemática.
(B) Duas ou mais chamadas a procedimentos externos.
(C) Uma ou mais chamadas a si mesmo.
(D) Somente chamadas externas.
(E) Uma ou mais chamadas a procedimentos internos.

## Fonte
Exame POSCOMP 2019, aplicado pela Sociedade Brasileira de Computação (SBC). Gabarito oficial: *Gabarito-2019.pdf*, disponível em sbc.org.br — questão 24, componente "Algoritmos e Estrutura de Dados".

## Gabarito
**(C) Uma ou mais chamadas a si mesmo.**

## Resolução comentada
A característica que define um procedimento recursivo é chamar a si mesmo pelo menos uma vez durante sua execução. O **Quicksort** é um exemplo clássico: a função `quicksort()` particiona o vetor e então se chama novamente para ordenar cada uma das duas partições geradas — exatamente como implementado em [`codigo/quicksort/quicksort.cpp`](../../codigo/quicksort/quicksort.cpp). A recursão termina quando a partição tem 0 ou 1 elemento (caso base).

## Conceito cobrado
Definição de recursividade; ligação direta com a estrutura do Quicksort (chamadas recursivas após o particionamento).
