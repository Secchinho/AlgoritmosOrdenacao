#include <stdio.h>
#include <time.h>

void shellsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    
    long int troca = 0;
    long int comp = 0;
    int i, j, h = 1, aux;
    while (h < n)
    {
        h = 3 * h + 1;
    }
    while (h > 1)
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            aux = vetor[i];
            j = i - h;
            while (j >= 0 && aux < vetor[j])
            {
                comp++;
                vetor[j+h] = vetor[j];
                troca++;
                j -= h;
            }

            if (j >= 0) {
                comp++;
            }

            vetor[j+h] = aux;

            if (j + h != i) {
                troca++;
            }
        }
    }
    end = clock();
    printf("\nShellsort com %d elementos\nQuantidade de Comparacoes: %ld\nQuantidade de Trocas: %ld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}