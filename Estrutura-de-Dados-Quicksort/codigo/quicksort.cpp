// quicksort.cpp
// Implementação do Quicksort com particionamento de Lomuto.
//


#include <iostream>
#include <vector>

// Troca o conteúdo de duas posições do vetor
void trocar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Particiona o vetor em torno do pivô (último elemento do intervalo).
// Retorna a posição final do pivô, já ordenada.
int particionar(vector<int> &v, int inicio, int fim)
{
    int pivo = v[fim];   // escolha do pivô: último elemento
    int i = inicio - 1;  // limite da região "menor que o pivô"

    for (int j = inicio; j < fim; j++)
    {
        if (v[j] < pivo)
        {
            i++;
            trocar(v[i], v[j]);
        }
    }

    // Move o pivô para sua posição final (entre as duas regiões)
    trocar(v[i + 1], v[fim]);
    return i + 1;
}

// Ordena recursivamente v[inicio..fim]
void quicksort(vector<int> &v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int posPivo = particionar(v, inicio, fim);

        quicksort(v, inicio, posPivo - 1); // ordena a partição da esquerda
        quicksort(v, posPivo + 1, fim);    // ordena a partição da direita
    }
}

int main()
{
    vector<int> dados = {8, 3, 7, 4, 9, 1, 5, 2, 6};

    cout << "Antes: ";
    for (int n : dados) cout << n << " ";
    cout << "\n";

    quicksort(dados, 0, dados.size() - 1);

    cout << "Depois: ";
    for (int n : dados) cout << n << " ";
    cout << "\n";

    return 0;
}
