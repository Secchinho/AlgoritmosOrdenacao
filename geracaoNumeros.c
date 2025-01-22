#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void ordemAleatoria(int tam)
{
    srand(time(NULL)); // Inicializa a semente do gerador de numeros aleatórios

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
        printf("\nTamanho invalido!\n");
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
        printf("\nTamanho invalido!\n");
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
        printf("\nTamanho invalido!\n");
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

int* lerArquivo(int n) {
    int x = 0, i = 0;
    printf("----------MENU----------\nQue tipo de lista voce deseja ordenar:\n");
    printf("1 - Lista Aleatoria\n");
    printf("2 - Lista Crescente\n");
    printf("3 - Lista Decrescente\n");
    printf("------------------------\n");
    printf("Opcao: ");
    scanf("%d", &x);

    int* vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    FILE* arqv = NULL;
    char nomeArquivo[30];
    char numstr[6];

    sprintf(numstr, "%d", n);

    if (x == 1) 
    {
        strcpy(nomeArquivo, "ListaAleatoria");
    } 
    else if (x == 2) 
    {
        strcpy(nomeArquivo, "ListaCrescente");
    } 
    else if (x == 3)
    {
        strcpy(nomeArquivo, "ListaDecrescente");
    }
    else 
    {
        printf("Opcao invalida!\n");
        free(vetor);
        exit(1);
    }

    strcat(nomeArquivo, numstr);
    strcat(nomeArquivo, ".txt");

    arqv = fopen(nomeArquivo, "r");
    if (arqv == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        free(vetor);
        exit(1);
    }

    while (i < n && fscanf(arqv, "%d", &vetor[i]) == 1) {
        i++;
    }
    fclose(arqv);

    return vetor;
}

void saida(int *vetor, int n, char str[])
{
    char numstr[6], nomeArquivo[50] = "Saida";
    strcat(nomeArquivo, str);
    sprintf(numstr, "%d", n);
    strcat(nomeArquivo, numstr);
    strcat(nomeArquivo, ".txt");
    FILE *arqSaida = fopen(nomeArquivo, "w");
    if (arqSaida == NULL) {
        printf("Erro ao criar o arquivo: %s\n", nomeArquivo);
        exit(1);
    }
    for (int i = 0; i < n; i++) 
    {
        if (fprintf(arqSaida, "%d\n", vetor[i]) < 0) 
        {
            printf("Erro ao escrever no arquivo: %s\n", nomeArquivo);
            fclose(arqSaida);
            exit(1);
        }
    }
    fclose(arqSaida);
}
