#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void trocar(int &a, int &b)
{
    int temporario = a;
    a = b;
    b = temporario;
}

size_t particionar(vector<int> &valores,
                   size_t inicio,
                   size_t fim)
{
    const int pivo = valores[fim];
    size_t limiteMenores = inicio;

    for (size_t atual = inicio; atual < fim; ++atual)
    {
        if (valores[atual] < pivo)
        {
            trocar(valores[limiteMenores], valores[atual]);
            ++limiteMenores;
        }
    }

    trocar(valores[limiteMenores], valores[fim]);
    return limiteMenores;
}

void quicksortIntervalo(vector<int> &valores,size_t inicio,size_t fim)
{
    if (inicio >= fim)
    {
        return;
    }

    const size_t posicaoPivo = particionar(valores, inicio, fim);

    if (posicaoPivo > inicio)
    {
        quicksortIntervalo(valores, inicio, posicaoPivo - 1);
    }
    if (posicaoPivo < fim)
    {
        quicksortIntervalo(valores, posicaoPivo + 1, fim);
    }
}

void quicksort(vector<int> &valores)
{
    if (valores.size() > 1)
    {
        quicksortIntervalo(valores, 0, valores.size() - 1);
    }
}

void verificarCasosLimite()
{
    std::vector<int> vazio;
    quicksort(vazio);
    assert(vazio.empty());

    vector<int> unitario = {7};
    quicksort(unitario);
    assert((unitario == vector<int>{7}));

    vector<int> repetidos = {3, 1, 3, 2, 1};
    quicksort(repetidos);
    assert((repetidos == vector<int>{1, 1, 2, 3, 3}));
}

int main()
{
    verificarCasosLimite();

    vector<int> dados = {8, 3, 7, 4, 9, 1, 5, 2, 6};

    cout << "Antes: ";
    for (int valor : dados)
    {
        cout << valor << ' ';
    }
    cout << '\n';

    quicksort(dados);

    cout << "Depois: ";
    for (int valor : dados)
    {
        cout << valor << ' ';
    }
    cout << '\n';
}
