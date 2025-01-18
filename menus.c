#include <stdio.h>
#include <stdlib.h>
#include "geracaoNumeros.h"
#include "algoritmos.h"

void menuNumeros(int tam)
{
    system("clear");
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
        ordemDecrescente(tam);
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }
}

void menuOrdenacao(int tamanho)
{
    system("clear");
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
        void bolha(vetor, tamanho);
        break;
    case 2:
        // Ordenação Bolha com Parada
        void bolhaComParada(vetor, tamanho);
        break;
    case 3:
        // Inserção Direta
        void insercaoDireta(vetor, tamanho);
        break;
    case 4:
        // Inserção Binária
        void insercaoBinaria(vetor, tamanho);
        break;
    case 5:
        // ShellSort
        void shellsort(vetor, tamanho);
        break;
    case 6:
        // Seleção Direta
        void selecaoDireta(vetor, tamanho);
        break;
    case 7:
        // HeapSort
        void heapsort(vetor, tamanho);
        break;
    case 8:
        // QuickSort Início
        void contadorQuicksortIni(vetor, 0, tamanho);
        break;
    case 9:
        // QuickSort Centro
        void quicksortCentro(vetor, 0, tamanho);
        break;
    case 10:
        // QuickSort Mediana
        void quicksortMediana(int *vetor, int esq, int dir);
        break;
    case 11:
        // MergeSort
        void mergesort(vetor, 0, tamanho);
        break;
    case 12:
        // RadixSort
        void radixsort(vetor, tamanho);
        break;
    case 13:
        // BucketSort
        void bucketsort(vetor, tamanho);
        break;
    default:
        printf("\nErro, opção inválida\n");
        break;
    }
}

void menuTamEntrada(int opcao)
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

    if(opcao == 1)
    {
        menuNumeros(tam);
    }
    else if(opcao == 2)
    {
        menuOrdenacao(tam);
    }
    else 
    {
        printf("\nOpção inválida!");
    }
}
