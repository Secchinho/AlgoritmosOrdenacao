typedef struct Baldes
{
    int topo;
    int *balde;
} baldes;

void bolha(int *vetor, int n);
void bolhaComParada(int *vetor, int n);
void insercaoDireta(int *vetor, int n);
void insercaoBinaria(int *vetor, int n);
void shellsort(int *vetor, int n);
void criaHeap(int *vetor, int i, int f, int *comp);
void heapsort(int *vetor, int n);
void selecaoDireta(int *vetor, int n);
void particao(int *vetor, int esquerda, int direita, int *i, int *j, int *comp);
void ordena(int *vetor, int esquerda, int direita, int *comp);
void quicksortCentro(int *vetor, int esquerda, int direita);
void intercalar(int *vetor, int inicio, int fim, int meio);
void merge(int *vetor, int inicio, int fim);
void mergesort(int *vetor, int inicio, int fim);
void quicksortIni(int *vetor, int esq, int dir);
int mediana(int *vetor, int esq, int dir);
void quicksortMediana(int *vetor, int esq, int dir);
void bucketsort(int *vetor, int n);
int maiorNumero(int *vetor, int n);
void contagem(int *vetor, int n, int exp);
void radixsort(int *vetor, int n);