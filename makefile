all: compila

compila: main.o menus.o bolha.o bolhaComParada.o insercaoDireta.o insercaoBinaria.o shellSort.o heapSort.o selecaoDireta.o quickSortIni.o quickSortCentro.o quickSortMediana.o mergeSort.o bucketSort.o radixSort.o geracaoNumeros.o
	gcc main.o menus.o bolha.o bolhaComParada.o insercaoDireta.o insercaoBinaria.o shellSort.o heapSort.o selecaoDireta.o quickSortIni.o quickSortCentro.o quickSortMediana.o mergeSort.o bucketSort.o radixSort.o geracaoNumeros.o -o prog

main.o: main.c
	gcc -c main.c

menus.o: menus.c
	gcc -c menus.c

bolha.o: bolha.c
	gcc -c bolha.c

bolhaComParada.o: bolhaComParada.c
	gcc -c bolhaComParada.c

insercaoDireta.o: insercaoDireta.c
	gcc -c insercaoDireta.c

insercaoBinaria.o: insercaoBinaria.c
	gcc -c insercaoBinaria.c

shellSort.o: shellSort.c
	gcc -c shellSort.c

heapSort.o: heapSort.c
	gcc -c heapSort.c

selecaoDireta.o: selecaoDireta.c
	gcc -c selecaoDireta.c

quickSortIni.o: quickSortIni.c
	gcc -c quickSortIni.c

quickSortCentro.o: quickSortCentro.c
	gcc -c quickSortCentro.c

quickSortMediana.o: quickSortMediana.c
	gcc -c quickSortMediana.c

mergeSort.o: mergeSort.c
	gcc -c mergeSort.c

bucketSort.o: bucketSort.c
	gcc -c bucketSort.c

radixSort.o: radixSort.c
	gcc -c radixSort.c

geracaoNumeros.o: geracaoNumeros.c
	gcc -c geracaoNumeros.c

del:
	rm prog main.o menus.o bolha.o bolhaComParada.o insercaoDireta.o insercaoBinaria.o shellSort.o heapSort.o selecaoDireta.o quickSortIni.o quickSortCentro.o quickSortMediana.o mergeSort.o bucketSort.o radixSort.o geracaoNumeros.o
