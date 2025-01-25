#include <stdio.h>
#include <time.h>

void selecaoDireta(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int comp = 0;
    int menor = 0;
    int aux = 0;
    for(int i = 0; i <= (n - 1); i++)
    {
        menor = i;
        for(int j = (i+1); j < n; j++)
        {
            comp++;
            if(vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        if(i != menor)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
    end = clock();
    printf("\nSelecao Direta com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}