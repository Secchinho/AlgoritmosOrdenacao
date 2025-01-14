#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordemAleatoria(int tam)
{
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    FILE *arqRand;
    if(tam == 1000)
    {
        arqRand = fopen("ListaAleatoria1000.txt", "w");
        if (arqRand == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }else if(tam == 10000)
    {
        arqRand = fopen("ListaAleatoria10000.txt", "w");
        if (arqRand == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else if(tam == 100000)
    {
        arqRand = fopen("ListaAleatoria100000.txt", "w");
        if (arqRand == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else
    {
        printf("\nTamanho inválido!\n");
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
    FILE *arqCresc;
    if(tam == 1000)
    {
        arqCresc = fopen("ListaCrescente1000.txt", "w");
        if (arqCresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }else if(tam == 10000)
    {
        arqCresc = fopen("ListaCrescente10000.txt", "w");
        if (arqCresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else if(tam == 100000)
    {
        arqCresc = fopen("ListaCrescente100000.txt", "w");
        if (arqCresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else
    {
        printf("\nTamanho inválido!\n");
    }

    for (int i = 0; i < tam; i++)
    {
        if (fprintf(arqCresc, "%d\n", i + 1) < 0)
        {
            printf("Erro ao escrever no arquivo\n");
            fclose(arqCresc);
            exit(1);
        }
    }
    fclose(arqCresc);
}

void ordemDecrescente(int tam)
{
    FILE *arqDecresc;
    if(tam == 1000)
    {
        arqDecresc = fopen("ListaDecrescente1000.txt", "w");
        if (arqDecresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }else if(tam == 10000)
    {
        arqDecresc = fopen("ListaDecrescente10000.txt", "w");
        if (arqDecresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else if(tam == 100000)
    {
        arqDecresc = fopen("ListaDecrescente100000.txt", "w");
        if (arqDecresc == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
    }
    else
    {
        printf("\nTamanho inválido!\n");
    }
    for (int i = tam; i > 0; i--)
    {
        if (fprintf(arqDecresc, "%d\n", i) < 0)
        {
            printf("Erro ao escrever no arquivo\n");
            fclose(arqDecresc);
            exit(1);
        }
    }
    fclose(arqDecresc);
}
