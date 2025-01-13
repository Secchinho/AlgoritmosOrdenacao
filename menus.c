#include <stdio.h>
#include "geracaoNumeros.h"
#include "algoritmos.h"

void menuNumeros(int tam)
{
    int op = 0;
    printf("----------MENU----------\n");
    printf("1 - Ordem Aleatória\n");
    printf("2 - Ordem Crescente\n");
    printf("3 - Ordem Decrescente\n");
    printf("------------------------\n");
    printf("Opção: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        // Função geração aleatória
        ordemAleatoria(tam);
        break;
    case 2:
        // Função geração crescente
        ordemCrescente(tam);
        break;
    case 3:
        // Função geração decrescente
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }
}

void menuTamEntrada()
{
    int op = 0;
    int tam = 0;
    printf("----------MENU----------\n");
    printf("1 - Tamanho 1000\n");
    printf("2 - Tamanho 10000\n");
    printf("3 - Tamanho 100000\n");
    printf("------------------------\n");
    printf("Opção: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        // Tamanho 1000
        tam = 1000;
        break;
    case 2:
        // Tamanho 10000
        tam = 10000;
        break;
    case 3:
        // Tamanho 100000
        tam = 100000;
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }

    menuNumeros(tam);
}

void menuOrdenacao()
{
    int op = 0;
    printf("----------MENU----------\n");
    printf("1 - Bolha\n");
    printf("2 - Bolha com Parada\n");
    printf("3 - Inserção Direta\n");
    printf("4 - Inserção Binária\n");
    printf("5 - ShellSort\n");
    printf("6 - Seleção Direta\n");
    printf("7 - HeapSort\n");
    printf("8 - QuickSort Início\n");
    printf("9 - QuickSort Centro\n");
    printf("10 - QuickSort Mediana\n");
    printf("11 - MergeSort\n");
    printf("12 - RadixSort\n");
    printf("13 - BucketSort\n");
    printf("------------------------\n");
    printf("Opção: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        // Ordenação Bolha
        void bolha();
        break;
    case 2:
        // Ordenação Bolha com Parada
        break;
    case 3:
        // Inserção Direta
        break;
    case 4:
        // Inserção Binária
        break;
    case 5:
        // ShellSort
        break;
    case 6:
        // Seleção Direta
        break;
    case 7:
        // HeapSort
        break;
    case 8:
        // QuickSort Início
        break;
    case 9:
        // QuickSort Centro
        break;
    case 10:
        // QuickSort Mediana
        break;
    case 11:
        // MergeSort
        break;
    case 12:
        // RadixSort
        break;
    case 13:
        // BucketSort
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }
}
