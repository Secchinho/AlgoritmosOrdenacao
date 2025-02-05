#include <stdio.h>
#include <stdlib.h>
#include "geracaoNumeros.h"
#include "bolha.h"
#include "bolhaComParada.h"
#include "insercaoDireta.h"
#include "insercaoBinaria.h"
#include "shellSort.h"
#include "heapSort.h"
#include "selecaoDireta.h"
#include "quickSortIni.h"
#include "quickSortCentro.h"
#include "quickSortMediana.h"
#include "mergeSort.h"
#include "bucketSort.h"
#include "radixSort.h"


void menuNumeros(int tam)
{
    system("cls");
    int op = 0;
    printf("----------MENU----------\n");
    printf("1 - Ordem Aleatoria\n");
    printf("2 - Ordem Crescente\n");
    printf("3 - Ordem Decrescente\n");
    printf("------------------------\n");
    printf("Opcao: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        // Funcao geracao aleatória
        ordemAleatoria(tam);
        break;
    case 2:
        // Funcao geracao crescente
        ordemCrescente(tam);
        break;
    case 3:
        // Funcao geracao decrescente
        ordemDecrescente(tam);
        break;
    default:
        printf("\nErro, opcao invalida\n");
        break;
    }
}

void menuOrdenacao(int tamanho)
{
    system("cls");
    int op = 0;
    printf("----------MENU----------\n");
    printf("1 - Bolha\n");
    printf("2 - Bolha com Parada\n");
    printf("3 - Insercao Direta\n");
    printf("4 - Insercao Binaria\n");
    printf("5 - ShellSort\n");
    printf("6 - Selecao Direta\n");
    printf("7 - HeapSort\n");
    printf("8 - QuickSort Inicio\n");
    printf("9 - QuickSort Centro\n");
    printf("10 - QuickSort Mediana\n");
    printf("11 - MergeSort\n");
    printf("12 - RadixSort\n");
    printf("13 - BucketSort\n");
    printf("------------------------\n");
    printf("Opcao: ");
    scanf(" %d", &op);

    int *vetor = lerArquivo(tamanho);
    
    switch (op)
    {
    case 1:
        // Ordenacao Bolha
        chamaBolha(vetor, tamanho);
        saida(vetor, tamanho, "Bolha");
        break;
    case 2:
        // Ordenacao Bolha com Parada
        bolhaComParada(vetor, tamanho);
        saida(vetor, tamanho, "BolhaComParada");
        break;
    case 3:
        // Insercao Direta
        insercaoDireta(vetor, tamanho);
        saida(vetor, tamanho, "InsercaoDireta");
        break;
    case 4:
        // Insercao Binaria
        insercaoBinaria(vetor, tamanho);
        saida(vetor, tamanho, "InsercaoBinaria");
        break;
    case 5:
        // ShellSort
        shellsort(vetor, tamanho);
        saida(vetor, tamanho, "Shellsort");
        break;
    case 6:
        // Selecao Direta
        selecaoDireta(vetor, tamanho);
        saida(vetor, tamanho, "SelecaoDireta");
        break;
    case 7:
        // HeapSort
        heapsort(vetor, tamanho);
        saida(vetor, tamanho, "Heapsort");
        break;
    case 8:
        // QuickSort Inicio
        contadorQuickSortIni(vetor, 0, tamanho);
        saida(vetor, tamanho, "QuicksortInicio");
        break;
    case 9:
        // QuickSort Centro
        contadorQuicksortCentro(vetor, 0, tamanho);
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
        printf("\nErro, opcao invalida\n");
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
    printf("Opcao: ");
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
        printf("\nErro, opcao invalida\n");
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
        printf("\nOpcao invalida!");
    }
}
