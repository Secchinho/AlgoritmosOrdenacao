#include <stdio.h>
#include <time.h>

void particao(int *vetor, int esquerda, int direita, int *i, int *j, int *comp)
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
        }
    }
}

void ordena(int *vetor, int esquerda, int direita, int *comp)
{
    int i, j;
    particao(vetor, esquerda, direita, &i, &j, comp);
    if (i < direita)
    {
        ordena(vetor, i, direita, comp);
    }
    if (j > esquerda)
    {
        ordena(vetor, esquerda, j, comp);
    }
}

void quicksortCentro(int *vetor, int esquerda, int direita)
{
    clock_t start, end;
    start = clock();
    int comp = 0;
    ordena(vetor, esquerda, direita, &comp);
    end = clock();
    printf("\nQuicksort Centro com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", direita, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}