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

    menuTamEntrada(op);
    return 0;
}