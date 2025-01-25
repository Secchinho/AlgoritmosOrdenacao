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
        if (op == 1 || op == 2)
        {
            menuTamEntrada(op);
        }
        else if(op == 3)
        {
            printf("Saindo.....\n");
        }
        else
        {
            printf("Opção inválida.Tente novamente!\n\n");
        }
    } while (op != 3);
    
    return 0;
}
