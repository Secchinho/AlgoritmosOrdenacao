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

    int *vetor = lerArquivo(tamanho);
    
    switch (op)
    {
    case 1:
        // Ordenação Bolha
        bolha(vetor, tamanho);
        saida(vetor, tamanho, "Bolha");
        break;
    case 2:
        // Ordenação Bolha com Parada
        bolhaComParada(vetor, tamanho);
        saida(vetor, tamanho, "BolhaComParada");
        break;
    case 3:
        // Inserção Direta
        insercaoDireta(vetor, tamanho);
        saida(vetor, tamanho, "InsercaoDireta");
        break;
    case 4:
        // Inserção Binária
        insercaoBinaria(vetor, tamanho);
        saida(vetor, tamanho, "InsercaoBinaria");
        break;
    case 5:
        // ShellSort
        shellsort(vetor, tamanho);
        saida(vetor, tamanho, "Shellsort");
        break;
    case 6:
        // Seleção Direta
        selecaoDireta(vetor, tamanho);
        saida(vetor, tamanho, "SelecaoDireta");
        break;
    case 7:
        // HeapSort
        heapsort(vetor, tamanho);
        saida(vetor, tamanho, "Heapsort");
        break;
    case 8:
        // QuickSort Início
        contadorQuickSortIni(vetor, 0, tamanho);
        saida(vetor, tamanho, "QuicksortInicio");
        break;
    case 9:
        // QuickSort Centro
        quicksortCentro(vetor, 0, tamanho);
        saida(vetor, tamanho, "QuicksortCentro");
        break;
    case 10:
        // QuickSort Mediana
        contadorQuickSortMediana(vetor, 0, tamanho);
        saida(vetor, tamanho, "QuicksortMediana");
        break;
    case 11:
        // MergeSort
        mergesort(vetor, 0, tamanho);
        saida(vetor, tamanho, "Mergesort");
        break;
    case 12:
        // RadixSort
        radixsort(vetor, tamanho);
        saida(vetor, tamanho, "Radixsort");
        break;
    case 13:
        // BucketSort
        bucketsort(vetor, tamanho);
        saida(vetor, tamanho, "Bucketsort");
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
