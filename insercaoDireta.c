#include <stdio.h>
#include <time.h>

void insercaoDireta(int *vetor, int n){
    clock_t start, end;
    start = clock();
    long int comp = 0;
    long int troca = 0;
    int i, auxiliar, j;
    for(i = 1; i < n; i++)
    {
        auxiliar = vetor[i];
        j = i-1;
        while(j >= 0)
        {
            comp++;
            if(vetor[j] > auxiliar)
            {
                vetor[j+1] = vetor[j];
                j--;
                troca++;
            }
            else
            {
                break;
            }
        }
        if(j != i-1)
        {
            vetor[j+1] = auxiliar;
        }
    }
    end = clock();
    printf("\nInsercao Direta com %d elementos\nQuantidade de Comparacoes: %ld\nQuantidade de Trocas: %ld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}