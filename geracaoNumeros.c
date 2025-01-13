#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordemAleatoria(int tam)
{
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    FILE *arqRand;
    arqRand = fopen("ListaAleatoria.txt", "w");
    if (arqRand == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
    {
        int numeroRandom = rand() % (tam + 1);
        if (fprintf(arqRand, "%d\n", (int)numeroRandom) < 0)
        {
            printf("Erro ao escrever no arquivo\n");
            fclose(arqRand);
            exit(1);
        }
    }

    fclose(arqRand);
}

void ordemCrescente(int tam)
{
    FILE *arqv;
    arqv = fopen("ListaCrescente.txt", "w");
    if (arqv == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    for (int i = 0; i < tam; i++)
    {
        if (fprintf(arqv, "%d\n", i + 1) < 0)
        {
            printf("Erro ao escrever no arquivo\n");
            fclose(arqv);
            exit(1);
        }
    }
    fclose(arqv);
}

void ordemDecrescente(int tam)
{
    FILE *arqv;
    arqv = fopen("ListaDecrescente.txt", "w");
    if (arqv == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    for (int i = tam; i > 0; i--)
    {
        if (fprintf(arqv, "%d\n", i) < 0)
        {
            printf("Erro ao escrever no arquivo\n");
            fclose(arqv);
            exit(1);
        }
    }
    fclose(arqv);
}