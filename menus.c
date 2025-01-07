#include <stdio.h>

void menuNumeros()
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
        break;
    case 2:
        // Função geração crescente
        break;
    case 3:
        // Função geração decrescente
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }
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