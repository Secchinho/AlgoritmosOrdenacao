#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bolha.h"
#include "bucketSort.h"

void bucketsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();

    long long int comp = 0;
    long long int troca = 0;
    long long int compBolha = 0;
    long long int trocaBolha = 0;
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
    baldes bal[numeroBaldes];

    for (int i = 0; i < numeroBaldes; i++)
    {
        bal[i].topo = 0;        
    }

    for (int i = 0; i < n; i++) {
        comp++;
        int idx = vetor[i] / (maior / numeroBaldes + 1);
        
        if(bal[idx].topo < 10)
        {
            bal[idx].balde[bal[idx].topo++] = vetor[i];
        }
    }

    for (int i = 0; i < numeroBaldes; i++)
    {
        if (bal[i].topo > 0)
        {
            bolha(bal[i].balde, bal[i].topo, &compBolha, &trocaBolha);
        }
    }

    for (int i = 0, j = 0; j < numeroBaldes; j++)
    {
        for (int k = 0; k < bal[j].topo; k++)
        {
            troca++;
            vetor[i++] = bal[j].balde[k];
        }
    }

    comp += compBolha;
    troca += trocaBolha;
    end = clock();
    printf("\nBucketSort com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Troca: %lld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
    
}
