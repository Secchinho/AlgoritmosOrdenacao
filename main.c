#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

// Fiz um menu básico aqui, ainda precisa ser ajeitado
// Falta colocar um loop pro programa não finalizar após a execução e também não sei se esse menu vai ser fácil de integrar aos algoritmos
// Fiz ele mais pra podermos testar os algoritmos que quisermos e já ir adiantando um menu ao mesmo tempo.

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
        menuNumeros();
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