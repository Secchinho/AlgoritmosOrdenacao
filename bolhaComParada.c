#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void bolhaComParada(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    long int comp = 0;
    long int troca = 0;
    int aux = 0;
    int ultimoIndex = n - 1;
    bool trocou = true;

    while (trocou)
    {
        trocou = false;
        int novoUltimoIndex = 0;
        for (int j = 0; j < ultimoIndex; j++)
        {
            comp++;
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = true;
                novoUltimoIndex = j;
                troca++;
            }
        }
        ultimoIndex = novoUltimoIndex;
    }
    end = clock();
    printf("\nBolha(com parada) com %d elementos\nQuantidade de Comparacoes: %ld\nQuantidade de Trocas: %ld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}
