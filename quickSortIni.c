#include <stdio.h>
#include <time.h>

void quicksortIni(int *vetor, int esq, int dir, int *comp) {
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
                i++;
                j--;
            }
        }
        
        vetor[esq] = vetor[j];
        vetor[j] = pivo;
        
        quicksortIni(vetor, esq, j - 1, comp);
        quicksortIni(vetor, j + 1, dir, comp);
    }
}


void contadorQuickSortIni(int *vetor, int esq, int dir)
{
    clock_t start, end;
    start = clock();
    int comp = 0;

    quicksortIni(vetor, esq, dir, &comp);

    end = clock();
    printf("\nQuicksort Inicio com %d elementos\nQuantidade de Comparacoes: %d\nTempo de execucao: %f segundos\n\n", dir+1, comp, ((double)(end - start)) / CLOCKS_PER_SEC);
}