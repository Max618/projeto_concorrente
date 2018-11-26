#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>

using namespace std;

void ler_arquivo(int *vet, int tam){
	FILE *arq;
	arq = fopen("entrada1e+06.txt","r");
	for(int i = 0; i < tam; i++){
		fscanf(arq,"%d",&vet[i]);
	}
	fclose(arq);
}

void escreve_arquivo(int *vet, int tam, char *tipo){
	FILE *arq;
	arq = fopen("saida_thread.txt",tipo);
    fprintf(arq,"------INICIO------\n");
	for(int i = 0; i < tam; i++){
		fprintf(arq,"%d\n",vet[i]);
	}
    fprintf(arq,"\n");
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
    int TAM = 100000;
    int *vet = new int[TAM];
    int *vet2 = new int[TAM];
    int *vet3 = new int[TAM];
    int *vet4 = new int[TAM];
    int *vet5 = new int[TAM];
    int *vet6 = new int[TAM];

    ler_arquivo(vet, TAM);
    ler_arquivo(vet2, TAM);
    ler_arquivo(vet3, TAM);
    ler_arquivo(vet4, TAM);
    ler_arquivo(vet5, TAM);
    ler_arquivo(vet6, TAM);

    auto t_start = chrono::high_resolution_clock::now();
    thread t1(insertion_sort,vet,TAM);
    thread t2(insertion_sort,vet2,TAM);
    thread t3(insertion_sort,vet3,TAM);
    thread t4(insertion_sort,vet4,TAM);
    thread t5(insertion_sort,vet5,TAM);
    thread t6(insertion_sort,vet6,TAM);

    t1.join(); 
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    auto t_end = chrono::high_resolution_clock::now();

    cout << "Tempo total gasto: " << chrono::duration<double, milli>(t_end-t_start).count() << " em ms" << endl;
    cout << endl;

    escreve_arquivo(vet,TAM,"w");
    escreve_arquivo(vet2,TAM,"a");
    escreve_arquivo(vet3,TAM,"a");
    escreve_arquivo(vet4,TAM,"a");
    escreve_arquivo(vet5,TAM,"a");
    escreve_arquivo(vet6,TAM,"a");

    delete [] vet;
    delete [] vet2;
    delete [] vet3;
    delete [] vet4;
    delete [] vet5;
    delete [] vet6;

    return 0;
}