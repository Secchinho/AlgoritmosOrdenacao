#include <stdio.h>
#include <time.h>

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

        quicksortMediana(vetor, esq, j - 1, comp);
        quicksortMediana(vetor, j + 1, dir, comp);
    }
}

void contadorQuickSortMediana(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    quicksortMediana(vetor, esq, dir, &comp);

    end = clock();
    printf("\nQuickSort Mediana com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", dir, comp, ((double)(end - start)) / CLOCKS_PER_SEC);

}