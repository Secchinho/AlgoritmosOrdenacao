#include <stdio.h>
#include <time.h>

void particao(int *vetor, int esquerda, int direita, int *i, int *j, long long int *comp, long long int *troca)
{
    *i = esquerda; 
    *j = direita; 
    int aux, pivo = vetor[(esquerda+direita)/2];
    while (*i <= *j)
    {
        while (vetor[*i] < pivo && *i < direita)
        {
            (*comp)++;
            (*i)++;
        }
        (*comp)++;
        while (vetor[*j] > pivo && *j > esquerda)
        {
            (*comp)++;
            (*j)--;
        }
        (*comp)++;
        if (*i <= *j)
        {
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
            (*troca)++;
        }
    }
}

void quickSortCentro(int *vetor, int esquerda, int direita, long long int *comp, long long int *troca)
{
    int i, j;
    particao(vetor, esquerda, direita, &i, &j, comp, troca);
    if (i < direita)
    {
        ordena(vetor, i, direita, comp, troca);
    }
    if (j > esquerda)
    {
        ordena(vetor, esquerda, j, comp, troca);
    }
}

void ContadorQuickSortCentro(int *vetor, int esquerda, int direita)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;
    ordena(vetor, esquerda, direita, &comp, &troca);
    end = clock();
    printf("\nQuicksort Centro com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Trocas: %lld\nTempo de execucao: %f segundos\n\n", direita, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}
