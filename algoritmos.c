#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "algoritmos.h"

void bolha(int *vetor, int n){
    clock_t start, end;
    start = clock();
    int comp = 0;
    int i, j = 0, aux;
    for ( i = n-1; i > 0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            comp++;
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    end = clock();
    printf("\nBolha com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void bolhaComParada(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int comp = 0;
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
            }
        }
        ultimoIndex = novoUltimoIndex;
    }
    end = clock();
    printf("\nBolha(com parada) com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void insercaoDireta(int *vetor, int n){
    clock_t start, end;
    start = clock();
    int comp = 0;
    int i, auxiliar, j;
    for(i=1; i<n; i++)
    {
        auxiliar = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>auxiliar)
        {
            comp++;
            vetor[j+1] = vetor[j];
            j--;
        }
        if(j != i-1)
        {
            vetor[j+1] = auxiliar;
        }
    }
    end = clock();
    printf("\nInsercao Direta com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void insercaoBinaria(int *vet, int n)
{
    clock_t start, end;
    start = clock();

    int comp = 0;
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
        }

        vet[dir] = aux;
    }

    end = clock();
    printf("\nInsercao Binaria com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);

}

void shellsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    
    int comp = 0;
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
                j -= h;
            }

            if (j >= 0) {
                comp++;
            }
            vetor[j+h] = aux;
        }
    }
    end = clock();
    printf("\nShellsort com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void criaHeap(int *vetor, int i, int f, int *comp)
{
    int aux = vetor[i], j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            (*comp)++;
            if (vetor[j] < vetor[j+1])
            {
                j++;
            }
        }
        (*comp)++;
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
    int comp = 0;
    int aux;
    for (int i = (n-1)/2; i >= 0; i--)
    {
        criaHeap(vetor, i, n-1, &comp);
    }
    for (int i = n-1; i > 0; i--)
    {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1, &comp);
    }
    end = clock();
    printf("\nHeapsort com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

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
    printf("\nSelecao Direta com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void particao(int *vetor, int esquerda, int direita, int *i, int *j, int *comp)
{
    *i = esquerda; 
    *j = direita; 
    int aux, pivo = vetor[(esquerda+direita)/2];
    while (*i <= *j)
    {
        while (vetor[*i] < pivo && *i < direita)
        {
            (*comp)++;
            (*i)++;
        }
        (*comp)++;
        while (vetor[*j] > pivo && *j > esquerda)
        {
            (*comp)++;
            (*j)--;
        }
        (*comp)++;
        if (*i <= *j)
        {
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void ordena(int *vetor, int esquerda, int direita, int *comp)
{
    int i, j;
    particao(vetor, esquerda, direita, &i, &j, comp);
    if (i < direita)
    {
        ordena(vetor, i, direita, comp);
    }
    if (j > esquerda)
    {
        ordena(vetor, esquerda, j, comp);
    }
}

void quicksortCentro(int *vetor, int esquerda, int direita)
{
    clock_t start, end;
    start = clock();
    int comp = 0;
    ordena(vetor, esquerda, direita, &comp);
    end = clock();
    printf("\nQuicksort Centro com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", direita+1, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void merge(int *vetor, int inicio, int fim, int *comp)
{
    if (inicio < fim)
    {
        int meio = (inicio+fim)/2;
        merge(vetor, inicio, meio, comp);
        merge(vetor, meio+1, fim, comp);
        intercalar(vetor, inicio, fim, meio, comp);
    }
}

void mergesort(int *vetor, int inicio, int fim)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    merge(vetor, inicio, fim, &comp);
    end = clock();
    printf("\nMergesort com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", fim+1, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}

void intercalar(int *vetor, int inicio, int fim, int meio, int *comp)
{
    int i=inicio, j=meio+1, k=0, tmp[fim+1];
    while (i <= meio || j <= fim)
    {
        if (i == meio+1 || (vetor[j] < vetor[i] && j != fim+1))
        {
            (*comp)++;
            tmp[k] = vetor[j];
            j++;
        }
        else
        {
            if(i <= meio)
            {
                (*comp)++;
            }
            tmp[k] = vetor[i];
            i++;
        }
        k++;
    }
    for (i = inicio; i <= fim; i++)
    {
        vetor[i] = tmp[i-inicio];
    }
}

void quicksortIni(int *vetor, int esq, int dir, int *comp)
{
    if(esq < dir)
    {
        int pivo = vetor[esq];
        int i = esq + 1;
        int j = dir;

        while(i <= j)
        {
            while(i <= j && vetor[i] < pivo)
            {
                comp++;
                i++;
            }
            comp++;

            while(i <= j && vetor[j] > pivo)
            {
                comp++;
                j--;
            }
            comp++;

            if(i < j)
            {
                comp++;
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
        vetor[esq] = vetor[j];
        vetor[j] = pivo;

        quicksortIni(vetor, esq, j - 1);
        quicksortIni(vetor, i + 1; dir);
    }
}

void contadorQuickSortIni(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    quicksortIni(vetor, esq, dir, &comp)

    end = clock();
    printf("\nQuicksort Inicio com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", dir+1, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}


int particionarComMediana(int *vetor, int esq, int dir, int *comp) {
    int meio = esq + (dir - esq) / 2;

    if (vetor[esq] > vetor[meio]) {
        int temp = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = temp;
        (*comp)++;
    }
    if (vetor[esq] > vetor[dir]) {
        int temp = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = temp;
        (*comp)++;
    }
    if (vetor[meio] > vetor[dir]) {
        int temp = vetor[meio];
        vetor[meio] = vetor[dir];
        vetor[dir] = temp;
        (*comp)++;
    }

    int temp = vetor[esq];
    vetor[esq] = vetor[meio];
    vetor[meio] = temp;

    return vetor[esq];
}

void quicksortMediana(int *vetor, int esq, int dir, int *comp) {
    if (esq < dir) {
        int pivo = particionarComMediana(vetor, esq, dir, comp);
        int i = esq + 1;
        int j = dir;

        while (i <= j) {
            while (i <= j && vetor[i] <= pivo) {
                i++;
                (*comp)++;
            }
            while (i <= j && vetor[j] > pivo) {
                j--;
                (*comp)++;
            }
            if (i < j) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }

        vetor[esq] = vetor[j];
        vetor[j] = pivo;

        quicksortMediana(vetor, esq, j - 1);
        quicksortMediana(vetor, j + 1, dir);
    }
}

void contadorQuickSortMediana(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    quicksortMediana(vetor, esq, dir, &comp);

    end = clock();
    printf("\nQuickSort Mediana com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);

}

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
        b[i].balde = (int *)malloc(10 * sizeof(int));
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
            bolha(b[i].balde, b[i].topo);
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
    printf("\nBucketSort com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
    
}

int maiorNumero(int *vetor, int n, int *comp)
{
    int maior = vetor[0];

    for(int i = 1; i < n; i++)
    {
        (*comp)++;
        if(maior < vetor[i])
        {
            maior = vetor[i];
        }
    }

    return maior;
}

void contagem(int *vetor, int n, int exp, int *comp)
{
    int saida[n];
    int contagem[10] = {0};

    for(int i = 0; i < n; i++)
    {
        (*comp)++;
        contagem[(vetor[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        contagem[i] = contagem[i - 1];
    }

    for(int i = 0; i < n; i++)
    {
        saida[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
    {
        vetor[i] = saida[i];
    }
}

void radixsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    int maior = maiorNumero(vetor, n, &comp);

    for(int i = 1; max / i > 0; i *= 10)
    {
        contagem(vetor, n, i, &comp);
    }

    end = clock();
    printf("\nRadixsort com %d elementos\nQuantidade de Comparações: %d\nTempo de execucao: %f segundos\n\n", n, comp, ((double)(end - start)) / CLOCKS_PER_SEC);

}
