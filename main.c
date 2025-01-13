#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main()
{
    int op = 0;
    printf("----------MENU----------\n");
    printf("1 - Gerar números\n");
    printf("2 - Ordenar números\n");
    printf("------------------------\n");
    printf("Opção: ");
    scanf(" %d", &op);

    system("clear");

    switch (op)
    {
    case 1:
        menuTamEntrada();
        break;
    case 2:
        menuOrdenacao();
        break;
    default:
        printf("\nErro, opção inválida!\n");
        break;
    }
    return 0;
}