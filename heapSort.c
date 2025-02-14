#include <stdio.h>
#include <time.h>

void criaHeap(int *vetor, int i, int f, long long int *comp, long long int *troca)
{
    int aux = vetor[i], j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            (*comp)++;
            if (vetor[j] < vetor[j+1])
            {
                j++;
            }
        }
        (*comp)++;
        if (aux < vetor[j])
        {
            vetor[i] = vetor[j];
            i = j;
            j = 2*i+1;
            (*troca)++;
        }
        else
        {
            j = f+1;
        }
    }
    vetor[i] = aux;
}

void heapsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;
    int aux;
    for (int i = (n-1)/2; i >= 0; i--)
    {
        criaHeap(vetor, i, n-1, &comp, &troca);
    }
    for (int i = n-1; i > 0; i--)
    {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        troca++;
        criaHeap(vetor, 0, i-1, &comp, &troca);
    }
    end = clock();
    printf("\nHeapsort com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Trocas: %lld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}
