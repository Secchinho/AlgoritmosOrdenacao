#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    end = clock();
    printf("\n\n  %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

void bolhaComParada(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int aux = 0;
    int ultimoIndex = n - 1;
    bool trocou = true;

    while (trocou)
    {
        trocou = false;
        int novoUltimoIndex = 0;
        for (int j = 0; j < ultimoIndex; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = true;
                novoUltimoIndex = j;
            }
        }
        ultimoIndex = novoUltimoIndex;
    }
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

void insercaoBinaria(int *vet, int n)
{
    clock_t start, end;
    start = clock();

    int aux = 0;
    int dir = 0, esq = 0, meio = 0;

    for(int i = 1; i < n; i++)
    {
        aux = vet[i];
        esq = 0;
        dir = i;

        while(esq < dir)
        {
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
        }

        vet[dir] = aux;
    }

    end = clock();
    printf("\n\n  %f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);

}

void shellsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
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
                vetor[j+h] = vetor[j];
                j -= h;
            }
            vetor[j+h] = aux;
        }
    }
    end = clock();
    printf("\n  %f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

void criaHeap(int *vetor, int i, int f)
{
    int aux = vetor[i], j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            if (vetor[j] < vetor[j+1])
            {
                j++;
            }
        }
        if (aux < vetor[j])
        {
            vetor[i] = vetor[j];
            i = j;
            j = 2*i+1;
        }
        else
        {
            j = f+1;
        }
    }
    vetor[i] = aux;
}

void heapsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int aux;
    for (int i = (n-1)/2; i >= 0; i--)
    {
        criaHeap(vetor, i, n-1);
    }
    for (int i = n-1; i > 0; i--)
    {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1);
    }
    end = clock();
    printf("\n  %f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

void selecaoDireta(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int menor = 0;
    int aux = 0;
    for(int i = 0; i <= (n - 1); i++)
    {
        menor = i;
        for(int j = (i+1); j < n; j++)
        {
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
    printf("\n  %f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}
