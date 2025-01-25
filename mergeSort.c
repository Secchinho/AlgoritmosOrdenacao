#include <stdio.h>
#include <time.h>

void intercalar(int *vetor, int inicio, int fim, int meio, int *comp)
{
    int i=inicio, j=meio+1, k=0, tmp[fim+1];
    while (i <= meio || j <= fim)
    {
        if (i == meio+1 || (vetor[j] < vetor[i] && j != fim+1))
        {
            (*comp)++;
            tmp[k] = vetor[j];
            j++;
        }
        else
        {
            if(i <= meio)
            {
                (*comp)++;
            }
            tmp[k] = vetor[i];
            i++;
        }
        k++;
    }
    for (i = inicio; i <= fim; i++)
    {
        vetor[i] = tmp[i-inicio];
    }
}

void merge(int *vetor, int inicio, int fim, int *comp)
{
    if (inicio < fim)
    {
        int meio = (inicio+fim)/2;
        merge(vetor, inicio, meio, comp);
        merge(vetor, meio+1, fim, comp);
        intercalar(vetor, inicio, fim, meio, comp);
    }
}

void mergesort(int *vetor, int inicio, int fim)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    merge(vetor, inicio, fim, &comp);
    end = clock();
    printf("\nMergesort com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", fim, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}