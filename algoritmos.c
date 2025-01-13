#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bolha(int *vetor, int n){
    clock_t start, end;
    start = clock();
    int i, j = 0, aux;
    for ( i = n-1; i > 0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    criarArquivo(n);
    end = clock();
    printf("\n\n  %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

void insercaoDireta(int *vetor, int n){
    clock_t start, end;
    start = clock();
    int i, auxiliar, j;
    for(i=1; i<n; i++)
    {
        auxiliar = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>auxiliar)
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        if(j != i-1)
        {
            vetor[j+1] = auxiliar;
        }
    }
    end = clock();
    printf("\n\n  %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}
