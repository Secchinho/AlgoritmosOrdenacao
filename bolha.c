#include <stdio.h>
#include <time.h>

void bolha(int *vetor, int n, long int *comp, long int *troca)
{
    int i, j = 0, aux;
    for ( i = n-1; i > 0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            (*comp)++;
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                (*troca)++;
            }
        }
    }
}

void chamaBolha(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    long int comp = 0;
    long int troca = 0;

    bolha(vetor, n, &comp, &troca);

    end = clock();
    printf("\nBolha com %d elementos\nQuantidade de Comparacoes: %ld\nQuantidade de Trocas: %ld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}