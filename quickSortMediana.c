#include <stdio.h>
#include <time.h>

int particionarComMediana(int *vetor, int esq, int dir, long long int *comp, long long int *troca) {
    int meio = esq + (dir - esq) / 2;

    if (vetor[esq] > vetor[meio]) {
        int temp = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = temp;
        (*comp)++;
        (*troca)++;
    }
    if (vetor[esq] > vetor[dir]) {
        int temp = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = temp;
        (*comp)++;
        (*troca)++;
    }
    if (vetor[meio] > vetor[dir]) {
        int temp = vetor[meio];
        vetor[meio] = vetor[dir];
        vetor[dir] = temp;
        (*comp)++;
        (*troca)++;
    }

    int temp = vetor[esq];
    vetor[esq] = vetor[meio];
    vetor[meio] = temp;
    (*troca)++;

    return vetor[esq];
}

void quicksortMediana(int *vetor, int esq, int dir, long long int *comp, long long int *troca) {
    if (esq < dir) {
        int pivo = particionarComMediana(vetor, esq, dir, comp, troca);
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
                (*troca)++;
            }
        }

        vetor[esq] = vetor[j];
        vetor[j] = pivo;
        (*troca)++;

        quicksortMediana(vetor, esq, j - 1, comp, troca);
        quicksortMediana(vetor, j + 1, dir, comp, troca);
    }
}

void contadorQuickSortMediana(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;

    quicksortMediana(vetor, esq, dir, &comp, &troca);

    end = clock();
    printf("\nQuickSort Mediana com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Elementos: %lld\nTempo de execucao: %f segundos\n\n", dir, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);

}