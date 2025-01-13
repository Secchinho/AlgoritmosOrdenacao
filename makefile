all: compila

compila: main.o menus.o algoritmos.o geracaoNumeros.o
	gcc main.o menus.o algoritmos.o geracaoNumeros.o -o prog

main.o: main.c
	gcc -c main.c

menus.o: menus.c
	gcc -c menus.c

algoritmos.o: algoritmos.c
	gcc -c algoritmos.c

geracaoNumeros.o: geracaoNumeros.c
	gcc -c geracaoNumeros.c

del:
	rm prog main.o menus.o algoritmos.o geracaoNumeros.o
