#include <stdio.h>
#include <time.h>

void quicksortIni(int *vetor, int esq, int dir, long long int *comp, long long int *troca) {
    if (esq < dir) {
        int pivo = vetor[esq];
        int i = esq + 1;
        int j = dir;
        
        while (i <= j) 
        {
            while (i <= j && vetor[i] <= pivo) 
            {
                (*comp)++;
                i++;
            }

            while (i <= j && vetor[j] > pivo) 
            {
                (*comp)++;
                j--; 
            }

            if (i < j) 
            {
                (*comp)++;
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                (*troca)++;
                i++;
                j--;
            }
        }
        
        vetor[esq] = vetor[j];
        vetor[j] = pivo;
        (*troca)++;
        
        quicksortIni(vetor, esq, j - 1, comp, troca);
        quicksortIni(vetor, j + 1, dir, comp, troca);
    }
}

void contadorQuickSortIni(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;

    quicksortIni(vetor, esq, dir, &comp, &troca);

    end = clock();
    printf("\nQuicksort Inicio com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Troca: %lld\nTempo de execucao: %f segundos\n\n", dir, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}
