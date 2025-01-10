#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

/*
    Mudei a entrada do menu, porque quando fiz o menu esqueci que precisávamos de 1000, 10000 e 100000 como opção de entrada kakakakakakakak
    Agora coloquei essa opção, não me agradou ter que chamar a função no arquivo menus.c 3 vezes, mesmo que em condicional, ainda vou pensar em como solucionar, se tiver
    uma ideia, sinta-se a vontade para resolver lá.
*/

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