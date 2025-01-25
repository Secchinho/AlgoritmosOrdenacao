#include <stdio.h>
#include <time.h>

void insercaoBinaria(int *vet, int n)
{
    clock_t start, end;
    start = clock();

    long int comp = 0;
    long int troca = 0;
    int aux = 0;
    int dir = 0, esq = 0, meio = 0;

    for(int i = 1; i < n; i++)
    {
        aux = vet[i];
        esq = 0;
        dir = i;

        while(esq < dir)
        {
            comp++;
            meio = (esq + dir) / 2;
            if(vet[meio] <= aux)
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio;
            }
        }

        for(int j = i; j > esq; j--)
        {
            vet[j] = vet[j-1];
            troca++;
        }

        vet[dir] = aux;
    }

    end = clock();
    printf("\nInsercao Binaria com %d elementos\nQuantidade de Comparacoes: %ld\nQuantidade de Trocas: %ld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}