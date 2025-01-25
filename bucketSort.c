#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bolha.h"
#include "bucketSort.h"

void bucketsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();

    int comp = 0;
    int maior=0;
    for (int i = 0; i < n; i++)
    {
        comp++;
        if (vetor[i] > maior)
        {
            maior  = vetor[i];
        }
    }
    int numeroBaldes = (maior/10)+1;
    baldes *b = (baldes *)malloc(numeroBaldes * sizeof(baldes));
    if (b == NULL) {
        printf("Erro ao alocar memória para os baldes!\n");
        exit(1);
    }
    for (int i = 0; i < numeroBaldes; i++)
    {
        b[i].topo = 0;
        b[i].balde = (int *)malloc(24 * sizeof(int));
        if (b[i].balde == NULL) {
            printf("Erro ao alocar memória para o balde %d!\n", i);
            exit(1);
        }
    }
    for (int i = 0; i < n; i++) {
        comp++;
        int idx = vetor[i] / 10;
        b[idx].balde[b[idx].topo++] = vetor[i];
    }
    for (int i = 0; i < numeroBaldes; i++)
    {
        if (b[i].topo > 0)
        {
            long int compBolha = 0, trocaBolha = 0;
            bolha(b[i].balde, b[i].topo, &compBolha, &trocaBolha);
        }
    }
    for (int i = 0, j = 0; j < numeroBaldes; j++)
    {
        for (int k = 0; k < b[j].topo; k++)
        {
            comp++;
            vetor[i++] = b[j].balde[k];
        }
    }
    for (int i = 0; i < numeroBaldes; i++) 
    {
        free(b[i].balde);
    }
    free(b);
    end = clock();
    printf("\nBucketSort com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
    
}