#include <stdio.h>
#include <time.h>

void intercalar(int *vetor, int inicio, int fim, int meio, long long int *comp, long long int *troca)
{
    int i = inicio, j = meio + 1, k = 0, tmp[fim + 1];
    while (i <= meio || j <= fim)
    {
        (*comp)++;
        if (i == meio + 1 || (vetor[j] < vetor[i] && j != fim + 1))
        {
            tmp[k] = vetor[j];
            j++;
        }
        else
        {
            tmp[k] = vetor[i];
            i++;
        }
        k++;
    }
    for (i = inicio; i <= fim; i++)
    {
        if(vetor[i] != tmp[i - inicio])
        {
            (*troca)++;
        }
        vetor[i] = tmp[i - inicio];
    }
}

void merge(int *vetor, int inicio, int fim, long long int *comp, long long int *troca)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        merge(vetor, inicio, meio, comp, troca);
        merge(vetor, meio + 1, fim, comp, troca);
        intercalar(vetor, inicio, fim, meio, comp, troca);
    }
}

void mergesort(int *vetor, int inicio, int fim)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;

    merge(vetor, inicio, fim, &comp, &troca);
    end = clock();
    printf("\nMergesort com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Trocas: %lld\nTempo de execucao: %f segundos\n\n", fim, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}