#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main()
{
    int op = 0;
    do
    {
        printf("----------MENU----------\n");
        printf("1 - Gerar numeros\n");
        printf("2 - Ordenar numeros\n");
        printf("3 - Sair\n");
        printf("------------------------\n");
        printf("Opcao: ");
        scanf(" %d", &op);

        system("cls");
        if (op != 3)
        {
            menuTamEntrada(op);
        }
        else
        {
            printf("Saindo.....\n");
        } 
    } while (op != 3);
    
    return 0;
}
