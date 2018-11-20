#include<iostream>
#include<thread>
#include<time.h>

using namespace std;

void cria_decrescente(int *vet, int tam){
	for(int i = tam-1; i >= 0; i--){
		vet[i] = tam-i;
	}
}

void ler_arquivo(int *vet, int tam){
	FILE *arq;
	arq = fopen("entrada1e+06.txt","r");
	for(int i = 0; i < tam; i++){
		fscanf(arq,"%d",&vet[i]);
	}
	fclose(arq);
}

void insertion_sort(int *elementos, int n){
    int j, x;
	for(int i =1; i <n; i++)
	{
		j =i-1;
		x = elementos[i];
		while( x < elementos[j] && j>=0)
		{
			elementos[j+1] = elementos[j];
			elementos[j] = x;
			j--;
		}
	}
}

void Juntar(int vetor[], int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void MergeSort(int vetor[], int inicio, int fim, int vetorAux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, vetorAux);
    MergeSort(vetor, meio, fim, vetorAux);
    Juntar(vetor, inicio, meio, fim, vetorAux);
}

void merge_sort(int vetor[], int tamanho) {
    int vetorAux[tamanho];
    MergeSort(vetor, 0, tamanho, vetorAux);
}

int main() {
    int *vet = new int[1000000], *vet2 = new int[1000000], tam = 1000000;

   //ler_arquivo(vet, tam);
    ler_arquivo(vet2, tam);
    // cria_decrescente(vet,tam);
    // cria_decrescente(vet2,tam);
    clock_t Ticks[4];


    /*Ticks[0] = clock();
    insertion_sort(vet,tam);
    Ticks[1] = clock();*/

    Ticks[2] = clock();
    thread t1(insertion_sort, vet2, tam);
    Ticks[3] = clock();

    t1.join();
    /*
    cout << "Tempo gasto sem thread: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
    cout << endl;*/

    cout << "Tempo gasto com thread: " << (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
    cout << endl;

    for(int i = 0; i < 1000000; i++){
        cout << "I:" << i << " - " << vet2[i] << endl;
    }    

    delete [] vet;
    delete [] vet2;

    return 0;
}