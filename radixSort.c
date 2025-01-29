#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int maiorNumero(int *vetor, int n, long long int *comp)
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

void contagem(int *vetor, int n, int exp, long long int *comp, long long int *troca)
{
    int *saida = (int*)malloc(n * sizeof(int));
    if (saida == NULL) {
        printf("Erro ao alocar memória para saída!\n");
        exit(1);
    }
    int contagem[10] = {0};

    for(int i = 0; i < n; i++)
    {
        contagem[(vetor[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        contagem[i] += contagem[i - 1];
    }

    for(int i = n-1; i >= 0; i--)
    {
        saida[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
    {
        if(vetor[i] != saida[i])
        {
            (*troca)++; 
        }
        vetor[i] = saida[i];
    }
    free(saida);
}

void radixsort(int *vetor, int n)
{
    clock_t start, end;
    start = clock();
    long long int comp = 0;
    long long int troca = 0;

    int maior = maiorNumero(vetor, n, &comp);

    for(int exp = 1; maior / exp > 0; exp *= 10)
    {
        contagem(vetor, n, exp, &comp, &troca);
    }

    end = clock();
    printf("\nRadixsort com %d elementos\nQuantidade de Comparacoes: %lld\nQuantidade de Trocas: %lld\nTempo de execucao: %f segundos\n\n", n, comp, troca, ((double)(end - start)) / CLOCKS_PER_SEC);
}